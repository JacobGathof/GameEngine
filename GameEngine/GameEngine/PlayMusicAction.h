#pragma once
#include "AbstractAction.h"
#include "ResourceManager.h"

class PlayMusicAction : public AbstractAction
{
public:
	PlayMusicAction(MusicType type);
	~PlayMusicAction();
	virtual int run(float dt);

private:
	MusicType song;
};

