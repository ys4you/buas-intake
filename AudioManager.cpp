#include "precomp.h"
#define MINIAUDIO_IMPLEMENTATION
#include "AudioManager.h"
#include <iostream>

AudioManager& AudioManager::Get() {
    static AudioManager instance;
    return instance;
}

AudioManager::AudioManager() = default;

AudioManager::~AudioManager() {
    if (m_initialized) {
        deconstruct();
    }
}



bool AudioManager::initialize() {
    if (m_initialized) {
        std::cerr << "AudioManager is already initialized.\n";
        return false;
    }

    // Initialize the engine
    if (ma_engine_init(NULL, &m_engine) != MA_SUCCESS) {
        std::cerr << "Failed to initialize audio engine.\n";
        return false;
    }

    m_initialized = true;
    std::cout << "AudioManager initialized successfully.\n";

    SetupAudioDict();
    return true;
}

//add audio to a dict so referencing it in other files is easier
void AudioManager::SetupAudioDict()
{
    audioDict["hit"] = "C:/Buas/Intake/Collect/assets/audio/hit.wav";
}

void AudioManager::deconstruct() {
    if (!m_initialized) {
        std::cerr << "AudioManager is not initialized.\n";
        return;
    }

    // Cleanup the engine
    ma_engine_uninit(&m_engine);
    m_initialized = false;
    std::cout << "AudioManager deconstructed successfully.\n";
}

bool AudioManager::playAudio(const std::string& audioName) {
    if (!m_initialized) {
        std::cerr << "AudioManager is not initialized. Cannot play audio.\n";
        return false;
    }

    auto it = audioDict.find(audioName);
    if (it == audioDict.end())
    {
        std::cerr << "Audio file not found: " << audioName << "\n";
        return false;
    }

    const std::string& audioFilePath = it->second;


    // Play the audio file
    if (ma_engine_play_sound(&m_engine, audioFilePath.c_str(), NULL) != MA_SUCCESS) {
        std::cerr << "Failed to play audio: " << audioFilePath << "\n";
        return false;
    }

    std::cout << "Playing audio: " << audioFilePath << "\n";
    return true;
}
