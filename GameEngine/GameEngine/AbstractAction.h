#pragma once
class AbstractAction
{
public:
	AbstractAction();
	~AbstractAction();

	virtual int run(float dt = 0.0f);
	virtual void reset();
};

