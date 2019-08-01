//
//  RemoteUserCollectionViewItem.h
//  RtcSample
//
//  Created by daijian on 2019/4/8.
//  Copyright © 2019年 mt. All rights reserved.
//

#import <Cocoa/Cocoa.h>

NS_ASSUME_NONNULL_BEGIN

@interface RemoteUserCollectionViewItem : NSCollectionViewItem

/**
 @brief 镜像点击事件回调
 */
@property(nonatomic,copy) void(^cameraMirrorBlock)(BOOL);

/**
 @brief 媒体流点击事件回调
 */
@property(nonatomic,copy) void(^mediaInfoBlock)();

@property (weak) IBOutlet NSButtonCell *cameraMirrorButton;
@property (weak) IBOutlet NSButton *mediaInfoButton;
@end

NS_ASSUME_NONNULL_END
