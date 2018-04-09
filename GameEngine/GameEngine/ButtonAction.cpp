#include "ButtonAction.h"
#include "Window.h"

void FullscreenButtonAction::performAction()
{
	Window::toggleFullscreen();
}

void NoteButtonAction::performAction()
{
	Res::get(AudioType::SOUND_A_NOTE)->play();
}

void MusicButtonAction::performAction()
{
	Res::get(AudioType::SONG_FMAB_AGAIN)->play();
}
