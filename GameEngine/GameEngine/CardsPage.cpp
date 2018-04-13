#include "CardsPage.h"
#include "TextUtils.h"
#include "ResourceManager.h"
#include "Text.h"

CardsPage::CardsPage()
{
	cardName = new Text(Vector2f(0, 0), std::string(""), Vector2f(0, 0), 0);
	cardDesc = new Text(Vector2f(0, 0), std::string(""), Vector2f(0, 0), 0);

	deck.add(Card("Urano Metria", "The spell of the starry heavens, destined to bring destruction to the Gods", 0));
	deck.add(Card("Sema", "The spell of the starry heavens, destined to bring destruction to the Gods", 0));
	deck.add(Card("UWW", "The spell of the starry heavens, destined to bring destruction to the Gods", 0));
	deck.add(Card("Altaris", "The spell of the starry heavens, destined to bring destruction to the Gods", 0));
}


CardsPage::~CardsPage()
{
	delete cardName;
	delete cardDesc;
}

void CardsPage::draw()
{
	UIUtils::drawRectangle(Vector2f(200, 200), Vector2f(200, 400), Color(0xffffffff));
	UIUtils::drawRectangle(Vector2f(200, 200) + Vector2f(2,2), Vector2f(196, 396), Color(0x000000ff));
	UIUtils::drawRectangle(Vector2f(200, 200) + Vector2f(4, 4), Vector2f(192, 392), Color(0x00000000));

	UIUtils::drawRectangle(Vector2f(420, 200), Vector2f(200, 400), Color(0xffffffff));
	UIUtils::drawRectangle(Vector2f(420, 200) + Vector2f(2, 2), Vector2f(196, 396), Color(0x000000ff));
	UIUtils::drawRectangle(Vector2f(420, 200) + Vector2f(4, 4), Vector2f(192, 392), Color(0x00000000));


	for (int i = 0; i < deck.size(); i++) {
		Card c = deck[i];
		int height = 30;
		int padding = 2;

		UIUtils::drawRectangle(Vector2f(200, 200 - i*(height+padding)+400 - 30) + Vector2f(8, -8), Vector2f(184, height), Color(0x0000ffff));
		UIUtils::drawImage(Vector2f(200, 200 - i * (height + padding) +400 - 30) + Vector2f(8, -8), Vector2f(height, height), TextureType::CARD_GHOST);
		std::string str = c.getName();

		Text text(Vector2f(200 + 2*height, 200+400 - 34 - i * (height + padding)), str, Vector2f(20, 20), 0);
		text.draw();
	}

	UIUtils::drawRectangle(Vector2f(420, 200+200) + Vector2f(8, 8), Vector2f(184, 184), Color(0x000000ff));

	if (selectedCard != 0) {
		UIUtils::drawRectangle(Vector2f(418, 198) + Vector2f(8, 8), Vector2f(188, 388), Color(0xaaaaffff));

		UIUtils::drawImage(Vector2f(420, 200 + 200) + Vector2f(8, 8), Vector2f(184, 184), TextureType::CARD_ACE, time*2.0f);

		std::string str = selectedCard->getName();
		str = TextUtils::processString(str, Res::get(FontType::DEFAULT), Vector2f(20, 20), 184);

		Text text(Vector2f(428, 208 + 184 - 20), str, Vector2f(20, 20), 0);
		text.draw();
	}
}

void CardsPage::update(float dt)
{
	time += dt;
}

void CardsPage::handleMouseEvents(Mouse & mouse)
{
	for (int i = 0; i < deck.size(); i++) {
		if (mouse.pos().between(Vector2f(420, 300), Vector2f(500, 400))) {
			selectedCard = &(deck[0]);
			cardName->setText(selectedCard->getName());
			cardDesc->setText(selectedCard->getDescription());
			cardTexture = selectedCard->getTexture();
		}
	}
}

void CardsPage::handleKeyEvents(Keyboard & keyboard)
{
}

