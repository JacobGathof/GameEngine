#include "AudioSystem.h"
#include "SoundScheduler.h"
#include "MusicScheduler.h"
#include "MidiScheduler.h"

ALCdevice* AudioSystem::device;
ALCcontext* AudioSystem::context;

void AudioSystem::init()
{
	device = alcOpenDevice(0);
	context = alcCreateContext(device, 0);

	alcMakeContextCurrent(context);

	SoundScheduler::init();
	MusicScheduler::init();
	MidiScheduler::init();
}

void AudioSystem::clean()
{
	alcMakeContextCurrent(0);
	alcDestroyContext(context);
	alcCloseDevice(device);

	SoundScheduler::clean();
	MusicScheduler::clean();
	MidiScheduler::clean();
}

void AudioSystem::setMasterVolume(float f)
{
	SoundScheduler::setVolume(f);
	MusicScheduler::setVolume(f);
}
