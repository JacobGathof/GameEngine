#pragma once
#include "Projectile.h"
#include "BezierSpline.h"


class Boomerang : public Projectile
{
public:
	Boomerang(std::string& name, TextureType t, Vector2f& position, Vector2f& sc, Vector2f& dir, Object* owner);
	~Boomerang();

	void setPoints(Vector2f v1, Vector2f v2, Vector2f v3, Vector2f v4);
	virtual bool update(float dt);
	virtual void onEnterTrigger();
	virtual void onExitTrigger();

protected:
	BezierSpline path;
	bool thrown = false;
};

