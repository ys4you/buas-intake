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
    return true;
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

bool AudioManager::playAudio(const std::string& filePath) {
    if (!m_initialized) {
        std::cerr << "AudioManager is not initialized. Cannot play audio.\n";
        return false;
    }

    // Play the audio file
    if (ma_engine_play_sound(&m_engine, filePath.c_str(), NULL) != MA_SUCCESS) {
        std::cerr << "Failed to play audio: " << filePath << "\n";
        return false;
    }

    std::cout << "Playing audio: " << filePath << "\n";
    return true;
}
