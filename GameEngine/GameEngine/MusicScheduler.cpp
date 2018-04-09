#include "MusicScheduler.h"
#include <iostream>

unsigned int MusicScheduler::source;

void MusicScheduler::init()
{
	alGenSources(1, &source);
}

void MusicScheduler::clean()
{
	alDeleteSources(1, &source);
}

void MusicScheduler::playMusic(SoundEntity * entity)
{
	alSourcei(source, AL_BUFFER, entity->buffer);
	alSourcePlay(source);
}

void MusicScheduler::setVolume(float f)
{
	alSourcef(source, AL_GAIN, f);
}
