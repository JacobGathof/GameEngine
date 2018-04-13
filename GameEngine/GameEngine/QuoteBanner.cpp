#include "QuoteBanner.h"
#include "Text.h"


QuoteBanner::QuoteBanner()
{
	position = Vector2f(0, 500);
	scale = Vector2f(800, 200);
	textColor = Color::White;
	animationState = 0;
	timer.setTickLength(0.05f);
	alpha = 1.0f;

	text = new Text(position + scale / 2, std::string("The Echo Effect"), Vector2f(40, 40), 0);
	text->center();
	text->setColor(textColor);
	text->resetLength();
}


QuoteBanner::~QuoteBanner()
{
	delete text;
}

void QuoteBanner::draw()
{
	if (!visible)
		return;

	text->draw();
}

void QuoteBanner::update(float dt)
{
	if (!visible)
		return;

	timer.update(dt);
	if (timer.tick()) {
		if (animationState == 0) {
			text->addLetter();
		}
		if (text->isDisplayingFullLength()) {
			animationState = 1;
		}
	}
	if (animationState == 1) {
		alpha -= dt / 1.0f;
		text->setAlpha(alpha);
	}
	if (alpha <= 0) {
		visible = false;
	}
}

void QuoteBanner::setText(std::string & str)
{
	timer.reset();

	text->setText(str);
	text->center();
	text->resetLength();
	
	visible = true;
	animationState = 0;
	timer.reset();
	alpha = 1.0f;
	text->setAlpha(alpha);
}

bool QuoteBanner::isVisible()
{
	return visible;
}
