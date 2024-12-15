#include "precomp.h"
#include "SoundDevice.h"

SoundDevice* SoundDevice::get()
{
	static SoundDevice* snd_device = new SoundDevice();
	return  snd_device;
}

SoundDevice::SoundDevice()
{
	ALDevice = alcOpenDevice(nullptr); //get default audio device

	if (!ALDevice)
		throw("failed to get a sound device");

	ALCCtx = alcCreateContext(ALDevice, nullptr); //create context 

	if (!ALCCtx)
		throw("failed to set sound context");

	if (!alcMakeContextCurrent(ALCCtx)) //make context current
		throw("failed to make context current");

	const ALCchar* name = nullptr;
	if (alcIsExtensionPresent(ALDevice, "ALC_ENUMERATE_ALL_EXT")) //checks if present
		name = alcGetString(ALDevice, ALC_ALL_DEVICES_SPECIFIER);
	if (!name || alcGetError(ALDevice) != ALC_NO_ERROR) 
		name = alcGetString(ALDevice, ALC_DEVICE_SPECIFIER);
}

void SoundDevice::ShutdownSoundDevice()
{
	if (ALCCtx && ALDevice)
	{
		alcDestroyContext(ALCCtx);
		ALCCtx = nullptr;

		alcCloseDevice(ALDevice);
		ALDevice = nullptr;
	}
}



