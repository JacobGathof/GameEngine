#include "Input.h"
#include "Window.h"

bool Input::keys[512];
std::map<int, int> Input::keyBinds;
PlayerAI * Input::ai;
std::map<int, KeyMaps> Input::physicalMap;

Input::Input(){

}


Input::~Input(){

}

void Input::processInput(float dt) {
	
	if (keys[GLFW_KEY_ESCAPE]) {
		Window::close();
	}

	if (keys[GLFW_KEY_T]) {
		keys[GLFW_KEY_T] = false;
		std::cout << "Hi" << std::endl;
	}

	if (keys[GLFW_KEY_Q]) {
		keys[GLFW_KEY_Q] = false;
		std::cout << "Debug" << std::endl;
	}
}

void Input::feedKey(int key, int state){
	if (key < 0 || key > 512) return;
	keys[key] = state;
	std::map<int, KeyMaps>::iterator it = physicalMap.find(key);
	if (it == physicalMap.end()) {
		return;
	}
	ai->receiveInput(it->second, state);
}

void Input::init()
{
	physicalMap.insert(std::pair<int, KeyMaps>(87, KeyMaps::KEY_UP));
	physicalMap.insert(std::pair<int, KeyMaps>(83, KeyMaps::KEY_DOWN));
	physicalMap.insert(std::pair<int, KeyMaps>(65, KeyMaps::KEY_LEFT));
	physicalMap.insert(std::pair<int, KeyMaps>(68, KeyMaps::KEY_RIGHT));
	physicalMap.insert(std::pair<int, KeyMaps>(69, KeyMaps::KEY_INTERACT));
	physicalMap.insert(std::pair<int, KeyMaps>(49, KeyMaps::KEY_SKILL_1));
	physicalMap.insert(std::pair<int, KeyMaps>(50, KeyMaps::KEY_SKILL_2));
	physicalMap.insert(std::pair<int, KeyMaps>(51, KeyMaps::KEY_SKILL_3));
	physicalMap.insert(std::pair<int, KeyMaps>(52, KeyMaps::KEY_SKILL_4));
	physicalMap.insert(std::pair<int, KeyMaps>(53, KeyMaps::KEY_SKILL_5));
}

void Input::setupKeybinds(){
	for (int i = 0; i < 512; i++) {
		keyBinds[i] = i;
	}
}

