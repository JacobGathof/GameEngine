#pragma once
#include "AbstractScriptAction.h"
#include "UIManager.h"
#include "List.h"

class TextChoiceAction : public AbstractScriptAction
{
public:
	TextChoiceAction(List<std::string> ch);
	~TextChoiceAction();
	virtual int run(float dt);
private:
	List<std::string> choices;
	bool sentChoice = false;
};

