//
//  FakeAuthrization.h
//  Demo
//
//  Created by mt on 2018/6/27.
//  Copyright © 2018年 mt. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <AliRTCSdk/AliRTCSdk.h>


// 用户APP Server
static NSString *AppServer   =  @"";   //Your APP Server Address


@interface FakeAuthrization : NSObject

/** 这是app厂商实现app server查询的示例代码
 */
+ (void)GetPassportFromAppServer:(NSString *)channelName userName:(NSString *)username block:(void (^)(AliRtcAuthInfo *loginModel, NSError *error))block;

@end
