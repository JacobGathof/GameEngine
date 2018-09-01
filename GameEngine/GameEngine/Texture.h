#pragma once
#include "gl3w.h"
#include "lodepng.h"
#include "Vector2f.h"

struct ResourceData {
	unsigned char* data;
	int size;
};

class Texture
{
public:

	void bind(int offset = 0);

	Texture();
	Texture(char* filename, bool enable_mipmap=false);
	Texture(GLuint t);
	virtual ~Texture();

	void getData(float* data);
	ResourceData getDataFromResource();

private:
	GLuint tbo;
	int width, height;

};

