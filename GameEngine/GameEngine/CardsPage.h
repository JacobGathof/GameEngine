#pragma once
#include "AbstractUIComponent.h"
#include "Card.h"
#include "List.h"

class Text;


class CardGrid : public AbstractUIComponent {
public:
	CardGrid();
	~CardGrid();
	virtual void draw();
	virtual void update(float dt);
	virtual void handleMouseEvents(Mouse& mouse);
	virtual void handleKeyEvents(Keyboard& keyboard);


	int getIndexAtPosition(Vector2f& pos);
	int* index;

	int carryIndex;
	bool mouseDown;
	Vector2f mousePos;

private:

	Vector2f position = Vector2f(150, 300);

	Vector2f card_box_scale = Vector2f(50, 50);
	float card_box_gap = 4;

	int cards_per_row = 4;
	int cards_per_column = 4;

	Vector2f scale = Vector2f(cards_per_row * card_box_scale[0] + (cards_per_row*2)*card_box_gap, 300);

};




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
	CardGrid cardGrid;

	int selectedIndex;
	int lastIndex = selectedIndex;
};

