#pragma once
#include "AbstractUIComponent.h"
#include "Button.h"
#include "Slider.h"
#include "KeyBinder.h"

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
	std::vector<AbstractUIComponent*> comps;
};

