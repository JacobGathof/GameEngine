#pragma once
#include "AbstractAction.h"
#include <string>

class SetFlagAction : public AbstractAction
{
public:
	SetFlagAction(std::string& str, bool val);
	~SetFlagAction();
	virtual int run(float dt);

private:
	std::string str;
	bool val;
};

