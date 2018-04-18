#pragma once
#include "AbstractAction.h"
#include "UIManager.h"
#include "List.h"

class TextChoiceAction : public AbstractAction
{
public:
	TextChoiceAction(List<std::string> ch);
	~TextChoiceAction();
	virtual int run(float dt);
	virtual void reset();
private:
	List<std::string> choices;
	bool sentChoice = false;
};

