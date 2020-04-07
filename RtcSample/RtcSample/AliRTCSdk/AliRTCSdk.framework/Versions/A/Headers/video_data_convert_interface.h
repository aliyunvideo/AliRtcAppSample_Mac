//
//  video_data_convert_interface.h
//  AliRTCSdk
//
//  Created by mt on 2019/12/25.
//  Copyright © 2019 mt. All rights reserved.
//

#pragma once
#include <stdint.h>

namespace AliRTCSdk {

enum AliRTCSdk_Video_Convert_Format{
    AliRTCSdk_Video_Convert_Format_UnKnown,
    AliRTCSdk_Video_Convert_Format_I420,
    AliRTCSdk_Video_Convert_Format_ABGR,
};

struct ConvertVideoFrame {
    AliRTCSdk_Video_Convert_Format format = AliRTCSdk_Video_Convert_Format_UnKnown;
    uint8_t *frame = nullptr;
    int32_t width = 0;
    int32_t height = 0;
    int32_t stride_y = 0;
    int32_t stride_u = 0;
    int32_t stride_v = 0;
};

class VideoVideoDataConvertInterface {
public:
    static int ConvertVideoData(const ConvertVideoFrame &frame, ConvertVideoFrame *des_frame) ;
};

}
