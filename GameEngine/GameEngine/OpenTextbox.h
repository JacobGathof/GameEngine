#pragma once

#include "LivingAi.h"
#include "UIManager.h"

class OpenTextbox : public LivingAi
{
public:
	OpenTextbox(std::string text);
	~OpenTextbox();

	std::string str;
	virtual bool execute(LivingObject * obj, float dt);
};

