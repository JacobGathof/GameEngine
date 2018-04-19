#pragma once
#include "UIManager.h"
#include "AbstractAction.h"
#include "Item.h"
#include "Inventory.h"

class TextInteractionObject : public AbstractAction {
public:
	TextInteractionObject(std::string s);
	~TextInteractionObject();

	std::string text = "";

	virtual int run(float dt = 0.0f);
};

class GiveItemAction : public AbstractAction {
public:
	GiveItemAction();
	~GiveItemAction();

	List<Item *> items;
	int timesGiven = 1;

	virtual int run(float dt = 0.0f);
	void addItem(Item * it);
};

