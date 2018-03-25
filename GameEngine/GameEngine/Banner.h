#pragma once
#include "AbstractUIComponent.h"
#include "Timer.h"

class Text;

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

	bool playAnimation(float dt);

private:
	float alpha;
	bool visible;
	int animationState;

	Timer timer;
	Color bannerColor;
	Color textColor;
	Text* text;
	Text* subText;
};

