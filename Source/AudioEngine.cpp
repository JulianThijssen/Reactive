#include "AudioEngine.h"

AudioEngine::AudioEngine() :
    _playHandle(-1)
{

}

void AudioEngine::Init()
{
    _soloud.init(SoLoud::Soloud::ENABLE_VISUALIZATION);
}

void AudioEngine::LoadAudioFromFile(std::string fileName)
{
    _sample.load(fileName.c_str());
}

void AudioEngine::SetPlaybackSpeed(float playbackSpeed)
{
    _soloud.setRelativePlaySpeed(_playHandle, playbackSpeed);
}

void AudioEngine::Play()
{
    _playHandle = _soloud.play(_sample);
}

double AudioEngine::GetCurrentPlayTime()
{
    return _soloud.getStreamTime(_playHandle);
}

float* AudioEngine::GetCurrentAudioWindow()
{
    return _soloud.getWave();
}

float* AudioEngine::GetCurrentFrequencyWindow()
{
    return _soloud.calcFFT();
}
