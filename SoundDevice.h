#pragma once
#include <OpenAL/include/alc.h>
class SoundDevice
{
public:
	static SoundDevice* get();
	void ShutdownSoundDevice();
private:
	SoundDevice();

	ALCcontext* ALCCtx;
	ALCdevice* ALDevice;

};

