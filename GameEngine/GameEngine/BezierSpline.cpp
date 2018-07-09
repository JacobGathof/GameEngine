#include "BezierSpline.h"
#include "ResourceManager.h"


BezierSpline::BezierSpline()
{
	p1 = Vector2f(0, 0);
	p2 = Vector2f(0, 0);
	p3 = Vector2f(0, 0);
	p4 = Vector2f(0, 0);
}

BezierSpline::BezierSpline(Vector2f & q1, Vector2f & q2, Vector2f & q3, Vector2f & q4)
{
	p1 = q1;
	p2 = q2;
	p3 = q3;
	p4 = q4;
}

BezierSpline::~BezierSpline()
{
}

void BezierSpline::draw()
{
	ShaderProgram* p = Res::get(ShaderType::LINE_SHADER);
	p->bind();
	p->loadVector2f("translate", Vector2f(0,0));
	p->loadVector2f("scale", Vector2f(1,1));

	for (int i = 0; i < 40; i++) {
		float t1 = (i)/40.0f;
		float t2 = (i+1)/40.0f;

		p->loadVector2f("points[0]", positionAt(t1));
		p->loadVector2f("points[1]", positionAt(t2));

		glDrawArrays(GL_LINES, 0, 2);
	}

}

Vector2f BezierSpline::positionAt(float t)
{
	float tt = 1 - t;
	return tt * tt*tt*p1 + 3 * tt*tt*t*p2 + 3 * tt*t*t*p3 + t * t*t*p4;
}

Vector2f BezierSpline::velocityAt(float t)
{
	float tt = 1 - t;
	return 3 * tt*tt*(p2 - p1) + 6 * tt*t*(p3 - p2) + 3 * t*t*(p4 - p3);
}

Vector2f BezierSpline::accelerationAt(float t)
{
	float tt = 1 - t;
	return 6 * tt*(p3 - 2*p2 + p1) + 6 * t*(p4 - 2*p3 + p2) ;
}
