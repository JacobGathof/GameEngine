#pragma once
#include "AbstractUIComponent.h"
#include "Text.h"

class Banner : public AbstractUIComponent
{
public:
	Banner();
	~Banner();
	virtual void draw();
	virtual void update(float dt);
	virtual void handleMouseEvents(Mouse& mouse);
	virtual void handleKeyEvents(Keyboard& keyboard);
	void setText(std::string& str, std::string& str_sub);
	bool isVisible();

	void show();
	void hide();

private:
	Color bannerColor;
	Color textColor;
	Text* text;
	Text* subText;
};

