#include "DialogueAction.h"



DialogueAction::DialogueAction(std::string & txt, std::string & nm, TextureType f, bool block)
{
	text = txt;
	name = nm;
	face = f;
	blocking = block;
}

DialogueAction::~DialogueAction()
{
}

int DialogueAction::run(float dt)
{
	if (!sent) {
		sent = true;
		UIManager::addText(text, name, face);
	}
	return !blocking | UIManager::isTextboxEmpty();
}

void DialogueAction::reset()
{
	sent = false;
}
