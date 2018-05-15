#pragma once
#include "List.h"
#include "Vector2f.h"

class Path
{
public:
	Path();
	Path(List<Vector2f> points);
	Path(float speed);
	Path(List<Vector2f> points, float speed);
	~Path();

	void addPoint(Vector2f point);
	void insertPoint(Vector2f point, int index);
	void runFromStart();
	void runFromHere();
	Vector2f update(float dt);
	Vector2f getCurrentPos();
	Vector2f getTarget();
	void reset();
	void setSpeed(float sp);
	void loop(bool loop);
	bool isFinished();

private:
	List<Vector2f> points;
	Vector2f pos;
	float speed = 600;
	int targetIndex = 0;
	bool looped = false;
	bool finished = false;

};

