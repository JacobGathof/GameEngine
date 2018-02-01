#pragma once
#include "ResourceManager.h"
#include "Screen.h"

class UIUtils
{
public:
	UIUtils();
	~UIUtils();

	static void drawRectangle(Vector2f pos, Vector2f scale, Color color);
	static void drawImage(Vector2f pos, Vector2f scale, TextureType tex);

};
