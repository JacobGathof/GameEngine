#pragma once
class ButtonAction
{
public:
	virtual void performAction() = 0;
};


class FullscreenButtonAction : public ButtonAction{
public:
	virtual void performAction();
};

