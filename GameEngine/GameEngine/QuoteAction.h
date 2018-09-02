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


class QuoteActionWrapper : public AbstractAction {
public:
	QuoteActionWrapper(std::string& s1);
	~QuoteActionWrapper();
	virtual int run(float dt = 0.0f);
private:
	std::string str;
};
