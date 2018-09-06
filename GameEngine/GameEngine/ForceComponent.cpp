#include "ForceComponent.h"
#include "Object.h"

ForceComponent ForceComponent::comp;

ForceComponent::ForceComponent()
{
}


ForceComponent::~ForceComponent()
{
	for (auto f : forces) {
		delete f;
	}
}

ForceComponent * ForceComponent::getComponent()
{
	return &comp;
}

bool ForceComponent::update(float dt)
{
	parent->pos += getTotalForce().value * dt;
	for (int i = 0; i < forces.size(); i++) {
		Force* f = forces[i];
		if (!f->update(dt)) {
			forces.remove(f);
			delete f;
			i--;
		}
	}
	return true;
}

void ForceComponent::addForce(Force * f)
{
	forces.add(f);
}

Force ForceComponent::getTotalForce()
{
	Force sum(Vector2f(0,0));
	for (auto f : forces) {
		sum.value += f->value;
	}
	sum.value / forces.size();
	return sum;
}
