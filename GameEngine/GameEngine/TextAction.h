#pragma once
#include "AbstractAction.h"
#include "UIManager.h"
#include "Textbox.h"

class TextAction : public AbstractAction
{
public:
	TextAction(TextboxContentData& data);
	~TextAction();
	virtual int run(float dt);

private:
	TextboxContentData data;
};

