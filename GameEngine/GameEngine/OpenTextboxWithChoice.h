#pragma once

#include "LivingAi.h"
#include "Textbox.h"
#include "UIManager.h"

class OpenTextboxWithChoice : public LivingAi
{
public:
	OpenTextboxWithChoice(std::string text);
	~OpenTextboxWithChoice();

	std::string str;
	virtual bool execute(LivingObject * obj, float dt);
};

