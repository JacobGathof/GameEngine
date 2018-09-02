#include "ScriptManager.h"


bool ScriptManager::running = false;

ScriptManager::ScriptManager()
{
}


ScriptManager::~ScriptManager()
{
}

void ScriptManager::update(float dt)
{
	running = false;

	int b = NODE_HALTED;
	if (currentScript != 0) {
		b = currentScript->update(dt);
		if (b == NODE_HALTED) {
			currentScript = 0;
		}
		if (b == NODE_TERMINATED) {
			activeScripts.remove(currentScript);
			currentScript = 0;

		}
		else {
			running = true;
		}
	}
	if (b == NODE_RUNNING) {
		return;
	}

	for (int i = 0; i < activeScripts.size(); i++) {

		b = activeScripts[i]->readyToRun(dt);

		if (b == ACTION_COMPLETE) {
			running = true;
			currentScript = activeScripts[i];
			return;
		}
	}


}

void ScriptManager::init()
{
	elements[GraphType::MAIN] = new Graph("res/script/test.txt");
	elements[GraphType::SECONDARY] = new Graph("res/script/blacksmith.txt");
	elements[GraphType::TERNARY] = new Graph("res/script/bookkeeper.txt");

	activeScripts.add(elements[GraphType::MAIN]);
	activeScripts.add(elements[GraphType::SECONDARY]);

}

bool ScriptManager::isRunning()
{
	return running;
}

void ScriptManager::addScript(GraphType type)
{
	if (std::find(activeScripts.begin(), activeScripts.end(), elements[type]) == activeScripts.end()) {
		elements[type]->reset();
		activeScripts.add(elements[type]);
	}
	
}
