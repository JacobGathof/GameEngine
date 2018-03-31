#pragma once
#include "TextureManager.h"
#include "ModelManager.h"
#include "FontManager.h"
#include "FramebufferManager.h"
#include "MusicManager.h"
#include "ShaderManager.h"
#include "CardManager.h"
#include "SoundManager.h"

class ResourceManager
{
public:

	static void init();
	static void clean();

	static ShaderProgram* get(ShaderType type);
	static SpriteSheet* get(TextureType type);
	static Framebuffer* get(FramebufferType type);
	static MusicEntity* get(MusicType type);
	static Card* get(CardType type);
	static Font* get(FontType type);
	static Model* get(ModelType type);
	static SoundEntity* get(SoundType type);

	static void updateFramebufferSizes(float x, float y);
	static void uploadGlobalUniform(char* location, Vector2f& val);

private:

	static CardManager* cardManager;
	static FontManager* fontManager;
	static ModelManager* modelManager;
	static MusicManager* musicManager;
	static ShaderManager* shaderManager;
	static TextureManager* textureManager;
	static FramebufferManager* frameManager;
	static SoundManager* soundManager;

};

typedef ResourceManager Res;
