#include "CenteredText.h"
#include "Textbox.h"

Text* CenteredText::text;
Vector2f CenteredText::textStartPosition;
float CenteredText::textEffectiveWidth;



CenteredText::CenteredText(TextboxContentData & dat)
{
	data = dat;
}

void CenteredText::init()
{
	text = new Text(Vector2f(0, 0), std::string("-----"), Textbox::textScale, 0);
	text->setColor(Color(0xffffffff));
}

void CenteredText::clean()
{
	delete text;
}

void CenteredText::prepare()
{
	text->setText(data.text);
	text->resetLength();
	text->setPosition(Textbox::contentPosition + Textbox::contentScale / 2);
	text->setScale(Textbox::textScale * data.scale);

	Textbox::setTextSpeed(data.textSpeed);
	Textbox::setSkippable(data.skippable);

	if (data.time >= 0) {
		Textbox::initAdvanceTimer(data.time);
	}
}

void CenteredText::draw()
{
	text->draw();
}

void CenteredText::finish()
{
	Textbox::resetTextboxOptions();
}

void CenteredText::resize()
{
}

bool CenteredText::isDisplayingFullLength()
{
	return text->isDisplayingFullLength();
}

void CenteredText::displayFullLength()
{
	text->displayFullLength();
	text->center();
}

void CenteredText::addLetter()
{
	text->addLetter();
	text->centerDisplayable();
}
