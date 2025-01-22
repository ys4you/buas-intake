#pragma once

#include "miniaudio.h"
#include <string>

class AudioManager {
public:
    // Get the singleton instance
    static AudioManager& Get();

    bool initialize();

    void deconstruct();

    bool playAudio(const std::string& audioName);

private:
    AudioManager();
    ~AudioManager();

    void SetupAudioDict();

    // Disable copy and assignment
    AudioManager(const AudioManager&) = delete;
    AudioManager& operator=(const AudioManager&) = delete;

    ma_engine m_engine;
    bool m_initialized = false;

    std::map<std::string, std::string> audioDict;
};

