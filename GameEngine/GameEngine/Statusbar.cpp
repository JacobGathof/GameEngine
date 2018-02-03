#include "Statusbar.h"



Statusbar::Statusbar()
{
}


Statusbar::~Statusbar()
{
}

void Statusbar::draw()
{
	UIUtils::drawRectangle(Vector2f(600, 590), Vector2f(100, -100), Color(0xffdddd88));
	UIUtils::drawRectangle(Vector2f(602, 588), Vector2f(96, -96), Color(0x44448844));
	UIUtils::drawRectangle(Vector2f(604, 586), Vector2f(92, -92), Color(0xffdddd88));
	UIUtils::drawImage(Vector2f(606, 584), Vector2f(88, -88), TextureType::TEXTURE_MELODY);

	UIUtils::drawRectangle(Vector2f(600, 390), Vector2f(100, -100), Color(0xddddff88));
	UIUtils::drawRectangle(Vector2f(602, 388), Vector2f(96, -96), Color(0x44448844));
	UIUtils::drawRectangle(Vector2f(604, 386), Vector2f(92, -92), Color(0xddddff88));
	UIUtils::drawImage(Vector2f(606, 384), Vector2f(88, -88), TextureType::TEXTURE_MELODY);
}

void Statusbar::update(float dt)
{
}
