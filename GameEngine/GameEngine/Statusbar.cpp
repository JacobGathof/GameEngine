#include "Statusbar.h"



Statusbar::Statusbar()
{
}


Statusbar::~Statusbar()
{
}

void Statusbar::draw()
{
	UIUtils::drawRectangle(Vector2f(600, 790), Vector2f(190, -100), Color(0xffdddd88));
	UIUtils::drawRectangle(Vector2f(602, 788), Vector2f(186, -96), Color(0x44448844));
	UIUtils::drawRectangle(Vector2f(604, 786), Vector2f(182, -92), Color(0xffdddd88));
}

void Statusbar::update(float dt)
{
}
