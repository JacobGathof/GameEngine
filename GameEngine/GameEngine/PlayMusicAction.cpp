#include "PlayMusicAction.h"
#include "ResourceManager.h"


PlayMusicAction::PlayMusicAction(AudioType type)
{
	song = type;
}

PlayMusicAction::~PlayMusicAction()
{
}

int PlayMusicAction::run(float dt)
{
	Res::get(song)->play();
	return 1;
}
