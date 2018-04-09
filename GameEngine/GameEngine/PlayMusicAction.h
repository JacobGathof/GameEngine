#pragma once
#include "AbstractScriptAction.h"
#include "AudioManager.h"

class PlayMusicAction : public AbstractScriptAction
{
public:
	PlayMusicAction(AudioType type);
	~PlayMusicAction();
	virtual int run(float dt);

private:
	AudioType song;
};

