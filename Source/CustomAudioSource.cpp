#include "CustomAudioSource.h"

CustomAudioSource::CustomAudioSource()
{

}

CustomAudioSource::~CustomAudioSource()
{
    stop();
}

SoLoud::AudioSourceInstance* CustomAudioSource::createInstance()
{
    return new CustomAudioSourceInstance(this);
}

CustomAudioSourceInstance::CustomAudioSourceInstance(CustomAudioSource* source) :
    _source(source),
    _samplesRead(0)
{

}

unsigned int CustomAudioSourceInstance::getAudio(float* aBuffer, unsigned int aSamplesToRead, unsigned int aBufferSize)
{
    if (_source->_samples.empty())
        return 0;

    // Compute how many samples are left in the source
    unsigned int samplesLeft = _source->_samples.size() - _samplesRead;
    // Copy either aSamplesToRead or however many samples are still left in the source
    unsigned int copyLen = samplesLeft > aSamplesToRead ? aSamplesToRead : samplesLeft;

    // Copy over segment from source samples to aBuffer
    memcpy(aBuffer, _source->_samples.data() + _samplesRead, sizeof(float) * copyLen);

    _samplesRead += copyLen;
    return copyLen;
}

bool CustomAudioSourceInstance::hasEnded()
{
    return _samplesRead >= _source->_samples.size() && !(mFlags & AudioSourceInstance::LOOPING);
}

SoLoud::result CustomAudioSourceInstance::rewind()
{
    _samplesRead = 0;
    mStreamPosition = 0.0f;
    return 0;
}
