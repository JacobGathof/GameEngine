#pragma once
#include "gl3w.h"
#include <vector>

class Model
{
public:
	Model();
	~Model();

	void init();
	void bind();
	unsigned int addData(float* data, int data_length, int components, int attrib_location);
	void updateData(unsigned int vbo, float* data, int data_length);
	void resizeData(unsigned int vbo, float* data, int data_length);

private:
	unsigned int vao;
	std::vector<unsigned int> vbos;

};

