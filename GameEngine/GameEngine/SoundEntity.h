#pragma once
#include "openal\include\al.h"

class SoundEntity
{
public:
	SoundEntity(unsigned char* data, unsigned int size, unsigned int frequency, short numChannels);
	virtual ~SoundEntity();
	virtual void play();

	unsigned int buffer;

};

