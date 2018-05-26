#include "Statusbar.h"
#include "Screen.h"
#include "Text.h"


Statusbar::Statusbar()
{

	healthText =	new Text(pos_h - Vector2f(offsetX, 0), std::string("100/100"), Vector2f(scale_h[1]), 0);
	staminaText =	new Text(pos_s - Vector2f(offsetX, 0), std::string("100/100"), Vector2f(scale_h[1]), 0);
	manaText =		new Text(pos_m - Vector2f(offsetX, 0), std::string("100/100"), Vector2f(scale_h[1]), 0);
}


Statusbar::~Statusbar()
{
	delete healthText;
	delete staminaText;
	delete manaText;
}

void Statusbar::draw()
{
	if (!visible)
		return;

	UIUtils::drawRectangle(pos_h			, scale_h				, backdrop);
	UIUtils::drawRectangle(pos_h+barPadding	, (scale_h*Vector2f(healthPercentage, 1))-2*barPadding	, healthColor);

	UIUtils::drawRectangle(pos_s			, scale_s				, backdrop);
	UIUtils::drawRectangle(pos_s+barPadding	, scale_s-2*barPadding	, staminaColor);

	UIUtils::drawRectangle(pos_m			, scale_m				, backdrop);
	UIUtils::drawRectangle(pos_m+barPadding	, scale_m-2*barPadding	, magicColor);


	UIUtils::drawRectangle(pos_box, scale_box, Color(0x8888aa88));
	UIUtils::drawRectangle(pos_box + boxPadding, scale_box - 2 * boxPadding, boxColor);


	healthText->draw();
	staminaText->draw();
	manaText->draw();

}

void Statusbar::update(float dt)
{
	
	if( (*health_max != hpml) || (*health_cur != hpcl)){
		updateStats();
	}
	

	hpml = *health_max;
	hpcl = *health_cur;



	hpc -= dt;

}


void Statusbar::resize(int x, int y)
{
	height = y;
	width = x*.4f;

	pos_box = Vector2f(offsetX, height - offsetY - boxHeight);
	scale_box = Vector2f(boxHeight, boxWidth);

	pos_h = Vector2f(pos_box[0] + scale_box[0] + offsetX, height - offsetY - barHeight);
	pos_s = Vector2f(pos_box[0] + scale_box[0] + offsetX, height - offsetY - 2 * barHeight - gap);
	pos_m = Vector2f(pos_box[0] + scale_box[0] + offsetX, height - offsetY - 3 * barHeight - 2 * gap);

	scale_h = Vector2f(width + 2 * barPadding, barHeight);
	scale_s = Vector2f(width + 2 * barPadding, barHeight);
	scale_m = Vector2f(width + 2 * barPadding, barHeight);

	healthText->setPosition(	Vector2f(pos_box[0]+offsetX, pos_h[1]));
	staminaText->setPosition(	Vector2f(pos_box[0]+offsetX, pos_s[1]));
	manaText->setPosition(		Vector2f(pos_box[0]+offsetX, pos_m[1]));

	healthText->setScale(Vector2f(scale_h[1]));
	staminaText->setScale(Vector2f(scale_h[1]));
	manaText->setScale(Vector2f(scale_h[1]));
}

void Statusbar::updateStats()
{
	healthPercentage = *health_cur / *health_max;
	std::string healthDisplay = formatStatString(*health_cur, *health_max);
	healthText->setText(healthDisplay);

}

std::string Statusbar::formatStatString(float cur, float max)
{
	return std::to_string((int)(cur)) + "/" + std::to_string((int)(max));
}
