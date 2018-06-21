#include "ResourceManager.h"

CardManager* Res::cardManager;
FontManager* Res::fontManager;
ModelManager* Res::modelManager;
ShaderManager* Res::shaderManager;
TextureManager* Res::textureManager;
FramebufferManager* Res::frameManager;
AudioManager* Res::soundManager;
DeckManager* Res::deckManager;

WeaponManager* Res::weaponManager;
KeyItemManager* Res::keyItemManager;

void ResourceManager::init()
{
	cardManager = new CardManager();
	fontManager = new FontManager();
	modelManager = new ModelManager();
	shaderManager = new ShaderManager();
	textureManager = new TextureManager();
	frameManager = new FramebufferManager();
	soundManager = new AudioManager();
	deckManager = new DeckManager();

	weaponManager = new WeaponManager();
	keyItemManager = new KeyItemManager();
	

	cardManager->init();
	deckManager->init();
	fontManager->init();
	modelManager->init();
	shaderManager->init();
	textureManager->init();
	frameManager->init();
	soundManager->init();

	weaponManager->init();
	keyItemManager->init();
}

void ResourceManager::clean()
{
	cardManager->clean();
	fontManager->clean();
	modelManager->clean();
	shaderManager->clean();
	textureManager->clean();
	frameManager->clean();
	soundManager->clean();
	deckManager->clean();
	weaponManager->clean();
	keyItemManager->clean();

	delete deckManager;
	delete fontManager;
	delete cardManager;
	delete modelManager;
	delete shaderManager;
	delete textureManager;
	delete frameManager;
	delete soundManager;
	delete weaponManager;
	delete keyItemManager;
}

ShaderProgram* ResourceManager::get(ShaderType type){
	return shaderManager->get(type);
}

Model* ResourceManager::get(ModelType type){
	return modelManager->get(type);
}

SoundEntity * ResourceManager::get(AudioType type)
{
	return soundManager->get(type);
}

Weapon * ResourceManager::get(WeaponType type)
{
	return weaponManager->get(type);
}

KeyItem * ResourceManager::get(KeyItemType type)
{
	return keyItemManager->get(type);
}

void ResourceManager::updateFramebufferSizes(float x, float y)
{
	frameManager->updateSizes((int)x, (int)y);
}

void ResourceManager::uploadGlobalUniform(char * location, Vector2f & val)
{
	shaderManager->uploadAll(location, val);
}

Font* ResourceManager::get(FontType type){
	return fontManager->get(type);
}

SpriteSheet* ResourceManager::get(TextureType type){
	return textureManager->get(type);
}

Framebuffer * ResourceManager::get(FramebufferType type){
	return frameManager->get(type);
}

Card * ResourceManager::get(CardType type){
	return cardManager->get(type);
}

Deck * ResourceManager::get(DeckType deck)
{
	return deckManager->get(deck);
}
