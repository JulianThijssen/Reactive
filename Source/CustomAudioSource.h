#pragma once

#include "soloud.h"

#include <vector>

class CustomAudioSource : public SoLoud::AudioSource
{
public:
    CustomAudioSource();
    virtual ~CustomAudioSource() override;
    virtual SoLoud::AudioSourceInstance* createInstance() override;

private:
    std::vector<float> _samples;

    friend class CustomAudioSourceInstance;
};

class CustomAudioSourceInstance : public SoLoud::AudioSourceInstance
{
public:
    CustomAudioSourceInstance(CustomAudioSource* source);
    virtual unsigned int getAudio(float* aBuffer, unsigned int aSamplesToRead, unsigned int aBufferSize) override;
    virtual bool hasEnded() override;
    //virtual SoLoud::result seek(float aSeconds, float* mScratch, int mScratchSize);
    virtual SoLoud::result rewind() override;

private:
    CustomAudioSource* _source;

    int _samplesRead;
};
