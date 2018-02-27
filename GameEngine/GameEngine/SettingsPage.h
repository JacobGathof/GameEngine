#pragma once
#include "AbstractUIComponent.h"
#include "Button.h"
#include "Slider.h"

#define NUM_COMPS 3

class SettingsPage : public AbstractUIComponent
{
public:
	SettingsPage();
	~SettingsPage();

	virtual void draw();
	virtual void update(float dt);
	virtual void handleMouseEvents(Mouse& mouse);
	virtual void handleKeyEvents(Keyboard& keyboard);

private:
	AbstractUIComponent * comps[NUM_COMPS];
};

