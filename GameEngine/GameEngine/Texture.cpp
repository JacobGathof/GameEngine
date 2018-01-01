#include "Texture.h"


void Texture::bind(int offset)
{
	glActiveTexture(GL_TEXTURE0 + offset);
	glBindTexture(GL_TEXTURE_2D, tbo);
}

Texture::Texture(char * filename)
{
	dimensions = Vector2f(1, 1);
	unsigned int width, height;
	std::vector<unsigned char> image;
	lodepng::decode(image, width, height, filename);

	glGenTextures(1, &tbo);
	glBindTexture(GL_TEXTURE_2D, tbo);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, &image[0]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

}

Texture::Texture() {};

Texture::Texture(GLuint t) {
	tbo = t;
}


Texture::~Texture() {
	glDeleteTextures(1, &tbo);
}
