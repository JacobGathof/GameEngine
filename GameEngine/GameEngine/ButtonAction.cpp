#include "ButtonAction.h"
#include "ResourceManager.h"
#include "Window.h"
#include "Input.h"

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
	Res::get(AudioType::SONG_1)->play();
	return 1;
}

int UnpauseAction::run(float dt)
{
	Input::pause(false);
	return 1;
}

int ExitAction::run(float dt)
{
	Window::close();
	return 1;
}

int MusicButtonAction2::run(float dt)
{
	Res::get(AudioType::SONG_2)->play();
	return 1;
}
