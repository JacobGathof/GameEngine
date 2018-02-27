#include "SettingsPage.h"
#include "GameState.h"

SettingsPage::SettingsPage()
{
	comps[0] = new Button(Vector2f(50, 600), Vector2f(200, 50), std::string("Fullscreen"), new FullscreenButtonAction());
	comps[1] = new Slider(Vector2f(50, 770), Vector2f(300, 10), std::string("Transparency"), &GameState::sliderValue, .25f, 1.0f, 0);
	comps[2] = new Slider(Vector2f(50, 720), Vector2f(300, 10), std::string("Blue Shift"), &GameState::ui_blue, 0.0f, 1.0f, 0);

}


SettingsPage::~SettingsPage()
{
	for (int i = 0; i < NUM_COMPS; i++) {
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

	for (int i = 0; i < NUM_COMPS; i++) {
		comps[i]->draw();
	}


}

void SettingsPage::update(float dt)
{
	for (int i = 0; i < NUM_COMPS; i++) {
		comps[i]->update(dt);
	}
}

void SettingsPage::handleMouseEvents(Mouse & mouse)
{
	for (int i = 0; i < NUM_COMPS; i++) {
		comps[i]->handleMouseEvents(mouse);
	}
}

void SettingsPage::handleKeyEvents(Keyboard & keyboard)
{
}
