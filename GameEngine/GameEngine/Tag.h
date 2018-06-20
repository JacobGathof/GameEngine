#pragma once
#include "Effect.h"
#include "Vector2f.h"
#include <string>

class Text;

class Tag : public Effect
{
public:
	Tag(std::string& name, Vector2f& offset);
	virtual ~Tag();
	virtual void draw();
	virtual bool update(float dt);

	void increasePosition(Vector2f& v);

protected:
	Vector2f offset;

private:
	Text * text;

};

