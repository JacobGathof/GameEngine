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
	void setText(std::string str);

private:
	Color bannerColor;
	Color textColor;
	Text* text;
};

