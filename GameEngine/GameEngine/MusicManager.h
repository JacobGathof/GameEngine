#pragma once
#include "AudioEntity.h"
#include "IManager.h"
#include "ResourceType.h"


class MusicManager : public IManager<AudioEntity, MusicType>
{
public:
	virtual void init();

private:
	void addAudio(MusicType type, char* filename);

};
