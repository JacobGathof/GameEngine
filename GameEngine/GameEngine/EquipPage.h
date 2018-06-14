#pragma once
#include "AbstractUIComponent.h"
#include "Weapon.h"
#include "List.h"
#include "Grid.h"

class Text;

class EquipPage : public AbstractUIComponent
{
public:
	EquipPage();
	~EquipPage();
	virtual void draw();
	virtual void update(float dt);
	virtual void handleMouseEvents(Mouse& mouse);
	virtual void handleKeyEvents(Keyboard& keyboard);

private:

	void setCurrentWeapon(Weapon* w);

	Weapon * selectedWeapon = 0;

	Text* weaponName;
	Text* weaponDesc;
	TextureType weaponTexture;
	Grid<Weapon*>* weaponGrid;

	List<Weapon*>* weapons;

	TextureType weaponTextureEquip;

	int selectedIndex = -1;
	int lastIndex = selectedIndex;

	int specialIndex = -1;
	int lastSpecialIndex = specialIndex;

};

