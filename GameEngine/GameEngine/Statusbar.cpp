#include "Statusbar.h"
#include "Screen.h"


Statusbar::Statusbar()
{
}


Statusbar::~Statusbar()
{
}

void Statusbar::draw()
{

	UIUtils::drawRectangle(Vector2f(offsetX, topOfScreen - offsetY - barHeight), Vector2f(width+2*barPadding, barHeight), backdrop);
	UIUtils::drawRectangle(Vector2f(offsetX+barPadding, topOfScreen - offsetY - barHeight + barPadding), Vector2f(width, barHeight-2*barPadding), healthColor);

	
	UIUtils::drawRectangle(Vector2f(offsetX, topOfScreen - offsetY - 2*barHeight - gap), Vector2f(width + 2 * barPadding, barHeight), backdrop);
	UIUtils::drawRectangle(Vector2f(offsetX + barPadding, topOfScreen - offsetY - 2*barHeight - gap + barPadding), Vector2f(width, barHeight - 2 * barPadding), staminaColor);
	
	
	UIUtils::drawRectangle(Vector2f(offsetX, topOfScreen - offsetY - 3*barHeight - 2*gap), Vector2f(width + 2 * barPadding, barHeight), backdrop);
	UIUtils::drawRectangle(Vector2f(offsetX + barPadding, topOfScreen - offsetY - 3 * barHeight - 2 * gap + barPadding), Vector2f(width, barHeight - 2 * barPadding), magicColor);
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

void Statusbar::resize(int x, int y)
{
	topOfScreen = y;
	width = x * .35f;
}
