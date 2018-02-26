#pragma once
#include "AudioEntity.h"
#include <fstream>


class AudioLoader
{
public:
	static AudioEntity* loadWavFile(char* file);

};

