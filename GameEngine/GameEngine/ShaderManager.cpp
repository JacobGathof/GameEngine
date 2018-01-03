#include "ShaderManager.h"


std::map<Shader, ShaderProgram*> ShaderManager::shaders;

void ShaderManager::init(){
	addShader(Shader::TEXT_SHADER, "res_test/defaultShader.vert", 0, "res_test/defaultShader.frag");
}

void ShaderManager::clean(){
	for (auto pair : shaders) {
		delete pair.second;
	}
}

ShaderProgram * ShaderManager::get(Shader type)
{
	return shaders[type];
}

void ShaderManager::addShader(Shader shader, char * v, char * g, char * f){
	ShaderProgram * sh = new ShaderProgram();
	sh->compileShader(v, g, f);
	shaders[shader] = sh;
}
