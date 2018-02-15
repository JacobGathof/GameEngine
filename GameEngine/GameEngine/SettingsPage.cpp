#include "SettingsPage.h"



SettingsPage::SettingsPage(Vector2f *position)
{
	parentOffset = position;
}


SettingsPage::~SettingsPage()
{
}

void SettingsPage::draw()
{
	Vector2f position;
	if (parentOffset != 0) {
		position += *parentOffset;
	}
	UIUtils::drawRectangle(Vector2f(20, 20) + position, Vector2f(80, 80), Color(0xffffffff));
	UIUtils::drawRectangle(Vector2f(22, 22) + position, Vector2f(76, 76), Color(0x0000ffff));
	UIUtils::drawRectangle(Vector2f(24, 24) + position, Vector2f(72, 72), Color(0x000000ff));
}

void SettingsPage::update(float dt)
{
}
