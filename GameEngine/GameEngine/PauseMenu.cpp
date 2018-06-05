#include "PauseMenu.h"
#include "Text.h"


PauseMenu::PauseMenu()
{
	text = new Text(Vector2f(100, 500), std::string("PAUSED"), Vector2f(100, 100), 0);
	resume = new Button(Vector2f(100, 300), Vector2f(200, 50), std::string("Resume Game"), new UnpauseAction());
	exit = new Button(Vector2f(100, 400), Vector2f(200, 50), std::string("Exit Game"), new ExitAction());
}


PauseMenu::~PauseMenu()
{
	delete text;
	delete resume;
	delete exit;
}

void PauseMenu::draw()
{
	text->draw();
	resume->draw();
	exit->draw();
}

void PauseMenu::handleMouseEvents(Mouse & mouse)
{
	resume->handleMouseEvents(mouse);
	exit->handleMouseEvents(mouse);
}
