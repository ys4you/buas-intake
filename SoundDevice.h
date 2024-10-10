#pragma once
#include <OpenAL/include/alc.h>
class SoundDevice
{
public:
	static SoundDevice* get();
private:
	SoundDevice();
	~SoundDevice();

	ALCcontext* ALCCtx;
	ALCdevice* Device;

};

