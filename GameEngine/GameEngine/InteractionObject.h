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



class GiveItemAction : public AbstractAction {
public:
	GiveItemAction(Item* i) {
		item = i;
	};
	~GiveItemAction() {};

	virtual int run(float dt = 0.0f) {
		GameState::inv->add(item);
		TextboxContentData data;
		data.text = "You just got : " + item->getName();
		data.portrait = item->getTexture();
		data.dialogue = true;
		UIManager::addText(data);
		return 1;
	};
private:
	Item* item;

};

