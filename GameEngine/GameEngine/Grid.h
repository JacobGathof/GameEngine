#pragma once
#include "AbstractUIComponent.h"
#include "Item.h"
#include "List.h"

template <class T>
class Grid : public AbstractUIComponent {
public:
	Grid(List<T>* contents);
	Grid(List<T>* contents, int cpr, int cpc);
	~Grid();
	virtual void draw();
	virtual void update(float dt);
	virtual void handleMouseEvents(Mouse& mouse);
	virtual void handleKeyEvents(Keyboard& keyboard);


	int getIndexAtPosition(Vector2f& pos);
	int* index;
	int* specialIndex;

	int carryIndex;
	bool mouseDown;
	bool mouseMoving;
	Vector2f mousePos;

private:

	Vector2f position = Vector2f(150, 300);

	Vector2f card_box_scale = Vector2f(50, 50);
	float card_box_gap = 4;

	int cards_per_row = 4;
	int cards_per_column = 4;

	Vector2f scale = Vector2f(cards_per_row * card_box_scale[0] + (cards_per_row * 2)*card_box_gap, 300);

	List<T>* contents;

};
