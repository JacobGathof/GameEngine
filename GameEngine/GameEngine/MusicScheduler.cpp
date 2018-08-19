#include "MusicScheduler.h"
#include <iostream>

unsigned int MusicScheduler::source;
SoundEntity* MusicScheduler::current;


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
	if (entity != current) {
		alSourceStop(source);
		alSourcei(source, AL_BUFFER, entity->buffer);
		alSourcePlay(source);
		current = entity;
	}
}

void MusicScheduler::setVolume(float f)
{
	alSourcef(source, AL_GAIN, f);
}


