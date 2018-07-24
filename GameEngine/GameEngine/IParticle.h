#pragma once
#include "Vector2f.h"
#include "Color.h"
#include "ResourceType.h"


struct ParticleData {
	Vector2f position;
	Vector2f velocity;
	Vector2f acceleration;
	Vector2f scale;
	Color primaryColor, secondaryColor;
	float life;
	TextureType tex;
};



class IParticle
{
public:
	IParticle(ParticleData& data);
	~IParticle();

	virtual void draw() {};
	virtual void update(float dt) {};

protected:
	Vector2f position;
	Vector2f velocity;
	Color color;
	float life;
	float maxLife;
};


class SimpleParticle : public IParticle
{
public:
	SimpleParticle(ParticleData& data);
	virtual void update(float dt);
	virtual void draw();

private:
	

};


class LightParticle : public IParticle
{
public:
	LightParticle(ParticleData& data);
	virtual void update(float dt);
	virtual void draw();

};


