#include "SettingsPage.h"
#include "GameState.h"
#include "Input.h"
#include "InputTextArea.h"

SettingsPage::SettingsPage()
{
	comps[0] = new Button(Vector2f(120, 300), Vector2f(100, 30), std::string("Fullscreen"), new FullscreenButtonAction());
	comps[1] = new Button(Vector2f(210, 300), Vector2f(80, 30), std::string("A Note"), new NoteButtonAction());
	comps[2] = new Slider(Vector2f(120, 550), Vector2f(300, 10), std::string("Transparency"), &GameState::sliderValue, .25f, 1.0f, 0);
	comps[3] = new Slider(Vector2f(120, 600), Vector2f(300, 10), std::string("Blue Shift"), &GameState::ui_blue, 0.0f, 1.0f, 0);
	comps[4] = new KeyBinder(Vector2f(120, 350), Vector2f(100, 40), Input::keyboard);
	comps[5] = new Button(Vector2f(310, 300), Vector2f(80, 30), std::string("Music"), new MusicButtonAction());
	comps[6] = new Button(Vector2f(410, 300), Vector2f(80, 30), std::string("Music2"), new MusicButtonAction2());
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
	for (int i = 0; i < NUM_COMPS; i++) {
		comps[i]->handleKeyEvents(keyboard);
	}
}
