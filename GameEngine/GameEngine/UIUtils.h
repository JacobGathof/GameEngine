#pragma once
#include "Vector2f.h"
#include "Color.h"
#include "TextureManager.h"

class UIUtils
{
public:
	UIUtils();
	~UIUtils();

	static void drawRectangle(Vector2f& pos, Vector2f& scale, Color& color);
	static void drawRectangleIcon(Vector2f& pos, Vector2f& scale, Color colors[3], float spacing);
	static void drawImage(Vector2f& pos, Vector2f& scale, TextureType tex);

};

