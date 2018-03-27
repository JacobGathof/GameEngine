#include "EnemyStatusbar.h"



EnemyStatusbar::EnemyStatusbar()
{
	text = new Text(Vector2f(0,0), std::string("The Moon"), Vector2f(0,0), 0);
}


EnemyStatusbar::~EnemyStatusbar()
{
	delete text;
}

void EnemyStatusbar::draw()
{
	UIUtils::drawRectangle(pos_h, scale_h, backdrop);
	UIUtils::drawRectangle(pos_h + barPadding, scale_h - 2 * barPadding, healthColor);

	text->draw();
}

void EnemyStatusbar::update(float dt)
{
}

void EnemyStatusbar::resize(int x, int y)
{
	height = y;
	width = x - 2*offsetX - 2*barPadding;
	
	pos_h = Vector2f(offsetX, offsetY);
	scale_h = Vector2f(width + 2 * barPadding, barHeight);

	text->setPosition(pos_h+Vector2f(barPadding, barHeight));
	text->setColor(Color::White);
	text->setScale(Vector2f(30, 30));
}
