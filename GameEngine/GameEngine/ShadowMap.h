#pragma once
#include "Model.h"
#include <vector>
#include "Vector2f.h"

class ShadowMap
{
public:
	ShadowMap();
	~ShadowMap();

	void calculateShadowMap(Vector2f& pos);
	void drawShadows();

private:
	Model model;
	unsigned int vbo_pos;
	unsigned int vbo_intensity;

	std::vector<Vector2f> pos;
	std::vector<float> itn;
};

