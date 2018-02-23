#include "Textbox.h"
#include "Window.h"


Textbox::Textbox()
{
	text = new Text(Vector2f(16, 210), std::string("-----"), Vector2f(50,50), FontManager::get(FontType::DEFAULT));
	text->setColor(Color(0xffffffff));
}


Textbox::~Textbox()
{
	delete text;
}

void Textbox::draw(){
	
	UIUtils::drawRectangle(Vector2f(10, 10), Vector2f(780, 200), Color(0xffaaaaff));
	UIUtils::drawRectangle(Vector2f(12, 12), Vector2f(776, 196), Color(0xffffffff));
	UIUtils::drawRectangle(Vector2f(14, 14), Vector2f(772, 192), Color(0x000000ff));

	/*
	UIUtils::drawRectangle(Vector2f(10, 110)+Vector2f(6,-6), Vector2f(100, 100), Color(0x000000dd));
	UIUtils::drawRectangle(Vector2f(12, 112) + Vector2f(6, -6), Vector2f(96, 96), Color(0xaaaaaa88));
	UIUtils::drawRectangle(Vector2f(14, 114) + Vector2f(6, -6), Vector2f(92, 92), Color(0x000000dd));
	UIUtils::drawImage(Vector2f(14, 114) + Vector2f(6, -6), Vector2f(92, 92), TextureType::TEXTURE_MELODY);
	*/

	/*
	UIUtils::drawRectangle(Vector2f(10, 210), Vector2f(200, 50), Color(0x000000dd));
	UIUtils::drawRectangle(Vector2f(12, 212), Vector2f(196, 46), Color(0xaaaaaa88));
	UIUtils::drawRectangle(Vector2f(14, 214), Vector2f(192, 42), Color(0x000000dd));
	*/

	/*
	UIUtils::drawRectangle(Vector2f(10, 210), Vector2f(100, 100), Color(0x000000dd));
	UIUtils::drawRectangle(Vector2f(12, 212), Vector2f(96, 96), Color(0xaaaaaa88));
	UIUtils::drawRectangle(Vector2f(14, 214), Vector2f(92, 92), Color(0x000000dd));
	*/

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
