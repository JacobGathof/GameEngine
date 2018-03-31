#include "ButtonAction.h"
#include "Window.h"

void FullscreenButtonAction::performAction()
{
	Window::toggleFullscreen();
}

void NoteButtonAction::performAction()
{
	Res::get(SoundType::SOUND_A_NOTE)->play();
}
