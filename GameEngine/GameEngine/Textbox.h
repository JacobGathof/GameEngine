#pragma once
#include "Text.h"
#include <queue>

class Textbox
{
public:
	Textbox(Font * font);
	~Textbox();

	void render();
	void advanceText();
	void addTextToQueue(std::string text);

private:
	void prepareText(std::string& nextText);

	std::queue<std::string> textQueue;
	Text text;

};

