#pragma once

#include "miniaudio.h"
#include <string>
#include <map>

/// @brief Manages audio playback and initialization using MiniAudio.
class AudioManager {
public:
    /// @brief Gets the singleton instance of the AudioManager.
    /// @return Reference to the AudioManager instance.
    static AudioManager& Get();

    /// @brief Initializes the audio engine.
    /// @return True if initialization succeeds, false otherwise.
    bool initialize();

    /// @brief Cleans up and shuts down the audio engine.
    void deconstruct();

    /// @brief Plays an audio file by name.
    /// @param audioName The name of the audio file to play.
    /// @return True if the audio plays successfully, false otherwise.
    bool playAudio(const std::string& audioName);

private:
    AudioManager();
    ~AudioManager();

    /// @brief Sets up the audio dictionary with audio file paths.
    void SetupAudioDict();

    // Disable copy and assignment
    AudioManager(const AudioManager&) = delete;
    AudioManager& operator=(const AudioManager&) = delete;

    ma_engine m_engine;
    bool m_initialized = false;

    std::map<std::string, std::string> audioDict;
};
