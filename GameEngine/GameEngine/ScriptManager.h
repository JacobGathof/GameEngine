#pragma once
#include "IManager.h"
#include "Graph.h"
#include "ResourceType.h"
#include "Object.h"

class ScriptManager : public IManager<Graph, GraphType>
{
public:
	ScriptManager();
	~ScriptManager();

	void update(float dt);
	virtual void init();

private:
	List<Graph*> activeScripts;
	Graph* currentScript;
};

