#include "Menu.h"

#include "InventoryPage.h"
#include "SettingsPage.h"
#include "CardsPage.h"

Menu::Menu()
{

	position = basePos;
	scale = baseScale;

	settings = new SettingsPage();
	cardsPage = new CardsPage();

	activeComponent = settings;
	tabs.add(MenuTab(settings, std::string("Settings"), Vector2f(100,650), Vector2f(150,50)));
	tabs.add(MenuTab(cardsPage, std::string("Cards"), Vector2f(270, 650), Vector2f(150, 50)));
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

	//Hwhat?								|
	//										v
	UIUtils::drawRectangle(position, scale, Color(0x888888ff));
	UIUtils::drawRectangle(position + Vector2f(4, 4), scale - Vector2f(8, 8), Color(0xaaaaaa88));
	UIUtils::drawRectangle(position + Vector2f(2, 2), scale - Vector2f(4,4), Color(0x00000888));

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

	position[0] = x / 2 - scale[0]/2;
	position[1] = 2*y / 4 - 3*scale[1] / 8;
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
	UIUtils::drawRectangle(position, scale, Color::Red);
	UIUtils::drawRectangle(position+Vector2f(2,2), scale-Vector2f(4,4), Color::LightRed);
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
