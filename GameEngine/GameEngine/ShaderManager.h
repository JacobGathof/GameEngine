#pragma once
#include <map>
#include "ShaderProgram.h"


enum class ShaderType {
	ANIMATED_SHADER,
	TEXT_SHADER,
	BASIC_SHADER,
	PARTICLE_SHADER,
	PARTICLE_FAST_SHADER,
	UI_SOLID_SHADER,
	UI_IMAGE_SHADER,
	TERRAIN_SHADER,
	CIRCLE_SHADER,
	POST_PROCESS_SHADER,
	RECTANGLE_SHADER,
};


class ShaderManager
{
public:

	static void init();
	static void clean();
	static ShaderProgram* get(ShaderType type);
	static void uploadAll(char* location, Vector2f& v2);

private:

	static void addShader(ShaderType shader, char* v, char* g, char* f);
	static void addShader(ShaderType shader, char* v, char* g, char* f, const GLchar* varying[], int length);
	static std::map<ShaderType, ShaderProgram*> shaders;

};

