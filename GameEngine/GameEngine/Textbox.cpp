#include "Textbox.h"
#include "Window.h"


Text* PlainText::text;


Textbox::Textbox()
{
	textScale = Vector2f(30, 30);
	textStartPos = Vector2f(24, 160);
	timer.setTickLength(0.05f);

	PlainText::init();
}


Textbox::~Textbox()
{
	PlainText::clean();
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
	if (current != 0) {
		current->draw();
	}
	
}

void Textbox::update(float dt)
{
	timer.update(dt);
	if (timer.tick() && visible && current!= 0) {
		current->addLetter();
	}
}

void Textbox::advanceText()
{
	if (!visible) {
		show();
	}
	if (current != 0) {
		delete current;
		current = 0;
	}
	current = queue.front();
	queue.pop();
	current->prepare();

}

void Textbox::addTextToQueue(std::string& text){
	queue.push(new PlainText(text));
	if (!visible) {
		advanceText();
	}
}

void Textbox::addChoiceToQueue(List<std::string>& text)
{
	queue.push(new Choice(text));
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

		if (current == 0 || current->isDisplayingFullLength()) {
			
			if (hasNext()) {
				advanceText();
			}
			else {
				hide();
			}
		}
		else {
			current->displayFullLength();
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
	return !queue.empty();
}




Choice::Choice(List<std::string>& ch) : choices(ch)
{
	text1 = new Text(Vector2f(24, 160), std::string(""), Vector2f(30, 30), 0);
	text2 = new Text(Vector2f(24, 60), std::string("Test"), Vector2f(30, 30), 0);
	text3 = new Text(Vector2f(424, 160), std::string(""), Vector2f(30, 30), 0);
	text4 = new Text(Vector2f(424, 60), std::string(""), Vector2f(30, 30), 0);

	choices = ch;
}

Choice::~Choice()
{
	delete text1;
	delete text2;
	delete text3;
	delete text4;
}

void Choice::draw()
{
	text1->draw();
	text2->draw();
}

void Choice::prepare()
{
	numChoices = 0;
	choicePointer = 0;

	numChoices = choices.size();
	std::string s1 = *choices.begin();
	text1->setText(s1);

}

bool Choice::isDisplayingFullLength(){
	return true;
}

void Choice::displayFullLength(){
}

void Choice::addLetter(){
}




PlainText::PlainText(std::string & st)
{
	str = st;
}

void PlainText::init()
{
	text = new Text(Vector2f(24, 160), std::string("-----"), Vector2f(30, 30), 0);
	text->setColor(Color(0xffffffff));
}

void PlainText::clean()
{
	delete text;
}

void PlainText::prepare()
{
	str = TextUtils::processString(str, Res::get(FontType::DEFAULT), Vector2f(30,30), 738.0f);
	text->setText(str);
	text->resetLength();
}

void PlainText::draw()
{
	text->draw();
}


bool PlainText::isDisplayingFullLength()
{
	return text->isDisplayingFullLength();
}

void PlainText::displayFullLength()
{
	text->displayFullLength();
}

void PlainText::addLetter()
{
	text->addLetter();
}
