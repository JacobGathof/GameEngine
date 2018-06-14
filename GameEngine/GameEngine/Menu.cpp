#include "Menu.h"

#include "InventoryPage.h"
#include "SettingsPage.h"
#include "CardsPage.h"
#include "EquipPage.h"

Menu::Menu()
{
	position = basePos;
	scale = baseScale;

	settings = new SettingsPage();
	cardsPage = new CardsPage();
	equipPage = new EquipPage();

	activeComponent = settings;
	tabs.add(MenuTab(settings, std::string("Settings"), Vector2f(100,650), Vector2f(75,25)));
	tabs.add(MenuTab(cardsPage, std::string("Cards"), Vector2f(200, 650), Vector2f(75, 25)));
	tabs.add(MenuTab(equipPage, std::string("Weapons"), Vector2f(300, 650), Vector2f(75, 25)));
}

Menu::~Menu()
{
	delete settings;
	delete cardsPage;
	delete equipPage;
}

void Menu::draw()
{
	if (!visible)
		return;

	//Hwhat?								|
	//										v
	UIUtils::drawRectangle(position, scale, Color(0x888888ff));
	UIUtils::drawRectangle(position + Vector2f(4, 4), scale - Vector2f(8, 8), Color(0xaaaaaaff));
	UIUtils::drawRectangle(position + Vector2f(2, 2), scale - Vector2f(4,4), Color(0x000008ff));

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




MenuTab::MenuTab(AbstractUIComponent * a, std::string& txt, Vector2f& pos, Vector2f& sc)
{
	content = a;
	position = pos;
	scale = sc;
	tabText = new Text(pos+sc/2, txt, Vector2f(sc[1]/2, sc[1]/2), 0);
	tabText->center();
}

MenuTab::~MenuTab()
{
}

void MenuTab::draw()
{
	UIUtils::drawRectangle(position, scale, Color::Black);
	UIUtils::drawRectangle(position+Vector2f(2,2), scale-Vector2f(4,4), Color::DarkGray);
	tabText->draw();
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
