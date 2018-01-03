#include "ShaderManager.h"


std::map<ShaderType, ShaderProgram*> ShaderManager::shaders;

void ShaderManager::init(){
	addShader(ShaderType::TEXT_SHADER, "res_test/defaultShader.vert", 0, "res_test/defaultShader.frag");
}

void ShaderManager::clean(){
	for (auto pair : shaders) {
		delete pair.second;
	}
}

ShaderProgram * ShaderManager::get(ShaderType type)
{
	return shaders[type];
}

void ShaderManager::addShader(ShaderType shader, char * v, char * g, char * f){
	ShaderProgram * sh = new ShaderProgram();
	sh->compileShader(v, g, f);
	shaders[shader] = sh;
}
