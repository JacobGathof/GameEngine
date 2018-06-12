#pragma once


#include "List.h"
#include "Item.h"
#include "Weapon.h"
#include "Armor.h"
#include "KeyItem.h"
#include "Card.h"
#include <map>


class Inventory
{
public:
	Inventory();
	~Inventory();

	void add(Weapon * w);
	void add(Armor * a);
	void add(KeyItem * k);
	void add(Card * c);

	List<Card *>& getCards();
	List<Weapon *>& getWeapons();
	List<Armor *>& getArmor();
	List<KeyItem *>& getKeyItems();

	Weapon* getCurrentWeapon();
	Armor* getCurrentArmor();
	List<Card*>& getCurrentDeck();

	void printInventory();
	void printCurrentInventory();

	void addCardToCurrentDeck(Card* card);
	void removeCardFromCurrentDeck(Card* card);
	void setCurrentWeapon(Weapon* w);
	void setCurrentArmor(Armor* armor);


private:
	List<Card*> cards;
	List<Armor*> armors;
	List<Weapon*> weapons;
	List<KeyItem*> keyItems;

	//Duplication Bug is possible if we allow more than one deck to be created

	struct CurrentUse {
		List<Card*> deck;
		Weapon* weapon;
		Armor* armor;
	} current;




};

