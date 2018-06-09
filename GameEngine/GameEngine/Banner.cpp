#include "Banner.h"
#include "Text.h"


Banner::Banner()
{
	position = Vector2f(0, 400);
	scale = Vector2f(800, 200);
	bannerColor = Color::White;
	textColor = Color::Black;
	alpha = 0.0f;
	animationState = 0;
	visible = false;
	timer.setTickLength(2.0f);

	text = new Text(position+scale/2, std::string("The Echo Effect"), Vector2f(40,40), 0);
	text->center();
	text->setColor(textColor);

	subText = new Text(position + scale / 2 - Vector2f(0, 30), std::string("Prepare to Die Edition"), Vector2f(20, 20), 0);
	subText->center();
	subText->setColor(textColor);
}


Banner::~Banner()
{
	delete text;
	delete subText;
}

void Banner::draw()
{
	if (!visible)
		return;
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	UIUtils::drawRectangle(position, scale, Color(1,1,1,alpha));
	text->draw();
	subText->draw();

	UIUtils::drawRectangle(position + Vector2f(200, 75), Vector2f(400,2), Color(0,0,0, alpha));

}

void Banner::update(float dt)
{
	text->setAlpha(alpha);
	subText->setAlpha(alpha);
}

void Banner::handleMouseEvents(Mouse & mouse)
{
}

void Banner::handleKeyEvents(Keyboard & keyboard)
{
}

void Banner::setText(std::string& str, std::string& str_sub)
{
	text->setText(str);
	subText->setText(str_sub);

	text->center();
	subText->center();
}

bool Banner::isVisible()
{
	return visible;
}

bool Banner::playAnimation(float dt)
{
	timer.update(dt);
	if (timer.tick()) {
		animationState++;
	}

	if (animationState == 0) {
		visible = true;
		alpha = timer.getCurrentTime() / timer.getTickLength();
	}
	else if (animationState == 1) {
		alpha = 1;
	}
	else if (animationState == 2) {
		alpha = 1-timer.getCurrentTime()/timer.getTickLength();
	}
	else {
		alpha = 0;
		animationState = 0;
		visible = false;
		timer.reset();
		return true;
	}

	return false;
}
