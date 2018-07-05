#pragma once
#include "AbstractAction.h"
class TextboxWaitAction : public AbstractAction
{
public:
	TextboxWaitAction();
	~TextboxWaitAction();
	virtual int run(float dt);

};

