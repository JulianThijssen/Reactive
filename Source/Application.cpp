#include "AudioEngine.h"

#include <iostream>

int main()
{
    AudioEngine audioEngine;

    audioEngine.Init();
    audioEngine.LoadAudioFromFile("Resources/until_then.wav");
    audioEngine.Play();

    float prevAmp = 0;
    while (1)
    {
        SoLoud::time audioTime = audioEngine.GetCurrentPlayTime();

        // Compute amplitude
        float amp = 0;

        float* wav = audioEngine.GetCurrentAudioWindow();

        //for (int i = 0; i < 256; i++)
        //{
        //    amp += abs(wav[i]);
        //}
        //amp /= 10;

        float* fft = audioEngine.GetCurrentFrequencyWindow();

        for (int i = 0; i < 256; i++)
        {
            std::cout << fft[i] << std::endl;
        }

        Sleep(16);
    }

    return 0;
}
