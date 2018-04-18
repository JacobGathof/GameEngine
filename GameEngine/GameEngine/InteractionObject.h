#pragma once
#include "UIManager.h"
#include "AbstractAction.h"

class TextInteractionObject : public AbstractAction {
public:
	TextInteractionObject(std::string s);
	~TextInteractionObject();

	std::string text = "";

	virtual int run(float dt = 0.0f);
};

