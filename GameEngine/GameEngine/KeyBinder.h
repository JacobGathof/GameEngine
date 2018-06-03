#pragma once
#include "AbstractUIComponent.h"
#include <vector>
#include "Timer.h"

class Text;

class SingleKeyBindCell {
public:
	SingleKeyBindCell(Vector2f& pos, Vector2f& scale, VirtualKey vk, char* nm, const char* rn);
	~SingleKeyBindCell();
	VirtualKey key;
	Text * text;
	Text * realName;
	Vector2f position;
	Vector2f scale;
	
	void updateText(const char* name);
	void draw(Color* col);
};


class KeyBinder : public AbstractUIComponent
{
public:
	KeyBinder(Vector2f& pos, Vector2f& scale, Keyboard& keyboard);
	~KeyBinder();

	virtual void draw();
	virtual void update(float dt);
	virtual void handleMouseEvents(Mouse& mouse);
	virtual void handleKeyEvents(Keyboard& keyboard);

private:
	Keyboard keyboard;
	std::vector<SingleKeyBindCell*> cells;
	SingleKeyBindCell* current;
	bool waitingForInput = false;
	Timer timer;

	Color colors[3] =			{ Color(0xffffffff), Color(0x888888ff), Color(0x000000ff) };
	Color colors_active[3] =	{ Color(0xffffffff), Color(0x00ff00ff), Color(0x000000ff) };
};

