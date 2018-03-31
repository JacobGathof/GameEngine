#include "AudioSystem.h"
#include "SoundScheduler.h"

ALCdevice* AudioSystem::device;
ALCcontext* AudioSystem::context;

void AudioSystem::init()
{
	device = alcOpenDevice(0);
	context = alcCreateContext(device, 0);

	alcMakeContextCurrent(context);

	SoundScheduler::init();
}

void AudioSystem::clean()
{
	alcMakeContextCurrent(0);
	alcDestroyContext(context);
	alcCloseDevice(device);

	SoundScheduler::clean();
}