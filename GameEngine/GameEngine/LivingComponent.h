#pragma once
#include "AbstractObjectComponent.h"

class LivingComponent : public AbstractObjectComponent
{
public:
	LivingComponent();
	~LivingComponent();

	static LivingComponent comp;
	static LivingComponent* getComponent();

	virtual bool update(float dt);
};

