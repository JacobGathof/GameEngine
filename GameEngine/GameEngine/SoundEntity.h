#pragma once
#include "openal\include\al.h"

class SoundEntity
{
public:
	SoundEntity(unsigned char* data, unsigned int size, unsigned int frequency, short numChannels);
	~SoundEntity();
	void play();

	unsigned int buffer;

};

