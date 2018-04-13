#pragma once
#include <string>
#include "AbstractScriptAction.h"

class QuoteAction : public AbstractScriptAction
{
public:
	QuoteAction(std::string& s1);
	~QuoteAction();
	virtual int run(float dt);
	virtual void reset();
private:
	bool first;
	std::string str;
};
