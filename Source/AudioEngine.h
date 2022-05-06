#include "soloud.h"
#include "soloud_wav.h"

#include <string>

class AudioEngine
{
public:
    AudioEngine();

    void Init();
    void LoadAudioFromFile(std::string fileName);

    void SetPlaybackSpeed(float playbackSpeed);
    void Play();

    double GetCurrentPlayTime();
    float* GetCurrentAudioWindow();
    float* GetCurrentFrequencyWindow();

private:
    SoLoud::Soloud _soloud; // Engine core
    SoLoud::Wav _sample;    // One sample

    int _playHandle;
};
