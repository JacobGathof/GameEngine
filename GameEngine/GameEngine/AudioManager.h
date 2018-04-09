#pragma once
#include "SoundEntity.h"
#include "IManager.h"
#include "ResourceType.h"


class AudioManager : public IManager<SoundEntity, AudioType>{
public:
	virtual void init();

private:
	void addSound(AudioType type, char* filename);
	void addMusic(AudioType type, char* filename);
};
