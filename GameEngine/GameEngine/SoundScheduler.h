#pragma once
#include <vector>
#include "SoundEntity.h"

class SoundScheduler
{
public:
	static void init();
	static void clean();

	static void playSound(SoundEntity* entity);
	static void setVolume(float f);

private:
	static std::vector<unsigned int> sources;
	static int sourcePtr;
	static int maximumSources;

};

