#include "precomp.h"
#include "SoundManager.h"
#include <AL/al.h>
#include <iostream>

SoundManager* SoundManager::get()
{
    std::cout << "test";
    static SoundManager instance;
    return &instance;
}

SoundManager::SoundManager()
{
    source = new ALuint[maxSources];  
    alGenSources(maxSources, source); // Generate OpenAL sources

    // Check for OpenAL errors
    if (alGetError() != AL_NO_ERROR)
    {
        std::cerr << "Error generating OpenAL sources." << std::endl;
    }
}

//function generated by AI

void SoundManager::ShutdownOpenAL()
{
    // Stop all sources before deletion
    for (int i = 0; i < maxSources; i++) 
    {
        alSourceStop(source[i]);
    }

    // Delete OpenAL sources
    alDeleteSources(maxSources, source);



    // Free the dynamically allocated memory for sources
    delete[] source;

    // Destroy the context and close the device
    ALCcontext* context = alcGetCurrentContext();
    ALCdevice* device = alcGetContextsDevice(context);

    alcMakeContextCurrent(nullptr);
    alcDestroyContext(context);
    alcCloseDevice(device);

}


void SoundManager::LoadingSounds()
{
    std::cout << "in LoadingSounds";

	const char * soundFile = "assets/audio/hit.wav";
    ALuint buffer = soundBuffer_->addSoundEffect(soundFile); 
    std::cout << buffer;

    ALuint sourceID = source[sources.size()];  // Pick a free source from the list
    sources.push_back(audio("hit", buffer, sourceID)); // Add the audio object to the list

    std::cout << "Loaded sound: " << soundFile << std::endl;
}

void SoundManager::Play(const std::string& pAudioName)
{

    bool audioFound = false;  // Flag to track if the audio is found

    for (auto& source : sources)
    {
        if (source.fileName == pAudioName)
        {
            audioFound = true;  // Set flag to true if the audio is found

            ALint state;
            alGetSourcei(source.audioSource, AL_SOURCE_STATE, &state); 

            if (state != AL_PLAYING)
            {
                alSourcei(source.audioSource, AL_BUFFER, source.audioBuffer); 
                alSourcePlay(source.audioSource); // Play the source
                break;
            }
        }
    }

    if (!audioFound)
    {
        printf("Error: Audio file \"%s\" not found in sources.\n", pAudioName.c_str());
    }
}

