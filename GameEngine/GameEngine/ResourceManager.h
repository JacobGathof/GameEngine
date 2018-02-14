#pragma once
#include "TextureManager.h"
#include "ModelManager.h"
#include "FontManager.h"
#include "ShaderManager.h"
#include "FramebufferManager.h"

class ResourceManager
{
public:

	static void init();
	static void clean();
	static ShaderProgram* get(ShaderType type);
	static Model* get(ModelType type);
	static Font* get(FontType type);
	static Texture* get(TextureType type);
	static Framebuffer* get(FramebufferType type);
};

typedef ResourceManager Res;
