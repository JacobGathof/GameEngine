#include "Grid.h"
#include "Card.h"
#include "Weapon.h"

template <class T>
Grid<T>::Grid(List<T>* c)
{
	contents = c;
}

template<class T>
Grid<T>::Grid(List<T>* c, int cpr, int cpc)
{
	contents = c;
	cards_per_row = cpr;
	cards_per_column = cpc;

	scale = Vector2f(cards_per_row * card_box_scale[0] + (cards_per_row * 2)*card_box_gap, cards_per_column * card_box_scale[0] + (cards_per_column * 2)*card_box_gap);
}

template <class T>
Grid<T>::~Grid()
{
}

template <class T>
void Grid<T>::draw()
{
	UIUtils::drawRectangle(position, scale, Color(0xcccccc88));

	for (int i = 0; i < contents->size(); i++) {

		int row = i % cards_per_row;
		int column = i / cards_per_row;


		Vector2f pos = position + Vector2f(row, column) * card_box_scale
			+ Vector2f((2.0f * row + 1.0f)*card_box_gap, (2.0f * column + 1.0f)*card_box_gap);
		Vector2f sc = card_box_scale;


		UIUtils::drawRectangle(pos, sc, (i == *index) ? Color(0x0000ff88) : Color(0xcccccc88));
		UIUtils::drawRectangle(pos + Vector2f(1), sc - Vector2f(2), Color(0x44444488));
		UIUtils::drawImage(pos + Vector2f(1), sc - Vector2f(2), (*contents)[i]->getTexture());

	}


	if (carryIndex >= 0 && carryIndex < contents->size() && mouseMoving) {
		Vector2f sc = card_box_scale - Vector2f(2);
		Vector2f pos = mousePos - sc / 2;
		UIUtils::drawImage(pos, sc, (*contents)[carryIndex]->getTexture());
	}


}

template <class T>
void Grid<T>::update(float dt)
{
}

template <class T>
void Grid<T>::handleMouseEvents(Mouse & mouse)
{

	if (mouse.release()) {

		if (carryIndex != -1) {

			Vector2f pos = mouse.pos();
			int swapPos = getIndexAtPosition(pos);


			if (swapPos != -1) {


				//List<T>* deck = &contents;
				//deck->swap(carryIndex, swapPos);
				contents->swap(carryIndex, swapPos);

			}

		}

	}



	if (mouse.down()) {

		if (mouse.click()) {
			Vector2f pos = mouse.pos();
			carryIndex = getIndexAtPosition(pos);
			mouseMoving = false;
		}

		if (mouse.mouseMoved()) {
			mouseMoving = true;
		}

		mouseDown = true;
		mousePos = mouse.pos();
	}
	else {
		mouseDown = false;
		carryIndex = -1;
	}



	if (mouse.click()) {
		Vector2f pos = mouse.pos();

		int i = getIndexAtPosition(pos);

		if (i != -1) {
			*index = i;
		}
	}

	if (mouse.doubleClick()) {
		Vector2f pos = mouse.pos();

		int i = getIndexAtPosition(pos);

		if (i != -1) {
			*specialIndex = i;
		}
	}

}

template <class T>
void Grid<T>::handleKeyEvents(Keyboard & keyboard)
{
}

template <class T>
int Grid<T>::getIndexAtPosition(Vector2f & pos)
{
	int rowClicked = -1;
	int columnClicked = -1;

	Vector2f tot = card_box_scale + 2 * card_box_gap;

	rowClicked = (int)((pos[1] - position[1]) / tot[1]);
	columnClicked = (int)((pos[0] - position[0]) / tot[0]);

	if (rowClicked < 0 || columnClicked < 0) {
		return -1;
	}

	int index = rowClicked * cards_per_column + columnClicked;

	if (index < 0 || index >= contents->size()) {
		return -1;
	}

	return index;
}


template class Grid<Card*>;
template class Grid<Weapon*>;