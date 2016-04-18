//
//  MWavPlayer.cpp
//  ModularSoftSynth
//
//  Created by Tate Allen on 4/17/16.
//  Copyright © 2016 tate. All rights reserved.
//

#include "MWavPlayer.hpp"

MWavPlayer::MWavPlayer(const std::string &filePath, int loops)
{
    hasOutput();
    this->loops = loops;
    
    SNDFILE *sf;
    SF_INFO info;
    int num;
    int f,sr;
    int i,j;
    FILE *out;
    
    /* Open the WAV file. */
    info.format = 0;
    sf = sf_open(filePath.c_str(), SFM_READ, &info);
    if (sf == NULL)
    {
        printf("Failed to open the file.\n");
        exit(-1);
    }
    
    /* Print some of the info, and figure out how much data to read. */
    f = info.frames;
    sr = info.samplerate;
    channelCount = info.channels;
    printf("frames=%d\n",f);
    printf("samplerate=%d\n",sr);
    printf("channels=%d\n", channelCount);
    sampleCount = f * channelCount;
    printf("num_items=%d\n", sampleCount);
    
    /* Allocate space for the data to be read, then read it. */
    buffer = (double*)malloc(sampleCount * sizeof(double));
    
    num = sf_read_double(sf, buffer, sampleCount);
    sf_close(sf);
    
    printf("Read %d items\n",num);
}

MWavPlayer::~MWavPlayer()
{
    
}

void MWavPlayer::update()
{
    while (getBufferSize() < MAX_BUFFER_SIZE) {
        writeToOutputs(buffer[currentSampleIndex]);
        currentSampleIndex += channelCount;
        if (currentSampleIndex >= sampleCount) {
            currentSampleIndex = 0;
        }
    }
}