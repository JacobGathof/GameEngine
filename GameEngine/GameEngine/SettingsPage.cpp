#include "SettingsPage.h"


SettingsPage::SettingsPage()
{
	button = new Button(Vector2f(0,0), Vector2f(100,100), std::string("Fullscreen"), new FullscreenButtonAction());
}


SettingsPage::~SettingsPage()
{
	delete button;
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

	button->draw();

}

void SettingsPage::update(float dt)
{
	button->update(dt);
}

void SettingsPage::hover(Vector2f & pos)
{
	button->hover(pos);
}

void SettingsPage::click(Vector2f & pos)
{
	button->click(pos);
}

void SettingsPage::release(Vector2f & pos)
{
	button->release(pos);
}

