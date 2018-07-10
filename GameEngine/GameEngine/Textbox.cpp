#include "Textbox.h"
#include "Window.h"
#include "Screen.h"
#include "GameState.h"

Text* PlainText::text;
Text* DialogueText::text;
Text* DialogueText::speakerName;
Text* Choice::texts[4];
Color Choice::selectedColor(0x00ffffff);
Color Choice::defaultColor(0xffffffff);


#pragma region Textbox

Textbox::Textbox()
{
	textScale = Vector2f(30, 30);
	textStartPos = Vector2f(24+100, 160);
	position = Vector2f(10, 10);
	scale = Vector2f(780, 200);

	timer.setTickLength(0.05f);
	advanceTimer.setPauseOnTick(true);
	advanceTimer.pause();
	advanceTimer.setTickLength(-1);
	visible = false;

	DialogueText::init();
	PlainText::init();
	Choice::init();
}


Textbox::~Textbox()
{
	DialogueText::clean();
	PlainText::clean();
	Choice::clean();
}

void Textbox::draw(){
	
	if (!visible) {
		return;
	}

	UIUtils::drawRectangle(position, scale, Color(0xaaaaffff));
	UIUtils::drawRectangle(position + Vector2f(2,2), scale - Vector2f(4, 4), Color(0xffffffff));
	UIUtils::drawRectangle(position + Vector2f(4, 4), scale - Vector2f(8, 8), Color(0x000000ff));

	if (current != 0) {
		current->draw();
	}
	
}

void Textbox::update(float dt)
{
	timer.update(dt);
	advanceTimer.update(dt);

	if (timer.tick() && visible && current!= 0) {
		current->addLetter();
	}

	if (advanceTimer.tick() && visible) {
		advanceText();
	}

	if (!visible) {
		GameState::textboxEmpty = true;
	}
}

void Textbox::advanceText()
{
	if (current != 0) {
		current->finish();
	}

	if (hasNext()) {
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
	else {
		hide();
	}
}

TextboxContent * Textbox::createContentFromData(TextboxContentData & data)
{
	if (data.dialogue) {
		return new DialogueText(data.text, data.name, data.portrait, data.offset);
	}
	else {
		return new PlainText(data.text);
	}
}

void Textbox::addText(TextboxContentData & data)
{
	addTextContentToQueue(createContentFromData(data));
}


void Textbox::addChoiceToQueue(List<std::string>& text)
{
	addTextContentToQueue(new Choice(text));
}

void Textbox::addTextContentToQueue(TextboxContent * content)
{
	queue.push(content);
	GameState::textboxEmpty = false;
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
		keyboard.setKeyState(VirtualKey::INTERACT, 0);
		if (current == 0 || current->isDisplayingFullLength()) {
			advanceText();
		}
		else {
			current->displayFullLength();
		}
	}
	else {
		if (current != 0) {
			current->handleKeyEvents(keyboard);
		}
	}
}

void Textbox::resize(int x, int y)
{
	textStartPos = Vector2f(24 + 100, 160);
	position[0] = x/2 - scale[0]/2;
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

#pragma endregion


#pragma region Choice

Choice::Choice(List<std::string>& ch) : choices(ch)
{
	choices = ch;
}

Choice::~Choice()
{
}

void Choice::init()
{
	texts[0] = new Text(Vector2f(24, 160), std::string(""), Vector2f(30, 30), 0);
	texts[1] = new Text(Vector2f(24, 60), std::string("Test"), Vector2f(30, 30), 0);
	texts[2] = new Text(Vector2f(424, 160), std::string(""), Vector2f(30, 30), 0);
	texts[3] = new Text(Vector2f(424, 60), std::string(""), Vector2f(30, 30), 0);
}

void Choice::clean()
{
	delete texts[0];
	delete texts[1];
	delete texts[2];
	delete texts[3];
}

void Choice::draw()
{
	for (int i = 0; i < numChoices; i++) {
		texts[i]->draw();
	}
}

void Choice::prepare()
{
	numChoices = 0;
	choicePointer = 0;

	numChoices = choices.size();
	for (int i = 0; i < numChoices; i++) {
		texts[i]->setText(*(choices.begin() + i));
		texts[i]->setColor(defaultColor);
	}

	texts[0]->setColor(selectedColor);

}

void Choice::finish()
{
	GameState::choicePointer = choicePointer;
}

bool Choice::isDisplayingFullLength(){
	return true;
}

void Choice::displayFullLength(){
}

void Choice::addLetter(){
}

void Choice::handleKeyEvents(Keyboard & keyboard)
{
	int i = 0;
	if (keyboard.press(VirtualKey::ARROW_UP)) {i = -1;}
	if (keyboard.press(VirtualKey::ARROW_DOWN)) { i = 1; }
	if (keyboard.press(VirtualKey::ARROW_LEFT)) { i = -2; }
	if (keyboard.press(VirtualKey::ARROW_RIGHT)) { i = 2; }

	if (i != 0) {
		texts[choicePointer]->setColor(defaultColor);
		choicePointer += i;
		choicePointer = (choicePointer % numChoices + numChoices) % numChoices;
		texts[choicePointer]->setColor(selectedColor);

	}
}

#pragma endregion


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

void PlainText::finish()
{
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

void PlainText::handleKeyEvents(Keyboard & keyboard)
{
}

void TextboxContent::handleKeyEvents(Keyboard & keyboard)
{
}




DialogueText::DialogueText(std::string & st, std::string & nm, TextureType tex, Vector2f & offset)
{
	str = st;
	name = nm;
	speakerPortrait = tex;
	imageOffset = offset;
}

void DialogueText::init()
{
	text = new Text(Vector2f(24 + 100, 160), std::string("-----"), Vector2f(30, 30), 0);
	text->setColor(Color(0xffffffff));

	speakerName = new Text(Vector2f(24, 60), std::string("-----"), Vector2f(30, 30), 0);
	speakerName->setColor(Color(0xaaaaffff));
}

void DialogueText::clean()
{
	delete text;
	delete speakerName;
}

void DialogueText::prepare()
{
	str = TextUtils::processString(str, Res::get(FontType::DEFAULT), Vector2f(30, 30), 738.0f);
	text->setText(str);
	text->resetLength();

	speakerName->setText(name);

	//advanceTimer.unpause();
	//advanceTimer.setTickLength(3.0f);
}

void DialogueText::draw()
{
	text->draw();

	UIUtils::drawRectangle(Vector2f(10, 110) + Vector2f(6, -6), Vector2f(100, 100), Color(0x000000dd));
	UIUtils::drawRectangle(Vector2f(12, 112) + Vector2f(6, -6), Vector2f(96, 96), Color(0xaaaaaa88));
	UIUtils::drawRectangle(Vector2f(14, 114) + Vector2f(6, -6), Vector2f(92, 92), Color(0x000000dd));
	UIUtils::drawImage(Vector2f(14, 114) + Vector2f(6, -6), Vector2f(92, 92), speakerPortrait, imageOffset);

	UIUtils::drawRectangle(Vector2f(10, 60) + Vector2f(6, -6), Vector2f(100, 40), Color(0x000000dd));
	UIUtils::drawRectangle(Vector2f(12, 62) + Vector2f(6, -6), Vector2f(96, 36), Color(0xaaaaaa88));
	UIUtils::drawRectangle(Vector2f(14, 64) + Vector2f(6, -6), Vector2f(92, 32), Color(0x000000dd));

	speakerName->draw();

}

void DialogueText::finish()
{
}

bool DialogueText::isDisplayingFullLength()
{
	return text->isDisplayingFullLength();
}

void DialogueText::displayFullLength()
{
	text->displayFullLength();
}

void DialogueText::addLetter()
{
	text->addLetter();
}

void DialogueText::handleKeyEvents(Keyboard & keyboard)
{
}
