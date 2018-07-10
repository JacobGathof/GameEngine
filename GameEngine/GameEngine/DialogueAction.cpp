#include "DialogueAction.h"



DialogueAction::DialogueAction(std::string & txt, std::string & nm, TextureType f, Vector2f& off, bool block)
{
	text = txt;
	name = nm;
	face = f;
	blocking = block;
	offset = off;
}

DialogueAction::~DialogueAction()
{
}

int DialogueAction::run(float dt)
{
	if (!sent) {
		sent = true;
		UIManager::addText(text, name, face, offset);
	}
	return !blocking | UIManager::isTextboxEmpty();
}

void DialogueAction::reset()
{
	sent = false;
}
