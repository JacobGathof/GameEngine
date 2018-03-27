#include "ResourceManager.h"

CardManager* Res::cardManager;
FontManager* Res::fontManager;
ModelManager* Res::modelManager;
MusicManager* Res::musicManager;
ShaderManager* Res::shaderManager;
TextureManager* Res::textureManager;
FramebufferManager* Res::frameManager;

void ResourceManager::init()
{
	cardManager = new CardManager();
	fontManager = new FontManager();
	modelManager = new ModelManager();
	musicManager = new MusicManager();
	shaderManager = new ShaderManager();
	textureManager = new TextureManager();
	frameManager = new FramebufferManager();

	
	cardManager->init();
	fontManager->init();
	modelManager->init();
	musicManager->init();
	shaderManager->init();
	textureManager->init();
	frameManager->init();
}

void ResourceManager::clean()
{
	cardManager->clean();
	fontManager->clean();
	modelManager->clean();
	musicManager->clean();
	shaderManager->clean();
	textureManager->clean();
	frameManager->clean();

	delete fontManager;
	delete cardManager;
	delete modelManager;
	delete musicManager;
	delete shaderManager;
	delete textureManager;
	delete frameManager;
}

ShaderProgram* ResourceManager::get(ShaderType type){
	return shaderManager->get(type);
}

Model* ResourceManager::get(ModelType type){
	return modelManager->get(type);
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

AudioEntity * ResourceManager::get(MusicType type){
	return musicManager->get(type);
}

Card * ResourceManager::get(CardType type){
	return cardManager->get(type);
}
