#include "Choice.h"
#include "GameState.h"
#include "Textbox.h"

Text* Choice::texts[4];
Color Choice::selectedColor(0x00ffffff);
Color Choice::defaultColor(0xffffffff);


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
	texts[1] = new Text(Vector2f(24, 60), std::string(""), Vector2f(30, 30), 0);
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

	/*
	UIUtils::drawRectangle(Textbox::contentPosition + Vector2f(Textbox::contentScale[0] / 2 - 1, 0), Vector2f(2, Textbox::contentScale[1]), Color::White);
	UIUtils::drawRectangle(Textbox::contentPosition + Vector2f(0, Textbox::contentScale[1] / 2 - 1), Vector2f(Textbox::contentScale[0], 2), Color::White);

	UIUtils::drawRectangle(Textbox::contentPosition + Vector2f(0, 2*Textbox::contentScale[1] / 8 - 1), Vector2f(Textbox::contentScale[0], 2), Color::White);
	UIUtils::drawRectangle(Textbox::contentPosition + Vector2f(0, 6*Textbox::contentScale[1] / 8 - 1), Vector2f(Textbox::contentScale[0], 2), Color::White);

	UIUtils::drawRectangle(Textbox::contentPosition + Vector2f(0, 0 * Textbox::contentScale[1] / 8 - 1), Vector2f(Textbox::contentScale[0], 2), Color::White);
	UIUtils::drawRectangle(Textbox::contentPosition + Vector2f(0, 8 * Textbox::contentScale[1] / 8 - 1), Vector2f(Textbox::contentScale[0], 2), Color::White);


	UIUtils::drawRectangle(Textbox::contentPosition + Vector2f(0, 1 * Textbox::contentScale[1] / 8 - 1), Vector2f(Textbox::contentScale[0], 2), Color::White);
	UIUtils::drawRectangle(Textbox::contentPosition + Vector2f(0, 7 * Textbox::contentScale[1] / 8 - 1), Vector2f(Textbox::contentScale[0], 2), Color::White);
	*/
}

void Choice::prepare()
{
	numChoices = 0;
	choicePointer = 0;

	numChoices = choices.size();
	for (int i = 0; i < numChoices; i++) {
		texts[i]->setText(choices[i]);
		texts[i]->setColor(defaultColor);
	}

	texts[0]->setColor(selectedColor);

}

void Choice::finish()
{
	GameState::choicePointer = choicePointer;
}

void Choice::resize()
{
	Vector2f textStartPosition = Textbox::contentPosition + Vector2f(0, Textbox::contentScale[1] - Textbox::textScale[1]);

	texts[0]->setPosition(textStartPosition + Vector2f(32, -2*Textbox::contentScale[1] / 16));
	texts[1]->setPosition(textStartPosition + Vector2f(32, -5*Textbox::contentScale[1] / 16));
	texts[2]->setPosition(textStartPosition + Vector2f(32, -8*Textbox::contentScale[1] / 16));
	texts[3]->setPosition(textStartPosition + Vector2f(32, -11*Textbox::contentScale[1] / 16));
}

bool Choice::isDisplayingFullLength() {
	return true;
}

void Choice::displayFullLength() {
}

void Choice::addLetter() {
}

void Choice::handleKeyEvents(Keyboard & keyboard)
{
	int i = 0;
	if (keyboard.press(VirtualKey::ARROW_UP)) { i = -1; }
	if (keyboard.press(VirtualKey::ARROW_DOWN)) { i = 1; }
	//if (keyboard.press(VirtualKey::ARROW_LEFT)) { i = -2; }
	//if (keyboard.press(VirtualKey::ARROW_RIGHT)) { i = 2; }

	if (i != 0) {
		texts[choicePointer]->setColor(defaultColor);
		choicePointer += i;
		choicePointer = (choicePointer % numChoices + numChoices) % numChoices;
		texts[choicePointer]->setColor(selectedColor);

	}
}
