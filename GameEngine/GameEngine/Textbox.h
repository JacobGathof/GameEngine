#pragma once
#include "Text.h"
#include "Screen.h"
#include <queue>
#include "AbstractUIComponent.h"

class Textbox : public AbstractUIComponent
{
public:
	Textbox();
	~Textbox();

	void draw();
	void advanceText();
	void addTextToQueue(std::string& text);
	void addChoiceToQueue(std::string* text, int length);

	virtual void handleMouseEvents(Mouse& mouse);

	void show();
	void hide();

	bool isEmpty();
	bool hasNext();

private:
	void prepareText(std::string& nextText);

	std::queue<std::string> textQueue;
	Text* text;

	bool visible = true;

};

