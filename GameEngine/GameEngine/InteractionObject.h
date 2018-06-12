#pragma once
#include "UIManager.h"
#include "AbstractAction.h"
#include "Item.h"
#include "Inventory.h"
#include "GameState.h"

class TextInteractionAction : public AbstractAction {
public:
	TextInteractionAction(std::string& s);
	~TextInteractionAction();

	virtual int run(float dt = 0.0f);
private:
	std::string text;

};



template<class T>
class ItemAction : public AbstractAction {
public:
	ItemAction(T t) {
		item = t;
	};
	~ItemAction() {};

	virtual int run(float dt = 0.0f) {
		GameState::inv->add(item);
		UIManager::addText(std::string("You just got ") + item->getName());
		return 1;
	};
private:
	T item;

};


typedef ItemAction<Card*> GiveCardAction;
typedef ItemAction<Armor*> GiveArmorAction;
typedef ItemAction<Weapon*> GiveWeaponAction;
typedef ItemAction<KeyItem*> GiveKeyItemAction;


/*
class GiveItemAction : public AbstractAction {
public:
	GiveItemAction();
	~GiveItemAction();

	List<Item *> items;
	int timesGiven = 1;

	virtual int run(float dt = 0.0f);
	void addItem(Item * it);
};
*/
