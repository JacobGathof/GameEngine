#include "Object.h"
#include "ResourceManager.h"
#include "AnimatedComponent.h"
#include "CollidableComponent.h"
#include "InteractableComponent.h"

int Object::numCreated = 0;
int Object::numDeleted = 0;

Object::Object(std::string& n, TextureType t, Vector2f& position, Vector2f& sc)
{
	texture = t;
	pos = position;
	scale = sc;
	name = n;

	numCreated++;
}

Object::Object(ObjectData & data)
{
	texture = data.tex;
	pos = data.position;
	scale = data.scale;
	name = data.name;

	numCreated++;
}


Object::~Object()
{
	numDeleted++;


	for (auto a : map) {
		delete a.second;
	}

}

void Object::draw()
{	
	ShaderProgram* p = Res::get(ShaderType::ANIMATED_SHADER);
	SpriteSheet* sh = Res::get(texture);
	Model * m = Res::get(ModelType::MODEL_SQUARE_CENTERED);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	m->bind();
	sh->bind();

	p->bind();
	p->loadVector2f("translate", pos);
	p->loadVector2f("scale", scale);
	p->loadColor("color", color);

	p->loadInteger("rows", sh->rows);
	p->loadInteger("columns", sh->columns);

	p->loadInteger("currentRow", 0);
	p->loadInteger("currentColumn", 0);
	if (hasTrait<AnimatedComponent>()) {
		p->loadInteger("currentRow", getComponent<AnimatedComponent>()->animationRow);
		p->loadInteger("currentColumn", getComponent<AnimatedComponent>()->animationColumn);
	}

	p->loadInteger("selected", selected);
	p->loadFloat("rotation", rotation);
	p->loadFloat("height", height);
	p->loadInteger("uniformDepth", uniformDepth);

	m->draw();
	

	if (hasTrait<CollidableComponent>()) {
		getComponent<CollidableComponent>()->drawHitboxes();
	}

	if (hasTrait<InteractableComponent>()) {
		getComponent<InteractableComponent>()->draw();
	}

}





void Object::drawInverted()
{
	Vector2f oPos = pos;
	Vector2f oScale = scale;

	pos -= Vector2f(0, scale[1]+2*height);
	scale *= Vector2f(1, -1);

	draw();

	pos = oPos;
	scale = oScale;

}

void Object::drawNegative()
{
	Color temp = color;

	color = Color(0,0,0,0);

	draw();

	color = temp;


}

void Object::eraseProjection(Vector2f & center, float radius)
{

	eraseHelper(pos + Vector2f(scale.x, scale.y), pos + Vector2f(scale.x, -scale.y), center, radius);
	eraseHelper(pos + Vector2f(scale.x, -scale.y), pos + Vector2f(-scale.x, -scale.y), center, radius);
	eraseHelper(pos + Vector2f(-scale.x, -scale.y), pos + Vector2f(-scale.x, scale.y), center, radius);
	eraseHelper(pos + Vector2f(-scale.x, scale.y), pos + Vector2f(scale.x, scale.y), center, radius);

	eraseHelper(pos + Vector2f(-scale.x, -scale.y), pos + Vector2f(scale.x, scale.y), center, radius);
	eraseHelper(pos + Vector2f(scale.x, -scale.y), pos + Vector2f(-scale.x, scale.y), center, radius);
}

void Object::eraseHelper(Vector2f & first, Vector2f & second, Vector2f& center, float radius)
{
	Vector2f points[4];
	points[0] = first;
	points[1] = second;
	points[2] = (first - center).normalize() * radius * 2;
	points[3] = (second - center).normalize() * radius * 2;


	ShaderProgram* p = Res::get(ShaderType::SHADOW_SHADER);
	Model * m = Res::get(ModelType::MODEL_SQUARE_CENTERED);

	m->bind();

	p->bind();
	p->loadVector2f("translate", Vector2f(0,0));
	p->loadVector2f("scale", Vector2f(1,1));

	p->loadVector2f("vertices[0]", points[0]);
	p->loadVector2f("vertices[1]", points[1]);
	p->loadVector2f("vertices[2]", points[2]);
	p->loadVector2f("vertices[3]", points[0]);
	p->loadVector2f("vertices[4]", points[1]);
	p->loadVector2f("vertices[5]", points[3]);

	m->draw();

	

	m->draw();
}


void Object::destroy(){
	alive = false;
}

bool Object::update(float dt)
{

	for (auto a : map) {
		a.second->update(dt);
	}

	return alive;
}





