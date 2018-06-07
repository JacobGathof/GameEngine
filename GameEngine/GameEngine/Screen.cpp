#include "Screen.h"
#include "UIManager.h"

#define SCALE_FACTOR 1

float Screen::width = 800;
float Screen::height = 800;
float Screen::scrollMultiplier = 1.0f*SCALE_FACTOR;
Vector2f Screen::offset;
Color Screen::screenColor;
float Screen::screenColorPercent;


Vector2f* Screen::target;
void(*Screen::behaviorPtr)(float dt) = nullBehavior;


Screen::Screen(){}
Screen::~Screen(){}

void Screen::init(){}

void Screen::updateRes(float x, float y){
	width = x/ SCALE_FACTOR;
	height = y/ SCALE_FACTOR;
	Res::updateFramebufferSizes(x / SCALE_FACTOR, y / SCALE_FACTOR);
	UIManager::resize(x / SCALE_FACTOR, y / SCALE_FACTOR);
}

void Screen::updateScroll(float f){
	scrollMultiplier += f;
	scrollMultiplier = max(.1f, min(scrollMultiplier, 4));
}

void Screen::updateUniforms()
{
	Vector2f v = 2.0f * Vector2f(1.0f, 1.0f) / (Vector2f(width, height));
	Res::uploadGlobalUniform("ui_scale", v);

	Res::uploadGlobalUniform("camera_translate", offset);
	Res::uploadGlobalUniform("camera_scale", Vector2f(1, 1) / Vector2f(scrollMultiplier * Vector2f(width, height)));

}

Vector2f Screen::toScreenCoords(Vector2f translate)
{
	return (translate-offset) / (scrollMultiplier * Vector2f(width, height));
}

Vector2f Screen::toScreenCoordsUI(Vector2f translate)
{
	return 2 * translate / (Vector2f(width, height));
}

Vector2f Screen::toScreenScale(Vector2f scale)
{
	return scale / (scrollMultiplier * Vector2f(width, height));
}

Vector2f Screen::fromScreenToUISpace(Vector2f pos)
{
	return Vector2f(pos[0], height-pos[1]);
}

void Screen::followBehavior(float dt)
{
	float dist = offset.distanceTo(*target);
	offset += (*target-offset).normalize() * (dist)/50;
}

void Screen::nullBehavior(float dt){}

void Screen::update(float dt){
	behaviorPtr(dt);
}

void Screen::setMovementBehavior(void(*fcn)(float dt)){
	behaviorPtr = fcn;
}

void Screen::setTargetPosition(Vector2f * vec)
{
	target = vec;
}

void Screen::setPosition(Vector2f& pos)
{
	offset = pos;
}


void Screen::moveToBehavior(float dt)
{
	offset = *target;
}
