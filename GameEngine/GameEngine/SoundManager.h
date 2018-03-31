#pragma once
#include "SoundEntity.h"
#include "IManager.h"
#include "ResourceType.h"


class SoundManager : public IManager<SoundEntity, SoundType>
{
public:
	virtual void init();

private:
	void addAudio(SoundType type, char* filename);

};
