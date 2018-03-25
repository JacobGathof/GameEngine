#include "KeyBinder.h"
#include "Text.h"



KeyBinder::KeyBinder(Vector2f & pos, Vector2f & sc, Keyboard & keyboard)
{
	position = pos;
	scale = sc;
	timer.setTickLength(5.0f);
	timer.pause();

	cells.push_back(new SingleKeyBindCell(position + 0*Vector2f(0, sc[1]+5), scale, VirtualKey::DOWN, keyboard.getKeyName(VirtualKey::DOWN), keyboard.getRealKeyName(VirtualKey::DOWN)));
	cells.push_back(new SingleKeyBindCell(position + 1*Vector2f(0, sc[1]+5), scale, VirtualKey::UP, keyboard.getKeyName(VirtualKey::UP), keyboard.getRealKeyName(VirtualKey::UP)));
	cells.push_back(new SingleKeyBindCell(position + 2*Vector2f(0, sc[1]+5), scale, VirtualKey::LEFT, keyboard.getKeyName(VirtualKey::LEFT), keyboard.getRealKeyName(VirtualKey::LEFT)));
	cells.push_back(new SingleKeyBindCell(position + 3*Vector2f(0, sc[1]+5), scale, VirtualKey::RIGHT, keyboard.getKeyName(VirtualKey::RIGHT), keyboard.getRealKeyName(VirtualKey::RIGHT)));

}

KeyBinder::~KeyBinder()
{
	for (auto c : cells) {
		delete c;
	}
}

void KeyBinder::draw()
{
	for (auto c : cells) {
		c->draw((c==current)?colors_active:colors);
	}
}

void KeyBinder::update(float dt)
{
	timer.update(dt);
	if (timer.tick()) {
		current = 0;
		waitingForInput = false;

		timer.pause();
		timer.reset();
	}

}

void KeyBinder::handleMouseEvents(Mouse & mouse)
{
	for (auto c : cells) {
		if (mouse.click() && mouse.pos().between(c->position, c->position+c->scale)) {
			current = c;
			waitingForInput = true;

			timer.reset();
			timer.unpause();
		}
	}
}

void KeyBinder::handleKeyEvents(Keyboard & keyboard)
{
	if (waitingForInput && current != 0) {
		int newKey = keyboard.getCurrentPressed();
		if (newKey == -1) {
			return;
		}

		keyboard.setKeyBind(current->key, newKey);
		current->updateText(keyboard.getRealKeyName(newKey));
		current = 0;
		waitingForInput = false;

		timer.pause();
		timer.reset();
	}
}



SingleKeyBindCell::SingleKeyBindCell(Vector2f & pos, Vector2f & sc, VirtualKey vk, char* nm, const char* rn)
{
	position = pos;
	scale = sc;
	key = vk;
	text = new Text(position+scale/2, std::string(nm), Vector2f(20, 20), 0);
	if (rn == 0)
		rn = "Unknown";
	realName = new Text(position + Vector2f(scale[0],0) + scale / 2, std::string(rn), Vector2f(20, 20), 0);

	text->center();
	realName->center();
}

SingleKeyBindCell::~SingleKeyBindCell()
{
	delete text;
}

void SingleKeyBindCell::updateText(const char* name)
{
	if (name == 0)
		name = "Unknown";
	realName->setText(std::string(name));
}

void SingleKeyBindCell::draw(Color * col)
{
	UIUtils::drawRectangleIcon(position, scale, col, 2.0f);
	text->draw();
	realName->draw();
}
