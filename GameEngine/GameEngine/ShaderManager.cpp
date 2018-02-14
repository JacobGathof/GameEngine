#include "ShaderManager.h"


std::map<ShaderType, ShaderProgram*> ShaderManager::shaders;

void ShaderManager::init(){
	addShader(ShaderType::TEXT_SHADER, "res/shaders/textShader.vert", 0, "res/shaders/textShader.frag");
	addShader(ShaderType::BASIC_SHADER, "res/shaders/basicShader.vert", 0, "res/shaders/basicShader.frag");
	addShader(ShaderType::PARTICLE_SHADER, "res/shaders/particleShader.vert", 0, "res/shaders/particleShader.frag");
	addShader(ShaderType::UI_SOLID_SHADER, "res/shaders/textboxShader.vert", 0, "res/shaders/textboxShader.frag");
	addShader(ShaderType::UI_IMAGE_SHADER, "res/shaders/uiImageShader.vert", 0, "res/shaders/uiImageShader.frag");
	addShader(ShaderType::TERRAIN_SHADER, "res/shaders/terrainShader.vert", 0, "res/shaders/terrainShader.frag");
	addShader(ShaderType::CIRCLE_SHADER, "res/shaders/circleShader.vert", 0, "res/shaders/circleShader.frag");
	addShader(ShaderType::POST_PROCESS_SHADER, "res/shaders/postProcessShader.vert", 0, "res/shaders/postProcessShader.frag");
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
