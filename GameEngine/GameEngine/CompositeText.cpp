#include "CompositeText.h"
#include "ResourceManager.h"
#include "Textbox.h"


Text* CompositeText::text;
Text* CompositeText::speakerName;
Vector2f CompositeText::imagePosition;
Vector2f CompositeText::imageScale;
Vector2f CompositeText::textStartPosition;
float CompositeText::textEffectiveWidth;
Vector2f CompositeText::namePosition;
Vector2f CompositeText::nameScale;
bool CompositeText::currentDialogue;



CompositeText::CompositeText(TextboxContentData & dat) {
	data = dat;
}

void CompositeText::init()
{

	text = new Text(Vector2f(0, 0), std::string("-----"), Textbox::textScale, 0);
	text->setColor(Color(0xffffffff));

	speakerName = new Text(Vector2f(0, 0), std::string("-----"), Textbox::textScale, 0);
	speakerName->setColor(Color(0xffffffff));

}

void CompositeText::clean()
{
	delete text;
	delete speakerName;
}

void CompositeText::prepare()
{
	Vector2f offset = data.dialogue * Vector2f(imageScale[0] + 8, 0);

	textEffectiveWidth = (Textbox::contentPosition[0] + Textbox::contentScale[0]) - (textStartPosition[0] + offset[0]);

	data.text = TextUtils::processString(data.text, Res::get(FontType::DEFAULT), Textbox::textScale, textEffectiveWidth);
	text->setText(data.text);
	text->resetLength();
	text->setPosition(textStartPosition + offset);


	speakerName->setText(data.name);
	nameScale = Vector2f(speakerName->getWidth() + 16, 32);
	currentDialogue = data.dialogue;

	Textbox::setTextSpeed(data.textSpeed);
	Textbox::setSkippable(data.skippable);

	if (data.time >= 0) {
		Textbox::initAdvanceTimer(data.time);
	}
}

void CompositeText::resize()
{
	imageScale = Vector2f(100, 100);
	imagePosition = Textbox::contentPosition + Vector2f(0, Textbox::contentScale[1] - imageScale[1]) + Vector2f(4, -4);
	textStartPosition = Textbox::contentPosition + Vector2f(0, Textbox::contentScale[1] - Textbox::textScale[1]);
	namePosition = Textbox::contentPosition + Vector2f(4, Textbox::contentScale[1]);


	Vector2f offset = currentDialogue * Vector2f(imageScale[0] + 8, 0);
	text->setPosition(textStartPosition + offset);

	speakerName->setPosition(namePosition + Vector2f(8, 0));
}

void CompositeText::draw()
{
	text->draw();

	if (data.dialogue) {
		UIUtils::drawRectangle(imagePosition, imageScale, Color(0x445588ff) /*Color(0xbb6666ff)*/);
		UIUtils::drawRectangle(imagePosition + Vector2f(2), imageScale - Vector2f(4), Color(0x88aaddff) /*Color(0x884455ff)*/);
		UIUtils::drawBorder(imagePosition, imageScale, Color(0x445588ff), 8, 2);
		UIUtils::drawRectangle(imagePosition + Vector2f(4), imageScale - Vector2f(8), Color(0x000000ff));

		UIUtils::drawImage(imagePosition + Vector2f(4), imageScale - Vector2f(8), data.portrait, data.offset);

		if (data.name != "") {
			UIUtils::drawRectangle(namePosition, nameScale, Color(0x445588ff));
			UIUtils::drawRectangle(namePosition + Vector2f(2), nameScale - Vector2f(4), Color(0x88aaddff));
			UIUtils::drawRectangle(namePosition + Vector2f(4), nameScale - Vector2f(8), Color(0x000000ff));

			speakerName->draw();
		}
	}
}

void CompositeText::finish()
{
	Textbox::resetTextboxOptions();
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


