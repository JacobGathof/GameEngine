#include "ButtonAction.h"
#include "Window.h"

void FullscreenButtonAction::performAction()
{
	Window::toggleFullscreen();
}
