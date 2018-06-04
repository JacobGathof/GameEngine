#pragma once
#include "AbstractUIComponent.h"
#include "InputTextArea.h"

class Text;

class CommandLine : public AbstractUIComponent
{
public:
	CommandLine();
	~CommandLine();
	void toggle();
	virtual void draw();
	virtual void update(float dt);
	virtual void handleKeyEvents(Keyboard & keyboard);

private:
	Text* text;
	std::string str;
	std::queue<std::string> pastCommands;

	void handleCommand(std::string s);
};

