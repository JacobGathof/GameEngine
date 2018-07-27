#pragma once


#include "List.h"
#include "Item.h"
#include "Weapon.h"
#include "KeyItem.h"
#include "Card.h"
#include <map>


class Inventory
{
public:
	Inventory();
	~Inventory();

	void add(Item* item);

	void add(Weapon * w);
	void add(KeyItem * k);
	void add(Card * c);


	List<Card *>& getCards();
	List<Weapon *>& getWeapons();
	List<KeyItem *>& getKeyItems();

	Weapon* getCurrentWeapon();
	List<Card*>& getCurrentDeck();

	void printInventory();
	void printCurrentInventory();

	void addCardToCurrentDeck(Card* card);
	void removeCardFromCurrentDeck(Card* card);
	void setCurrentWeapon(Weapon* w);


private:
	List<Card*> cards;
	List<Weapon*> weapons;
	List<KeyItem*> keyItems;

	//Duplication Bug is possible if we allow more than one deck to be created

	struct CurrentUse {
		List<Card*> deck;
		Weapon* weapon;
	} current;


};

