#include "ScriptManager.h"



ScriptManager::ScriptManager()
{
	init();
}


ScriptManager::~ScriptManager()
{
	clean();
}

void ScriptManager::update(float dt)
{
	int b = NODE_HALTED;
	if (currentScript != 0) {
		b = currentScript->update(dt);
		if (b == NODE_HALTED) {
			currentScript = 0;
		}
	}
	if (b == NODE_RUNNING) {
		return;
	}

	for (int i = 0; i < activeScripts.size(); i++) {

		b = activeScripts[i]->readyToRun(dt);

		if (b == ACTION_COMPLETE) {
			currentScript = activeScripts[i];
			return;
		}
	}
}

void ScriptManager::init()
{
	elements[GraphType::MAIN] = new Graph("res/script/test.txt");
	//elements[GraphType::SECONDARY] = new Graph("res/script/test2.txt");

	activeScripts.add(elements[GraphType::MAIN]);

}
