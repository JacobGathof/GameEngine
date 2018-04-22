#pragma once
#include "ShaderProgram.h"
#include "ResourceType.h"
#include "IManager.h"


class ShaderManager : public IManager<ShaderProgram, ShaderType>
{
public:

	virtual void init();
	void uploadAll(char* location, Vector2f& v2);

private:

	void addShader(ShaderType shader, char* v, char* f);
	void addShader(ShaderType shader, char* c);
	void addShader(ShaderType shader, char* v, char* f, const GLchar* varying[], int length);

};

