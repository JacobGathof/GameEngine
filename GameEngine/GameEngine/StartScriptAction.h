#pragma once
#include "AbstractAction.h"
#include "ResourceManager.h"

class StartScriptAction :
	public AbstractAction
{
public:
	StartScriptAction(GraphType type);
	~StartScriptAction();

	virtual int run(float dt);
	GraphType tp;
};

