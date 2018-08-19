#pragma once
#include "openal\include\alc.h"

class AudioSystem
{
public:
	static void init();
	static void clean();
	static void setMasterVolume(float f);

private:
	static ALCdevice* device;
	static ALCcontext* context;
};

