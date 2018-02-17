#include "Menu.h"



Menu::Menu()
{
	
}

Menu::~Menu()
{
	
}

void Menu::draw()
{
	glBlendFunc(GL_ONE, GL_ZERO);
	//UIUtils::drawRectangle(position, Vector2f(800, 800), Color(0xffffffff));
	//UIUtils::drawRectangle(position+Vector2f(2,2), Vector2f(796, 796), Color(0x00000000));
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void Menu::update(float dt)
{
	
}