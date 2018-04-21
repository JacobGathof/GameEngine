#pragma once
#include <iostream>
#include "Color.h"
#include "gl3w.h"
#include "Vector2f.h"

class ShaderProgram {

private:
	int shader_program;

public:
	ShaderProgram();
	~ShaderProgram();

	void compileShader(char* file_vertex, char* file_frag);
	void compileShader(char* file_compute);
	void compileFeedbackShader(char* file_vertex, char* file_frag, const GLchar* varying[], int length);

	void bind();
	
	void loadInteger(char* location, int i);
	void loadFloat(char* location, float f);
	void loadVector2f(char* location, Vector2f &v);
	void loadVector2f(char* location, float x, float y);
	void loadColor(char* location, Color &c);

private:
	void checkCompileErrors(int shader, char* file);
	void checkLinkErrors(int program);
	const char* getShaderSource(char* filename);
	void compileShaderFile(char* file, int type);
};

