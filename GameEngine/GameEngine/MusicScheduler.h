#pragma once
#include "SoundEntity.h"

class MusicScheduler
{
public:
	static void init();
	static void clean();

	static void playMusic(SoundEntity* entity);
	static void setVolume(float f);

private:
	static unsigned int source;
};

