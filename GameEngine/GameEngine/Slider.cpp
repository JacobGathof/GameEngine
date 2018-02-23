#include "Slider.h"




Slider::Slider(Vector2f & pos, Vector2f & sc, float* r, float mi, float ma, int ic)
{
	position = pos;
	scale = sc;
	ref = r;
	minX = mi;
	maxX = ma;
	inc = ic;

	*ref = (maxX - minX)*ptr + minX;
	text = new Text(position + scale, std::string("0"), Vector2f(20, 20), 0);
}

Slider::~Slider()
{
	delete text;
}

void Slider::draw()
{
	UIUtils::drawRectangleIcon(position, scale, currentColor, 1.0f);
	UIUtils::drawRectangleIcon(position + Vector2f((ptr*scale[0]-4), -5), Vector2f(8, 20), currentColor, 1.0f);
	text->draw();
}

void Slider::update(float dt)
{
}

void Slider::hover(Vector2f & pos)
{
	if (held) {
		ptr = min(1, max(0, (pos[0] - position[0])/scale[0]));
		if (inc != 0) {
			ptr = ((int)(ptr * inc + .5f) / inc);
		}
		*ref = (maxX - minX)*ptr + minX;
		text->setText(std::to_string(((int)(*ref * 100))/100.0f).substr(0,4));
	}
}

void Slider::click(Vector2f & pos)
{
	if (pos.between(position, position + scale)) {
		held = true;
	}
}

void Slider::release(Vector2f & pos)
{
	held = false;
}
