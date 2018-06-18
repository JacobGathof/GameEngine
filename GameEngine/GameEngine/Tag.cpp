#include "Tag.h"
#include "Text.h"
#include "Object.h"

Tag::Tag(std::string & name, Vector2f& off) : Effect()
{
	text = new Text(Vector2f(0, 0), name, Vector2f(30), 0);
	text->setColor(Color::White);
	text->setWorldRelative(true);
	offset = off;
}

Tag::~Tag(){

	delete text;
}

void Tag::draw()
{
	text->draw();
}

void Tag::update(float dt)
{
	text->setPosition(offset + parent->pos);
	text->center();
}
