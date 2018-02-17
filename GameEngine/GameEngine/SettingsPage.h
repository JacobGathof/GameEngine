#pragma once
#include "AbstractUIComponent.h"
#include "Text.h"


class SettingsAction {
public:
	virtual void performAction() = 0;
};


class SettingsActionToggleFullscreen : public SettingsAction {
public:
	virtual void performAction();
};


class SettingsButton : public AbstractUIComponent 
{
public:
	SettingsButton();
	~SettingsButton();
	virtual void draw();
	virtual void update(float dt);
	virtual void hover(Vector2f& pos);
	virtual void click(Vector2f& pos);
	virtual void release(Vector2f& pos);
	SettingsAction* action;
private:
	//Text text;
	Color defaultColor[3] = {Color(0xffffffff), Color(0x0000ffff), Color(0xddddddff)};
	Color hoverColor[3] =	{Color(0x8888ffff), Color(0x0000ffff), Color(0xffffffff)};
	Color clickColor[3] =	{Color(0x888888ff), Color(0x0000ffff), Color(0x888888ff)};
	Color * currentColor;
	int state;
};



class SettingsPage : public AbstractUIComponent
{
public:
	SettingsPage();
	~SettingsPage();

	virtual void draw();
	virtual void update(float dt);
	virtual void hover(Vector2f& pos);
	virtual void click(Vector2f& pos);
	virtual void release(Vector2f& pos);

private:
	SettingsButton button;

};

