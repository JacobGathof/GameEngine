#include "Textbox.h"



Textbox::Textbox() 
	: text(Vector2f(-1, 1), std::string("-=-=-ERROR TEXT-=-=-"), 
		Vector2f(0.5f, 0.5f), FontManager::get(FontType::DEFAULT))
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
