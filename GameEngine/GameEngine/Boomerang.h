#pragma once
#include "Projectile.h"
#include "BezierSpline.h"


class Boomerang : public Projectile
{
public:
	Boomerang(ObjectData& data, Vector2f& dir, Object* owner);
	~Boomerang();

	void setPoints(Vector2f v1, Vector2f v2, Vector2f v3, Vector2f v4);
	virtual bool update(float dt);
	virtual void onEnterTrigger();
	virtual void onExitTrigger();

protected:
	BezierSpline path;
	bool thrown = false;
};

