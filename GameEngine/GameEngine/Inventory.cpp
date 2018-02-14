#include "Inventory.h"



Inventory::Inventory(Vector2f* parent)
{
	this->parentOffset = parent;

	/*Very temporary instantiation*/
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			grid[i][j] = InventoryCell(Vector2f(i * 105+30, j * 105+30), &position, Vector2f(100, 100), (TextureType)((rand()%8)+2));
		}
	}
	window = InventoryWindow(Vector2f(600-30, 22), &position, Vector2f(300, 536), TextureType::TEXTURE_PANDORA);
}


Inventory::~Inventory(){}

void Inventory::draw()
{
	UIUtils::drawRectangle(Vector2f(20, 20)+position, Vector2f(540, 540), Color(0x00000088));
	UIUtils::drawRectangle(Vector2f(22, 22)+position, Vector2f(536, 536), Color(0xffffff88));
	UIUtils::drawRectangle(Vector2f(24, 24)+position, Vector2f(532, 532), Color(0x00000088));

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			grid[i][j].draw();
		}
	}
	window.draw();
	
}

void Inventory::update(float dt)
{
	position = Vector2f(0, 150);
	if (parentOffset != 0) {
		position += *parentOffset;
	}
}

void Inventory::hover(Vector2f & pos)
{
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			grid[i][j].hover(pos);
		}
	}
}

void Inventory::click(Vector2f & pos)
{
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			grid[i][j].click(pos);
		}
	}
}


InventoryCell::InventoryCell(Vector2f & pos, Vector2f * parOff, Vector2f & sc, TextureType t)
{
	position = pos;
	parentOffset = parOff;
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
	UIUtils::drawRectangle(drawPos + Vector2f(0, 0), scale - Vector2f(0, 0), Color(0xffffff44));
	UIUtils::drawRectangle(drawPos + Vector2f(2, 2), scale - Vector2f(4, 4), Color(0x00000044));
	UIUtils::drawRectangle(drawPos + Vector2f(4, 4), scale - Vector2f(8, 8), Color(0x44444444));
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

InventoryWindow::InventoryWindow(Vector2f & pos, Vector2f * parOff, Vector2f & sc, TextureType t){
	position = pos;
	parentOffset = parOff;
	scale = sc;
	color = Color(0xddddff88);
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
