#pragma once
#include <string>
#include "AbstractAction.h"

class QuoteAction : public AbstractAction
{
public:
	QuoteAction(std::string& s1);
	~QuoteAction();
	virtual int run(float dt = 0.0f);
	virtual void reset();
private:
	bool first;
	std::string str;
};
