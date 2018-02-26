#pragma once
#include "openal\include\al.h"

class AudioEntity
{
public:
	AudioEntity(unsigned char* data, unsigned int size, unsigned int frequency, short numChannels);
	~AudioEntity();

	void play(bool loop);
	void pause();
	void stop();

	void setDirection(float x, float y, float z);
	void setPosition(float x, float y, float z);
	void setPitch(float pi);
	void setVolume(float gain);

private:
	unsigned int source;
	unsigned int buffer;
	unsigned int state;

};

