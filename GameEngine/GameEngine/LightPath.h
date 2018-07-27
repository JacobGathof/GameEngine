#pragma once
#include "Effect.h"
#include "BezierSpline.h"
#include "Model.h"

/* Work in progress class, do not use, but keep in mind if we ever need to use something like this */

class LightPath : public Effect
{
public:
	LightPath();
	~LightPath();

	virtual void draw();
	virtual bool update(float dt);

private:
	BezierSpline path;
	Model model;
};

