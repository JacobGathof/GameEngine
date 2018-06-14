#include "EquipPage.h"
#include "TextUtils.h"
#include "ResourceManager.h"
#include "Text.h"
#include "GameState.h"


EquipPage::EquipPage()
{
	weaponName = new Text(Vector2f(520, 375), std::string(""), Vector2f(25, 25), 0);
	weaponDesc = new Text(Vector2f(520, 325), std::string(""), Vector2f(20, 20), 0);
	weapons = &GameState::inv->getWeapons();
	weaponGrid = new Grid<Weapon*>(weapons, 5, 1);
	weaponGrid->index = &selectedIndex;
}

EquipPage::~EquipPage()
{
	delete weaponName;
	delete weaponDesc;

	delete weaponGrid;
}

void EquipPage::draw()
{
	UIUtils::drawRectangle(Vector2f(520, 250), Vector2f(200, 400), Color(0xcccccc88));
	UIUtils::drawRectangle(Vector2f(520, 250) + Vector2f(2, 2), Vector2f(196, 396), Color(0x00000088));
	UIUtils::drawRectangle(Vector2f(520, 250) + Vector2f(4, 4), Vector2f(192, 392), Color(0x00000088));


	UIUtils::drawImage(Vector2f(520, 200 + 250) + Vector2f(8, 8), Vector2f(184, 184), weaponTexture);
	weaponName->draw();
	weaponDesc->draw();

	weaponGrid->draw();
}

void EquipPage::update(float dt)
{
	if (lastIndex != selectedIndex) {

		if (selectedIndex < weapons->size()) {
			lastIndex = selectedIndex;
			selectedWeapon = (*weapons)[selectedIndex];

			weaponName->setText(selectedWeapon->getName());
			weaponDesc->setText(selectedWeapon->getDescription());
			weaponTexture = selectedWeapon->getTexture();
		}

	}
}

void EquipPage::handleMouseEvents(Mouse & mouse)
{
	weaponGrid->handleMouseEvents(mouse);
}

void EquipPage::handleKeyEvents(Keyboard & keyboard)
{
}
