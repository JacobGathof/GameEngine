#pragma once
#include "AbstractScriptAction.h"
#include "UIManager.h"

class TextAction : public AbstractScriptAction
{
public:
	TextAction(std::string& txt, bool block = false);
	~TextAction();
	virtual int run(float dt);
	virtual void reset();

private:
	std::string text;
	bool blocking = false;
	bool sent = false;
};

