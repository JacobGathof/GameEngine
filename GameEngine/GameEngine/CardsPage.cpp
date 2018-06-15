#include "CardsPage.h"
#include "TextUtils.h"
#include "ResourceManager.h"
#include "Text.h"
#include "GameState.h"

CardsPage::CardsPage()
{
	cardName = new Text(Vector2f(520, 375), std::string(""), Vector2f(25, 25), 0);
	cardDesc = new Text(Vector2f(520, 325), std::string(""), Vector2f(20, 20), 0);
	cards = &GameState::inv->getCards();
	cardGrid = new Grid<Card*>(cards);
	cardGrid->index = &selectedIndex;
	cardGrid->specialIndex = &selectedIndex;
}


CardsPage::~CardsPage()
{
	delete cardName;
	delete cardDesc;

	delete cardGrid;
}

void CardsPage::draw()
{

	/*
	UIUtils::drawRectangle(Vector2f(200, 200), Vector2f(200, 400), Color(0xffffff88));
	UIUtils::drawRectangle(Vector2f(200, 200) + Vector2f(2,2), Vector2f(196, 396), Color(0x00000088));
	UIUtils::drawRectangle(Vector2f(200, 200) + Vector2f(4, 4), Vector2f(192, 392), Color(0x00000088));
	*/
	UIUtils::drawRectangle(Vector2f(520, 250), Vector2f(200, 400), Color(0xcccccc88));
	UIUtils::drawRectangle(Vector2f(520, 250) + Vector2f(2, 2), Vector2f(196, 396), Color(0x00000088));
	UIUtils::drawRectangle(Vector2f(520, 250) + Vector2f(4, 4), Vector2f(192, 392), Color(0x00000088));

	UIUtils::drawImage(Vector2f(520, 200 + 250) + Vector2f(8, 8), Vector2f(184, 184), cardTexture);
	cardName->draw();
	cardDesc->draw();


	cardGrid->draw();
}

void CardsPage::update(float dt)
{
	if (lastIndex != selectedIndex) {

		if (selectedIndex < cards->size()) {
			lastIndex = selectedIndex;
			selectedCard = (*cards)[selectedIndex];

			cardName->setText(selectedCard->getName());
			cardDesc->setText(selectedCard->getDescription());
			cardTexture = selectedCard->getTexture();
		}

	}
}

void CardsPage::handleMouseEvents(Mouse & mouse)
{
	cardGrid->handleMouseEvents(mouse);
}

void CardsPage::handleKeyEvents(Keyboard & keyboard)
{
}


