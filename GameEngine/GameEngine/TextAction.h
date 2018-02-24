#pragma once
#include "AbstractScriptAction.h"
#include "UIManager.h"

class TextAction : public AbstractScriptAction
{
public:
	TextAction(std::string& txt);
	~TextAction();
	virtual int run(float dt);

private:
	std::string text;
};

