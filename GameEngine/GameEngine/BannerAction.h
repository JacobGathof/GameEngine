#pragma once
#include "AbstractScriptAction.h"
#include "UIManager.h"

class BannerAction : public AbstractScriptAction
{
public:
	BannerAction(std::string& s1, std::string& s2);
	~BannerAction();
	virtual int run(float dt);
	virtual void reset();
private:
	bool first;
	std::string str1;
	std::string str2;
};

