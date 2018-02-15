#include "SettingsPage.h"



SettingsPage::SettingsPage()
{
}


SettingsPage::~SettingsPage()
{
}

void SettingsPage::draw()
{
	Vector2f pos = position;
	if (parentOffset != 0) {
		pos += *parentOffset;
	}
	UIUtils::drawRectangle(Vector2f(20, 20) + pos, Vector2f(80, 80), Color(0xffffffff));
	UIUtils::drawRectangle(Vector2f(22, 22) + pos, Vector2f(76, 76), Color(0x0000ffff));
	UIUtils::drawRectangle(Vector2f(24, 24) + pos, Vector2f(72, 72), Color(0x000000ff));
}

void SettingsPage::update(float dt)
{
}
