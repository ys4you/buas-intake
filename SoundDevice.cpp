#include "precomp.h"
#include "SoundDevice.h"

SoundDevice* SoundDevice::get()
{
	static SoundDevice* snd_device = new SoundDevice();
	return  snd_device;
}

SoundDevice::SoundDevice()
{
	Device = alcOpenDevice(nullptr); //get default audio device

	if (!Device)
		throw("failed to get a sound device");

	ALCCtx = alcCreateContext(Device, nullptr); //create context 

	if (!ALCCtx)
		throw("failed to set sound context");

	if (!alcMakeContextCurrent(ALCCtx)) //make context current
		throw("failed to make context current");

	const ALCchar* name = nullptr;
	if (alcIsExtensionPresent(Device, "ALC_ENUMERATE_ALL_EXT"))
		name = alcGetString(Device, ALC_ALL_DEVICES_SPECIFIER);
	if (!name || alcGetError(Device) != ALC_NO_ERROR)
		name = alcGetString(Device, ALC_DEVICE_SPECIFIER);
}


