#include "Screen.h"

float Screen::width = 800;
float Screen::height = 800;
float Screen::scrollMultiplier = 1.0f;
ShaderType Screen::worldShaders[]{ ShaderType::BASIC_SHADER, ShaderType::TERRAIN_SHADER};

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
}

void Screen::updateScroll(float f){
	scrollMultiplier += f;
	scrollMultiplier = max(1, min(scrollMultiplier, 4));
}

Vector2f Screen::toScreenCoords(Vector2f scale)
{
	return scale / (scrollMultiplier * Vector2f(width, height));
}
