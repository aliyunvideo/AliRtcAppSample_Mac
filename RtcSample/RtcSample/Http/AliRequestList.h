//
//  AliRequestList.h
//  RTCDemo
//
//  Created by mt on 2017/8/18.
//  Copyright © 2017年 mt. All rights reserved.
//


#import "AliBaseHttpClient.h"

@interface AliRequestList : NSObject

/**
 登录

 @param param 参数
 @param block 回调
 */
+ (void)userLoginParam:(NSDictionary *)param block:(void (^)(NSDictionary *loginModel, NSError *error))block;

@end
