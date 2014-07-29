/* Copyright (c) 2013 - 2014, The Linux Foundation. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *     * Redistributions of source code must retain the above copyright
 *      notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above
 *       copyright notice, this list of conditions and the following
 *       disclaimer in the documentation and/or other materials provided
 *      with the distribution.
 *     * Neither the name of The Linux Foundation nor the names of its
 *      contributors may be used to endorse or promote products derived
 *       from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
 * BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
 * IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
#ifndef EXTENDED_UTILS_H_
#define EXTENDED_UTILS_H_

#include <utils/StrongPointer.h>
#include <media/Metadata.h>
#include <media/stagefright/MediaSource.h>
#include <media/stagefright/foundation/AString.h>
#include <media/stagefright/MediaCodecList.h>

#include <media/MediaRecorderBase.h>
#include <media/stagefright/MediaExtractor.h>
#include <camera/CameraParameters.h>
#include <OMX_Video.h>
#include <android/native_window.h>

#define MIN_BITERATE_AAC 24000
#define MAX_BITERATE_AAC 192000

namespace android {

/*
 * This class is a placeholder for utility methods for
 * QC specific changes
 */
struct ExtendedUtils {

    /*
     * This class is a placeholder for methods to override
     * default heaviour based on shell properties set
     */
    struct ShellProp {
        // check if shell property to disable audio is set
        static bool isAudioDisabled(bool isEncoder);

        //helper function to set encoding profiles
        static void setEncoderProfile(video_encoder &videoEncoder,
                int32_t &videoEncoderProfile, int32_t &videoEncoderLevel);

        static bool isSmoothStreamingEnabled();

        static int64_t getMaxAVSyncLateMargin();
    };

    static const int32_t kNumBFramesPerPFrame = 1;

    //set B frames for MPEG4
    static void setBFrames(OMX_VIDEO_PARAM_MPEG4TYPE &mpeg4type,
            const char* componentName);

    //set B frames for H264
    static void setBFrames(OMX_VIDEO_PARAM_AVCTYPE &h264type,
            const int32_t iFramesInterval, const int32_t frameRate,
            const char* componentName);

    static bool UseQCHWAACEncoder(audio_encoder Encoder, int32_t Channel,
            int32_t BitRate, int32_t SampleRate);

    static sp<MediaExtractor> MediaExtractor_CreateIfNeeded(
            sp<MediaExtractor> defaultExt, const sp<DataSource> &source,
            const char *mime);

    static bool isAVCProfileSupported(int32_t profile);

    //notify stride change to ANW
    static void updateNativeWindowBufferGeometry(ANativeWindow* anw,
            OMX_U32 width, OMX_U32 height, OMX_COLOR_FORMATTYPE colorFormat);

    static bool checkIsThumbNailMode(const uint32_t flags, char* componentName);

};

}
#endif  //EXTENDED_UTILS_H_
