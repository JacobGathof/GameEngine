#pragma once
#include "AbstractUIComponent.h"

class Item;
class UIText;

class ShopWindow : public AbstractUIComponent
{
public:
	ShopWindow();
	~ShopWindow();

	virtual void draw();
	virtual void handleMouseEvents(Mouse& mouse);
	virtual void update(float dt);

	void setItem(Item* item);
	void confirmBuy() {};


private:

	Color windowColor = Color(0x8888aaff);
	Item* displayItem;
	UIText* itemName;


};

