//
//  AliBaseHttpClient.h
//  RTCDemo
//
//  Created by mt on 2017/8/18.
//  Copyright © 2017年 mt. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface AliBaseHttpClient : NSObject


/**
 初始化
 */
+ (AliBaseHttpClient *)client;


/**
 请求数据

 @param host 服务器host
 @param param 参数
 @param block 回调
 */
- (void)httpPostWithHost:(NSString *)host param:(NSDictionary *)param block:(void (^)(NSDictionary *response, NSError *err))block;

@end

