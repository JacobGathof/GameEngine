#pragma once
#include "AbstractScriptAction.h"
#include "MusicManager.h"

class PlayMusicAction : public AbstractScriptAction
{
public:
	PlayMusicAction(MusicType type);
	~PlayMusicAction();
	virtual int run(float dt);

private:
	MusicType song;
};

