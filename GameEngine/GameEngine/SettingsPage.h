#pragma once
#include "AbstractUIComponent.h"

class SettingsPage : public AbstractUIComponent
{
public:
	SettingsPage(Vector2f *position);
	~SettingsPage();

	virtual void draw();
	virtual void update(float dt);

private:
	Vector2f * parentOffset;
};

