#pragma once
#include "AbstractUIComponent.h"
#include "Card.h"
#include "List.h"
#include "Grid.h"

class Text;

class CardsPage : public AbstractUIComponent
{
public:
	CardsPage();
	~CardsPage();
	virtual void draw();
	virtual void update(float dt);
	virtual void handleMouseEvents(Mouse& mouse);
	virtual void handleKeyEvents(Keyboard& keyboard);

private:
	Card * selectedCard = 0;

	Text* cardName;
	Text* cardDesc;
	TextureType cardTexture;
	Grid<Card*>* cardGrid;

	List<Card*>* cards;

	int selectedIndex = -1;
	int lastIndex = selectedIndex;
};

