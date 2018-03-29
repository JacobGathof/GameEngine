#include "ShaderManager.h"



void ShaderManager::init(){
	addShader(ShaderType::ANIMATED_SHADER, "res/shaders/animatedShader.vert", 0, "res/shaders/animatedShader.frag");
	addShader(ShaderType::TEXT_SHADER, "res/shaders/textShader.vert", 0, "res/shaders/textShader.frag");
	addShader(ShaderType::BASIC_SHADER, "res/shaders/basicShader.vert", 0, "res/shaders/basicShader.frag");
	addShader(ShaderType::PARTICLE_SHADER, "res/shaders/particleShader.vert", 0, "res/shaders/particleShader.frag");
	addShader(ShaderType::PARTICLE_FAST_SHADER, "res/shaders/particleFastShader.vert", 0, "res/shaders/particleFastShader.frag", new const GLchar*[3]{"newPosition", "newVelocity", "newLife"}, 3);
	addShader(ShaderType::UI_SOLID_SHADER, "res/shaders/textboxShader.vert", 0, "res/shaders/textboxShader.frag");
	addShader(ShaderType::UI_IMAGE_SHADER, "res/shaders/uiImageShader.vert", 0, "res/shaders/uiImageShader.frag");
	addShader(ShaderType::TERRAIN_SHADER, "res/shaders/terrainShader.vert", 0, "res/shaders/terrainShader.frag");
	addShader(ShaderType::CIRCLE_SHADER, "res/shaders/circleShader.vert", 0, "res/shaders/circleShader.frag");
	addShader(ShaderType::POST_PROCESS_SHADER, "res/shaders/postProcessShader.vert", 0, "res/shaders/postProcessShader.frag");
	addShader(ShaderType::RECTANGLE_SHADER, "res/shaders/rectangleShader.vert", 0, "res/shaders/rectangleShader.frag");
	addShader(ShaderType::PLAIN_SHADER, "res/shaders/plainShader.vert", 0, "res/shaders/plainShader.frag");

	addShader(ShaderType::FRACTAL_SHADER, "res/shaders/fractalShader.vert", 0, "res/shaders/fractalShader.frag");
}


void ShaderManager::uploadAll(char* location, Vector2f & v2){
	for (auto a : elements) {
		a.second->bind();
		a.second->loadVector2f(location, v2);
	}
}

void ShaderManager::addShader(ShaderType shader, char * v, char * g, char * f){
	ShaderProgram * sh = new ShaderProgram();
	sh->compileShader(v, g, f);
	elements[shader] = sh;
}

void ShaderManager::addShader(ShaderType shader, char * v, char * g, char * f, const GLchar * varying[], int length)
{
	ShaderProgram * sh = new ShaderProgram();
	sh->compileFeedbackShader(v, g, f, varying, length);
	elements[shader] = sh;
	delete[] varying;
}
