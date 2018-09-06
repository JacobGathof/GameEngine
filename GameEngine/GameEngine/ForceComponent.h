#pragma once
#include "AbstractObjectComponent.h"
#include "List.h"
#include "Force.h"

class ForceComponent : public AbstractObjectComponent
{
public:
	ForceComponent();
	~ForceComponent();

	static ForceComponent comp;
	static ForceComponent* getComponent();

	virtual bool update(float dt);

	void addForce(Force* f);

	Force getTotalForce();

private:
	List<Force*> forces;

};

