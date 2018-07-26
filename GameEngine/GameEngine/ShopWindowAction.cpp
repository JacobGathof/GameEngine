#include "ShopWindowAction.h"
#include "Item.h"
#include "UIManager.h"

ShopWindowAction::ShopWindowAction(Item * i, bool s)
{
	item = i;
	show = s;
}

ShopWindowAction::~ShopWindowAction()
{
}

int ShopWindowAction::run(float dt)
{
	UIManager::showShopWindow(item, show);
	return 1;
}
