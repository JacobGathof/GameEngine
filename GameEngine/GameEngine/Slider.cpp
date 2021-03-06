#include "Slider.h"
#include "Text.h"
#include "AbstractAction.h"


Slider::Slider(Vector2f & pos, Vector2f & sc, std::string & t, float * r, float mi, float ma, int ic, AbstractAction * act)
{
	position = pos;
	scale = sc;
	ref = r;
	minX = mi;
	maxX = ma;
	inc = ic;

	//*ref = (maxX - minX)*ptr + minX;
	data = new Text(position + scale, std::string(""), Vector2f(20, 20), 0);
	title = new Text(position + Vector2f(scale[0] / 2, -10), t, Vector2f(20, 20), 0);
	title->center();

	ptr = (*ref - minX) / (maxX - minX);
	data->setText(std::to_string(((int)(*ref * 100)) / 100.0f).substr(0, 4));

	action = act;
	if (act != 0) {
		act->run(0);
	}
}

Slider::~Slider()
{
	delete data;
	delete title;

	if (action != 0) {
		delete action;
	}
}

void Slider::draw()
{
	UIUtils::drawRectangleIcon(position, scale, currentColor, 1.0f);
	UIUtils::drawRectangleIcon(position + Vector2f((ptr*scale[0]-4), -5), Vector2f(8, 20), currentColor, 1.0f);
	data->draw();
	title->draw();
}

void Slider::update(float dt)
{
}

void Slider::handleMouseEvents(Mouse & mouse)
{
	if (mouse.click() && mouse.pos().between(position, position + scale)) {
		held = true;
	}

	if (held) {
		ptr = min(1, max(0, (mouse.pos()[0] - position[0]) / scale[0]));
		if (inc != 0) {
			ptr = (float)((int)(ptr * inc + .5f) / inc);
		}
		*ref = (maxX - minX)*ptr + minX;
		data->setText(std::to_string(((int)(*ref * 100)) / 100.0f).substr(0, 4));

		if (action != 0) {
			action->run(0);
		}
	}

	if (mouse.release()) {
		held = false;
	}

}

void Slider::handleKeyEvents(Keyboard & keyboard)
{
}
