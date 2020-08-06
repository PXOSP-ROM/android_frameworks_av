/*
 * Copyright (C) 2019 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef WRITER_UTILITY_H_
#define WRITER_UTILITY_H_

#include <fstream>
#include <iostream>
#include <vector>

#include <media/stagefright/foundation/ABuffer.h>
#include <media/stagefright/foundation/ADebug.h>
#include <media/stagefright/foundation/AMessage.h>

#include <media/stagefright/MediaAdapter.h>

#include "WriterListener.h"

#define CODEC_CONFIG_FLAG 32

constexpr uint32_t kMaxTrackCount = 2;
constexpr uint32_t kMaxCSDStrlen = 16;
constexpr uint32_t kMaxCount = 20;
constexpr int32_t kMimeSize = 128;

struct BufferInfo {
    int32_t size;
    uint32_t flags;
    int64_t timeUs;
};

struct configFormat {
    char mime[kMimeSize];
    int32_t width;
    int32_t height;
    int32_t sampleRate;
    int32_t channelCount;
};

int32_t sendBuffersToWriter(ifstream &inputStream, vector<BufferInfo> &bufferInfo,
                            int32_t &inputFrameId, sp<MediaAdapter> &currentTrack, int32_t offset,
                            int32_t range, bool isPaused = false,
                            sp<WriterListener> listener = nullptr);

int32_t writeHeaderBuffers(ifstream &inputStream, vector<BufferInfo> &bufferInfo,
                           int32_t &inputFrameId, sp<AMessage> &format, int32_t numCsds);

#endif  // WRITER_UTILITY_H_
