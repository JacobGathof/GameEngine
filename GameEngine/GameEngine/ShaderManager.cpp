#include "ShaderManager.h"


std::map<ShaderType, ShaderProgram*> ShaderManager::shaders;

void ShaderManager::init(){
	addShader(ShaderType::TEXT_SHADER, "res_test/textShader.vert", 0, "res_test/textShader.frag");
	addShader(ShaderType::BASIC_SHADER, "res_test/basicShader.vert", 0, "res_test/basicShader.frag");
	addShader(ShaderType::PARTICLE_SHADER, "res_test/particleShader.vert", 0, "res_test/particleShader.frag");
	addShader(ShaderType::UI_SOLID_SHADER, "res_test/textboxShader.vert", 0, "res_test/textboxShader.frag");
	addShader(ShaderType::UI_IMAGE_SHADER, "res_test/uiImageShader.vert", 0, "res_test/uiImageShader.frag");
	addShader(ShaderType::TERRAIN_SHADER, "res_test/terrainShader.vert", 0, "res_test/terrainShader.frag");
	addShader(ShaderType::CIRCLE_SHADER, "res_test/circleShader.vert", 0, "res_test/circleShader.frag");
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
