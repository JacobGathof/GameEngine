#include "Textbox.h"
#include "Window.h"
#include "Screen.h"
#include "GameState.h"

#include "CompositeText.h"
#include "Choice.h"
#include "CenteredText.h"


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
	CenteredText::init();
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
	UIUtils::drawBorder(position, scale, Color(0x445588ff), 8, 2);
	UIUtils::drawRectangle(position + Vector2f(4, 4), scale - Vector2f(8, 8), Color(0x000000ff));

	UIUtils::drawImage(position + Vector2f(6, 6), Vector2f(32, 32), TextureType::T_UI_DECOR, Vector2f(0, 0), Color(0x88aaddff));
	UIUtils::drawImage(position + scale - Vector2f(6, 6), Vector2f(-32,-32), TextureType::T_UI_DECOR, Vector2f(0, 0), Color(0x88aaddff));

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

	CompositeText::resize();
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




