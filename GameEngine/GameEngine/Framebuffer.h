#pragma once
#include "gl3w.h"

class Framebuffer
{
public:
	Framebuffer();
	Framebuffer(unsigned int fb);
	~Framebuffer();
	GLuint fbo;
	GLuint tbo;
	GLuint rbo;
	void bind();
	void updateSize(int x, int y);
};

