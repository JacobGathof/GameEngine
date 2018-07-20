#include "SoundScheduler.h"


int SoundScheduler::maximumSources = 16;
int SoundScheduler::sourcePtr = 0;
std::vector<unsigned int> SoundScheduler::sources;


void SoundScheduler::init()
{
	for (int i = 0; i < maximumSources; i++) {
		unsigned int s;
		alGenSources(1, &s);
		sources.push_back(s);
	}
}

void SoundScheduler::clean()
{
	for (unsigned int i : sources) {
		alDeleteSources(1, &i);
	}
}

void SoundScheduler::playSound(SoundEntity * entity)
{
	unsigned int src = sources[sourcePtr++];
	sourcePtr = sourcePtr % maximumSources;

	alSourcei(src, AL_BUFFER, entity->buffer);

	alSourcePlay(src);
}

void SoundScheduler::setVolume(float f)
{
	for (int i = 0; i < maximumSources; i++) {
		alSourcef(sources[i], AL_GAIN, f);
	}
}
