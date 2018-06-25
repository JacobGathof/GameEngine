#pragma once
#include "AbstractUIComponent.h"
#include "Text.h"

class InputTextArea : public AbstractUIComponent
{
public:
	InputTextArea(Vector2f& position, Vector2f& scale);
	~InputTextArea();

	virtual void draw();
	virtual void handleMouseEvents(Mouse& mouse);
	virtual void handleKeyEvents(Keyboard& keyboard);

	std::string& getString();

private:
	Text * text;
	std::string str;

	int maxChars = 20;
	bool selected = false;
};

