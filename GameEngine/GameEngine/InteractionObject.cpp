#include "InteractionObject.h"
#include "Inventory.h"


TextInteractionAction::TextInteractionAction(std::string& s) {
	text = s;
}

TextInteractionAction::~TextInteractionAction(){}

int TextInteractionAction::run(float dt)
{
	UIManager::addText(text);
	return 1;
}



/*
GiveItemAction::GiveItemAction(){}
GiveItemAction::~GiveItemAction(){}


int GiveItemAction::run(float dt)
{
	if (timesGiven != 0) {
		for (auto it : items) {
			//GameState::inv->add(it);
		}
		timesGiven--;
	}
	return 1;
}

void GiveItemAction::addItem(Item * it)
{
	items.add(it);
}

*/

