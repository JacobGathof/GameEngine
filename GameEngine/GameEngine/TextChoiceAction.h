#pragma once
#include "AbstractScriptAction.h"
#include "UIManager.h"

class TextChoiceAction : public AbstractScriptAction
{
public:
	TextChoiceAction(std::string* ch, int len);
	~TextChoiceAction();
	virtual int run(float dt);
private:
	std::string* choices;
	int length;
	bool sentChoice = false;
};

