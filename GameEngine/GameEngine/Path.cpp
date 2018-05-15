#include "Path.h"



Path::Path()
{
	finished = true;
}

Path::Path(List<Vector2f> pts)
{
	points = pts;
	finished = false;
}

Path::Path(float spd)
{
	speed = spd;
	finished = true;
}

Path::Path(List<Vector2f> pts, float spd)
{
	speed = spd;
	points = pts;
	finished = false;
}


Path::~Path()
{
}

void Path::addPoint(Vector2f point)
{
	points.add(point);
	finished = false;
}

void Path::insertPoint(Vector2f point, int index)
{
	points.add(point, index);
	if (index > targetIndex) {
		finished = false;
	}
}

void Path::runFromStart()
{
	pos = points.get(0);
	targetIndex++;
}

void Path::runFromHere()
{
	targetIndex = 0;
}

Vector2f Path::update(float dt)
{
	if (finished) {
		return pos;
	}
	float moveDist = speed * dt;
	float distToPoint = pos.distanceTo(points.get(targetIndex));
	while (moveDist > distToPoint) {
		moveDist -= distToPoint;
		pos = points.get(targetIndex);
		targetIndex++;
		if (targetIndex > points.size()) {
			if (looped) {
				targetIndex = 0;
			}
			else {
				finished = true;
				return pos;
			}
		}
		distToPoint = pos.distanceTo(points.get(targetIndex));
	}

	Vector2f dir = points.get(targetIndex) - pos;
	pos += dir.normalize() * moveDist;

	return pos;
}

Vector2f Path::getCurrentPos()
{
	return pos;
}

Vector2f Path::getTarget()
{
	return points.get(targetIndex);
}

void Path::reset()
{
	targetIndex = 0;
}

void Path::setSpeed(float sp)
{
	speed = sp;
}

void Path::loop(bool lp)
{
	looped = lp;
}

bool Path::isFinished()
{
	return finished;
}
