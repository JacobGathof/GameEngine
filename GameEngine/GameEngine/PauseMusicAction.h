#pragma once
#include "AbstractAction.h"
#include "ResourceManager.h"

class PauseMusicAction : public AbstractAction
{
public:
	PauseMusicAction(MusicType type);
	~PauseMusicAction();
	virtual int run(float dt);

private:
	MusicType song;
};

