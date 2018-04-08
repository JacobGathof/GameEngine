#pragma once
#include "SoundEntity.h"

class MusicEntity : public SoundEntity
{
public:
	MusicEntity(unsigned char * data, unsigned int size, unsigned int frequency, short numChannels);
	virtual void play();
};

