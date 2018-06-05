#pragma once
#include "AbstractUIComponent.h"
#include "Button.h"
class Text;

class PauseMenu : public AbstractUIComponent
{
public:
	PauseMenu();
	~PauseMenu();
	virtual void draw();
	virtual void handleMouseEvents(Mouse& mouse);
private:
	Text * text;
	Button * resume;
	Button * exit;
};

