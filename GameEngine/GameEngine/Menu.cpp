#include "Menu.h"

#include "InventoryPage.h"
#include "SettingsPage.h"
#include "CardsPage.h"

Menu::Menu()
{
	settings = new SettingsPage();
	cardsPage = new CardsPage();

	activeComponent = settings;
	tabs.add(MenuTab(settings, TextureType::TEXTURE_DEFAULT, Vector2f(100,650), Vector2f(50,50)));
	tabs.add(MenuTab(cardsPage, TextureType::TEXTURE_DEFAULT, Vector2f(170, 650), Vector2f(50, 50)));
}

Menu::~Menu()
{
	delete settings;
	delete cardsPage;
}

void Menu::draw()
{
	if (!visible)
		return;

	UIUtils::drawRectangle(Vector2f(100, 100), Vector2f(600, 600), Color(0xffffffff));
	UIUtils::drawRectangle(Vector2f(100, 100) + Vector2f(2, 2), Vector2f(596, 596), Color(0x00000088));
	//UIUtils::drawRectangle(Vector2f(100, 100) + Vector2f(4, 4), Vector2f(592, 592), Color(0x00000000));

	for (auto t : tabs) {
		t.draw();
	}

	activeComponent->draw();
}

void Menu::update(float dt)
{
	if (!visible)
		return;

	activeComponent->update(dt);
}

void Menu::resize(int x, int y)
{
	settings->resize(x, y);
	cardsPage->resize(x, y);
}

void Menu::handleMouseEvents(Mouse & mouse)
{
	if (!visible)
		return;

	for (auto t : tabs) {
		if (t.clicked(mouse)) {
			activeComponent = t.getContent();
			break;
		}
	}

	activeComponent->handleMouseEvents(mouse);
}

void Menu::handleKeyEvents(Keyboard & keyboard)
{
	if (!visible)
		return;

	activeComponent->handleKeyEvents(keyboard);
}

void Menu::toggle()
{
	visible = !visible;
}




MenuTab::MenuTab(AbstractUIComponent * a, TextureType t, Vector2f pos, Vector2f sc)
{
	content = a;
	tex = t;
	position = pos;
	scale = sc;
}

void MenuTab::draw()
{
	UIUtils::drawRectangle(position, scale, Color::LightRed);
}

void MenuTab::resize(int x, int y)
{
}

bool MenuTab::clicked(Mouse & mouse)
{
	return mouse.click() && mouse.pos().between(position, position+scale);
}

AbstractUIComponent * MenuTab::getContent()
{
	return content;
}
