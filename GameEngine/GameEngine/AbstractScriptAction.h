#pragma once
class AbstractScriptAction
{
public:
	AbstractScriptAction();
	~AbstractScriptAction();
	virtual int run(float dt) = 0;
};

