#include "SettingsPage.h"
#include "GameState.h"

SettingsPage::SettingsPage()
{
	comps[0] = new Button(Vector2f(0, 0), Vector2f(100, 100), std::string("Fullscreen"), new FullscreenButtonAction());
	comps[1] = new Slider(Vector2f(200, 200), Vector2f(300, 10), &GameState::sliderValue, .25f, 1.0f, 0);
}


SettingsPage::~SettingsPage()
{
	for (int i = 0; i < 2; i++) {
		delete comps[i];
	}
}

void SettingsPage::draw()
{
	/*
	Vector2f pos = position;
	if (parentOffset != 0) {
		pos += *parentOffset;
	}
	UIUtils::drawRectangle(Vector2f(20, 20) + pos, Vector2f(80, 80), Color(0xffffffff));
	UIUtils::drawRectangle(Vector2f(22, 22) + pos, Vector2f(76, 76), Color(0x0000ffff));
	UIUtils::drawRectangle(Vector2f(24, 24) + pos, Vector2f(72, 72), Color(0x000000ff));
	*/

	for (int i = 0; i < 2; i++) {
		comps[i]->draw();
	}


}

void SettingsPage::update(float dt)
{
	for (int i = 0; i < 2; i++) {
		comps[i]->update(dt);
	}
}

void SettingsPage::hover(Vector2f & pos)
{
	for (int i = 0; i < 2; i++) {
		comps[i]->hover(pos);
	}
}

void SettingsPage::click(Vector2f & pos)
{
	for (int i = 0; i < 2; i++) {
		comps[i]->click(pos);
	}
}

void SettingsPage::release(Vector2f & pos)
{
	for (int i = 0; i < 2; i++) {
		comps[i]->release(pos);
	}
}

