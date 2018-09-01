#include "Texture.h"
#include "resource.h"

void Texture::bind(int offset)
{
	glActiveTexture(GL_TEXTURE0 + offset);
	glBindTexture(GL_TEXTURE_2D, tbo);
}

Texture::Texture(char * filename, bool enable_mipmap)
{
	unsigned int w, h;
	std::vector<unsigned char> image;
	lodepng::decode(image, w, h, filename);

	//ResourceData d = getDataFromResource();
	//lodepng::decode(image, w, h, d.data, d.size);
	//std::cout << d.data[0] << " " << d.size << std::endl;

	if (image.empty()) {
		std::cout << "Image could not be loaded: " << filename << std::endl;
		w = 0;
		h = 0;
		image.push_back(0);
	}

	width = w;
	height = h;

	glGenTextures(1, &tbo);
	glBindTexture(GL_TEXTURE_2D, tbo);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, &image[0]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	if (enable_mipmap) {
		glGenerateMipmap(GL_TEXTURE_2D);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_LOD_BIAS, 0);
	}
}

Texture::Texture() {};

Texture::Texture(GLuint t) {
	tbo = t;
}


Texture::~Texture() {
	glDeleteTextures(1, &tbo);
}

void Texture::getData(float * data)
{
	bind();
	glGetTexImage(GL_TEXTURE_2D, 0, GL_RGBA, GL_FLOAT, data);
}

ResourceData Texture::getDataFromResource()
{
	ResourceData data{};
	HGLOBAL     res_handle = NULL;
	HRSRC       res;
	unsigned char *      res_data;
	DWORD       res_size;

	res = FindResource(NULL, MAKEINTRESOURCE(T_MELDY), "PNG");
	if (!res)
		return data;
	res_handle = LoadResource(NULL, res);
	if (!res_handle)
		return data;
	res_data = (unsigned char*)LockResource(res_handle);
	res_size = SizeofResource(NULL, res);

	data.data = res_data;
	data.size = res_size;

	return data;
}
