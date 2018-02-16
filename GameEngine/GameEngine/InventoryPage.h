#pragma once
#include "AbstractUIComponent.h"


class InventoryCell : public AbstractUIComponent
{
public:
	InventoryCell(Vector2f& pos, Vector2f& sc, TextureType tex);
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

	TextureType tex;
};


class InventoryWindow : public AbstractUIComponent
{
public:
	InventoryWindow(Vector2f& pos, Vector2f& sc, TextureType tex);
	InventoryWindow();
	~InventoryWindow();
	virtual void draw();
	virtual void update(float dt);
	virtual void hover(Vector2f& pos);

private:
	Color color;
	TextureType tex;

};


class InventoryPage : public AbstractUIComponent
{
public:
	InventoryPage();
	~InventoryPage();
	virtual void draw();
	virtual void update(float dt);
	virtual void hover(Vector2f& pos);
	virtual void click(Vector2f& pos);

private:
	InventoryCell grid[5][5];
	InventoryWindow window;
};



