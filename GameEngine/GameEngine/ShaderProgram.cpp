#include "ShaderProgram.h"
#include <fstream>


ShaderProgram::ShaderProgram() {}

ShaderProgram::~ShaderProgram() {
	glDeleteProgram(shader_program);
}

void ShaderProgram::compileShader(char * file_vertex, char * file_frag)
{
	shader_program = glCreateProgram();

	compileShaderFile(file_vertex, GL_VERTEX_SHADER);
	compileShaderFile(file_frag, GL_FRAGMENT_SHADER);


	glLinkProgram(shader_program);
	checkLinkErrors(shader_program);
	glUseProgram(shader_program);

}

void ShaderProgram::compileShader(char * file_compute)
{
	shader_program = glCreateProgram();

	compileShaderFile(file_compute, GL_COMPUTE_SHADER);

	glLinkProgram(shader_program);
	checkLinkErrors(shader_program);
	glUseProgram(shader_program);
}

void ShaderProgram::bind() {
	glUseProgram(this->shader_program);
}

void ShaderProgram::checkCompileErrors(int shader, char* file)
{
	int success;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

	if (!success) {
		char infolog[2048];
		glGetShaderInfoLog(shader, 2048, 0, infolog);
		std::cout << infolog << std::endl;
		std::cout << file << std::endl;
	}

}

void ShaderProgram::checkLinkErrors(int program)
{
	int success;
	glGetProgramiv(program, GL_LINK_STATUS, &success);

	if (!success) {
		char infolog[2048];
		glGetShaderInfoLog(program, 2048, 0, infolog);
		//std::cout << infolog << std::endl;
	}

}

const char* ShaderProgram::getShaderSource(char * filename)
{
	std::ifstream file;
	file.open(filename, file.binary | file.in);

	if (file.is_open()) {
		char *buffer;
		int size;

		file.seekg(0, file.end);
		size = (int)file.tellg();
		file.seekg(0, file.beg);

		buffer = new char[size + 1];
		file.read(buffer, size);

		buffer[size] = '\0';

		return buffer;
	} else {
		std::cout << "Could not open shader source: " << filename << std::endl;
		return new char[1]{ '#' };
	}

}

void ShaderProgram::compileShaderFile(char * file, int type)
{
	int shader_vertex = glCreateShader(type);
	const char* source_vertex = getShaderSource(file);
	glShaderSource(shader_vertex, 1, &source_vertex, 0);
	glCompileShader(shader_vertex);
	checkCompileErrors(shader_vertex, file);
	glAttachShader(shader_program, shader_vertex);
	delete[] source_vertex;
	glDeleteShader(shader_vertex);
}

void ShaderProgram::loadInteger(char * location, int i) {
	glUniform1i(glGetUniformLocation(shader_program, location), i);
}

void ShaderProgram::loadFloat(char * location, float f) {
	glUniform1f(glGetUniformLocation(shader_program, location), f);
}

void ShaderProgram::loadVector2f(char * location, Vector2f & v) {
	glUniform2fv(glGetUniformLocation(shader_program, location), 1, v);
}

void ShaderProgram::loadColor(char * location, Color & c) {
	glUniform4f(glGetUniformLocation(shader_program, location), c[0], c[1], c[2], c[3]);
}
