#pragma once
#include "SoundBuffer.h"
#include "SoundDevice.h"
#include <vector>
#include <AL/al.h>

struct audio
{
    std::string fileName;   // Audio file name
    ALuint audioBuffer;     // OpenAL buffer ID
    ALuint audioSource;     // OpenAL source ID

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
    const ALsizei maxSources = 16;           // Max number of sources
    std::vector<audio> sources;              // Audio source and buffer list
    ALuint* source = nullptr;                // Pointer to OpenAL sources

    SoundManager();

    SoundBuffer* soundBuffer_ = SoundBuffer::get();
    SoundDevice* device_ = SoundDevice::get();
};
