#include "MusicEntity.h"
#include "MusicScheduler.h"



MusicEntity::MusicEntity(unsigned char * data, unsigned int size, unsigned int frequency, short numChannels) :
	SoundEntity(data, size, frequency, numChannels)
{
}

void MusicEntity::play()
{
	MusicScheduler::playMusic(this);
}
