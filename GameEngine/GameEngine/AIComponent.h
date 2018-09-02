#pragma once
#include "AbstractObjectComponent.h"
#include "AI.h"
#include "List.h"

class AIComponent : public AbstractObjectComponent
{
public:
	AIComponent();
	~AIComponent();

	static AIComponent comp;
	static AIComponent* getComponent();

	AI * defaultAI;
	List<AI *> aiQueue;

	void addAI(AI * ai);
	virtual bool update(float dt);

};

