#include "Banner.h"



Banner::Banner()
{
	position = Vector2f(0, 500);
	scale = Vector2f(800, 200);
	bannerColor = Color::White;
	textColor = Color::Black;
	text = new Text(position+scale/2, std::string("The Echo Effect"), Vector2f(40,40), 0);
	text->center();
	text->setColor(textColor);

	subText = new Text(position + scale / 2 - Vector2f(0, 30), std::string("Prepare to Die Edition"), Vector2f(20, 20), 0);
	subText->center();
	subText->setColor(textColor);
}


Banner::~Banner()
{
	delete text;
	delete subText;
}

void Banner::draw()
{
	UIUtils::drawRectangle(position, scale, bannerColor);
	text->draw();
	subText->draw();
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

void Banner::setText(std::string& str, std::string& str_sub)
{
	text->setText(str);
	subText->setText(str_sub);

	text->center();
	subText->center();
}

bool Banner::isVisible()
{
	//Not used yet
	return 0;
}

void Banner::show()
{
}

void Banner::hide()
{
}
