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

	UIUtils::drawRectangle(pos_h			, scale_h				, backdrop);
	UIUtils::drawRectangle(pos_h+barPadding	, scale_h-2*barPadding	, healthColor);

	UIUtils::drawRectangle(pos_s			, scale_s				, backdrop);
	UIUtils::drawRectangle(pos_s+barPadding	, scale_s-2*barPadding	, staminaColor);

	UIUtils::drawRectangle(pos_m			, scale_m				, backdrop);
	UIUtils::drawRectangle(pos_m+barPadding	, scale_m-2*barPadding	, magicColor);

}

void Statusbar::update(float dt)
{
	
}


void Statusbar::resize(int x, int y)
{
	height = y;
	width = x*.4f;

	pos_h = Vector2f(offsetX, height - offsetY - barHeight);
	pos_s = Vector2f(offsetX, height - offsetY - 2 * barHeight - gap);
	pos_m = Vector2f(offsetX, height - offsetY - 3 * barHeight - 2 * gap);

	scale_h = Vector2f(width + 2 * barPadding, barHeight);
	scale_s = Vector2f(width + 2 * barPadding, barHeight);
	scale_m = Vector2f(width + 2 * barPadding, barHeight);
}
