//
//  FakeAuthrization.m
//  Demo
//
//  Created by mt on 2018/6/27.
//  Copyright © 2018年 mt. All rights reserved.
//

#import "FakeAuthrization.h"
#import "AliRequestList.h"

@interface FakeAuthrization()

@end

@implementation FakeAuthrization

+ (void)GetPassportFromAppServer:(NSString *)channelName userName:(NSString *)username block:(void (^)(AliRtcAuthInfo *loginModel, NSError *error))block {
    
    [[NSUserDefaults standardUserDefaults] setObject:AppServer forKey:@"HostUrl"];
    
    // 用户名 频道号 服务器需要传的密码
    NSDictionary *param = @{@"user": username,
                            @"room": channelName,
                            @"passwd": @"12345678"};

    __block AliRtcAuthInfo * info = [[AliRtcAuthInfo alloc]init];;
    
    [AliRequestList userLoginParam:param block:^(NSDictionary *joinModel, NSError *err){
        if (err) {
            block(nil, err);
            NSLog(@"Failed to get token from your App Server. Please check your network and server status.");
        }
        else{
            NSMutableDictionary *loginDic = [[NSMutableDictionary alloc]init];
            NSDictionary *dataDic = joinModel[@"data"];
            NSArray *keysArray = [dataDic allKeys];
            for (NSUInteger i = 0; i < keysArray.count; i++) {
                NSString *key = keysArray[i];
                NSString *value = dataDic[key];
                [loginDic setObject:value forKey:key];
            }

            info.channel   = channelName;
            info.appid     = loginDic[@"appid"];
            info.nonce     = loginDic[@"nonce"];
            info.user_id   = loginDic[@"userid"];
            info.token     = loginDic[@"token"];
            info.timestamp = [loginDic[@"timestamp"] longLongValue];
            info.gslb      = loginDic[@"gslb"];
            
            block(info, nil);
        }
    }];
    
}

@end
