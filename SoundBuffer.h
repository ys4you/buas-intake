#pragma once
class SoundBuffer
{
public:
	static SoundBuffer* get();

	ALuint addSoundEffect(const char* fileName);
	bool removeSoundEffect(const ALuint& buffer);

	void clearBuffers();  // Function to clear all buffers
private:
	SoundBuffer();
	~SoundBuffer();

	std::vector<ALuint> soundEffectBuffers;
};

