#pragma once
#include "AbstractScriptAction.h"
#include "ResourceManager.h"

class PauseMusicAction : public AbstractScriptAction
{
public:
	PauseMusicAction(MusicType type);
	~PauseMusicAction();
	virtual int run(float dt);

private:
	MusicType song;
};

