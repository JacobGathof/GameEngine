#include "Statusbar.h"
#include "Screen.h"
#include "UIText.h"

Statusbar::Statusbar()
{
	health.name =	"HP: ";
	stamina.name =	"ST: ";
	mana.name =		"MP: ";

	health.text =	new UIText(pos_h - Vector2f(offsetX, 0), std::string("--------"), Vector2f(scale_h[1]), 0);
	stamina.text =	new UIText(pos_s - Vector2f(offsetX, 0), std::string("--------"), Vector2f(scale_h[1]), 0);
	mana.text =		new UIText(pos_m - Vector2f(offsetX, 0), std::string("--------"), Vector2f(scale_h[1]), 0);
	goldText =		new UIText(pos_g - Vector2f(offsetX, 0), std::string("$64"), Vector2f(scale_h[1]), 0);

	updateStats(health);
	updateStats(stamina);
	updateStats(mana);
}


Statusbar::~Statusbar()
{
	delete health.text;
	delete stamina.text;
	delete mana.text;
	delete goldText;

}

void Statusbar::draw()
{
	//if (!visible)
	//	return;

	UIUtils::drawRectangle(pos_h + fadePos, scale_h, backdrop*fadeColor);
	UIUtils::drawRectangle(pos_h + fadePos + barPadding, (scale_h - 2 * barPadding)*Vector2f(health.percentageShown, 1), healthLostColor*fadeColor);
	UIUtils::drawRectangle(pos_h + fadePos + barPadding, (scale_h - 2 * barPadding)*Vector2f(health.percentage, 1), healthColor*fadeColor);
	

	UIUtils::drawRectangle(pos_s + fadePos, scale_s, backdrop*fadeColor);
	UIUtils::drawRectangle(pos_s + fadePos + barPadding, (scale_s - 2 * barPadding)*Vector2f(stamina.percentageShown, 1), staminaLostColor*fadeColor);
	UIUtils::drawRectangle(pos_s + fadePos + barPadding, (scale_s - 2 * barPadding)*Vector2f(stamina.percentage, 1), staminaColor*fadeColor);
	

	UIUtils::drawRectangle(pos_m + fadePos, scale_m, backdrop*fadeColor);
	UIUtils::drawRectangle(pos_m + fadePos + barPadding, (scale_m - 2 * barPadding)*Vector2f(mana.percentageShown, 1), manaLostColor*fadeColor);
	UIUtils::drawRectangle(pos_m + fadePos + barPadding, (scale_m - 2 * barPadding)*Vector2f(mana.percentage, 1), manaColor*fadeColor);


	UIUtils::drawRectangle(pos_box + fadePos, scale_box, boxOutline*fadeColor);
	UIUtils::drawRectangle(pos_box + fadePos + boxPadding, scale_box - 2 * boxPadding, boxColor*fadeColor);


	health.text->draw(fadePos, fadeColor);
	stamina.text->draw(fadePos, fadeColor);
	mana.text->draw(fadePos, fadeColor);
	goldText->draw(fadePos, fadeColor);

}

void Statusbar::update(float dt)
{
	
	updateComponent(health, dt);
	updateComponent(stamina, dt);
	updateComponent(mana, dt);


	timer.update(dt);
	timer.setTickLength(1.0f);
	if (timer.tick()) {
		mana.hpc -= 5;
	}

	
	/*
	if (fading == 1 || fading == 3) {
		fadeTimer.update(dt);
	}

	if (visible && fading == 0) {
		fadeTimer.unpause();
		fading = 1;
	}

	if (fading == 1) {
		fadePos[1] = fadeCurve.positionAt(fadeTimer.getTotalTime() * fadeTime)[1];
		fadeColor[3] = 1 - fadeTimer.getTotalTime() * fadeTime;


		if (fadeTimer.getTotalTime() * fadeTime >= 1.0f) {
			fadeTimer.reset();
			fadeTimer.pause();
			fading = 2;
		}
	}
	
	if (!visible && fading == 2) {
		fadeTimer.unpause();
		fading = 3;
	}

	if (fading == 3) {
		fadePos[1] = fadeCurve.positionAt(1 - fadeTimer.getTotalTime()  * fadeTime)[1];
		fadeColor[3] = fadeTimer.getTotalTime() * fadeTime;

		if (fadeTimer.getTotalTime() * fadeTime >= 1.0f) {
			fadeTimer.reset();
			fadeTimer.pause();
			fading = 0;
		}
	}

	*/



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
	float height = y;
	float width = x*.4f;

	pos_box = Vector2f(offsetX, height - offsetBoxY - boxHeight);
	scale_box = Vector2f(boxHeight, boxWidth);

	pos_h = Vector2f(pos_box[0] + scale_box[0] + offsetX, height - offsetY - barHeight);
	pos_s = Vector2f(pos_box[0] + scale_box[0] + offsetX, height - offsetY - 2 * barHeight - 1 * gap);
	pos_m = Vector2f(pos_box[0] + scale_box[0] + offsetX, height - offsetY - 3 * barHeight - 2 * gap);
	pos_g = Vector2f(pos_box[0] + scale_box[0] + offsetX, height - offsetY - 4 * barHeight - 3 * gap);

	scale_h = Vector2f(width + 2 * barPadding, barHeight);
	scale_s = Vector2f(width + 2 * barPadding, barHeight);
	scale_m = Vector2f(width + 2 * barPadding, barHeight);

	health.text->setPosition(	Vector2f(pos_box[0]+offsetX, pos_h[1]));
	stamina.text->setPosition(	Vector2f(pos_box[0]+offsetX, pos_s[1]));
	mana.text->setPosition(		Vector2f(pos_box[0]+offsetX, pos_m[1]));
	goldText->setPosition(Vector2f(pos_box[0] + offsetX, pos_g[1]));

	health.text->setScale(Vector2f(scale_h[1]));
	stamina.text->setScale(Vector2f(scale_h[1]));
	mana.text->setScale(Vector2f(scale_h[1]));
	goldText->setScale(Vector2f(scale_h[1]));
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
	data.text->setText(data.name + display);
}


std::string Statusbar::formatStatString(float cur, float max)
{
	return std::to_string((int)(cur)) + "/" + std::to_string((int)(max));
}
