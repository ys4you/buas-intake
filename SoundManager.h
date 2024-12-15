#pragma once
#include "SoundBuffer.h"
#include "SoundDevice.h"
#include <vector>
#include <AL/al.h>

struct audio
{
    std::string fileName;
    ALuint audioBuffer; // OpenAL buffer ID
    ALuint audioSource; // OpenAL source ID

    // Constructor
    audio(const std::string& name, ALuint buffer, ALuint source)
        : fileName(name), audioBuffer(buffer), audioSource(source)
    {
    }
};

class SoundManager
{
public:
    static SoundManager* get();

    void LoadingSounds();
    void Play(const std::string& soundName);
    void ShutdownOpenAL();

private:
    const ALsizei maxSources = 16;
    std::vector<audio> sources;
    ALuint* source = nullptr;

    SoundManager();

    SoundBuffer* soundBuffer_ = SoundBuffer::get();
    SoundDevice* device_ = SoundDevice::get();
};
