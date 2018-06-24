#pragma once
#include "AbstractAction.h"
#include "UIManager.h"

class DialogueAction : public AbstractAction
{
public:
	DialogueAction(std::string& txt, std::string& name, TextureType face, bool block = false);
	~DialogueAction();
	virtual int run(float dt);
	virtual void reset();

private:
	std::string text;
	std::string name;
	TextureType face;

	bool blocking = false;
	bool sent = false;
};

