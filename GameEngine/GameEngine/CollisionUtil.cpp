#include "CollisionUtil.h"
#include "RectHitbox.h"
#include "CircleHitbox.h"
#include "ComplexHitbox.h"
#include "Hitbox.h"
#include <math.h>

#include "Object.h"
#include "CollidableComponent.h"
#include "ForceComponent.h"

Vector2f CollisionUtil::shortestResolve;
Object * CollisionUtil::one;
Object * CollisionUtil::two;

CollisionUtil::CollisionUtil()
{
}


CollisionUtil::~CollisionUtil()
{
}

bool CollisionUtil::collide(CircleHitbox& c1, CircleHitbox& c2)
{
	float dist = (c1.getPos() + c1.offset).distanceTo((c2.getPos() + c2.offset));
	float sumRad = c1.shape.radius + c2.shape.radius;
	if (dist < sumRad) {
		return true;
	}

	shortestResolve = (c1.getPos() - c2.getPos()).normalize();

	return false;
}

bool CollisionUtil::collide(RectHitbox& r1, RectHitbox& r2)
{
	float x1 = r1.getPos()[0] - r1.shape.scale[0]/2.0f;
	float y1 = r1.getPos()[1] - r1.shape.scale[1] / 2.0f;
	float xScale1 = r1.shape.scale[0];
	float yScale1 = r1.shape.scale[1];

	float x2 = r2.getPos()[0] - r2.shape.scale[0] / 2.0f;
	float y2 = r2.getPos()[1] - r2.shape.scale[1] / 2.0f;
	float xScale2 = r2.shape.scale[0];
	float yScale2 = r2.shape.scale[1];
	if (x1 < x2 + xScale2 && x2 < x1 + xScale1) {
		if (y1 < y2 + yScale2 && y2 < y1 + yScale1) {
			float dist1 = (x2 + xScale2) - x1;
			if (dist1 < 0) {
				dist1 = 10000;
			}
			float dist2 = (x1 + xScale1) - x2;
			if (dist2 < 0) {
				dist2 = 10000;
			}
			float dist3 = (y2 + yScale2) - y1;
			if (dist3 < 0) {
				dist3 = 10000;
			}
			float dist4 = (y1 + yScale1) - y2;
			if (dist4 < 0) {
				dist4 = 10000;
			}

			float minimum = min(dist1, dist2);
			minimum = min(minimum, dist3);
			minimum = min(minimum, dist4);


			if (minimum == dist1) {
				shortestResolve = Vector2f(1,0);
			}
			else if (minimum == dist2) {
				shortestResolve = Vector2f(-1, 0);
			}
			else if (minimum == dist3) {
				shortestResolve = Vector2f(0, 1);
			}
			else {
				shortestResolve = Vector2f(0, -1);
			}
			return true;
		}
	}
	return false;
}

bool CollisionUtil::collide(ComplexHitbox& c1, ComplexHitbox& c2)
{

	if (!(c1.outerCollide->collide(c2.outerCollide))) {
		return false;
	}

	List<Vector2f> normals = c1.shape->normals;
	List<Vector2f> vert1 = c1.shape->getVertices();
	List<Vector2f> vert2 = c2.shape->getVertices();

	for (int i = 0; i < normals.size(); i++) {
		bool instFound = false;
		for (int k = 0; k < vert2.size(); k++) {
			Vector2f p1 = vert1.get(i);
			Vector2f norm = normals.get(i);
			Vector2f p2 = vert2.get(k);
			float val = (p2 - p1).dot(norm);
			if (val < 0) {
				instFound = true;
				break;
			}
		}
		if (!instFound) {
			
			return false;
		}
	}
	
	return true;
}

bool CollisionUtil::collide(CircleHitbox& c1, RectHitbox& r1)
{

	float distX = abs(c1.getPos()[0] - r1.getPos()[0]);
	float distY = abs(c1.getPos()[1] - r1.getPos()[1]);

	shortestResolve = Vector2f(distX, distY).normalize();

	if (distX > r1.shape.scale[0] / 2 + c1.shape.radius) {
		return false;
	}
	else if (distY > r1.shape.scale[1] / 2 + c1.shape.radius) {
		return false;
	}
	else if (distX < r1.shape.scale[0] / 2) {
		return true;
	}
	else if (distY < r1.shape.scale[1] / 2) {
		return true;
	}

	float distCorner = r1.getPos().distanceTo(r1.getPos() + Vector2f(r1.shape.scale[0] / 2, r1.shape.scale[1] / 2));
	return distCorner <= pow(c1.shape.radius,2);
}

bool CollisionUtil::collide(CircleHitbox& c1, ComplexHitbox& c2)
{

	if (!c1.collide(c2.outerCollide)) {
		return false;
	}

	List<Vector2f> normals = c2.shape->normals;
	List<Vector2f> vert1 = c2.shape->getVertices();
	List<Vector2f> vert2;

	Circle shape = c1.shape;

	Vector2f p1 = shape.center + Vector2f(shape.radius, 0);
	Vector2f p2 = shape.center - Vector2f(shape.radius, 0);
	Vector2f p3 = shape.center + Vector2f(0,shape.radius);
	Vector2f p4 = shape.center - Vector2f(0, shape.radius);
	Vector2f p5 = shape.center + Vector2f(sqrt(2)/2.0f * shape.radius, sqrt(2) / 2.0f * shape.radius);
	Vector2f p6 = shape.center + Vector2f(-sqrt(2) / 2.0f * shape.radius, sqrt(2) / 2.0f * shape.radius);
	Vector2f p7 = shape.center + Vector2f(sqrt(2) / 2.0f * shape.radius, -sqrt(2) / 2.0f * shape.radius);
	Vector2f p8 = shape.center - Vector2f(sqrt(2) / 2.0f * shape.radius, sqrt(2) / 2.0f * shape.radius);

	vert2.add(p1);
	vert2.add(p2);
	vert2.add(p3);
	vert2.add(p4);
	vert2.add(p5);
	vert2.add(p6);
	vert2.add(p7);
	vert2.add(p8);


	for (int i = 0; i < normals.size(); i++) {
		bool instFound = false;
		for (int k = 0; k < vert2.size(); k++) {
			Vector2f p1 = vert1.get(i);
			Vector2f norm = normals.get(i);
			Vector2f p2 = vert2.get(k);
			float val = (p2 - p1).dot(norm);
			if (val < 0) {
				instFound = true;
				break;
			}
		}
		if (!instFound) {

			return false;
		}
	}
	return true;
}

bool CollisionUtil::collide(RectHitbox& r1, ComplexHitbox& c1)
{
	if (!r1.collide(c1.outerCollide)) {
		return false;
	}

	List<Vector2f> normals = c1.shape->normals;
	List<Vector2f> vert1 = c1.shape->getVertices();
	List<Vector2f> vert2 = r1.getShape()->getVertices();

	for (int i = 0; i < normals.size(); i++) {
		bool instFound = false;
		for (int k = 0; k < vert2.size(); k++) {
			Vector2f p1 = vert1.get(i);
			Vector2f norm = normals.get(i);
			Vector2f p2 = vert2.get(k);
			float val = (p2 - p1).dot(norm);
			if (val < 0) {
				instFound = true;
				break;
			}
		}
		if (!instFound) {

			return false;
		}
	}
	return true;
}

bool CollisionUtil::equalResolve(Object * o1, Object * o2, float bounciness)
{
	CollidableComponent* comp1 = o1->getComponent<CollidableComponent>();
	CollidableComponent* comp2 = o2->getComponent<CollidableComponent>();
	
	/*
	while (comp1->getHitbox(0)->collide(comp2->getHitbox(0))) {
		Vector2f dir = (o1->pos - o2->pos).normalize();
		o1->pos += dir * bounciness / 2.0f;
		o2->pos -= dir * bounciness / 2.0f;

		comp1->updateHitbox();
		comp2->updateHitbox();
	}
	*/

	Vector2f dir = (o1->pos - o2->pos);
	float length = dir.length();
	dir = dir.normalize();
	o1->pos += dir * (256 - length) / 2;
	o2->pos -= dir * (256 - length) / 2;

	comp1->updateHitbox();
	comp2->updateHitbox();
	
	applyForce(o1, o2);

	return false;
}

bool CollisionUtil::unequalResolve(Object * o1, Hitbox * h2, float bounciness)
{
	/*
	CollidableComponent* comp1 = o1->getComponent<CollidableComponent>();
	CollidableComponent* comp2 = o2->getComponent<CollidableComponent>();

	while (o1->getHitbox(0)->collide(h2)) {
		Vector2f dir = shortestResolve;
		if (o1 == two) {
			dir = Vector2f(-dir[0], -dir[1]);
		}
		
		o1->pos += dir * bounciness;
		
		o1->updateHitbox();
	}
	*/
	return false;
}

bool CollisionUtil::unequalResolve(Object * o1, Object * o2, float bounciness)
{
	CollidableComponent* comp1 = o1->getComponent<CollidableComponent>();
	CollidableComponent* comp2 = o2->getComponent<CollidableComponent>();

	/*
	while (comp1->getHitbox(0)->collide(comp2->getHitbox(0))) {
		Vector2f dir = (o1->pos - o2->pos).normalize();
		o1->pos += dir * bounciness;

		comp1->updateHitbox();
		comp2->updateHitbox();
	}
	*/

	Vector2f dir = (o1->pos - o2->pos);
	float length = dir.length();
	dir = dir.normalize();
	
	//TODO: Fix This To not assume Circles
	o1->pos += dir * (2*((CircleHitbox*)o2->getComponent<CollidableComponent>()->getHitbox())->shape.radius - length);

	comp1->updateHitbox();
	comp2->updateHitbox();
	
	return false;
}

void CollisionUtil::applyForce(Object * o1, Object * o2)
{
	if (o1->hasTrait<ForceComponent>() && o2->hasTrait<ForceComponent>()) {
		ForceComponent* comp1 = o1->getComponent<ForceComponent>();
		ForceComponent* comp2 = o2->getComponent<ForceComponent>();

		Force f1 = comp1->getTotalForce();
		Force f2 = comp2->getTotalForce();

		//comp1->addForce(new Force(f2.value));
		//comp2->addForce(new Force(f1.value));

		Vector2f dir = -1*(o1->pos - o2->pos);
		comp2->addForce(new Force(dir.normalize() * 64));

	}

}
