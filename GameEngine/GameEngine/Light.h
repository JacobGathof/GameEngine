#pragma once
#include "Effect.h"
#include "Vector2f.h"
#include "Color.h"

class Light : public Effect
{
public:
	Light(Vector2f& offset, Color& color);
	virtual ~Light();
	virtual void draw();
	virtual bool update(float dt);

private:
	Color color;
	Vector2f offset;
};

