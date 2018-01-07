#pragma once
#include <map>
#include "ShaderProgram.h"


enum class ShaderType {
	TEXT_SHADER,
	BASIC_SHADER
};


class ShaderManager
{
public:

	static void init();
	static void clean();
	static ShaderProgram* get(ShaderType type);

private:

	static void addShader(ShaderType shader, char* v, char* g, char* f);
	static std::map<ShaderType, ShaderProgram*> shaders;

};

