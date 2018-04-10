#pragma once
#include "Model.h"
#include <vector>
#include "Vector2f.h"
#include "List.h"

struct ShadowPoint {
	Vector2f v;
	float in;
};

struct Segment {
	Vector2f start;
	Vector2f end;
};

class ShadowMap
{
public:
	ShadowMap();
	~ShadowMap();

	void calculateShadowMap(Vector2f& pos);
	void drawShadows();
	void testRay(Vector2f vec, Vector2f pos);

private:
	Model model;
	unsigned int vbo_pos;
	unsigned int vbo_int;

	std::vector<ShadowPoint> points;
	List<Segment> lineSegments;
};

