#pragma once
#include "IManager.h"
#include "Graph.h"
#include "ResourceType.h"


class ScriptManager : public IManager<Graph, GraphType>
{
public:
	ScriptManager();
	~ScriptManager();
};

