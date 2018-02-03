#include "Circle.h"
#include "Screen.h"


bool Circle::contains(Vector2f & pt)
{
	return (center-pt).lengthSquared() < radius*radius;
}

Circle::Circle(Vector2f& c, float rad){
	center = c;
	radius = rad;
}


Circle::~Circle()
{
}

void Circle::draw(float gt){
	ShaderProgram* shader = Res::get(ShaderType::CIRCLE_SHADER);
	Model * model = Res::get(ModelType::MODEL_SQUARE_CENTERED);

	model->bind();
	shader->bind();
	shader->loadVector2f("translate", Screen::toScreenCoords(center));
	shader->loadVector2f("scale", 3*abs(cos(gt))*Screen::toScreenScale(Vector2f(radius, radius)));
	shader->loadFloat("gt", 1.0f);
	model->draw();
}
