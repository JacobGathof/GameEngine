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

void Screen::init(){
	updateShaders();
}

void Screen::updateRes(float x, float y){
	width = x;
	height = y;
	updateShaders();
}

void Screen::updateScroll(float f){
	scrollMultiplier += f;
	scrollMultiplier = max(1, min(scrollMultiplier, 4));
	updateShaders();
}

void Screen::updateShaders(){
	for (ShaderType st : worldShaders) {
		Res::get(st)->bind();
		Res::get(st)->loadVector2f("dim", scrollMultiplier*Vector2f(width, height));
		Res::get(st)->loadFloat("aspect_ratio", (float)width / height);
	}
}
