#pragma once
#include "openal\include\alc.h"

class AudioSystem
{
public:
	static void init();
	static void clean();

private:
	static ALCdevice* device;
	static ALCcontext* context;
};

