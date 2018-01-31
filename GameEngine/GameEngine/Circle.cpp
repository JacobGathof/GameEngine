#include "Circle.h"



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
	shader->loadVector2f("translate", center);
	shader->loadVector2f("scale", Vector2f(radius, radius));
	shader->loadFloat("radius", abs(cos(gt/3)));
	shader->loadFloat("gt", .5f);
	model->draw();
}
