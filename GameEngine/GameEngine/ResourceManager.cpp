#include "ResourceManager.h"

void ResourceManager::init()
{
	ShaderManager::init();
	FontManager::init();
	TextureManager::init();
	ModelManager::init();
	FramebufferManager::init();
}

void ResourceManager::clean()
{
	ShaderManager::clean();
	FontManager::clean();
	TextureManager::clean();
	ModelManager::clean();
	FramebufferManager::clean();
}

ShaderProgram* ResourceManager::get(ShaderType type){
	return ShaderManager::get(type);
}

Model* ResourceManager::get(ModelType type){
	return ModelManager::get(type);
}

Font* ResourceManager::get(FontType type){
	return FontManager::get(type);
}

Texture* ResourceManager::get(TextureType type){
	return TextureManager::get(type);
}

Framebuffer * ResourceManager::get(FramebufferType type){
	return FramebufferManager::get(type);
}
