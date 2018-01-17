#pragma once
#include "gl3w.h"
#include "lodepng.h"
#include "Vector2f.h"

class Texture
{
public:
	void bind(int offset = 0);

	Texture();
	Texture(char* filename);
	Texture(GLuint t);
	~Texture();

	void getData(float* data);
	void eraseData();

private:
	GLuint tbo;
	int width, height;

};

