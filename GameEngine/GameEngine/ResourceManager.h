#pragma once
#include "TextureManager.h"
#include "ModelManager.h"
#include "FontManager.h"
#include "ShaderManager.h"

class ResourceManager
{
public:

	static void init();
	static void clean();
	static ShaderProgram* get(ShaderType type);
	static Model* get(ModelType type);
	static Font* get(FontType type);
	static Texture* get(TextureType type);
};

typedef ResourceManager Res;
