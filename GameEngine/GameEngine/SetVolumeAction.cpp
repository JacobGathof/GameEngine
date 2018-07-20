#include "SetVolumeAction.h"
#include "MusicScheduler.h"
#include "SoundScheduler.h"


SetVolumeAction::SetVolumeAction(float * ref)
{
	f = ref;
}

SetVolumeAction::~SetVolumeAction()
{
}

int SetVolumeAction::run(float dt)
{
	MusicScheduler::setVolume(*f);
	SoundScheduler::setVolume(*f);
	return 1;
}
