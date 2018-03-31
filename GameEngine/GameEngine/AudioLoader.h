#pragma once
#include "MusicEntity.h"
#include "SoundEntity.h"
#include <fstream>


class AudioLoader
{
public:
	static MusicEntity* loadMusicFile(char* file);
	static SoundEntity* loadSoundFile(char* file);

private:
	static void loadData(char* file, unsigned char** data, unsigned int *size, int *samplesPerSecond, short* channels);
};

