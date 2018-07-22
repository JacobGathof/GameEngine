#pragma once
#include "Vector2f.h"
#include "Color.h"

class IParticle
{
public:
	IParticle();
	~IParticle();

	virtual void draw() {};
	virtual void update(float dt) {};

protected:
	Vector2f position;
};


class SimpleParticle : public IParticle
{
public:
	SimpleParticle(Vector2f&pos, Vector2f& v, Color& col);
	virtual void update(float dt);
	virtual void draw();

protected:
	Vector2f velocity;
	Color color;
};


class LightParticle : public IParticle
{
public:
	LightParticle(Vector2f& pos, Vector2f& v, Color& col);
	virtual void update(float dt);
	virtual void draw();

protected:
	Vector2f velocity;
	Color color;
};


