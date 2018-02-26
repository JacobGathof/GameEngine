#include "PauseMusicAction.h"



PauseMusicAction::PauseMusicAction(MusicType type)
{
	song = type;
}

PauseMusicAction::~PauseMusicAction()
{
}

int PauseMusicAction::run(float dt)
{
	Res::get(song)->pause();
	return 1;
}
