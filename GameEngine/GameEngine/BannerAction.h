#pragma once
#include "AbstractAction.h"
#include <string>

class BannerAction : public AbstractAction
{
public:
	BannerAction(std::string& s1, std::string& s2);
	~BannerAction();
	virtual int run(float dt = 0.0f);
	virtual void reset();
private:
	bool first;
	std::string str1;
	std::string str2;
};

