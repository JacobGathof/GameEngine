#include "Textbox.h"



Textbox::Textbox()
{
	text = new Text(Vector2f(18,200), std::string("Textbox text"), Vector2f(128,128), FontManager::get(FontType::DEFAULT));
	text->setColor(Color(0xffffffff));
	text->setText(std::string("The quick brown fox jumped over the lazy dog"));
}


Textbox::~Textbox()
{
	delete text;
}

void Textbox::draw(){
	
	UIUtils::drawRectangle(Vector2f(10, 10), Vector2f(780, 200), Color(0x000000dd));
	UIUtils::drawRectangle(Vector2f(12, 12), Vector2f(776, 196), Color(0xaaaaaa88));
	UIUtils::drawRectangle(Vector2f(14, 14), Vector2f(772, 192), Color(0x000000dd));

	text->draw();

}

void Textbox::advanceText()
{
	std::string newText = textQueue.front();
	textQueue.pop();
	prepareText(newText);

	text->setText(newText);
}

void Textbox::addTextToQueue(std::string text){
	textQueue.push(text);
}

void Textbox::prepareText(std::string& nextText)
{
	nextText.append("*@*");
}
