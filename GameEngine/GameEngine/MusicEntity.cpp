#include "MusicEntity.h"
#include <iostream>



MusicEntity::MusicEntity(unsigned char * data, unsigned int size, unsigned int frequency, short numChannels)
{
	alGenBuffers(1, &buffer);
	alBufferData(buffer, (numChannels == 2) ? AL_FORMAT_STEREO16 : AL_FORMAT_MONO16, data, size, frequency);

	alGenSources(1, &source);
	alSourcei(source, AL_BUFFER, buffer);

	int error = alGetError();
	if (error != AL_NO_ERROR) {
		std::cout << "Error loading entity" << std::endl;
	}

	alSourcef(source, AL_MIN_GAIN, 0.01f);
	alSourcef(source, AL_MAX_GAIN, 1.0f);
	alSourcef(source, AL_REFERENCE_DISTANCE, 2.0f);

	state = 0;
}

MusicEntity::~MusicEntity()
{
	alDeleteSources(1, &source);
	alDeleteBuffers(1, &buffer);
}

void MusicEntity::play(bool loop)
{
	if (state != 1) {
		state = 1;

		alSourcei(source, AL_LOOPING, loop);
		alSourcePlay(source);
	}
}

void MusicEntity::pause()
{
	if (state != 2) {
		state = 2;

		alSourcePause(source);
	}
}

void MusicEntity::stop()
{
	if (state != 0) {
		state = 0;

		alSourceStop(source);
	}
}


void MusicEntity::setDirection(float x, float y, float z)
{
}

void MusicEntity::setPosition(float x, float y, float z)
{
	alSource3f(source, AL_POSITION, x, y, z);
}

void MusicEntity::setPitch(float pi)
{
	alSourcef(source, AL_PITCH, pi);
}

void MusicEntity::setVolume(float gain)
{
	alSourcef(source, AL_GAIN, gain);
}
