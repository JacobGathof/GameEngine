#include "Statusbar.h"



Statusbar::Statusbar()
{
}


Statusbar::~Statusbar()
{
}

void Statusbar::draw()
{
	UIUtils::drawRectangle(Vector2f(600, 590+50), Vector2f(100, -100), Color(0xffdddd88));
	UIUtils::drawRectangle(Vector2f(602, 588+50), Vector2f(96, -96), Color(0x44448844));
	UIUtils::drawRectangle(Vector2f(604, 586+50), Vector2f(92, -92), Color(0xffdddd88));
	UIUtils::drawImage(Vector2f(606, 584+50), Vector2f(88, -88), TextureType::TEXTURE_MAVIS);

	UIUtils::drawRectangle(Vector2f(600, 390+100), Vector2f(100, -100), Color(0xddddff88));
	UIUtils::drawRectangle(Vector2f(602, 388+100), Vector2f(96, -96), Color(0x44448844));
	UIUtils::drawRectangle(Vector2f(604, 386+100), Vector2f(92, -92), Color(0xddddff88));
	UIUtils::drawImage(Vector2f(606, 384+100), Vector2f(88, -88), TextureType::TEXTURE_PANDORA);

	UIUtils::drawRectangle(Vector2f(600, 190+150), Vector2f(100, -100), Color(0xddddff88));
	UIUtils::drawRectangle(Vector2f(602, 188+150), Vector2f(96, -96), Color(0x44448844));
	UIUtils::drawRectangle(Vector2f(604, 186+150), Vector2f(92, -92), Color(0xddddff88));
	UIUtils::drawImage(Vector2f(606, 184+150), Vector2f(88, -88), TextureType::TEXTURE_MELODY_BOOK);
}

void Statusbar::update(float dt)
{
}
