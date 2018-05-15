#include "ButtonAction.h"
#include "ResourceManager.h"
#include "Window.h"

int FullscreenButtonAction::run(float dt)
{
	Window::toggleFullscreen();
	return 1;
}

int NoteButtonAction::run(float dt)
{
	Res::get(AudioType::SOUND_A_NOTE)->play();
	return 1;
}

int MusicButtonAction::run(float dt)
{
	Res::get(AudioType::SONG_FMAB_AGAIN)->play();
	return 1;
}

