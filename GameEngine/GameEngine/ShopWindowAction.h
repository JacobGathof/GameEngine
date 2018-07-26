#pragma once
#include "AbstractAction.h"

class Item;

class ShopWindowAction : public AbstractAction
{
public:
	ShopWindowAction(Item* item, bool s);
	~ShopWindowAction();
	virtual int run(float dt);

private:
	Item * item;
	bool show;
};

