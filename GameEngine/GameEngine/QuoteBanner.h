#pragma once
#include "AbstractUIComponent.h"
#include "Timer.h"

class Text;

class QuoteBanner : public AbstractUIComponent
{
public:
	QuoteBanner();
	~QuoteBanner();
	virtual void draw();
	virtual void update(float dt);
	void setText(std::string& str);
	bool isVisible();

private:
	int animationState;
	float alpha;

	Timer timer;
	Color textColor;
	Text* text;
};
