#pragma once
#include <iostream>
#include "Color.h"
#include "gl3w.h"
#include "Vector2f.h"
#include <fstream>

class ShaderProgram {

private:
	int shader_program;

	enum ShaderType {
		VERTEX,
		GEOMETRY,
		FRAGMENT
	};

public:
	ShaderProgram();
	~ShaderProgram();

	void compileShader(char* file_vertex, char* file_geo, char* file_frag);

	void use();
	
	void loadInteger(char* location, int i);
	void loadFloat(char* location, float f);
	void loadVector2f(char* location, Vector2f &v);
	void loadVector2f(char* location, float x, float y);
	void loadColor(char* location, Color &c);

private:
	void checkCompileErrors(int shader);
	void checkLinkErrors(int program);
	const char* getShaderSource(char* filename);
	void compileShaderFile(char* file, int type);
};

