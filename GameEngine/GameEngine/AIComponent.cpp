#include "AIComponent.h"

AIComponent AIComponent::comp;


AIComponent::AIComponent()
{
}


AIComponent::~AIComponent()
{
	for (auto ai : aiQueue) {
		delete ai;
	}
	delete defaultAI;
}

AIComponent * AIComponent::getComponent()
{
	return &comp;
}



void AIComponent::addAI(AI * ai)
{
	if (defaultAI == 0) {
		defaultAI = ai;
	}
	else {
		aiQueue.add(ai);
	}
}

bool AIComponent::update(float dt)
{
	if (aiQueue.size() == 0) {
		if (defaultAI != 0) {
			defaultAI->execute(parent, dt);
		}
	}
	else {
		if (aiQueue[0]->execute(parent, dt)) {
			//If the current AI is done, remove it
			AI * ai = aiQueue[0];
			aiQueue.removeIndex(0);
			delete ai;
		}
	}
	return false;
}
