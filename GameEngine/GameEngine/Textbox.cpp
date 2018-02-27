#include "Textbox.h"
#include "Window.h"


Textbox::Textbox()
{
	textScale = Vector2f(30, 30);
	textStartPos = Vector2f(24, 160);
	text = new Text(textStartPos, std::string("-----"), textScale, FontManager::get(FontType::DEFAULT));
	text->setColor(Color(0xffffffff));
	timer.setTickLength(0.05f);
}


Textbox::~Textbox()
{
	delete text;
}

void Textbox::draw(){
	
	if (!visible) {
		return;
	}

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

void Textbox::update(float dt)
{
	timer.update(dt);
	if (timer.tick()) {
		text->addLetter();
	}
}

void Textbox::advanceText()
{
	if (!visible) {
		show();
	}
	std::string newText = textQueue.front();
	textQueue.pop();
	prepareText(newText);

	text->setText(newText);
	text->resetLength();
}

void Textbox::addTextToQueue(std::string& text){
	textQueue.push(text);
	if (!visible) {
		advanceText();
	}
}

void Textbox::addChoiceToQueue(std::string * text, int length)
{
	textQueue.push(std::string("Choice Stand-in"));
	if (!visible) {
		advanceText();
	}
}

void Textbox::handleMouseEvents(Mouse & mouse)
{
}

void Textbox::handleKeyEvents(Keyboard & keyboard)
{
	if (keyboard.press(VirtualKey::INTERACT) && visible) {
		if (text->isDisplayingFullLength()) {
			if (hasNext()) {
				advanceText();
			}
			else {
				hide();
			}
		}
		else {
			text->displayFullLength();
		}
	}
}

void Textbox::show()
{
	visible = true;
}

void Textbox::hide()
{
	visible = false;
}

bool Textbox::isEmpty()
{
	return !visible;
}

bool Textbox::hasNext()
{
	return !textQueue.empty();
}

void Textbox::prepareText(std::string& nextText)
{
	nextText = TextUtils::processString(nextText, Res::get(FontType::DEFAULT), textScale, 738.0f);
}
