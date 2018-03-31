#pragma once
#include "openal\include\al.h"

class MusicEntity
{
public:
	MusicEntity(unsigned char* data, unsigned int size, unsigned int frequency, short numChannels);
	~MusicEntity();

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

