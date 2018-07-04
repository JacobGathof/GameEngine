#include "Statusbar.h"
#include "Screen.h"
#include "Text.h"


Statusbar::Statusbar()
{
	health.text =	new Text(pos_h - Vector2f(offsetX, 0), std::string("100/100"), Vector2f(scale_h[1]), 0);
	stamina.text =	new Text(pos_s - Vector2f(offsetX, 0), std::string("100/100"), Vector2f(scale_h[1]), 0);
	mana.text =		new Text(pos_m - Vector2f(offsetX, 0), std::string("100/100"), Vector2f(scale_h[1]), 0);
}


Statusbar::~Statusbar()
{
	delete health.text;
	delete stamina.text;
	delete mana.text;

}

void Statusbar::draw()
{
	if (!visible)
		return;

	UIUtils::drawRectangle(pos_h, scale_h, backdrop);
	UIUtils::drawRectangle(pos_h + barPadding, (scale_h - 2 * barPadding)*Vector2f(health.percentageShown, 1), healthLostColor);
	UIUtils::drawRectangle(pos_h + barPadding, (scale_h - 2 * barPadding)*Vector2f(health.percentage, 1), healthColor);
	

	UIUtils::drawRectangle(pos_s, scale_s, backdrop);
	UIUtils::drawRectangle(pos_s + barPadding, (scale_s - 2 * barPadding)*Vector2f(stamina.percentageShown, 1), staminaLostColor);
	UIUtils::drawRectangle(pos_s + barPadding, (scale_s - 2 * barPadding)*Vector2f(stamina.percentage, 1), staminaColor);
	

	UIUtils::drawRectangle(pos_m			, scale_m				, backdrop);
	UIUtils::drawRectangle(pos_m+barPadding	, scale_m-2*barPadding	, magicColor);


	UIUtils::drawRectangle(pos_box, scale_box, Color(0x8888aa88));
	UIUtils::drawRectangle(pos_box + boxPadding, scale_box - 2 * boxPadding, boxColor);


	health.text->draw();
	stamina.text->draw();
	mana.text->draw();

}

void Statusbar::update(float dt)
{
	
	updateComponent(health, dt);
	updateComponent(stamina, dt);
	updateComponent(mana, dt);


	timer.update(dt);
	timer.setTickLength(1.0f);
	if (timer.tick()) {
		health.hpc -= 5;
	}

}


void Statusbar::updateComponent(DataContainer & data, float dt)
{
	if ((*data.data_max != data.hpml) || (*data.data_cur != data.hpcl)) {
		data.health_lost = data.hpcl - *data.data_cur;
		//health_lost = hpcs - *health_cur;
		updateStats(data);
	}

	data.hpml = *data.data_max;
	data.hpcl = *data.data_cur;

	if (data.hpcs > data.hpcl) {
		data.hpcs -= data.health_lost * dt;
		data.hpcs = max(data.hpcs, 0), 1;
		data.percentageShown = data.hpcs / *data.data_max;
	}
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

	health.text->setPosition(	Vector2f(pos_box[0]+offsetX, pos_h[1]));
	stamina.text->setPosition(	Vector2f(pos_box[0]+offsetX, pos_s[1]));
	mana.text->setPosition(		Vector2f(pos_box[0]+offsetX, pos_m[1]));

	health.text->setScale(Vector2f(scale_h[1]));
	stamina.text->setScale(Vector2f(scale_h[1]));
	mana.text->setScale(Vector2f(scale_h[1]));
}

void Statusbar::setHealth(float * maxHealth, float * currHealth)
{
	health.data_max = maxHealth;
	health.data_cur = currHealth;
	health.hpml = *maxHealth;
	health.hpcl = *currHealth;
}

void Statusbar::setStamina(float * maxStamina, float * currStamina)
{
	stamina.data_max = maxStamina;
	stamina.data_cur = currStamina;
	stamina.hpml = *maxStamina;
	stamina.hpcl = *currStamina;
}

void Statusbar::setMana(float * maxMana, float * currMana)
{
	mana.data_max = maxMana;
	mana.data_cur = currMana;
	mana.hpml = *maxMana;
	mana.hpcl = *currMana;
}


void Statusbar::updateStats(DataContainer & data)
{
	data.percentage = min(max(*data.data_cur / *data.data_max, 0), 1);
	std::string display = formatStatString(*data.data_cur, *data.data_max);
	data.text->setText(display);
}


std::string Statusbar::formatStatString(float cur, float max)
{
	return std::to_string((int)(cur)) + "/" + std::to_string((int)(max));
}
