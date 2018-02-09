#pragma once
#include "AbstractUIComponent.h"


class InventoryCell : public AbstractUIComponent
{
public:
	InventoryCell(Vector2f& pos, Vector2f* parentOffset, Vector2f& sc, TextureType tex);
	InventoryCell();
	~InventoryCell();
	virtual void draw();
	virtual void update(float dt);
	virtual void hover(Vector2f& pos);
	virtual void click(Vector2f& pos);

	void setImage(TextureType type);
private:
	Color defaultColor;
	Color hoverColor;
	Color clickColor;

	Color currentColor;

	Vector2f position;
	Vector2f * parentOffset;
	TextureType tex;
	Vector2f scale;
};


class InventoryWindow : public AbstractUIComponent
{
public:
	InventoryWindow(Vector2f& pos, Vector2f* parentOffset, Vector2f& sc, TextureType tex);
	InventoryWindow();
	~InventoryWindow();
	virtual void draw();
	virtual void update(float dt);
	virtual void hover(Vector2f& pos);

private:
	Vector2f position;
	Vector2f * parentOffset;
	Color color;
	TextureType tex;
	Vector2f scale;

};


class Inventory : public AbstractUIComponent
{
public:
	Inventory();
	~Inventory();
	virtual void draw();
	virtual void update(float dt);
	virtual void hover(Vector2f& pos);
	virtual void click(Vector2f& pos);

private:
	Vector2f position;
	InventoryCell grid[5][5];
	InventoryWindow window;
};



