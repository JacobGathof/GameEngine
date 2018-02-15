#pragma once
#include "AbstractUIComponent.h"

class SettingsPage : public AbstractUIComponent
{
public:
	SettingsPage();
	~SettingsPage();

	virtual void draw();
	virtual void update(float dt);

};

