#include "InventoryPage.h"



InventoryPage::InventoryPage()
{
	//baseOffset = Vector2f(0, 150);
	/*
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			grid[i][j] = InventoryCell(Vector2f(i * 105+30, j * 105+30), Vector2f(100, 100), (TextureType)((rand()%8)+2));
			grid[i][j].setParentPosition(&position);
		}
	}
	window = InventoryWindow(Vector2f(600-30, 30), Vector2f(272, 520), TextureType::TEXTURE_PANDORA);
	window.setParentPosition(&position);
	*/
}


InventoryPage::~InventoryPage(){}

void InventoryPage::draw()
{
	UIUtils::drawRectangle(Vector2f(20, 20)+position, Vector2f(840, 540), Color(0x000000ff));
	UIUtils::drawRectangle(Vector2f(22, 22)+position, Vector2f(836, 536), Color(0xffffffff));
	UIUtils::drawRectangle(Vector2f(24, 24)+position, Vector2f(832, 532), Color(0x000000ff));

	/*
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			grid[i][j].draw();
		}
	}
	window.draw();
	*/
}

void InventoryPage::update(float dt)
{
	AbstractUIComponent::update(dt);
	
}

void InventoryPage::hover(Vector2f & pos)
{
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			//grid[i][j].hover(pos);
		}
	}
}

void InventoryPage::click(Vector2f & pos)
{
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			//grid[i][j].click(pos);
		}
	}
}

/*
InventoryCell::InventoryCell(Vector2f & pos, Vector2f & sc, TextureType t)
{
	position = pos;
	scale = sc;
	currentColor = Color(0x44444488);

	defaultColor = Color(0x44444488);
	hoverColor = Color(0x22222288);
	clickColor = Color(0x00000088);
	tex = t;
}

InventoryCell::InventoryCell(){}
InventoryCell::~InventoryCell(){}

void InventoryCell::draw()
{
	Vector2f drawPos = position + *parentOffset;
	UIUtils::drawRectangle(drawPos + Vector2f(0, 0), scale - Vector2f(0, 0), Color(0xffffffff));
	UIUtils::drawRectangle(drawPos + Vector2f(2, 2), scale - Vector2f(4, 4), Color(0x000000ff));
	UIUtils::drawRectangle(drawPos + Vector2f(4, 4), scale - Vector2f(8, 8), Color(0x444444ff));
	//UIUtils::drawImage(drawPos + Vector2f(6, 6), scale - Vector2f(12, 12), tex);
}

void InventoryCell::update(float dt)
{
}

void InventoryCell::hover(Vector2f & pos)
{
	if (pos.between(position+*parentOffset, position+*parentOffset+scale)) {
		currentColor = hoverColor;
	}
	else {
		currentColor = defaultColor;
	}
}

void InventoryCell::click(Vector2f & pos)
{
	if (pos.between(position + *parentOffset, position + *parentOffset + scale)) {
		currentColor = clickColor;
	}
	else {
		currentColor = defaultColor;
	}
}

void InventoryCell::setImage(TextureType type)
{
	tex = type;
}

InventoryWindow::InventoryWindow(Vector2f & pos, Vector2f & sc, TextureType t){
	position = pos;
	scale = sc;
	color = Color(0xddddffff);
	tex = t;
}

InventoryWindow::InventoryWindow(){}
InventoryWindow::~InventoryWindow(){}

void InventoryWindow::draw()
{
	Vector2f drawPos = position + *parentOffset;
	UIUtils::drawRectangle(drawPos + Vector2f(0, 0), scale - Vector2f(0, 0), color);
	UIUtils::drawRectangle(drawPos + Vector2f(2, 2), scale - Vector2f(4, 4), color);
	UIUtils::drawRectangle(drawPos + Vector2f(4, 4), scale - Vector2f(8, 8), color);
	//UIUtils::drawImage(drawPos + Vector2f(6, 6), scale - Vector2f(12, 12), tex);
}


void InventoryWindow::update(float dt)
{
}


void InventoryWindow::hover(Vector2f & pos)
{
}
*/