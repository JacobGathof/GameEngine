#pragma once
#include "AbstractScriptAction.h"

class BannerAction : public AbstractScriptAction
{
public:
	BannerAction();
	~BannerAction();
	virtual int run(float dt);
	virtual void reset();
private:
	float fl;
};

