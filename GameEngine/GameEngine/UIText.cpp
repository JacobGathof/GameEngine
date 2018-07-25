#include "UIText.h"
#include "ResourceManager.h"

UIText::UIText(Vector2f & position, std::string & data, Vector2f & scale, Font * font) : Text(position, data, scale, font)
{
}

UIText::~UIText()
{
}

void UIText::draw(Vector2f & pos, Color & c)
{
	Color tempColor = color;
	Vector2f tempOffset = offset;

	color = c;
	offset += pos;

	Text::draw();

	color = tempColor;
	offset = tempOffset;
}

void UIText::draw()
{
	Text::draw();
}
