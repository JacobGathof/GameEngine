#pragma once
#include "gl3w.h"

class Framebuffer
{
public:
	Framebuffer();
	Framebuffer(unsigned int fb);
	~Framebuffer();
	void bind();
	void bindTexture(int offset = 0);
	void updateSize(int x, int y);

private:
	GLuint fbo;
	GLuint tbo;
	GLuint rbo;
};

