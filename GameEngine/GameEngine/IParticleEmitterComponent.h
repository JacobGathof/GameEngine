#pragma once
#include "IParticle.h"

class IParticleEmitterComponent{
public:
	virtual void setupData(ParticleData& data) = 0;
};


class RandomVelocityComp : public IParticleEmitterComponent {
public:
	virtual void setupData(ParticleData& data) {
		float r = (float)rand() / RAND_MAX * 2 * 3.14159f;
		data.velocity = Vector2f(cos(r), sin(r));
	}
};

class DirectedVelocityComp : public IParticleEmitterComponent {
public:
	DirectedVelocityComp(float f1, float f2) {
		min = f1;
		max = f2;
	}

	virtual void setupData(ParticleData& data) {
		//Radians, where 0 is straight up
		float f = (float)rand() / RAND_MAX * (max - min) + min;
		data.velocity = Vector2f(sin(f), cos(f));
	}
private:
	float min, max;
};


class ColorComp : public IParticleEmitterComponent {
public:
	ColorComp(Color& c, Color& c2) {
		color = c;
		color2 = c2;
	}
	ColorComp(Color& c) {
		color = c;
		color2 = c;
	}
	virtual void setupData(ParticleData& data) {
		Color c = Color::blend(color, color2, (float)rand() / RAND_MAX);
		data.primaryColor = c;
	}
private:
	Color color, color2;
};


class RandColorComp : public IParticleEmitterComponent {
public:
	virtual void setupData(ParticleData& data) {
		float r = (float)rand() / RAND_MAX;
		float g = (float)rand() / RAND_MAX;
		float b = (float)rand() / RAND_MAX;
		data.primaryColor = Color(r,g,b,1);
	}
};


class PosSpreadComp : public IParticleEmitterComponent {
public:
	PosSpreadComp(float si) {
		size = si;
	}
	virtual void setupData(ParticleData& data) {
		float r = (float)rand() / RAND_MAX * 2 * 3.14159f;
		data.position += size*Vector2f(cos(r), sin(r));
	}
private:
	float size;
};


class SpeedComp : public IParticleEmitterComponent {
public:
	SpeedComp(float f1, float f2) {
		speed1 = f1;
		speed2 = f2;
	}
	SpeedComp(float f1) {
		speed1 = f1;
		speed2 = f1;
	}
	virtual void setupData(ParticleData& data) {
		float f = (float)rand() / RAND_MAX * (speed2 - speed1) + speed1;
		data.velocity *= f;
	}
private:
	float speed1, speed2;
};

