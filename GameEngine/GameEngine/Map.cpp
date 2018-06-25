#include "Map.h"




Map::Map()
{
	position = Vector2f(600,600);
	scale = Vector2f(190,190);
}

Map::~Map()
{
}

void Map::draw()
{
	UIUtils::drawRectangle(position, scale, Color::Red);
	UIUtils::drawRectangle(position+Vector2f(2,2), scale-Vector2f(4,4), Color(0x00000000));

}

void Map::handleMouseEvents(Mouse & mouse)
{
}

void Map::handleKeyEvents(Keyboard & keyboard)
{
}

void Map::update(float dt)
{
}
