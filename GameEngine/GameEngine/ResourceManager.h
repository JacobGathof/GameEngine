#pragma once
#include "TextureManager.h"
#include "ModelManager.h"
#include "FontManager.h"
#include "ShaderManager.h"
#include "FramebufferManager.h"
#include "MusicManager.h"

class ResourceManager
{
public:

	static void init();
	static void clean();
	static ShaderProgram* get(ShaderType type);
	static Model* get(ModelType type);
	static Font* get(FontType type);
	static SpriteSheet* get(TextureType type);
	static Framebuffer* get(FramebufferType type);
	static AudioEntity* get(MusicType type);
};

typedef ResourceManager Res;
