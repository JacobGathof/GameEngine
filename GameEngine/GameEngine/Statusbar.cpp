#include "Statusbar.h"



Statusbar::Statusbar()
{
}


Statusbar::~Statusbar()
{
}

void Statusbar::draw()
{
	UIUtils::drawRectangle(Vector2f(16, 756), Vector2f(408, 12), backdrop);
	UIUtils::drawRectangle(Vector2f(20, 760), Vector2f(400, 4), healthColor);

	
	UIUtils::drawRectangle(Vector2f(16, 736), Vector2f(408, 12), backdrop);
	UIUtils::drawRectangle(Vector2f(20, 740), Vector2f(400, 4), staminaColor);
	
	
	UIUtils::drawRectangle(Vector2f(16, 716), Vector2f(408, 12), backdrop);
	UIUtils::drawRectangle(Vector2f(20, 720), Vector2f(400, 4), magicColor);
}

void Statusbar::update(float dt)
{
}

void Statusbar::handleMouseEvents(Mouse & mouse)
{
}

void Statusbar::handleKeyEvents(Keyboard & keyboard)
{
}
