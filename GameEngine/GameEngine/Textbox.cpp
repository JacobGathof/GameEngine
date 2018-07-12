#include "Textbox.h"
#include "Window.h"
#include "Screen.h"
#include "GameState.h"


Text* CompositeText::text;
Text* CompositeText::speakerName;
Vector2f CompositeText::imagePosition;
Vector2f CompositeText::imageScale;
Vector2f CompositeText::textStartPosition;
float CompositeText::textEffectiveWidth;
Vector2f CompositeText::namePosition;
Vector2f CompositeText::nameScale;

Text* Choice::texts[4];
Color Choice::selectedColor(0x00ffffff);
Color Choice::defaultColor(0xffffffff);

bool Textbox::skippable = true;
Timer Textbox::timer;
Timer Textbox::advanceTimer;
Vector2f Textbox::contentPosition;
Vector2f Textbox::contentScale;
Vector2f Textbox::textScale;


#pragma region Textbox

Textbox::Textbox()
{
	textScale = Vector2f(30, 30);

	position = Vector2f(10, 10);
	scale = Vector2f(780, 200);

	contentPosition = position+Vector2f(10,10);
	contentScale = scale - Vector2f(20,20);

	timer.setTickLength(TEXT_SPEED);
	advanceTimer.setPauseOnTick(true);
	advanceTimer.pause();
	advanceTimer.setTickLength(-1);
	visible = false;

	CompositeText::init();
	Choice::init();
}


Textbox::~Textbox()
{
	CompositeText::clean();
	Choice::clean();
}

void Textbox::draw(){
	
	if (!visible) {
		return;
	}

	UIUtils::drawRectangle(position, scale, Color(0x445588ff));
	UIUtils::drawRectangle(position + Vector2f(2,2), scale - Vector2f(4, 4), Color(0x88aaddff));
	UIUtils::drawRectangle(position + Vector2f(4, 4), scale - Vector2f(8, 8), Color(0x000000ff));


	//UIUtils::drawRectangle(contentPosition, contentScale, Color(0xff00ffff));
	//UIUtils::drawRectangle(contentPosition+Vector2f(2,2), contentScale-Vector2f(4,4), Color(0x000000ff));

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
	return new CompositeText(data);
	/*
	if (data.dialogue) {
		return new DialogueText(data.text, data.name, data.portrait, data.offset, data.time);
	}
	else {
		return new PlainText(data.text);
	}
	*/
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
		else if (skippable) {
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
	position[0] = x/2 - scale[0]/2;
	contentPosition = position + Vector2f(10, 10);

	if (current != 0) {
		current->resize();
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

void Textbox::setTextSpeed(float multiplier)
{
	timer.setTickLength(TEXT_SPEED / multiplier);
}

void Textbox::initAdvanceTimer(float time)
{
	advanceTimer.reset();
	advanceTimer.setTickLength(time);
	advanceTimer.unpause();
}

void Textbox::setSkippable(bool skip)
{
	skippable = skip;
}

void Textbox::resetTextboxOptions()
{
	timer.reset();
	timer.setTickLength(TEXT_SPEED);
	skippable = true;
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

/*
void PlainText::init()
{
	text = new Text(Vector2f(24, 160), std::string("-----"), Vector2f(30, 30), 0);
	text->setColor(Color(0xffffffff));
}
*/

/*
void PlainText::prepare()
{
	str = TextUtils::processString(str, Res::get(FontType::DEFAULT), Vector2f(30,30), 738.0f);
	text->setText(str);
	text->resetLength();
}
*/






CompositeText::CompositeText(TextboxContentData & dat){
	data = dat;
}

void CompositeText::init()
{
	textEffectiveWidth = (Textbox::contentPosition[0] + Textbox::contentScale[0]) - textStartPosition[0];

	text = new Text(Vector2f(0,0), std::string("-----"), Textbox::textScale, 0);
	text->setColor(Color(0xffffffff));

	speakerName = new Text(Vector2f(0,0), std::string("-----"), Textbox::textScale, 0);
	speakerName->setColor(Color(0xffffffff));

}

void CompositeText::clean()
{
	delete text;
	delete speakerName;
}

void CompositeText::prepare()
{
	data.text = TextUtils::processString(data.text, Res::get(FontType::DEFAULT), Textbox::textScale, textEffectiveWidth);
	text->setText(data.text);
	text->resetLength();

	speakerName->setText(data.name);
	nameScale = Vector2f(speakerName->getWidth() + 16, 32);

	Textbox::setTextSpeed(data.textSpeed);
	Textbox::setSkippable(data.skippable);

	if (data.time >= 0) {
		Textbox::initAdvanceTimer(data.time);
	}
}

void CompositeText::draw()
{
	text->draw();
	
	UIUtils::drawRectangle(imagePosition, imageScale, Color(0x445588ff));
	UIUtils::drawRectangle(imagePosition + Vector2f(2), imageScale - Vector2f(4), Color(0x88aaddff));
	UIUtils::drawRectangle(imagePosition + Vector2f(4), imageScale - Vector2f(8), Color(0x000000ff));
	UIUtils::drawImage(imagePosition + Vector2f(4), imageScale - Vector2f(8), data.portrait, data.offset);

	
	UIUtils::drawRectangle(namePosition, nameScale, Color(0x445588ff));
	UIUtils::drawRectangle(namePosition+Vector2f(2), nameScale-Vector2f(4), Color(0x88aaddff));
	UIUtils::drawRectangle(namePosition+Vector2f(4), nameScale-Vector2f(8), Color(0x000000ff));
	

	speakerName->draw();
	
}

void CompositeText::finish()
{
	Textbox::resetTextboxOptions();
}

void CompositeText::resize()
{
	imageScale = Vector2f(100, 100);
	imagePosition = Textbox::contentPosition + Vector2f(0, Textbox::contentScale[1]-imageScale[1]) + Vector2f(4, -4);
	textStartPosition = Textbox::contentPosition + Vector2f(0, Textbox::contentScale[1] - Textbox::textScale[1]) + Vector2f(imageScale[0] + 8, 0);
	namePosition = Textbox::contentPosition + Vector2f(4, Textbox::contentScale[1]);


	text->setPosition(textStartPosition);
	speakerName->setPosition(namePosition + Vector2f(8,0));
}

bool CompositeText::isDisplayingFullLength()
{
	return text->isDisplayingFullLength();
}

void CompositeText::displayFullLength()
{
	text->displayFullLength();
}

void CompositeText::addLetter()
{
	text->addLetter();
}
