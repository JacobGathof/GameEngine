#include "Input.h"
#include "Window.h"

bool Input::keys[512];
Vector2f Input::mousePtr;
std::map<int, int> Input::keyBinds;
PlayerAI * Input::ai;
std::map<int, KeyMap> Input::physicalMap;

Input::Input(){

}


Input::~Input(){

}

void Input::processInput(float dt) {
	
	if (keys[GLFW_KEY_ESCAPE]) {
		Window::close();
	}

	if (keys[GLFW_KEY_O]) {
		keys[GLFW_KEY_O] = false;
		Window::setMaximize(true);
	}

	if (keys[GLFW_KEY_P]) {
		keys[GLFW_KEY_P] = false;
		Window::setMaximize(false);
	}

	if (keys[GLFW_KEY_GRAVE_ACCENT]) {
		keys[GLFW_KEY_GRAVE_ACCENT] = false;
		Window::toggleFullscreen();
	}

}

void Input::feedKey(int key, int state){
	if (key < 0 || key > 512) return;
	keys[key] = state;
	std::map<int, KeyMap>::iterator it = physicalMap.find(key);
	if (it == physicalMap.end()) {
		return;
	}
	ai->receiveInput(it->second, state);
}

void Input::init()
{
	physicalMap.insert(std::pair<int, KeyMap>(87, KeyMap::KEY_UP));
	physicalMap.insert(std::pair<int, KeyMap>(83, KeyMap::KEY_DOWN));
	physicalMap.insert(std::pair<int, KeyMap>(65, KeyMap::KEY_LEFT));
	physicalMap.insert(std::pair<int, KeyMap>(68, KeyMap::KEY_RIGHT));
	physicalMap.insert(std::pair<int, KeyMap>(69, KeyMap::KEY_INTERACT));
	physicalMap.insert(std::pair<int, KeyMap>(49, KeyMap::KEY_SKILL_1));
	physicalMap.insert(std::pair<int, KeyMap>(50, KeyMap::KEY_SKILL_2));
	physicalMap.insert(std::pair<int, KeyMap>(51, KeyMap::KEY_SKILL_3));
	physicalMap.insert(std::pair<int, KeyMap>(52, KeyMap::KEY_SKILL_4));
	physicalMap.insert(std::pair<int, KeyMap>(53, KeyMap::KEY_SKILL_5));
}

void Input::feedMousePosition(Vector2f & pos)
{
	mousePtr = pos;
	UIManager::hover(pos);
}

void Input::feedMouseEvent(int button, int action){
	if (action == GLFW_PRESS) {
		UIManager::click(mousePtr);
	}
}

void Input::setupKeybinds(){
	for (int i = 0; i < 512; i++) {
		keyBinds[i] = i;
	}
}

