#pragma once
#include "Text.h"

class UIText : public Text
{
public:
	UIText(Vector2f& position, std::string& data, Vector2f& scale, Font* font);
	~UIText();

	void draw(Vector2f& pos, Color& color);
	void draw();
};

