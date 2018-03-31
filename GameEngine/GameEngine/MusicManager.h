#pragma once
#include "MusicEntity.h"
#include "IManager.h"
#include "ResourceType.h"


class MusicManager : public IManager<MusicEntity, MusicType>
{
public:
	virtual void init();

private:
	void addAudio(MusicType type, char* filename);

};
