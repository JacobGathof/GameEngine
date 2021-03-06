#pragma once
#include "AbstractAction.h"
#include "ResourceManager.h"

class PlayMusicAction : public AbstractAction
{
public:
	PlayMusicAction(AudioType type);
	~PlayMusicAction();
	virtual int run(float dt);

private:
	AudioType song;
};

