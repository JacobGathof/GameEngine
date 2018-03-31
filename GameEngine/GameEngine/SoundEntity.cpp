#include "SoundEntity.h"
#include "SoundScheduler.h"

SoundEntity::SoundEntity(unsigned char * data, unsigned int size, unsigned int frequency, short numChannels)
{
	alGenBuffers(1, &buffer);
	alBufferData(buffer, (numChannels == 2) ? AL_FORMAT_STEREO16 : AL_FORMAT_MONO16, data, size, frequency);
}


SoundEntity::~SoundEntity()
{
	alDeleteBuffers(1, &buffer);
}

void SoundEntity::play(){
	SoundScheduler::playSound(this);
}
