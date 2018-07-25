#pragma once
#include "AbstractUIComponent.h"

class UIText;
class InputTextArea;

class InputNamePage : public AbstractUIComponent
{
public:
	InputNamePage();
	~InputNamePage();

	virtual void draw();
	virtual void update(float dt);
	virtual void resize(int x, int y);

	virtual void handleMouseEvents(Mouse& mouse);
	virtual void handleKeyEvents(Keyboard& keyboard);

private:
	UIText * promptText;
	InputTextArea * area;
};

