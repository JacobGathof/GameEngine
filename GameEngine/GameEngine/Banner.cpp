#include "Banner.h"



Banner::Banner()
{
	position = Vector2f(0, 500);
	scale = Vector2f(800, 200);
	bannerColor = Color::White;
	textColor = Color::Black;
	text = new Text(position+scale/2, std::string(), Vector2f(20,20), 0);
	text->center();
}


Banner::~Banner()
{
}

void Banner::draw()
{
}

void Banner::update(float dt)
{
}

void Banner::handleMouseEvents(Mouse & mouse)
{
}

void Banner::handleKeyEvents(Keyboard & keyboard)
{
}

void Banner::setText(std::string str)
{
}
