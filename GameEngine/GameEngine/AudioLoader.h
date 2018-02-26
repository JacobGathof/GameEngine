#pragma once
#include "AudioEntity.h"
#include <fstream>
#include "openal\include\alc.h"

class AudioLoader
{
public:
	AudioLoader();
	~AudioLoader();
	static AudioEntity* loadWavFile(char* file);
	static void init();
	static void clean();

private:
	static ALCdevice* device;
	static ALCcontext* context;
};

