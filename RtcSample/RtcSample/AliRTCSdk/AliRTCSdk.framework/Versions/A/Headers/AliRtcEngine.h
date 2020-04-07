/* Copyright (c) 2018, Alibaba Inc.
 * All rights reserved
 */

/* This header file is part of Alibaba RTC engine sdk for
 * Mac system.
 */

#import <AppKit/NSOpenGLView.h>


/**
视频流类型

- AliRtcVideoTrackNo: 无摄像头和屏幕共享
- AliRtcVideoTrackCamera: 摄像头
- AliRtcVideoTrackScreen: 屏幕共享
- AliRtcVideoTrackBoth: 摄像头+屏幕共享
*/
typedef NS_ENUM(NSUInteger, AliRtcVideoTrack) {
    AliRtcVideoTrackNo     = 0,
    AliRtcVideoTrackCamera = 1,
    AliRtcVideoTrackScreen = 2,
    AliRtcVideoTrackBoth   = 3,
};

/**
 音频流类型
 
 - AliRtcAudioTrackNo: 无麦克风
 - AliRtcAudioTrackMic: 麦克风
 */
typedef NS_ENUM(NSUInteger, AliRtcAudioTrack) {
    AliRtcAudioTrackNo   = 0,
    AliRtcAudioTrackMic  = 1,
};

/**
网络质量

- AlivcRtcNetworkQualityExcellent: 网络极好，流程度清晰度质量好
- AlivcRtcNetworkQualityGood: 网络好，流畅度清晰度和极好差不多
- AlivcRtcNetworkQualityPoor: 网络较差，音视频流畅度清晰度有瑕疵，不影响沟通
- AlivcRtcNetworkQualityBad: 网络差，视频卡顿严重，音频能正常沟通
- AlivcRtcNetworkQualityVeryBad: 网络极差，基本无法沟通
- AlivcRtcNetworkQualityDisconnect: 网络中断
- AlivcRtcNetworkQualityUnknow: 未知
*/
typedef NS_ENUM(NSUInteger, AliRtcNetworkQuality) {
    AlivcRtcNetworkQualityExcellent  = 0,
    AlivcRtcNetworkQualityGood       = 1,
    AlivcRtcNetworkQualityPoor       = 2,
    AlivcRtcNetworkQualityBad        = 3,
    AlivcRtcNetworkQualityVeryBad    = 4,
    AlivcRtcNetworkQualityDisconnect = 5,
    AlivcRtcNetworkQualityUnknow     = 6,
};

/**
 渲染模式
 
 - AliRtcRenderModeAuto: 自动模式
 - AliRtcRenderModeStretch: 延伸
 - AliRtcRenderModeFill: 填充
 - AliRtcRenderModeCrop: 裁剪
 */
typedef NS_ENUM(NSUInteger, AliRtcRenderMode) {
    AliRtcRenderModeAuto    = 0,
    AliRtcRenderModeStretch = 1,
    AliRtcRenderModeFill    = 2,
    AliRtcRenderModeCrop    = 3,
};

/**
 镜像模式
 
 - AliRtcRenderMirrorModeAllEnabled: 镜像打开
 - AliRtcRenderMirrorModeAllDisabled: 镜像关闭
 */
typedef NS_ENUM(NSInteger, AliRtcRenderMirrorMode) {
    AliRtcRenderMirrorModeAllEnabled = 1,
    AliRtcRenderMirrorModeAllDisabled = 2,
};

/**
 Log级别
 */
typedef NS_ENUM(NSUInteger, AliRtcLogLevel) {
    AliRtcLogLevelDump,
    AliRtcLogLevelDebug,
    AliRtcLogLevelVerbose,
    AliRtcLogLevelInfo,
    AliRtcLogLevelWarn,
    AliRtcLogLevelError,
    AliRtcLogLevelFatal,
    AliRtcLogLevelNone,
};

/**
 视频配置参数
 */
typedef NS_ENUM(NSInteger, AliRtcVideoProfile) {
    AliRtcVideoProfile_Default = 0,
    AliRtcVideoProfile_180_240P_15,
    AliRtcVideoProfile_180_320P_15,
    AliRtcVideoProfile_180_320P_30,
    AliRtcVideoProfile_240_320P_15,
    AliRtcVideoProfile_360_480P_15,
    AliRtcVideoProfile_360_480P_30,
    AliRtcVideoProfile_360_640P_15,
    AliRtcVideoProfile_360_640P_30,
    AliRtcVideoProfile_480_640P_15,
    AliRtcVideoProfile_480_640P_30,
    AliRtcVideoProfile_720_960P_15,
    AliRtcVideoProfile_720_960P_30,
    AliRtcVideoProfile_720_1280P_15,
    AliRtcVideoProfile_720_1280P_30,
    AliRtcVideoProfile_1080_1920P_15,
    AliRtcVideoProfile_1080_1920P_30,
    AliRtcVideoProfile_480_640P_15_1500Kb,
    AliRtcVideoProfile_Max
};

/**
 音频裸数据源类型
 
 - AliRtcAudiosourcePub: 推流音频数据
 - AliRtcAudiosourceSub: 拉流音频数据
 - AliRtcAudiosourceRawData: 采集音频裸数据
 - AliRtcAudiosourceVolume: 音量
 */
typedef NS_ENUM(NSInteger, AliRtcAudioSource) {
    AliRtcAudiosourcePub = 0,
    AliRtcAudiosourceSub = 1,
    AliRtcAudiosourceRawData = 2,
    AliRtcAudiosourceVolume = 3,
};

/**
 视频裸数据源类型
 
 - AliRtcVideosourceCameraType: 视频流
 - AliRtcVideosourceScreenShareType: 屏幕共享流
 - AliRtcVideosourceTypeMax: 占位符，无意义
 */
typedef NS_ENUM(NSInteger, AliRtcVideoSource) {
    AliRtcVideosourceCameraType = 0,
    AliRtcVideosourceScreenShareType = 1,
    AliRtcVideosourceTypeMax,
};

/**
 音频声道数
 
 - AliRtcMonoAudio: 单声道
 - AliRtcStereoAudio: 双声道
 */
typedef NS_ENUM(NSInteger, AliRtcAudioNumChannel) {
    AliRtcMonoAudio = 1,
    AliRtcStereoAudio = 2,
};

/**
 视频数据格式
 */
typedef NS_ENUM(NSInteger, AliRtcVideoFormat) {
    AliRtcVideoFormat_UNKNOW = -1,
    AliRtcVideoFormat_BGRA = 0,
    AliRtcVideoFormat_I420,
    AliRtcVideoFormat_NV21,
    AliRtcVideoFormat_NV12,
};

/**
 视频数据类型
 
 - AliRtcBufferType_Raw_Data: YUV裸数据
 - AliRtcBufferType_CVPixelBuffer: CVPixelBuffer数据
 - AliRtcBufferType_Texture: 纹理数据
 */
typedef NS_ENUM(NSInteger, AliRtcBufferType) {
    AliRtcBufferType_Raw_Data = 0,
    AliRtcBufferType_CVPixelBuffer,
    AliRtcBufferType_Texture,
};

/**
 音效混响模式
 */
typedef NS_ENUM(NSInteger, AliRtcAudioEffectReverbMode) {
    AliRtcAudioEffectReverb_Off = 0,            // 关闭
    AliRtcAudioEffectReverb_Vocal_I ,           // 人声 I
    AliRtcAudioEffectReverb_Vocal_II,           // 人声 II
    AliRtcAudioEffectReverb_Bathroom,           // 澡堂
    AliRtcAudioEffectReverb_Small_Room_Bright,  // 明亮小房间
    AliRtcAudioEffectReverb_Small_Room_Dark,    // 黑暗小房间
    AliRtcAudioEffectReverb_Medium_Room,        // 中等房间
    AliRtcAudioEffectReverb_Large_Room,         // 大房间
    AliRtcAudioEffectReverb_Church_Hall,        // 教堂走廊
    AliRtcAudioEffectReverb_Cathedral,          // 大教堂
    AliRtcAudioEffectReverb_Mode_Max,           // 占位符，无含义
};

/**
 音效混响参数
 */
typedef NS_ENUM(NSInteger, AliRtcAudioEffectReverbParamType) {
    AliRtcAudioEffectReverb_Room_Size = 0, // 房间大小 [0, 100]
    AliRtcAudioEffectReverb_Pre_Delay,     // 预延时ms [0, 200]
    AliRtcAudioEffectReverb_Revetberance,  // 混响感[0,100]
    AliRtcAudioEffectReverb_Hf_Damping,    // 消声 [0,100]
    AliRtcAudioEffectReverb_Tone_Low,      // 低音调[0,100]
    AliRtcAudioEffectReverb_Tone_High,     // 高音调[0,100]
    AliRtcAudioEffectReverb_Dry_Gain,      // 干增益[-20,10]
    AliRtcAudioEffectReverb_Wet_Gain,      // 湿增益[-20,10]
    AliRtcAudioEffectReverb_Type_Max,      // 占位符，无含义
};

/**
 频道类型
 
 - AliRtcCommunication: 通信模式
 - AliRtcInteractivelive: 直播模式
 - AliRtcInteractiveWithLowLatencyLive: 低延时互动直播模式
 */
typedef NS_ENUM(NSInteger, AliRtcChannelProfile) {
    AliRtcCommunication = 0,
    AliRtcInteractivelive,
    AliRtcInteractiveWithLowLatencyLive,
};

/**
 角色类型
 
 - AliRtcClientRoleInteractive: 参与互动角色
 - AliRtcClientRolelive: 仅观看角色
 */
typedef NS_ENUM(NSInteger, AliRtcClientRole) {
    AliRtcClientRoleInteractive = 0,
    AliRtcClientRolelive,
};

/**
本地静音模式

- AliRtcMuteAudioModeDefault: 默认模式
- AliRtcMuteAllAudioMode: 静音全部(包括麦克风及外部输入音频)
- AliRtcMuteOnlyMicAudioMode: 只静音麦克风
*/
typedef NS_ENUM(NSInteger, AliRtcMuteLocalAudioMode) {
    AliRtcMuteAudioModeDefault = 0,
    AliRtcMuteAllAudioMode,
    AliRtcMuteOnlyMicAudioMode,
    AliRtcMuteLocalAudioMax,
};

/**
 错误码
 
 - AliRtcErrNone: 无
 **************************入会错误码****************************
 - AliRtcErrJoinBadAppId: AppId不存在
 - AliRtcErrJoinInvalidAppId: AppId已失效
 - AliRtcErrJoinBadChannel: 频道不存在
 - AliRtcErrJoinInvalidChannel: 频道已失效
 - AliRtcErrJoinBadToken: token不存在
 - AliRtcErrJoinTimeout: 加入频道超时
 - AliRtcErrJoinBadParam: 参数错误
 ************************音频设备错误码************************
 - AliRtcErrMicOpenFail: 采集设备初始化失败
 - AliRtcErrSpeakerOpenFail: 播放设备初始化失败
 - AliRtcErrMicInterrupt: 采集过程中出现异常
 - AliRtcErrSpeakerInterrupt: 播放过程中出现异常
 - AliRtcErrMicAuthFail: 麦克风设备未授权
 - AliRtcErrMicNotAvailable: 无可用的音频采集设备
 - AliRtcErrSpeakerNotAvailable: 无可用的音频播放设备
 ************************视频设备错误码*************************
 - AliRtcErrCameraOpenFail: 采集设备初始化失败
 - AliRtcErrCameraInterrupt: 采集过程中出现异常
 - AliRtcErrDisplayOpenFail: 渲染设备初始化失败
 - AliRtcErrDisplayInterrupt: 渲染过程中出现异常
 ***************************网络错误码***************************
 - AliRtcErrIceConnectionConnectFail: 媒体通道建立失败
 - AliRtcErrIceConnectionReconnectFail: 媒体通道重连失败
 - AliRtcErrIceConnectionHeartbeatTimeout: 信令心跳超时
 ********************低延时互动直播模式相关错误码********************
 - AliRtcErrCdnLiveCommunicationFailed: 低延时互动直播信令失败
 - AliRtcErrCdnLiveMeidaSettingFailed: 低延时互动直播媒体设置错误
 - AliRtcErrCdnLiveNoneBroadcaster: 低延时互动直播当前房间没有主播推流
 - AliRtcErrCdnLiveNeedRestart: 低延时互动直播错误，应用层需要重新创建新的SDK实例
 - AliRtcErrCdnLiveNeedRestartAgainLater: 低延时互动直播错误，应用层需要稍等一定时间（自定义间隔）重新创建新的SDK实例
 - AliRtcErrCdnLiveServiceUnavailable: 低延时互动直播服务不可用或者服务降级
 - AliRtcErrCdnLiveMediaConnectionInterruption: 低延时互动直播网络中断错误
 ***************************其他错误码***************************
 - AliRtcErrSdkInvalidState: sdk状态错误
 - AliRtcErrSessionRemoved: Session已经被移除
 - AliRtcErrAudioBufferFull: buffer队列饱和，用于外部输送裸数据功能
 - AliRtcErrInner: 其他错误
 */
typedef NS_ENUM(NSInteger, AliRtcErrorCode) {
    AliRtcErrNone                           = 0,
    AliRtcErrJoinBadAppId                   = 0x02010201,
    AliRtcErrJoinInvalidAppId               = 0x02010202,
    AliRtcErrJoinBadChannel                 = 0x02010204,
    AliRtcErrJoinInvalidChannel             = 0x02010203,
    AliRtcErrJoinBadToken                   = 0x02010205,
    AliRtcErrJoinTimeout                    = 0x01020204,
    AliRtcErrJoinBadParam                   = 0x01030101,
    AliRtcErrMicOpenFail                    = 0x01040404,
    AliRtcErrSpeakerOpenFail                = 0x01040405,
    AliRtcErrMicInterrupt                   = 0x01040406,
    AliRtcErrSpeakerInterrupt               = 0x01040407,
    AliRtcErrMicAuthFail                    = 0x01040408,
    AliRtcErrMicNotAvailable                = 0x01040409,
    AliRtcErrSpeakerNotAvailable            = 0x01040410,
    AliRtcErrCameraOpenFail                 = 0x01040104,
    AliRtcErrCameraInterrupt                = 0x01040106,
    AliRtcErrDisplayOpenFail                = 0x01040201,
    AliRtcErrDisplayInterrupt               = 0x01040202,
    AliRtcErrIceConnectionConnectFail       = 0x01050201,
    AliRtcErrIceConnectionReconnectFail     = 0x01050202,
    AliRtcErrIceConnectionHeartbeatTimeout  = 0x0102020C,
    AliRtcErrCdnLiveCommunicationFailed     = 0x01070003,
    AliRtcErrCdnLiveMeidaSettingFailed      = 0x01070004,
    AliRtcErrCdnLiveNoneBroadcaster         = 0x01070005,
    AliRtcErrCdnLiveNeedRestart             = 0x01070006,
    AliRtcErrCdnLiveNeedRestartAgainLater   = 0x01070007,
    AliRtcErrCdnLiveServiceUnavailable      = 0x01070008,
    AliRtcErrCdnLiveMediaConnectionInterruption = 0x01070009,
    AliRtcErrSdkInvalidState                = 0x01030204,
    AliRtcErrSessionRemoved                 = 0x02010105,
    AliRtcErrAudioBufferFull                = 0x01070101,
    AliRtcErrInner                          = -1,
};

/**
 OnBye类型
 
 - AliRtcOnByeBeKickedOut: 当前user被踢出channel
 - AliRtcOnByeChannelTerminated: channel已结束，需要离开会议
 - AliRtcOnByeUserReplaced: 相同userID在其他设备joinChannel，当前设备被下线
 */
typedef NS_ENUM(NSInteger, AliRtcOnByeType) {
    AliRtcOnByeBeKickedOut          = 1,
    AliRtcOnByeChannelTerminated    = 2,
    AliRtcOnByeUserReplaced         = 3,
};


/**
 录制类型

 - AliRtcRecordTypeAudio: 纯音频录制
 - AliRtcRecordTypeVideo: 纯视频录制
 - AliRtcRecordTypeBoth: 音视频录制
*/
typedef NS_ENUM(NSUInteger, AliRtcRecordType) {
    AliRtcRecordTypeAudio = 0,
    AliRtcRecordTypeVideo,
    AliRtcRecordTypeBoth,
};

/**
 录制格式

 - AliRtcRecordFormatAAC: AAC文件
 - AliRtcRecordFormatWAV: WAV文件
 - AliRtcRecordFormatMP4: MP4文件
*/
typedef NS_ENUM(NSUInteger, AliRtcRecordFormat) {
    AliRtcRecordFormatAAC = 0,
    AliRtcRecordFormatWAV,
    AliRtcRecordFormatMP4,
};

/**
 录制音频质量

 - AliRtcAudioQualityLow: 低
 - AliRtcAudioQualityMidium: 中
 - AliRtcAudioQualityHigh: 高
*/
typedef NS_ENUM(NSUInteger, AliRtcAudioQuality) {
    AliRtcAudioQualityLow = 0,
    AliRtcAudioQualityMidium,
    AliRtcAudioQualityHigh,
};

/**
 录制视频质量

 - AliRtcVideoQualityDefault: 默认，和采集保持一致
*/
typedef NS_ENUM(NSUInteger, AliRtcVideoQuality) {
    AliRtcVideoQualityDefault = 0,
};

/**
 录制音频采样率
*/
typedef NS_ENUM(NSInteger, AliRtcAudioSampleRate) {
    AliRtcAudioSampleRate_8000 = 0,
    AliRtcAudioSampleRate_11025 = 1,
    AliRtcAudioSampleRate_16000 = 2,
    AliRtcAudioSampleRate_22050 = 3,
    AliRtcAudioSampleRate_32000 = 4,
    AliRtcAudioSampleRate_44100 = 5,
    AliRtcAudioSampleRate_48000 = 6,
};

/**
 录制音频设置

 - sampleRate: 音频采样率
 - quality: 音频质量
 - enableRecordExternalCapturePCM: 是否允许录制外部pcm输入采集数据
 - enableRecordExternalRenderPCM: 是否允许录制外部pcm输入渲染数据
*/
typedef struct  {
    AliRtcAudioSampleRate sampleRate;
    AliRtcAudioQuality quality;
    bool enableRecordExternalCapturePCM;
    bool enableRecordExternalRenderPCM;
}AliRtcRecordAudioConfig;

/**
 录制视频设置

 - quality: 视频质量
*/
typedef struct  {
    AliRtcVideoQuality quality; //视频质量
}AliRtcRecordVideoConfig;

/**
 实时数据
 */
typedef struct {
    int64_t sent_kbitrate;      // 总发送码率(kb)
    int64_t rcvd_kbitrate;      // 总接收码率(kb)
    int64_t sent_bytes;         // 总发送数据量(bytes)
    int64_t rcvd_bytes;         // 总接收数据量(bytes)
    int64_t video_rcvd_kbitrate;// 视频发送码率(kb)
    int64_t video_sent_kbitrate;// 视频接收码率(kb)
    uint64_t call_duration;     // 通话时长(s)
    float cpu_usage;            // CPU使用量(%)
} AliRtcStats;


/**
 本地视频统计信息
 */
@interface AliRtcLocalVideoStats : NSObject

@property (nonatomic, assign) AliRtcVideoTrack track; // 视频流track类型
@property (nonatomic, assign) uint32_t sent_bitrate;  // 发送码率
@property (nonatomic, assign) uint32_t sent_fps;      // 发送帧率
@property (nonatomic, assign) uint32_t encode_fps;    // 编码帧率

@end

/**
 远端视频统计信息
 */
@interface AliRtcRemoteVideoStats : NSObject

@property (nonatomic, copy) NSString *userId;           // 远端用户userID
@property (nonatomic, assign) AliRtcVideoTrack track;   // 视频流track类型
@property (nonatomic, assign) uint32_t width;           // width
@property (nonatomic, assign) uint32_t height;          // height
@property (nonatomic, assign) uint32_t decode_fps;      // 解码帧率
@property (nonatomic, assign) uint32_t render_fps;      // 渲染帧率
@property (nonatomic, assign) uint32_t frozen_times;    // 卡顿次数

@end

/**
 设备信息
 */
@interface AliRtcDeviceInfo : NSObject

@property (nonatomic, copy) NSString *deviceName;   // 设备名称
@property (nonatomic, copy) NSString *deviceID;     // 设备ID

@end


/**
 入会参数
 */
@interface AliRtcAuthInfo : NSObject

@property (nonatomic, retain) NSString *channel;
@property (nonatomic, retain) NSString *user_id;
@property (nonatomic, retain) NSString *appid;
@property (nonatomic, retain) NSString *nonce;
@property (nonatomic, retain) NSString *token;
@property (nonatomic, retain) NSArray <NSString *> *gslb;
@property (nonatomic, retain) NSArray <NSString *> *agent;
@property (nonatomic, assign) long long timestamp;

@end

/**
 渲染view基类
 */
@interface AliRTCRenderView : NSOpenGLView

@end

/**
 渲染view
 */
@interface AliRenderView : AliRTCRenderView

@end


@interface AliVideoCanvas : NSObject

@property (nonatomic, strong) AliRenderView *view;          // 渲染view，不可为nil
@property (nonatomic) AliRtcRenderMode renderMode;          // 渲染模式，默认AliRtcRenderModeAuto
@property (nonatomic) AliRtcRenderMirrorMode mirrorMode;    // 镜像模式，播放默认关闭镜像

@end


/**
 视频裸数据
 */
@interface AliRtcVideoDataSample : NSObject

@property (nonatomic, assign) AliRtcVideoFormat format;
@property (nonatomic, assign) AliRtcBufferType type;
@property (nonatomic, assign) long dataPtr;
@property (nonatomic, assign) long dataLength;
@property (nonatomic, assign) int strideY;
@property (nonatomic, assign) int strideU;
@property (nonatomic, assign) int strideV;
@property (nonatomic, assign) int height;
@property (nonatomic, assign) int width;
@property (nonatomic, assign) int rotation;
@property (nonatomic, assign) long long timeStamp;

@end

/**
 音频裸数据
 */
@interface AliRtcAudioDataSample : NSObject

@property (nonatomic, assign) long dataPtr;
@property (nonatomic, assign) int numOfSamples;
@property (nonatomic, assign) int bytesPerSample;
@property (nonatomic, assign) int numOfChannels;
@property (nonatomic, assign) int samplesPerSec;

@end


#pragma mark - 回调


@protocol AliRtcEngineDelegate <NSObject>
@optional

/**
 * @brief 加入频道结果
 * @param result 加入频道结果，成功返回0，失败返回错误码
 * @note 此回调等同于joinChannel接口的block，二者择一处理即可
 */
- (void)onJoinChannelResult:(int)result;

/**
 * @brief 离开频道结果
 * @param result 离开频道结果，成功返回0，失败返回错误码
 * @note 调用leaveChannel接口后返回，如果leaveChannel后直接调用destroy，将不会收到此回调
 */
- (void)onLeaveChannelResult:(int)result;

/**
 * 发布流状态变化
 * @param result 当前推拉流结果
 * @param isPublished 是否处于推流状态 YES:推流 NO:停止推流
 * @note 此回调等同于publish接口的block，二者择一处理即可
 * @note 自动推流模式下建议使用此回调做推流状态的监听处理
 */
- (void)onPublishResult:(int)result isPublished:(BOOL)isPublished;

/**
 * @brief 当远端用户上线时会返回这个消息
 * @param uid userId 从App server分配的唯一标示符
 * @note This message does not mean the user remains online state
 */
- (void)onRemoteUserOnLineNotify:(NSString *)uid;

/**
 * @brief 当远端用户下线时会返回这个消息
 * @param uid userId 从App server分配的唯一标示符
 * @note This message does not mean the user remains offline state
 */
- (void)onRemoteUserOffLineNotify:(NSString *)uid;

/**
 * @brief 当远端用户的流发生变化时，返回这个消息
 * @note 远方用户停止推流，也会发送这个消息
 */
- (void)onRemoteTrackAvailableNotify:(NSString *)uid audioTrack:(AliRtcAudioTrack)audioTrack videoTrack:(AliRtcVideoTrack)videoTrack;

/**
 * @brief 当订阅情况发生变化时，返回这个消息
 */
- (void)onSubscribeChangedNotify:(NSString *)uid audioTrack:(AliRtcAudioTrack)audioTrack videoTrack:(AliRtcVideoTrack)videoTrack;

/**
 * @brief 当用户角色发生变化化时通知
 * @param oldRole 变化前角色类型
 * @param newRole 变化后角色类型
 * @note 调用setClientRole方法切换角色成功时触发此回调
 */
- (void)onUpdateRoleNotifyWithOldRole:(AliRtcClientRole)oldRole newRole:(AliRtcClientRole)newRole;

/**
 * @brief 网络质量变化时发出的消息
 * @param uid 网络质量发生变化的uid
 * @param upQuality  上行网络质量
 * @param downQuality  下行网络质量
 * @note 当网络质量发生变化时触发，uid为@""时代表self的网络质量变化
 */
- (void)onNetworkQualityChanged:(NSString *)uid
               upNetworkQuality:(AliRtcNetworkQuality)upQuality
             downNetworkQuality:(AliRtcNetworkQuality)downQuality;

/**
 * @brief 网络连接断开
 */
- (void)onConnectionLost;

/**
 * @brief 网络连接正在尝试重连中
 */
- (void)onTryToReconnect;

/**
 * @brief 网络连接重连成功
 */
- (void)onConnectionRecovery;

/**
 * @brief 被服务器踢出频道的消息
 */
- (void)onBye:(int)code;

/**
 * @brief 如果engine出现warning，通过这个回调通知app
 * @param warn  Warning type
 */
- (void)onOccurWarning:(int)warn;

/**
 * @brief 如果engine出现error，通过这个回调通知app
 * @param error  Error type
 */
- (void)onOccurError:(int)error;

/**
 * @brief 当前设备性能不足
 */
- (void)onPerformanceLow;

/**
 * @brief 当前设备性能恢复
 */
- (void)onPerformanceRecovery;

/**
 * @brief 首帧数据发送成功
 * @param audioTrack  发送成功的音频流类型
 * @param videoTrack  发送成功的视频流类型
 */
- (void)onFirstPacketSentWithAudioTrack:(AliRtcAudioTrack)audioTrack videoTrack:(AliRtcVideoTrack)videoTrack;

/**
 * @brief 首包数据接收成功
 * @param audioTrack  接收成功的音频流类型
 * @param videoTrack  接收成功的视频流类型
 */
- (void)onFirstPacketReceivedWithAudioTrack:(AliRtcAudioTrack)audioTrack videoTrack:(AliRtcVideoTrack)videoTrack;

/**
 * @brief remote user的第一帧视频帧显示时触发这个消息
 * @param uid   User ID。从App server分配的唯一标示符
 * @param videoTrack 屏幕流或者相机流
 */
- (void)onFirstRemoteVideoFrameDrawn:(NSString *)uid videoTrack:(AliRtcVideoTrack)videoTrack;

/**
 * @brief 订阅的音频音量回调，其中callid为"0"表示本地推流音量，"1"表示远端混音音量，其他表示远端用户音量
 * @param audioSource 音频数据类型
 * @param volume 当前回调的音量
 * @param uid 当前用户的uid，"0"表示本地，"1"表示远端混音，其他表示远端用户
 */
- (void)onAudioVolumeCallback:(AliRtcAudioSource)audioSource audioVolume:(NSInteger)volume audioUserid:(NSString *)uid audioState:(NSInteger)audiostate;

/**
 * @brief 订阅的音频数据回调
 * @param audioSource audio source
 * @param audioSample audio sample
 */
- (void)onAudioSampleCallback:(AliRtcAudioSource)audioSource audioSample:(AliRtcAudioDataSample *)audioSample;

/**
 * @brief 音频采集设备测试回调
 * @param level 音频采集设备音量值
 */
- (void)onAudioDeviceRecordLevel:(int)level;

/**
 * @brief 音频播放设备测试回调
 * @param level 音频采集设备音量值
 */
- (void)onAudioDevicePlayoutLevel:(int) level;

/**
 * @brief 音频播放设备测试结束(音频文件播放完毕)
 */
- (void)onAudioDevicePlayoutEnd;

/*
 * @brief 网络质量探测回调
 * @param networkQuality 网络质量
 */
- (void)onLastmileDetectResultWithQuality:(AliRtcNetworkQuality)networkQuality;

/**
 * @brief 订阅的视频数据回调
 * @param uid user id
 * @param videoSource video source
 * @param videoSample video sample
 */
- (void)onVideoSampleCallback:(NSString *)uid videoSource:(AliRtcVideoSource)videoSource videoSample:(AliRtcVideoDataSample *)videoSample;

/**
 * @brief 订阅的本地采集视频数据回调
 * @param videoSource video source
 * @param videoSample video sample
 */
- (void)onCaptureVideoSample:(AliRtcVideoSource)videoSource videoSample:(AliRtcVideoDataSample *)videoSample;

/**
 * @brief 订阅的远端视频数据回调
 * @param uid user id
 * @param videoSource video source
 * @param videoSample video sample
 */
- (void)onRemoteVideoSample:(NSString *)uid videoSource:(AliRtcVideoSource)videoSource videoSample:(AliRtcVideoDataSample *)videoSample;
/**
 * @brief 文件录制回调事件
 * @param event 录制事件
 * @param filePath 录制文件路径
*/
- (void)onMediaRecordEvent:(int)event filePath:(NSString *)filePath;

/**
 * @brief 实时数据回调(2s触发一次)
 * @param stats stats
 */
- (void)onRtcStats:(AliRtcStats)stats;

/**
 * @brief 本地视频统计信息(2s触发一次)
 * @param localVideoStats 本地视频统计信息
 * @note SDK每两秒触发一次此统计信息回调
 */
- (void)onRtcLocalVideoStats:(AliRtcLocalVideoStats *)localVideoStats;

/**
 * @brief 远端视频统计信息(2s触发一次)
 * @param remoteVideoStats 远端视频统计信息
 */
- (void)onRtcRemoteVideoStats:(AliRtcRemoteVideoStats *)remoteVideoStats;

@end


#pragma mark - 接口主类

@interface AliRtcEngine : NSObject <AliRtcEngineDelegate>

- (instancetype)init __attribute__((unavailable("use sharedInstance to create the singletone")));

#pragma mark - "Engine的生命周期，工作参数以及频道操作"

/**
 * @brief 初始化
 * @param delegate delegate
 * @param extras extras [可以为空 @""]
 * @return self
 */
+ (instancetype)sharedInstance:(id<AliRtcEngineDelegate>)delegate extras:(NSString *)extras;

/**
 * @brief 销毁
 */
+ (void)destroy;

/**
 * @brief 获取sdk版本号
 * @return SDK版本号
 * @note 在任何时刻都可以调用
 */
+ (NSString *)getSdkVersion;

/**
 * @brief 设置SDK日志文件保存路径
 * @param logDirPath 日志文件保存绝对路径
 * @return 0为成功，非0失败
 * @note 如需调用此接口，请在调用所有SDK接口前先进行设置，避免日志出现丢失，同时App必须保证指定的目录已存在且可写入
*/
+ (int)setLogDirPath:(NSString *)logDirPath;

/**
 * @brief 上报日志
 */
+ (void)uploadLog;

/**
 * @brief 设置是否自动publish音视频流和subscribe音视频流
 * @param autoPub    YES表示自动推流；NO表示不自动推流
 * @param autoSub    YES表示自动拉流；NO表示不自动拉流
 * @return 0表示Success 非0表示Failure
 * @note 缺省是自动推流和拉流。只可以在joinChannel之前设置
 */
- (int)setAutoPublish:(BOOL)autoPub withAutoSubscribe:(BOOL)autoSub;

/**
 * @brief 设置音频模式还是音视频模式
 * @param audioOnly  YES表示只有音频推流和拉流；NO表示音视频都支持
 * @return 0表示Success 非0表示Failure
 * @note 只可以在joinChannel之前设置
 */
- (int)setAudioOnlyMode:(BOOL)audioOnly;

/**
 * @brief 加入频道
 * @param authInfo    认证信息，从App Server获取。
 * @param userName    任意用于显示的用户名称。不是User ID
 * @param onResult    当joinChannel执行结束后调用这个回调
 * @note 异步接口 是否成功入会，通过onResult判断
 */
- (void)joinChannel:(AliRtcAuthInfo *)authInfo name:(NSString *)userName onResult:(void(^)(NSInteger errCode))onResult;

/**
 * @brief 离开频道
 * @note 如果当前不在频道内，leaveChannel不会有任何影响。leaveChannel会产生消息通知频道内其他用户
 */
- (void)leaveChannel;

/**
* @brief 设置频道模式
* @param profile 频道模式类型
* @return 0为成功，非0失败
* @note 只可以在入会之前调用，会议中不可以重新设置，LeaveChannel后可以重新设置
*/
- (int)setChannelProfile:(AliRtcChannelProfile)profile;

/**
 * @brief 设置用户角色
 * @param role 用户角色类型
 * @return 0为成功，非0失败
 * @note 只可以在频道模式为InteractiveLive下调用，入会前/会议中均可设置，设置成功会收到onUpdateRoleNotify
 * @note 从Interactive转换为Live角色需要先停止推流，否则返回失败
 */
- (int)setClientRole:(AliRtcClientRole)role;


#pragma mark - "设置和操作本地的媒体"

/**
 * @brief 为本地预览设置窗口以及绘制参数
 * @param viewConfig 包含了窗口以及渲染方式
 * @param track      must be AliVideoTrackCamera
 * @return 0表示Success 非0表示Failure
 * @note 支持joinChannel之前和之后切换窗口。如果viewConfig或者viewConfig中的view为nil，则停止渲染
 *       如果在预览过程中需要重新设置render mode，请保持canvas中其他成员变量不变，仅修改
 *       renderMode
 *       如果在预览过程中需要重新设置mirror mode，请保持canvas中其他成员变量不变，仅修改
 *       mirrorMode，预览mirror默认打开镜像
 */
- (int)setLocalViewConfig:(AliVideoCanvas *)viewConfig forTrack:(AliRtcVideoTrack)track;

/**
 * @brief 开始本地预览
 * @return 0表示Success 非0表示Failure
 * @note 如果没有设置view，则无法预览。可以在joinChannel之前就开启预览
 *       会自动打开摄像头
 */
- (int)startPreview;

/**
 * @brief 停止本地预览
 * @return 0表示Success 非0表示Failure
 * @note leaveChannel会自动停止本地预览
 *       会自动关闭摄像头 (如果正在publish camera流，则不会关闭摄像头)
 */
- (int)stopPreview;

/**
 * @brief 是否将停止本地视频采集
 * @param mute     YES表示停止视频采集；NO表示恢复正常
 * @param track    需要停止采集的track
 * @return 0表示Success 非0表示Failure
 * @note 发送黑色的视频帧。本地预览也呈现黑色。采集，编码，发送模块仍然工作，
 *       只是视频内容是黑色帧
 */
- (int)muteLocalCamera:(BOOL)mute forTrack:(AliRtcVideoTrack)track;

/**
 * @brief 手动推送视频和音频流
 * @param onResult    当publish执行结束后调用这个回调
 * @note 需要推送的流通过API xxxx设置好
 *       如果需要手工配置所有推流和拉流，请关闭autoPub (见- (int)setAutoPublish:(BOOL)autoPub withAutoSubscribe:(BOOL)autoSub)
 *       这个是异步接口。结果通过result返回。返回可能在caller线程，也可能在其他线程调用
 *       如果想停止推送所有流，通过publish实现
 */
- (void)publish:(void (^)(int errCode))onResult;

/**
 * @brief 设置视频track的profile
 * @param profile     预定义的视频profile
 * @param track       需要设置的track
 * @note 可以在join channel之前或者之后设置
 */
- (void)setVideoProfile:(AliRtcVideoProfile)profile forTrack:(AliRtcVideoTrack)track;

/**
 * @brief mute/unmute本地音频采集
 * @param mute  YES表示本地音频采集空帧；NO表示恢复正常
 * @param mode  静音模式
 * @note mute是指采集和发送静音帧。采集和编码模块仍然在工作
 * @return 0表示成功放入队列，-1表示被拒绝
 */
- (int)muteLocalMic:(BOOL)mute mode:(AliRtcMuteLocalAudioMode)mode;


#pragma mark - "操作来自远端的媒体"

/**
 * @brief 为远端的视频设置窗口以及绘制参数
 * @param canvas canvas包含了窗口以及渲染方式
 * @param uid userId 从App server分配的唯一标示符
 * @param track  需要设置的track
 * @return 0表示Success 非0表示Failure
 * @note 支持joinChannel之前和之后切换窗口。如果canvas为nil或者view为nil，则停止渲染相应的流
 *       如果在播放过程中需要重新设置render mode，请保持canvas中其他成员变量不变，仅修改
 *       renderMode
 *       如果在播放过程中需要重新设置mirror mode，请保持canvas中其他成员变量不变，仅修改
 *       mirrorMode，播放mirror默认不镜像
 */
- (int)setRemoteViewConfig:(AliVideoCanvas *)canvas uid:(NSString *)uid forTrack:(AliRtcVideoTrack)track;

/**
 * @brief mute/unmute远端的音频track的播放
 * @param uid userId 从App server分配的唯一标示符
 * @param mute    YES表示停止播放；NO表示恢复播放
 * @return 0表示Success 非0表示Failure
 * @note 拉流和解码不受影响。支持joinChannel之前和之后设置
 */
- (int)muteRemoteAudioPlaying:(NSString *)uid mute:(BOOL)mute;

/**
 * @brief mute/unmute远端的所有音频track的播放
 * @param mute    YES表示停止播放；NO表示恢复播放
 * @return 0表示Success 非0表示Failure
 * @note 拉流和解码不受影响。支持joinChannel之前和之后设置
 */
- (int)muteAllRemoteAudioPlaying:(BOOL)mute;

/**
 * @brief 手动拉视频和音频流
 * @param uid useId 不允许为nil
 * @param onResult   当subscribe执行结束后调用这个回调
 * @note 如果需要手动选择拉取的流，调用configRemoteAudio, configRemoteCameraTrack,
 *       configRemoteScreenTrack来设置。缺省是拉取audio和camera track
 *       如果需要unsub所有的流，先通过configRemoteAudio, configRemoteCameraTrack,
 *       configRemoteScreenTrack来清除设置，然后调用subscribe
 */
- (void)subscribe:(NSString *)uid onResult:(void (^)(NSString *uid, AliRtcVideoTrack vt, AliRtcAudioTrack at))onResult;


#pragma mark - "用户管理"

/**
 * @brief 设置是否允许推送camera track
 * @param enable   是否允许
 * @note 需要调用publish才能生效
 *       缺省允许camera track推流
 */
- (void)configLocalCameraPublish:(BOOL)enable;

/**
 * @brief 查询是否允许推送camera track
 * @return YES: 允许；NO: 禁止
 */
- (BOOL)isLocalCameraPublishEnabled;

/**
 * @brief 设置是否允许推送screen track
 * @param enable   是否允许
 * @note 需要调用publish才能生效
 *       缺省不允许screen track推流
 */
- (void)configLocalScreenPublish:(BOOL)enable;

/**
 * @brief 查询是否允许推送screen track
 * @return YES: 允许；NO: 禁止
 */
- (BOOL)isLocalScreenPublishEnabled;

/**
 * @brief 设置是否允许推送audio
 * @param enable   是否允许
 * @note 需要调用publish才能生效
 *       缺省允许音频推流
 */
- (void)configLocalAudioPublish:(BOOL)enable;

/**
 * @brief 查询是否允许推送audio track
 * @return YES: 允许；NO: 禁止
 */
- (BOOL)isLocalAudioPublishEnabled;

/**
 * @brief 是否允许推送次要视频流
 * @param enabled    YES表示需要推送次流；NO表示不推送次流
 * @param track      must be AliVideoTrackCamera
 * @return 0表示Success 非0表示Failure
 * @note 需要调用publish才能生效
 *。     缺省enable。目前只支持camera track，不支持screen track
 */
- (int)configLocalSimulcast:(BOOL)enabled forTrack:(AliRtcVideoTrack)track;

/**
 * @brief 查询是否允许推送simulcast (camera track)
 * @return YES: 允许；NO: 禁止
 */
- (BOOL)isLocalSimulcastEnabled;

/**
 * @brief 设置是否拉取音频流
 * @param uid userId 从App server分配的唯一标示符
 * @param enable  YES: 拉取; NO: 不拉取
 * @note 可以在joinChannel之前或者之后设置。如果已经订阅该用户的流，需要调用startSubscribe:uid才生效
 */
- (void)configRemoteAudio:(NSString *)uid enable:(BOOL)enable;

/**
 * @brief 设置是否拉取camera视频流
 * @param uid userId 从App server分配的唯一标示符
 * @param master  是否优先拉取大流
 * @param enable  YES: 拉取; NO: 不拉取
 * @note 可以在joinChannel之前或者之后设置。如果已经订阅该用户的流，需要调用startSubscribe:uid才生效
 */
- (void)configRemoteCameraTrack:(NSString *)uid preferMaster:(BOOL)master enable:(BOOL)enable;

/**
 * @brief 设置是否拉取screen视频流
 * @param uid userId 从App server分配的唯一标示符
 * @param enable  YES: 拉取; NO: 不拉取
 * @note 可以在joinChannel之前或者之后设置。如果已经订阅该用户的流，需要调用startSubscribe:uid才生效
 */
- (void)configRemoteScreenTrack:(NSString *)uid enable:(BOOL)enable;

/**
 * @brief 获取远端在线用户列表
 * @return 用户列表，保存的是用户ID
 */
- (NSArray<NSString *> *)getOnlineRemoteUsers;

/**
 * @brief 判断用户是否在线
 * @param uid  userId 从App server分配的唯一标示符。不可为nil
 * @return YES表示在线，NO表示不在线
 */
- (BOOL)isUserOnline:(NSString *)uid;


#pragma mark - "设备管理"

/**
 * @brief 获取系统中的录音设备列表
 */
- (NSArray<AliRtcDeviceInfo *> *)getAudioCaptures;

/**
 * @brief 获取使用的录音设备名称
 */
- (NSString *)getCurrentAudioCapture;

/**
 * @brief 获取使用的录音设备ID
 */
- (NSString *)getCurrentAudioCaptureID;

/**
 * @brief 选择录音设备(Name)
 */
- (void)setCurrentAudioCapture:(NSString *)capture;

/**
 * @brief 选择录音设备(ID)
 */
- (void)setCurrentAudioCaptureWithID:(NSString *)captureID;

/**
 * 获取系统中的扬声器列表
 */
- (NSArray<AliRtcDeviceInfo *> *)getAudioRenderers;

/**
 * 获取当前使用的扬声器名称
 */
- (NSString *)getCurrentAudioRenderer;

/**
 * 获取当前使用的扬声器ID
 */
- (NSString *)getCurrentAudioRendererID;

/**
 * 选择扬声器(Name)
 */
- (void)setCurrentAudioRenderer:(NSString *)renderer;

/**
 * 选择扬声器(ID)
 */
- (void)setCurrentAudioRendererWithID:(NSString *)rendererID;

/**
 * @brief 获取摄像头列表
 * @return 找到的系统中摄像头名称列表
 */
- (NSArray<AliRtcDeviceInfo *> *)getCameraList;

/**
 * @brief 获取当前使用的摄像头名称
 */
- (NSString *)getCurrentCamera;

/**
 * @brief 获取当前使用的摄像头ID
 */
- (NSString *)getCurrentCameraID;

/**
 * @breif 选择摄像头(Name)
 * @param camera   摄像头名称
 */
- (void)setCurrentCamera:(NSString *)camera;

/**
 * @breif 选择摄像头(ID)
 * @param cameraID   摄像头ID
 */
- (void)setCurrentCameraWithID:(NSString *)cameraID;

/**
 * @brief 开启音频采集
 * @note 此接口可以控制提前打开音频采集，如果不设置，则SDK会在合适的时机在打开音频采集
 */
- (void)startAudioCapture;

/**
 * @brief 关闭音频采集
 * @note 此接口可以控制关闭音频采集，与startAudioCapture对应
 */
- (void)stopAudioCapture;

/**
 * @brief 开启音频播放
 * @note 此接口可以控制提前打开音频播放，如果不设置，则SDK会在合适的时机在打开音频播放
 */
- (void)startAudioPlayer;

/**
 * @brief 关闭音频播放
 * @note 此接口可以控制关闭音频播放，与stopAudioPlayer对应
 */
- (void)stopAudioPlayer;

/**
 * @brief 开启智能降噪
 * @note 此接口可以通话过程中控制打开智能降噪功能
 */
- (void)startIntelligentDenoise;

/**
 * @brief 关闭智能降噪
 * @note 此接口可以通话过程中控制关闭智能降噪功能
 */
- (void)stopIntelligentDenoise;


#pragma mark - "其他"

/**
 * @brief 设置log
 * @param logLevel  Log级别
 */
- (void)setLogLevel:(AliRtcLogLevel)logLevel;

/**
 * @brief 设置录音音量
 * @param volume [0 400],0:静音，>100:放大音量，<100:减小音量
 * @return 0表示Success 非0表示Failure
 */
- (int)setRecordingVolume:(NSInteger)volume;

/**
 * @brief 设置播放音量
 * @param volume [0 400],0:静音，>100:放大音量，<100:减小音量
 * @return 0表示Success 非0表示Failure
 */
- (int)setPlayoutVolume:(NSInteger)volume;

/**
 * @brief 设置混响音效模式
 * @param mode 模式值 参看对应枚举类型
 * @return 0表示Success 非0表示Failure
 */
- (int)setAudioEffectReverbMode:(AliRtcAudioEffectReverbMode)mode;

/**
 * @brief 设置混响音效类型
 * @param type 模式值，参看对应枚举类型
 * @return 0表示Success 非0表示Failure
 */
- (int)setAudioEffectReverbParamType:(AliRtcAudioEffectReverbParamType)type value:(float)value;

/**
 * @brief 检查camera是否打开
 * @return YES表示摄像头已打开；NO表示摄像头没有打开
 */
- (BOOL)isCameraOn;

/**
 * @brief 检查当前是否在频道中
 * @return YES表示加入了频道；NO表示不在频道中
 */
- (BOOL)isInCall;

/**
 * @brief 查询是否自动publish
 * @return YES表示自动Publish  NO表示非自动
 */
- (BOOL)isAutoPublish;

/**
 * @brief 查询是否自动subscribe
 * @return YES表示自动Subscribe  NO表示非自动
 */
- (BOOL)isAutoSubscribe;

/**
 * @brief 查询是否audio only
 * @return YES表示audio Only  NO表示非audio Only
 */
- (BOOL)isAudioOnly;

/**
 * @brief 查询远端用户的各种状态
 * @param uid        User ID。从App server分配的唯一标示符
 * @note Key: userID, isOnline, sessionID, callID, displayName
 *            hasAudio, hasCameraMaster, hasCameraSlave, hasScreenSharing
 *            requestAudio, requestCameraMaster, requestCameraSlave, requestScreenSharing, preferCameraMaster
 *            subScribedAudio, subScribedCameraMaster, subScribedCamearSlave, subScribedScreenSharing
 *            hasCameraView, hasScreenView
 *            muteAudioPlaying
 */
- (NSDictionary *)getUserInfo:(NSString *)uid;

/**
 * @brief 设置H5兼容模式
 * @param comp    YES: 兼容H5; NO: 传统模式，不兼容H5
 * @note 只支持在sdk实例创建之前设置。如果在sdk创建之后改这个设置会引起互通问题。缺省不兼容H5
 */
+ (void)setH5CompatibleMode:(BOOL)comp;

/**
 * @brief 检查当前是否兼容H5
 * @return YES: 兼容H5; NO: 不兼容H5
 */
+ (BOOL)getH5CompatibleMode;


#pragma mark - "设备检测"

/**
 * @brief 开始测试音频采集设备
 * @param deviceName 音频采集设备Name
 * @return 0表示Success 非0表示Failure
 * @note 请在joinChannel之前调用
 */
- (int)startTestAudioRecordWithName:(NSString *)deviceName;

/**
 * @brief 停止测试音频采集设备
 * @return 0表示Success 非0表示Failure
 * @note 请在joinChannel之前调用
 */
- (int)stopTestAudioRecord;

/**
 * @brief 开始测试音频播放设备
 * @param deviceName 音频播放设备Name
 * @param filePath 音频文件路径
 * @param loopCycles 重复播放次数， -1为循环播放
 * @return 0表示Success 非0表示Failure
 * @note 请在joinChannel之前调用
 */
- (int)startTestAudioPlayoutWithName:(NSString *)deviceName filePath:(NSString *)filePath loopCycles:(NSInteger)loopCycles;

/**
 * @brief 停止测试音频播放设备
 * @return 0表示Success 非0表示Failure
 * @note 请在joinChannel之前调用
 */
- (int)stopTestAudioPlayout;


#pragma mark - "网络测试"

/**
 * @brief 开始网络质量探测
 * @return 0表示Success 非0表示Failure
 * @note 请在joinChannel之前调用，探测结果在onLastmileDetect回调
 */
- (int)startLastmileDetect;

/**
 * @brief 停止网络质量探测
 * @return 0表示Success 非0表示Failure
 */
- (int)stopLastmileDetect;


#pragma mark - "音视频裸数据输入输出"

/**
 * @brief 订阅音频数据
 * @param audioSource audio source
 */
- (void)subscribeAudioData:(AliRtcAudioSource)audioSource;

/**
 * @brief 取消订阅音频数据
 * @param audioSource audio source
 */
- (void)unSubscribeAudioData:(AliRtcAudioSource)audioSource;

/**
 * 设置音量回调频率和平滑系数
 *
 * @param interval 时间间隔，单位毫秒，最小值不得小于10ms
 * @param smooth 平滑系数，数值越大平滑程度越高，反之越低，实时性越好，建议设置3，范围[0, 9];
 * @param reportVad 本地语音检测开关，1：开启，通过onAudioVolumeCallback接口回调, 0:关闭
 * @return 0 表示成功，-1 表示interval设置小于10，-2 表示平滑系数超出范围.
 */
- (int)setVolumeCallbackIntervalMs:(NSInteger)interval smooth:(NSInteger)smooth reportVad:(NSInteger)reportVad;

/**
 * @brief 设置回调音频声道数，默认单声道
 * @param audioNumChannel audio num channel
 */
- (void)setSubscribeAudioNumChannel:(AliRtcAudioNumChannel)audioNumChannel;

/**
 * @brief 设置回调音频采样率，默认44100
 * @param audioSampleRate audio samplerate
 */
- (void)setSubscribeAudioSampleRate:(AliRtcAudioSampleRate)audioSampleRate;

/**
 * @brief 订阅视频数据
 */
- (void)registerVideoSampleObserver;

/**
 * @brief 取消订阅视频数据
 */
- (void)unregisterVideoSampleObserver;

/**
 * @brief 启用外部视频输入源
 * @param enable YES 开启，NO 关闭
 * @param useTexture 是否使用texture 模式
 * @param type 流类型
 */
- (int)setExternalVideoSource:(BOOL)enable useTexture:(BOOL)useTexture sourceType:(AliRtcVideoSource)type;

/**
 * @brief 输入视频数据
 * @param frame 帧数据
 * @param type 流类型
 */
- (int)pushExternalVideoFrame:(AliRtcVideoDataSample *)frame sourceType:(AliRtcVideoSource)type;

/**
* @brief 设置是否启用外部音频输入源
* @param enable YES 开启，NO 关闭
* @param sampleRate 采样率 16000 48000...
* @param channelsPerFrame 声道数 1 or 2
* @return return>=0 Success, return<0 Failure
*/
- (int)setExternalAudioSource:(BOOL)enable withSampleRate:(NSUInteger)sampleRate channelsPerFrame:(NSUInteger)channelsPerFrame;

/**
* @brief 输入音频数据
* @param data 音频数据 不建议超过40ms数据
* @param samples 采样
* @param timestamp 时间戳
* @return return>=0 Success, return<0 Failure
*/
- (int)pushExternalAudioFrameRawData:(void *_Nonnull)data samples:(NSUInteger)samples timestamp:(NSTimeInterval)timestamp;

/**
* @brief 设置混音音量
* @param vol 音量 0-100
*/
- (int)setExternalAudioVolume:(int)vol;

/**
* @brief 获取混音音量
* @return vol 音量
*/
- (int)getExternalAudioVolume;

/**
* @brief 设置是否与麦克风采集音频混合
* @param mixed YES 混音，NO 完全替换麦克风采集数据
*/
- (int)setMixedWithMic:(BOOL)mixed;


/**
 * @brief 设置是否启用外部输入音频播放
 * @param enable YES 开启，NO 关闭
 * @param sampleRate 采样率 16000 48000...
 * @param channelsPerFrame 声道数 1 or 2
 * @return return>=0 Success, return<0 Failure
 */
- (int)setExteranlAudioRender:(BOOL)enable sampleRate:(NSUInteger)sampleRate channelsPerFrame:(NSUInteger)channelsPerFrame;

/**
 * @brief 输入音频播放数据
 * @param audioSamples 音频数据
 * @param sampleLength 音频数据长度
 * @param sampleRate 音频采样率
 * @param channelsPerFrame 音频声道数
 * @param timestamp 时间戳
 * @return return>=0 Success, return<0 Failure
 * @note 如果返回值为errorCode中的AliRtcErrAudioBufferFull，代表当前buffer队列塞满，需要等待后再继续输送数据，建议等待20ms
 */
- (int)pushExternalAudioRenderRawData:(const void* _Nullable)audioSamples sampleLength:(NSUInteger)sampleLength sampleRate:(NSUInteger)sampleRate channelsPerFrame:(NSUInteger)channelsPerFrame timestamp:(long long)timestamp;


#pragma mark - "文件录制"

/**
 开始录制

 @param recordType 录制类型
 @param recordFormat 录制文件格式
 @param filePath 文件路径
 @param audioConfig 音频设置
 @param videoConfig 视频设置
 @return 成功/失败
 */
- (BOOL)startRecord:(AliRtcRecordType)recordType recordFormat:(AliRtcRecordFormat)recordFormat filePath:(NSString*)filePath audioConfig:(AliRtcRecordAudioConfig*)audioConfig videoConfig:(AliRtcRecordVideoConfig*)videoConfig;


/**
 停止录制

 */
- (void)stopRecord;


#pragma mark - "低延时互动直播模式"

/**
 * 开始低延时互动直播拉流
 * @param authInfo 入会鉴权信息
 * @param onResult 拉流结果 errCode=0为Success，其他为Failure
 */
- (void)startLiveStreamingWithAuthInfo:(AliRtcAuthInfo *)authInfo onResult:(void(^)(int errCode))onResult;

/**
 * 停止低延时互动直播拉流
 */
- (int)stopLiveStreaming;

/**
 * 设置低延时互动直播渲染Canvas
 * @param canvas 渲染参数
 */
- (int)setLiveStreamingViewConfig:(AliVideoCanvas *)canvas;

/**
* @brief 设置音频播放音量
* @param vol 音量 0-100
*/
- (int)setExternalAudioRenderVolume:(int)vol;

/**
* @brief 获取音频播放音量
* @return vol 音量
*/
- (int)getExternalAudioRenderVolume;

@end

