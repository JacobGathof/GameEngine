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
	static void drawImage(Vector2f& pos, Vector2f& scale, TextureType tex, Vector2f& offset = Vector2f(0,0), Color& color = Color::White);
	static void drawBorder(Vector2f& pos, Vector2f& scale, Color& color, int offset, int spacing);
	static void drawLine(Vector2f& start, Vector2f& end, Color& color, float width);

};

