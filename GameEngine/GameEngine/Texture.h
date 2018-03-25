#pragma once
#include "gl3w.h"
#include "lodepng.h"
#include "Vector2f.h"

class Texture
{
public:
	void bind(int offset = 0);

	Texture();
	Texture(char* filename, bool enable_mipmap=false);
	Texture(GLuint t);
	virtual ~Texture();

	void getData(float* data);

private:
	GLuint tbo;
	int width, height;

};

