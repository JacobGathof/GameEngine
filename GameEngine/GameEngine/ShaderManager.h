#pragma once
#include <map>
#include "ShaderProgram.h"


enum class Shader {
	TEXT_SHADER
};


class ShaderManager
{
public:

	static void init();
	static void clean();
	static ShaderProgram* get(Shader type);

private:

	static void addShader(Shader shader, char* v, char* g, char* f);
	static std::map<Shader, ShaderProgram*> shaders;

};

