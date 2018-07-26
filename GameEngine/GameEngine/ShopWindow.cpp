#include "ShopWindow.h"
#include "Item.h"
#include "UIText.h"


ShopWindow::ShopWindow()
{
	position = Vector2f(100, 100);
	scale = Vector2f(600, 600);
	itemName = new UIText(Vector2f(200, 400), std::string("---"), Vector2f(30, 30), 0);
}

ShopWindow::~ShopWindow()
{
	delete itemName;
}

void ShopWindow::draw()
{
	if (!visible || displayItem == 0)
		return;

	UIUtils::drawRectangle(position, scale, windowColor);
	UIUtils::drawImage(Vector2f(200, 200), Vector2f(100, 100), displayItem->getTexture());

	itemName->draw();
}

void ShopWindow::handleMouseEvents(Mouse & mouse)
{
}

void ShopWindow::update(float dt)
{
}

void ShopWindow::setItem(Item * item)
{
	if (item != 0) {
		displayItem = item;
		itemName->setText(displayItem->getName());
	}
}
