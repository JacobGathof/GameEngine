#pragma once
#include "Effect.h"
#include "Vector2f.h"
#include "Color.h"
#include "Timer.h"

class Light : public Effect
{
public:
	Light(Vector2f& offset, Color& color, Vector2f& sc);
	virtual ~Light();
	virtual void draw();
	virtual bool update(float dt);

	virtual void setActive(bool b);

	void setScale(Vector2f& s);

private:
	Color color;
	Vector2f offset;
	Vector2f scale;

	float decay;
	int direction = 1;
};

