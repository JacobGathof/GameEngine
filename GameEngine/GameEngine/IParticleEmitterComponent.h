#pragma once
#include "IParticle.h"

class IParticleEmitterComponent{
public:
	virtual void setupData(ParticleData& data) = 0;
};


class RandomVelocityComp : public IParticleEmitterComponent {
public:
	RandomVelocityComp(float sp) {
		speed = sp;
	}
	virtual void setupData(ParticleData& data) {
		float r = (float)rand() / RAND_MAX * 2 * 3.14159f;
		data.velocity = speed * Vector2f(cos(r), sin(r));
	}
private:
	float speed;
};


class ColorComp : public IParticleEmitterComponent {
public:
	ColorComp(Color& c) {
		color = c;
	}
	virtual void setupData(ParticleData& data) {
		data.primaryColor = color;
	}
private:
	Color color;
};
