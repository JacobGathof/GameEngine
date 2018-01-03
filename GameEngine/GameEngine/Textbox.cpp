#include "Textbox.h"



Textbox::Textbox() 
	: text(Vector2f(-1, 1), std::string("Default. You should not see this"), 
		Vector2f(.75f, .75f), FontManager::get(FontType::DEFAULT))
{
}


Textbox::~Textbox()
{
}

void Textbox::render()
{
	text.render();
}

void Textbox::advanceText()
{
	std::string newText = textQueue.front();
	textQueue.pop();
	prepareText(newText);

	text.setText(newText);
}

void Textbox::addTextToQueue(std::string text){
	textQueue.push(text);
}

void Textbox::prepareText(std::string& nextText)
{
	nextText.append("*@*");
}
