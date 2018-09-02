#pragma once
#include "TextureManager.h"
#include "ModelManager.h"
#include "FontManager.h"
#include "FramebufferManager.h"
#include "ShaderManager.h"
#include "CardManager.h"
#include "AudioManager.h"
#include "DeckManager.h"

#include "WeaponManager.h"
#include "KeyItemManager.h"


#include "IManager.h"

class ScriptManager;

class ResourceManager
{
public:

	static void init();
	static void clean();

	static ShaderProgram* get(ShaderType type);
	static SpriteSheet* get(TextureType type);
	static Framebuffer* get(FramebufferType type);
	static Card* get(CardType type);
	static Deck* get(DeckType deck);
	static Font* get(FontType type);
	static Model* get(ModelType type);
	static SoundEntity* get(AudioType type);
	
	static Weapon* get(WeaponType type);
	static KeyItem* get(KeyItemType type);


	static void updateFramebufferSizes(float x, float y);
	static void uploadGlobalUniform(char* location, Vector2f& val);
	static void uploadGlobalUniform(char* location, float f);

	static ScriptManager* scriptManager;

private:

	static CardManager* cardManager;
	static FontManager* fontManager;
	static ModelManager* modelManager;
	static ShaderManager* shaderManager;
	static TextureManager* textureManager;
	static FramebufferManager* frameManager;
	static AudioManager* soundManager;
	static DeckManager* deckManager;

	static WeaponManager* weaponManager;
	static KeyItemManager* keyItemManager;

};

typedef ResourceManager Res;
