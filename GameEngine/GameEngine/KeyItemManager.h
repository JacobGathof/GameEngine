#pragma once
#include "IManager.h"
#include "ResourceType.h"
#include "KeyItem.h"

class KeyItemManager : public IManager<KeyItem, KeyItemType>
{
public:
	virtual void init();

private:

	void addItem(KeyItemType name, KeyItem * item);
};