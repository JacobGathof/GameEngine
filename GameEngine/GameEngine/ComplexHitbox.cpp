#include "ComplexHitbox.h"
#include "CircleHitbox.h"
#include "RectHitbox.h"



ComplexHitbox::ComplexHitbox(ComplexPolygon* p, Vector2f off)
{
	shape = p;

	List<Vector2f> verts = shape->getVertices();

	float maxX = verts.get(0)[0];
	float minX = verts.get(0)[0];
	float maxY = verts.get(0)[1];
	float minY = verts.get(0)[1];
	
	for (int i = 1; i < verts.size(); i++) {
		Vector2f vert = verts.get(i);
		if (vert[0] > maxX) {
			maxX = vert[0];
		}
		else if (vert[0] < minX) {
			minX = vert[0];
		}

		if (vert[1] > maxY) {
			maxY = vert[1];
		}
		else if (vert[1] < minY) {
			minY = vert[1];
		}
	}
	Vector2f dif = Vector2f(maxX - minX, maxY - minY);
	outerCollide = new RectHitbox(Rect(Vector2f((maxX - minX)/2, (maxY - minY)/2),dif), off + Vector2f(0,dif[1]/2));



	offset = off;
}

ComplexHitbox::~ComplexHitbox()
{
	delete outerCollide;
	delete shape;
}

void ComplexHitbox::updatePos(Vector2f p)
{
	pos = p + offset;
	outerCollide->updatePos(p);
	shape->updatePos(pos);
}

bool ComplexHitbox::collide(Hitbox * s)
{
	return s->collide(this);
}

bool ComplexHitbox::collide(CircleHitbox * h)
{
	return CollisionUtil::collide(*h,*this);
}

bool ComplexHitbox::collide(RectHitbox * h)
{
	return CollisionUtil::collide(*h,*this);
}

bool ComplexHitbox::collide(ComplexHitbox * h)
{
	return CollisionUtil::collide(*h,*this);
}

void ComplexHitbox::draw()
{
	outerCollide->draw();
	

	shape->draw();
}

Shape * ComplexHitbox::getShape()
{
	return shape;
}
