#pragma once

#define ACTION_RUNNING 0
#define ACTION_COMPLETE 1
#define ACTION_PAUSE 2

class AbstractAction
{
public:
	AbstractAction();
	~AbstractAction();

	virtual int run(float dt = 0.0f);
	virtual void reset();
};

