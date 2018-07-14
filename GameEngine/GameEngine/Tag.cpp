#include "Tag.h"
#include "Text.h"
#include "Object.h"

Tag::Tag(std::string & name, Vector2f& off) : Effect()
{
	text = new Text(Vector2f(0, 0), name, Vector2f(30), 0);
	text->setColor(Color::Black);
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

bool Tag::update(float dt)
{
	text->setPosition(offset + parent->pos);
	text->center();
	return true;
}

void Tag::increasePosition(Vector2f & v)
{

}
