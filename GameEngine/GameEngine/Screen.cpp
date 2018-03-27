#include "Screen.h"
#include "UIManager.h"

float Screen::width = 800;
float Screen::height = 800;
float Screen::scrollMultiplier = 1.0f;
float Screen::x_offset;
float Screen::y_offset;
Vector2f Screen::offset;
Color Screen::screenColor;
float Screen::screenColorPercent;

Screen::Screen()
{
}

Screen::~Screen()
{
}

void Screen::init(){}

void Screen::updateRes(float x, float y){
	width = x;
	height = y;
	Res::updateFramebufferSizes(x,y);
	UIManager::resize(x, y);
}

void Screen::updateScroll(float f){
	scrollMultiplier += f;
	scrollMultiplier = max(1, min(scrollMultiplier, 4));
}

void Screen::updateUniforms()
{
	Vector2f v = 2.0f * Vector2f(1.0f, 1.0f) / (Vector2f(width, height));
	Res::uploadGlobalUniform("camera_scale", v);

	Res::get(ShaderType::ANIMATED_SHADER)->bind();
	Res::get(ShaderType::ANIMATED_SHADER)->loadVector2f("camera_translate", offset);
	Res::get(ShaderType::ANIMATED_SHADER)->loadVector2f("camera_scale", Vector2f(1, 1) / Vector2f(scrollMultiplier * Vector2f(width, height)));


	Res::get(ShaderType::BASIC_SHADER)->bind();
	Res::get(ShaderType::BASIC_SHADER)->loadVector2f("camera_translate", offset);
	Res::get(ShaderType::BASIC_SHADER)->loadVector2f("camera_scale", Vector2f(1,1)/Vector2f(scrollMultiplier * Vector2f(width, height)));

	Res::get(ShaderType::TERRAIN_SHADER)->bind();
	Res::get(ShaderType::TERRAIN_SHADER)->loadVector2f("camera_translate", offset);
	Res::get(ShaderType::TERRAIN_SHADER)->loadVector2f("camera_scale", Vector2f(1, 1) / Vector2f(scrollMultiplier * Vector2f(width, height)));


	Res::get(ShaderType::RECTANGLE_SHADER)->bind();
	Res::get(ShaderType::RECTANGLE_SHADER)->loadVector2f("camera_translate", offset);
	Res::get(ShaderType::RECTANGLE_SHADER)->loadVector2f("camera_scale", Vector2f(1, 1) / Vector2f(scrollMultiplier * Vector2f(width, height)));
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

void Screen::follow(Vector2f playerPos)
{
	float dist = offset.distanceTo(playerPos);
	offset += (playerPos-offset).normalize() * (dist)/50;
}
