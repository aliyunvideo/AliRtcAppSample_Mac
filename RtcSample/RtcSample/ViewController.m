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

@interface ViewController()<AliRtcEngineDelegate>

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
@property (weak) IBOutlet AliRenderView *localView;

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

@end

@implementation ViewController


- (void)viewDidLoad {
    
    [super viewDidLoad];

    [self initUI];
}

- (void)initUI {
    _versionLabel.stringValue = [AliRtcEngine getSdkVersion];
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
                [weakSelf trunRoomView];
            }
        }];
    } else {
        [self showNotice:@"请输入3-12位数字"];
    }
}

- (void)trunRoomView {
    __weak typeof(self)weakSelf = self;
    dispatch_async(dispatch_get_main_queue(), ^{
        
        // 初始化SDK
        weakSelf.engine = [AliRtcEngine sharedInstance:self extras:@""];
        
        // 设置自动推拉流
        [weakSelf.engine setAutoPublish:YES withAutoSubscribe:YES];
        
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
    [_engine leaveChannel];
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
}

// 开始
- (IBAction)startButtonClick:(id)sender {
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


#pragma mark - Lazy
- (AliVideoCanvas *)remoteCanvas {
    if (!_remoteCanvas) {
        _remoteCanvas = [[AliVideoCanvas alloc] init];
        _remoteCanvas.renderMode = AliRtcRenderModeAuto;
        _remoteCanvas.view = self.remoteView;
    }
    return _remoteCanvas;
}

#pragma mark Engin delegate
// 当远端用户上线时会返回这个消息
- (void)onRemoteUserOnLineNotify:(NSString *)uid{

}

// 当远端用户下线时会返回这个消息
- (void)onRemoteUserOffLineNotify:(NSString *)uid{

}

// 当订阅情况发生变化时，返回这个消息
- (void)onSubscribeChangedNotify:(NSString *)uid audioTrack:(AliRtcAudioTrack)audioTrack videoTrack:(AliRtcVideoTrack)videoTrack {
    
    __weak typeof(self)weakSelf = self;
    dispatch_async(dispatch_get_main_queue(), ^{
        __strong typeof(weakSelf)strongSelf = self;
        
        if(videoTrack == AliRtcVideoTrackCamera) {
            [strongSelf.engine setRemoteViewConfig:nil uid:strongSelf.curSubUid forTrack:AliRtcVideoTrackCamera];
            [strongSelf.engine setRemoteViewConfig:strongSelf.remoteCanvas uid:uid forTrack:AliRtcVideoTrackCamera];
        } else if(videoTrack == AliRtcVideoTrackScreen || videoTrack == AliRtcVideoTrackBoth) {
            [strongSelf.engine setRemoteViewConfig:nil uid:strongSelf.curSubUid forTrack:AliRtcVideoTrackCamera];
            [strongSelf.engine setRemoteViewConfig:strongSelf.remoteCanvas uid:uid forTrack:AliRtcVideoTrackScreen];
        }
        strongSelf.curSubUid = uid;

    });
}

// 如果engine出现error，通过这个回调通知app
- (void)onOccurError:(int)error {
    if (error != 0) {
        [self showNotice:@"通话错误"];
    }
}


@end
