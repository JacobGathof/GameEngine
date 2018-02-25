#pragma once
#include "Text.h"
#include "Screen.h"
#include <queue>
#include "AbstractUIComponent.h"
#include "Timer.h"

class Textbox : public AbstractUIComponent
{
public:
	Textbox();
	~Textbox();

	void draw();
	void update(float dt);
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
	Timer timer;

	bool visible = true;
	Vector2f textScale;
	Vector2f textStartPos;

};

