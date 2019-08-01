//
//  ViewController.m
//  Demo
//
//  Created by mt on 2018/6/15.
//  Copyright © 2018年 mt. All rights reserved.
//

#import "ViewController.h"
#import <AliRTCSdk/AliRtcEngine.h>
#import "FakeAuthrization.h"
#import "RemoteViewModel.h"
#import "LocalView.h"
#import "RemoteUserCollectionViewItem.h"

@interface ViewController()<AliRtcEngineDelegate,NSCollectionViewDelegate,NSCollectionViewDataSource>

/**
 频道号输入框
 */
@property (weak) IBOutlet NSTextField *channelTextField;

/**
 确认按钮
 */
@property (weak) IBOutlet NSButton *sureButton;

/**
 版本标签
 */
@property (weak) IBOutlet NSTextField *versionLabel;

/**
 退出按钮
 */
@property (weak) IBOutlet NSButton *exitButton;

/**
 本地视频显示视图
 */
@property (weak) IBOutlet LocalView *localView;

/**
 远程视频显示视图
 */
@property (weak) IBOutlet AliRenderView *remoteView;

/**
 开始按钮
 */
@property (weak) IBOutlet NSButton *startButton;

/**
 屏幕共享按钮
 */
@property (weak) IBOutlet NSButton *screenButton;

/**
 屏幕共享中
 */
@property (weak) IBOutlet NSTextField *screenSharingLabel;

/**
 音频采集
 */
@property (weak) IBOutlet NSButton *audioCapture;

/**
 音频播放
 */
@property (weak) IBOutlet NSButton *audioPlayer;

//记录audioCapture点击状态
@property (nonatomic, assign) BOOL isCapture;

//记录audioPlayer点击状态
@property (nonatomic, assign) BOOL isPlayer;

/**
 RTC工程类
 */
@property (nonatomic, strong) AliRtcEngine *engine;

/**
 鉴权信息
 */
@property (nonatomic, strong) AliRtcAuthInfo *authInfo;

/**
 远程显示画布
 */
@property (nonatomic, strong) AliVideoCanvas *remoteCanvas;

/**
 当前订阅的UID
 */
@property (nonatomic, copy) NSString *curSubUid;

/**
 用户名
 */
@property (nonatomic, copy) NSString *userName;

/**
 远程用户数组
 */
@property (nonatomic, strong) NSMutableArray<RemoteViewModel *> *remoteModelArr;


/**
 远程用户列表视图
 */
@property (weak) IBOutlet NSCollectionView *remoteUserView;

/**
 @brief 是否入会
 */
@property(nonatomic, assign) BOOL isJoinChannel;


/**
 @brief 操作锁
 */
@property(nonatomic, strong) NSRecursiveLock *arrLock;


@end

@implementation ViewController


- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    //初始化UI
    [self initUI];
}

#pragma mark - initUI
- (void)initUI {
    //获取sdk版本号
    _versionLabel.stringValue = [AliRtcEngine getSdkVersion];
    
    //collectionView
    self.remoteUserView.backgroundColors = @[[NSColor clearColor]];
    NSCollectionViewFlowLayout *gridLayout = self.remoteUserView.collectionViewLayout;
    gridLayout.itemSize = NSMakeSize(100, 160);
    gridLayout.scrollDirection = NSCollectionViewScrollDirectionHorizontal;
    [self.remoteUserView registerClass:[RemoteUserCollectionViewItem class] forItemWithIdentifier:@"cell"];
    
}


#pragma mark - Action
// 点击确认按钮
- (IBAction)sureButtonClick:(NSButton *)sender {
    if (_channelTextField.stringValue.length > 2 &&
        _channelTextField.stringValue.length < 13 &&
        [self isAllNum:_channelTextField.stringValue]) {
        
        NSInteger num = random() % 100000 + 1000;
        _userName = [NSString stringWithFormat:@"%zd", num];
        // 向服务器请求鉴权信息
        __weak typeof(self)weakSelf = self;
        [FakeAuthrization GetPassportFromAppServer:_channelTextField.stringValue userName:_userName block:^(AliRtcAuthInfo *loginModel, NSError *error) {
            if (error) {
                [weakSelf showNotice:@"数据请求失败"];
            } else {
                weakSelf.authInfo = loginModel;
                //初始化SDK, 开启本地预览
                [weakSelf startPreview];
            }
        }];
    } else {
        [self showNotice:@"请输入3-12位数字"];
    }
}

//初始化SDK, 开启本地预览
- (void)startPreview {
    __weak typeof(self)weakSelf = self;
    dispatch_async(dispatch_get_main_queue(), ^{
        
        // 初始化SDK
        weakSelf.engine = [AliRtcEngine sharedInstance:self extras:@""];
        
        // 设置自动推拉流
        [weakSelf.engine setAutoPublish:YES withAutoSubscribe:YES];
        
        //音频采集
        if (self.isCapture) {
            [self.engine startAudioCapture];
        }else{
            [self.engine stopAudioCapture];
        }
        self.audioCapture.enabled = NO;
        
        //音频播放
        if (self.isPlayer) {
            [self.engine startAudioPlayer];
        }else{
            [self.engine stopAudioPlayer];
        }
        self.audioPlayer.enabled = NO;
        
        // 开启本地预览
        [weakSelf setupPreview];
        
        weakSelf.channelTextField.hidden = true;
        weakSelf.sureButton.hidden = true;
        weakSelf.versionLabel.hidden = true;
        
        weakSelf.exitButton.hidden = false;
        weakSelf.localView.hidden = false;
        weakSelf.remoteView.hidden = false;
        weakSelf.startButton.hidden = false;
        weakSelf.screenButton.hidden = false;
        weakSelf.startButton.enabled = true;
        weakSelf.screenButton.enabled = true;
        
        [weakSelf.engine startPreview];
    });
}

// 点击退出按钮
- (IBAction)exitButtonClick:(id)sender {
    
    [_engine stopPreview];
    if (_isJoinChannel) {
        [_engine leaveChannel];
    }
    [AliRtcEngine destroy];
    _authInfo = nil;
    
    _channelTextField.hidden = false;
    _sureButton.hidden = false;
    _versionLabel.hidden = false;
    
    _exitButton.hidden = true;
    _localView.hidden = true;
    _remoteView.hidden = true;
    _startButton.hidden = true;
    _screenButton.hidden = true;
    _screenSharingLabel.hidden = true;
    
    self.audioCapture.enabled = YES;
    self.audioPlayer.enabled = YES;
    
    @synchronized (self) {
        for (NSInteger i = self.remoteModelArr.count - 1; i >= 0; i--) {
            RemoteViewModel *model = self.remoteModelArr[i];
            [self.remoteModelArr removeObject:model];
        }
        dispatch_async(dispatch_get_main_queue(), ^{
            [self.remoteUserView reloadData];
        });
    }
}

// 开始
- (IBAction)startButtonClick:(id)sender {
    // 加入频道
    [self joinChannel];
}

// 屏幕共享
- (IBAction)screenButtonClick:(id)sender {
    [_engine configLocalScreenPublish:true];
    
    __weak typeof(self)weakSelf = self;
    [_engine publish:^(int err) {
        dispatch_async(dispatch_get_main_queue(), ^{
            if(err != 0) {
                [weakSelf showNotice:@"屏幕共享失败"];
            } else {
                weakSelf.screenButton.enabled = false;
                weakSelf.screenSharingLabel.hidden = false;
            }
        });
    }];
}

#pragma mark - Pravite
// 判断是否是纯数字
- (BOOL)isAllNum:(NSString *)string {
    unichar c;
    for (int i = 0; i < string.length; i++) {
        c = [string characterAtIndex:i];
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}

// 开启本地预览
- (void)setupPreview {
    AliVideoCanvas *canvas = [[AliVideoCanvas alloc] init];
    canvas.view = _localView;
    canvas.renderMode = AliRtcRenderModeAuto;
    [_engine setLocalViewConfig:canvas forTrack:AliRtcVideoTrackCamera];
}

// 加入频道
- (void)joinChannel{
    // 加入频道
    __weak typeof(self)weakSelf = self;
    [self.engine joinChannel:_authInfo name:_userName onResult:^(NSInteger errCode) {
        NSLog(@"joinChannel result: %d", (int)errCode);
        dispatch_async(dispatch_get_main_queue(), ^{
            if (errCode != 0) {
                [weakSelf showNotice:@"加入频道失败"];
            } else {
                weakSelf.startButton.enabled = false;
            }
            self->_isJoinChannel = true;
        });
    }];
}

// 提示信息
- (void)showNotice:(NSString *)notice {
    dispatch_async(dispatch_get_main_queue(), ^{
        NSAlert * alert = [[NSAlert alloc]init];
        alert.messageText = @"提示";
        alert.alertStyle = NSAlertStyleInformational;
        [alert addButtonWithTitle:@"取消"];
        [alert setInformativeText:notice];
        [alert beginSheetModalForWindow:[self.view window] completionHandler:^(NSModalResponse returnCode) {
            
        }];
    });
}


- (void)addRemoteViewWithUid:(NSString *)uid videoTrack:(AliRtcVideoTrack)videoTrack {
    RemoteViewModel *cameraModel = nil;
    RemoteViewModel *screenModel = nil;
    @synchronized (self) {
        for (RemoteViewModel *model in self.remoteModelArr) {
            if ([uid isEqualToString:model.uid]) {
                if (model.videoTrack == AliRtcVideoTrackCamera) {
                    cameraModel = model;
                } else if (model.videoTrack == AliRtcVideoTrackScreen) {
                    screenModel = model;
                }
            }
        }
    }
    if (videoTrack == AliRtcVideoTrackCamera) {
        [self removeRemoteViewWithRemoteModel:screenModel];
        if (cameraModel) {
            // 覆盖
            [self.engine setRemoteViewConfig:cameraModel.remoteCanvas uid:uid forTrack:AliRtcVideoTrackCamera];
        } else {
            // 创建一个
            [self creatRemoteViewWithUid:uid videoTrack:AliRtcVideoTrackCamera];
        }
    } else if (videoTrack == AliRtcVideoTrackScreen) {
        [self removeRemoteViewWithRemoteModel:cameraModel];
        if (screenModel) {
            // 覆盖
            [self.engine setRemoteViewConfig:screenModel.remoteCanvas uid:uid forTrack:AliRtcVideoTrackScreen];
        } else {
            // 创建一个
            [self creatRemoteViewWithUid:uid videoTrack:AliRtcVideoTrackScreen];
        }
    } else if (videoTrack == AliRtcVideoTrackBoth) {
        if (cameraModel) {
            // 覆盖
            [self.engine setRemoteViewConfig:cameraModel.remoteCanvas uid:uid forTrack:AliRtcVideoTrackCamera];
        } else {
            // 创建一个
            [self creatRemoteViewWithUid:uid videoTrack:AliRtcVideoTrackCamera];
        }
        if (screenModel) {
            // 覆盖
            [self.engine setRemoteViewConfig:screenModel.remoteCanvas uid:uid forTrack:AliRtcVideoTrackScreen];
        } else {
            // 创建一个
            [self creatRemoteViewWithUid:uid videoTrack:AliRtcVideoTrackScreen];
        }
    }
    dispatch_async(dispatch_get_main_queue(), ^{
        [self.remoteUserView reloadData];
    });
}

- (void)removeRemoteViewWithRemoteModel:(RemoteViewModel *)model {
    if (model == nil) {
        return;
    }
    // 先删除数据 然后删除试图 然后重新排列
    [_arrLock lock];
    [self.remoteModelArr removeObject:model];
    [_arrLock unlock];
}

- (void)removeRemoteViewWithUid:(NSString *)uid {
    
    dispatch_async(dispatch_get_main_queue(), ^{
        [self.arrLock lock];
        // 先删除数据 然后删除试图 然后重新排列
        for (NSInteger i = self.remoteModelArr.count - 1; i >= 0; i--) {
            RemoteViewModel *model = self.remoteModelArr[i];
            if ([uid isEqualToString:model.uid]) {
                [self.remoteModelArr removeObject:model];
            }
        }
        [self.arrLock unlock];
        [self.remoteUserView reloadData];
    });
}

- (void)creatRemoteViewWithUid:(NSString *)uid videoTrack:(AliRtcVideoTrack)videoTrack {
    [self.arrLock lock];
    RemoteViewModel *model = [[RemoteViewModel alloc] init];
    model.uid = uid;
    model.remoteCanvas = [self creatRenderView];
    model.videoTrack = videoTrack;
    [self.remoteModelArr addObject:model];
    [self.arrLock unlock];
    // 加载视频
    [self.engine setRemoteViewConfig:model.remoteCanvas uid:uid forTrack:videoTrack];
}

- (AliVideoCanvas *)creatRenderView {
    AliRenderView *view = [[AliRenderView alloc] init];
    AliVideoCanvas *canvas = [[AliVideoCanvas alloc] init];
    canvas.view = view;
    canvas.renderMode = AliRtcRenderModeAuto;
    return canvas;
}


#pragma mark - Lazy

- (AliVideoCanvas *)remoteCanvas {
    if (!_remoteCanvas) {
        _remoteCanvas = [[AliVideoCanvas alloc] init];
        _remoteCanvas.renderMode = AliRtcRenderModeAuto;
        _remoteCanvas.view = self.remoteView;
    }
    return _remoteCanvas;
}

- (NSMutableArray<RemoteViewModel *> *)remoteModelArr {
    if (!_remoteModelArr) {
        _remoteModelArr = [NSMutableArray array];
    }
    return _remoteModelArr;
}

#pragma mark - NSCollectioView datasource

- (NSInteger)collectionView:(NSCollectionView *)collectionView numberOfItemsInSection:(NSInteger)section {
    return self.remoteModelArr.count;
}


- (NSCollectionViewItem *)collectionView:(NSCollectionView *)collectionView itemForRepresentedObjectAtIndexPath:(NSIndexPath *)indexPath {
    RemoteUserCollectionViewItem *item = [collectionView makeItemWithIdentifier:@"cell" forIndexPath:indexPath];
    RemoteViewModel *model = self.remoteModelArr[indexPath.item];
    CGRect frame = CGRectMake(0, 0, 100, 160-42);
    model.remoteCanvas.view.frame = frame;
    [item.view addSubview:model.remoteCanvas.view];
    
    //记录UID
    NSString *uid = model.uid;
    //视频流类型
    AliRtcVideoTrack track = model.videoTrack;

    item.cameraMirrorBlock = ^(BOOL isOn) {
        [self switchClick:isOn track:track uid:uid model:model];
    };
    
    item.mediaInfoBlock = ^{
        [self mediaInfoClick:track uid:uid];
    };
    
    return item;
}

//远端用户镜像按钮点击事件
- (void)switchClick:(BOOL)isOn track:(AliRtcVideoTrack)track uid:(NSString *)uid model:(RemoteViewModel *)model {
    AliVideoCanvas *canvas = [[AliVideoCanvas alloc] init];
    canvas.renderMode = AliRtcRenderModeFill;
    canvas.view = (AliRenderView *)model.remoteCanvas.view;
    if (isOn) {
        canvas.mirrorMode = AliRtcRenderMirrorModeAllEnabled;
    }else{
        canvas.mirrorMode = AliRtcRenderMirrorModeAllDisabled;
    }
    [self.engine setRemoteViewConfig:canvas uid:uid forTrack:track];
}

//获取当前的媒体流信息
- (void)mediaInfoClick:(AliRtcVideoTrack)track uid:(NSString *)uid {
    NSString *mediaInfoCamera = [self.engine getMediaInfoWithUserId:uid videoTrack:track keys:@[@"Height",@"Width",@"FPS",@"LossRate"]];
    dispatch_async(dispatch_get_main_queue(), ^{
        NSAlert * alert = [[NSAlert alloc]init];
        alert.messageText = @"媒体流信息";
        alert.alertStyle = NSAlertStyleInformational;
        [alert addButtonWithTitle:@"取消"];
        [alert setInformativeText:mediaInfoCamera];
        [alert beginSheetModalForWindow:[self.view window] completionHandler:^(NSModalResponse returnCode) {
            
        }];
    });
}



#pragma mark Engin delegate
// 当远端用户上线时会返回这个消息
- (void)onRemoteUserOnLineNotify:(NSString *)uid{
    // 如果上线了，那就创建一个远端的view
    
}

// 当远端用户下线时会返回这个消息
- (void)onRemoteUserOffLineNotify:(NSString *)uid{
    [self removeRemoteViewWithUid:uid];
}

// 当订阅情况发生变化时，返回这个消息
- (void)onSubscribeChangedNotify:(NSString *)uid audioTrack:(AliRtcAudioTrack)audioTrack videoTrack:(AliRtcVideoTrack)videoTrack {
    
    __weak typeof(self)weakSelf = self;
    dispatch_async(dispatch_get_main_queue(), ^{
        __strong typeof(weakSelf)strongSelf = self;
        if (videoTrack == AliRtcVideoTrackNo) {
            [self removeRemoteViewWithUid:uid];
        } else if(videoTrack == AliRtcVideoTrackCamera) {
            [strongSelf addRemoteViewWithUid:uid videoTrack:AliRtcVideoTrackCamera];
        } else if(videoTrack == AliRtcVideoTrackScreen) {
            [strongSelf addRemoteViewWithUid:uid videoTrack:AliRtcVideoTrackScreen];
        } else if(videoTrack == AliRtcVideoTrackBoth) {
            [strongSelf addRemoteViewWithUid:uid videoTrack:AliRtcVideoTrackBoth];
        }
    });
}

// 如果engine出现error，通过这个回调通知app
- (void)onOccurError:(int)error {
    if (error != 0) {
        [self showNotice:@"通话错误"];
    }
}

// 被服务器踢出频道
- (void)onBye:(int)code {
    if (code == AliRtcOnByeChannelTerminated) {
        [self showNotice:@"channel已结束"];
    }
}

//音频采集点击事件
- (IBAction)audioCaptureClick:(id)sender {
    self.isCapture = !self.isCapture;
}

//音频播放点击事件
- (IBAction)audioPlayerClick:(id)sender {
    self.isPlayer = !self.isPlayer;
}

@end
