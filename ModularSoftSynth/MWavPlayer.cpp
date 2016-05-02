//
//  MWavPlayer.cpp
//  ModularSoftSynth
//
//  Created by Tate Allen on 4/17/16.
//  Copyright © 2016 tate. All rights reserved.
//

#include "MWavPlayer.hpp"

MWavPlayer::MWavPlayer(const std::string &filePath)
{
    hasOutput();
    
    SNDFILE *file;
    SF_INFO info;
    
    /* Open the WAV file. */
    info.format = 0;
    file = sf_open(filePath.c_str(), SFM_READ, &info);
    if (file == NULL) {
        printf("Failed to open the file.\n");
        exit(-1);
    }
    
    sf_count_t frameCount = info.frames;
    sampleRate = info.samplerate;
    channelCount = info.channels;
    
//    printf("frames: %lld\n", frameCount);
//    printf("samplerate: %d\n", sampleRate);
//    printf("channels: %d\n", channelCount);
    
    sampleCount = frameCount * channelCount;
//    printf("num_items: %lld\n", sampleCount);
    
    buffer = new double[sampleCount];
    
    sf_read_double(file, buffer, sampleCount);
    sf_close(file);
        
//    printf("Read %lld items\n", num);
}

MWavPlayer::~MWavPlayer()
{
    delete [] buffer;
}

void MWavPlayer::update()
{
    int multiple = SAMPLE_RATE / sampleRate;
    while (getBufferSize() < MAX_BUFFER_SIZE) {
        for (int i = 0; i < multiple; ++i) {
            writeToOutputs(buffer[currentSampleIndex]);
        }
        currentSampleIndex += channelCount;
        if (currentSampleIndex >= sampleCount) {
            currentSampleIndex = 0;
        }
    }
}