#pragma once
#include "Effect.h"
#include "Vector2f.h"
#include <string>

class Text;

class Tag : public Effect
{
public:
	Tag(std::string& name, Vector2f& offset);
	~Tag();
	virtual void draw();
	virtual void update(float dt);

private:
	Text * text;
	Vector2f offset;
};

