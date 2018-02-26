#include "PlayMusicAction.h"



PlayMusicAction::PlayMusicAction(MusicType type)
{
	song = type;
}

PlayMusicAction::~PlayMusicAction()
{
}

int PlayMusicAction::run(float dt)
{
	Res::get(song)->play(true);
	return 1;
}
