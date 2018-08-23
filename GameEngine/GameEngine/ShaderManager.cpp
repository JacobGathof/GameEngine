#include "ShaderManager.h"



void ShaderManager::init(){
	addShader(ShaderType::ANIMATED_SHADER, "res/shaders/animatedShader.vert", "res/shaders/animatedShader.frag");
	addShader(ShaderType::TEXT_SHADER, "res/shaders/textShader.vert", "res/shaders/textShader.frag");
	addShader(ShaderType::TEXT_WORLD_SHADER, "res/shaders/text_worldShader.vert", "res/shaders/text_worldShader.frag");
	addShader(ShaderType::BASIC_SHADER, "res/shaders/basicShader.vert", "res/shaders/basicShader.frag");
	addShader(ShaderType::PARTICLE_SHADER, "res/shaders/particleShader.vert", "res/shaders/particleShader.frag");

	addShader(ShaderType::PARTICLE_COMPUTE_SHADER, "res/shaders/particleComputeShader.comp");
	addShader(ShaderType::PARTICLE_FAST_SHADER, "res/shaders/particleFastShader.vert", "res/shaders/particleFastShader.frag");

	addShader(ShaderType::UI_SOLID_SHADER, "res/shaders/textboxShader.vert", "res/shaders/textboxShader.frag");
	addShader(ShaderType::UI_IMAGE_SHADER, "res/shaders/uiImageShader.vert", "res/shaders/uiImageShader.frag");
	addShader(ShaderType::TERRAIN_SHADER, "res/shaders/terrainShader.vert", "res/shaders/terrainShader.frag");
	addShader(ShaderType::CIRCLE_SHADER, "res/shaders/circleShader.vert", "res/shaders/circleShader.frag");
	addShader(ShaderType::POST_PROCESS_SHADER, "res/shaders/postProcessShader.vert", "res/shaders/postProcessShader.frag");
	addShader(ShaderType::RECTANGLE_SHADER, "res/shaders/rectangleShader.vert", "res/shaders/rectangleShader.frag");
	//addShader(ShaderType::PLAIN_SHADER, "res/shaders/plainShader.vert", "res/shaders/plainShader.frag");

	addShader(ShaderType::LIGHT_SHADER, "res/shaders/lightShader.vert", "res/shaders/lightShader.frag");
	addShader(ShaderType::SHADOW_SHADER, "res/shaders/shadowShader.vert", "res/shaders/shadowShader.frag");

	addShader(ShaderType::WATER_SHADER, "res/shaders/waterShader.vert", "res/shaders/waterShader.frag");
	addShader(ShaderType::LINE_SHADER, "res/shaders/lineShader.vert", "res/shaders/lineShader.frag");

	addShader(ShaderType::TEST_SHADER_1, "res/shaders/lineLightShader.vert", "res/shaders/lineLightShader.frag");
	addShader(ShaderType::TEST_SHADER_2, "res/shaders/pulseShader.vert", "res/shaders/pulseShader.frag");
}


void ShaderManager::uploadAll(char* location, Vector2f & v2){
	for (auto a : elements) {
		a.second->bind();
		a.second->loadVector2f(location, v2);
	}
}

void ShaderManager::uploadAll(char * location, float f)
{
	for (auto a : elements) {
		a.second->bind();
		a.second->loadFloat(location, f);
	}
}

void ShaderManager::addShader(ShaderType shader, char * c){

	ShaderProgram * sh = new ShaderProgram();
	sh->compileShader(c);
	elements[shader] = sh;
}

void ShaderManager::addShader(ShaderType shader, char * v, char * f){
	ShaderProgram * sh = new ShaderProgram();
	sh->compileShader(v, f);
	elements[shader] = sh;
}

