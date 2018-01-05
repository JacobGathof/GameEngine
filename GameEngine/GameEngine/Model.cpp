#include "Model.h"



Model::Model(){}
Model::~Model(){}


void Model::init(){
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
}

void Model::bind(){
	glBindVertexArray(vao);
}

unsigned int Model::addData(float* data, int data_length, int components, int attrib_location){
	unsigned int vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float)*data_length, data, GL_STATIC_DRAW);
	glVertexAttribPointer(attrib_location, components, GL_FLOAT, false, 0, 0);
	glEnableVertexAttribArray(attrib_location);
	return vbo;
}

void Model::updateData(unsigned int vbo, float* data, int data_length){
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(float)*data_length, data);
}

void Model::resizeData(unsigned int vbo, float * data, int data_length){
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float)*data_length, data, GL_STATIC_DRAW);

}
