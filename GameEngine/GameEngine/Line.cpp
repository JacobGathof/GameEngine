#include "Line.h"
#include "ResourceManager.h"

Line::Line(Vector2f & v1, Vector2f & v2)
{
	p1 = v1;
	p2 = v2;
}

Line::~Line()
{
}

bool Line::contains(Vector2f & pt)
{
	return p1[0]*(p2[1]-pt[1]) + p2[0]*(pt[1] - p1[1]) + pt[0]*(p1[1] - p2[1]) == 0;
}

void Line::draw()
{
	ShaderProgram* p = Res::get(ShaderType::FRACTAL_SHADER);
	p->bind();
	p->loadVector2f("translate", Vector2f(0, 0));
	p->loadVector2f("scale", Vector2f(1, 1));

	p->loadVector2f("points[0]", p1);
	p->loadVector2f("points[1]", p2);

	glDrawArrays(GL_LINES, 0, 2);

}
