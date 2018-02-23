#pragma once
#include "AbstractUIComponent.h"
#include "Button.h"
#include "Slider.h"


class SettingsPage : public AbstractUIComponent
{
public:
	SettingsPage();
	~SettingsPage();

	virtual void draw();
	virtual void update(float dt);
	virtual void hover(Vector2f& pos);
	virtual void click(Vector2f& pos);
	virtual void release(Vector2f& pos);

private:
	AbstractUIComponent * comps[2];
};

