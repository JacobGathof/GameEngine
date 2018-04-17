#pragma once
#include "UIManager.h"

class InteractionObject
{
public:
	InteractionObject();
	~InteractionObject();

	virtual void execute();
};

class TextInteractionObject : public InteractionObject {
public:
	TextInteractionObject(std::string s);
	~TextInteractionObject();

	std::string text = "";

	virtual void execute();
};

