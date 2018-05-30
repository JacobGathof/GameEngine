#include "CardsPage.h"
#include "TextUtils.h"
#include "ResourceManager.h"
#include "Text.h"
#include "GameState.h"

CardsPage::CardsPage()
{
	cardName = new Text(Vector2f(520, 375), std::string(""), Vector2f(25, 25), 0);
	cardDesc = new Text(Vector2f(520, 200), std::string(""), Vector2f(20, 20), 0);
	cardGrid.index = &selectedIndex;
}


CardsPage::~CardsPage()
{
	delete cardName;
	delete cardDesc;
}

void CardsPage::draw()
{

	/*
	UIUtils::drawRectangle(Vector2f(200, 200), Vector2f(200, 400), Color(0xffffff88));
	UIUtils::drawRectangle(Vector2f(200, 200) + Vector2f(2,2), Vector2f(196, 396), Color(0x00000088));
	UIUtils::drawRectangle(Vector2f(200, 200) + Vector2f(4, 4), Vector2f(192, 392), Color(0x00000088));
	*/
	UIUtils::drawRectangle(Vector2f(520, 200), Vector2f(200, 400), Color(0x00ffff88));
	UIUtils::drawRectangle(Vector2f(520, 200) + Vector2f(2, 2), Vector2f(196, 396), Color(0x00000088));
	UIUtils::drawRectangle(Vector2f(520, 200) + Vector2f(4, 4), Vector2f(192, 392), Color(0x00000088));


	Deck* deck = Res::get(DeckType::TEST);

	List<Card*> cards = deck->getAllCards();

	UIUtils::drawImage(Vector2f(520, 200 + 200) + Vector2f(8, 8), Vector2f(184, 184), cardTexture);
	cardName->draw();
	cardDesc->draw();


	cardGrid.draw();
}

void CardsPage::update(float dt)
{
	if (lastIndex != selectedIndex) {

		if (selectedIndex < Res::get(DeckType::TEST)->getAllCards().size()) {
			lastIndex = selectedIndex;
			selectedCard = Res::get(DeckType::TEST)->getAllCards()[selectedIndex];

			cardName->setText(selectedCard->getName());
			cardDesc->setText(selectedCard->getDescription());
			cardTexture = selectedCard->getTexture();
		}

	}
}

void CardsPage::handleMouseEvents(Mouse & mouse)
{
	cardGrid.handleMouseEvents(mouse);
}

void CardsPage::handleKeyEvents(Keyboard & keyboard)
{
}








CardGrid::CardGrid()
{
}

CardGrid::~CardGrid()
{
}

void CardGrid::draw()
{
	UIUtils::drawRectangle(position, scale, Color(0x00ffff88));

	List<Card*> deck = Res::get(DeckType::TEST)->getAllCards();
	for (int i = 0; i < deck.size(); i++) {

		int row = i % cards_per_row;
		int column = i / cards_per_column;


		Vector2f pos = position + Vector2f(row, column) * card_box_scale 
								+ Vector2f((2*row+1)*card_box_gap, (2*column+1)*card_box_gap);
		Vector2f sc = card_box_scale;


		UIUtils::drawRectangle(pos, sc, (i==*index)?Color(0xff00ff88):Color(0x00ffff88));
		UIUtils::drawRectangle(pos+Vector2f(1), sc-Vector2f(2), Color(0x0000ff88));
		UIUtils::drawImage(pos + Vector2f(1), sc - Vector2f(2), deck[i]->getTexture());

	}


	if (carryIndex >= 0 && carryIndex < deck.size()) {
		Vector2f sc = card_box_scale - Vector2f(2);
		Vector2f pos = mousePos - sc / 2;
		UIUtils::drawImage(pos, sc, deck[carryIndex]->getTexture());
	}


}

void CardGrid::update(float dt)
{
}

void CardGrid::handleMouseEvents(Mouse & mouse)
{

	if (mouse.release()) {

		if (carryIndex != -1) {

			Vector2f pos = mouse.pos();
			int swapPos = getIndexAtPosition(pos);


			if (swapPos != -1) {

			
				List<Card*>* deck = &Res::get(DeckType::TEST)->getAllCards();
				deck->swap(carryIndex, swapPos);
				

			}

		}

	}



	if (mouse.down()) {

		if (mouse.click()) {
			Vector2f pos = mouse.pos();
			carryIndex = getIndexAtPosition(pos);
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

}

void CardGrid::handleKeyEvents(Keyboard & keyboard)
{
}

int CardGrid::getIndexAtPosition(Vector2f & pos)
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

	if (index < 0 || index >= Res::get(DeckType::TEST)->getAllCards().size()) {
		return -1;
	}

	return index;
}
