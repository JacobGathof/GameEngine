#include "Keyboard.h"


Keyboard::Keyboard()
{
	virtualMap[VirtualKey::UP] = GLFW_KEY_W;
	virtualMap[VirtualKey::DOWN] = GLFW_KEY_S;
	virtualMap[VirtualKey::LEFT] = GLFW_KEY_A;
	virtualMap[VirtualKey::RIGHT] = GLFW_KEY_D;
	virtualMap[VirtualKey::INTERACT] = GLFW_KEY_E;
	virtualMap[VirtualKey::SKILL_1] = GLFW_KEY_1;
	virtualMap[VirtualKey::SKILL_2] = GLFW_KEY_2;
	virtualMap[VirtualKey::SKILL_3] = GLFW_KEY_3;
	virtualMap[VirtualKey::SKILL_4] = GLFW_KEY_4;
	virtualMap[VirtualKey::SKILL_5] = GLFW_KEY_5;
	virtualMap[VirtualKey::ARROW_UP] = GLFW_KEY_UP;
	virtualMap[VirtualKey::ARROW_DOWN] = GLFW_KEY_DOWN;
	virtualMap[VirtualKey::ARROW_LEFT] = GLFW_KEY_LEFT;
	virtualMap[VirtualKey::ARROW_RIGHT] = GLFW_KEY_RIGHT;
	virtualMap[VirtualKey::DODGE] = GLFW_KEY_SPACE;

	
	nameMap[VirtualKey::UP] = "Up";
	nameMap[VirtualKey::DOWN] = "Down";
	nameMap[VirtualKey::LEFT] = "Left";
	nameMap[VirtualKey::RIGHT] = "Right";
	nameMap[VirtualKey::INTERACT] = "Interact";
	nameMap[VirtualKey::SKILL_1] = "Skill 1";
	nameMap[VirtualKey::SKILL_2] = "Skill 2";
	nameMap[VirtualKey::SKILL_3] = "Skill 3";
	nameMap[VirtualKey::SKILL_4] = "Skill 4";
	nameMap[VirtualKey::SKILL_5] = "Skill 5";
	nameMap[VirtualKey::DODGE] = "Dodge";

}


Keyboard::~Keyboard()
{
}

KeyState Keyboard::getKeyState(int i)
{
	return keys[i];
}

KeyState Keyboard::getKeyState(VirtualKey k)
{
	return getKeyState(virtualMap[k]);
}

void Keyboard::setKeyState(int key, int state)
{
	if (state == GLFW_PRESS) {
		keys[key] = KeyState::PRESS;
		pressed.push(key);
	}
	if (state == GLFW_RELEASE) {
		keys[key] = KeyState::RELEASE;
		released.push(key);
	}
}

void Keyboard::setKeyState(VirtualKey k, int state)
{
	setKeyState(virtualMap[k], state);
}

void Keyboard::setMods(int m, int state)
{
	if (state == GLFW_PRESS) {
		mods = mods | m;
	}
	if (state == GLFW_RELEASE) {
		mods = mods & m;
	}
}

void Keyboard::update(){

	while (!pressed.empty()) {
		keys[pressed.front()] = KeyState::DOWN;
		pressed.pop();
	}

	while (!released.empty()) {
		keys[released.front()] = KeyState::UP;
		released.pop();
	}
}

bool Keyboard::down(int key)
{
	return (keys[key] == KeyState::DOWN || keys[key] == KeyState::PRESS);
}

bool Keyboard::up(int key)
{
	return (keys[key] == KeyState::DOWN || keys[key] == KeyState::PRESS);
}

bool Keyboard::press(int key)
{
	return keys[key] == KeyState::PRESS;
}

bool Keyboard::release(int key)
{
	return keys[key] == KeyState::RELEASE;
}


bool Keyboard::down(VirtualKey key)
{
	return down(virtualMap[key]);
}

bool Keyboard::up(VirtualKey key)
{
	return up(virtualMap[key]);
}

bool Keyboard::press(VirtualKey key)
{
	return press(virtualMap[key]);
}

bool Keyboard::release(VirtualKey key)
{
	return release(virtualMap[key]);
}

bool Keyboard::modActive(int mod)
{
	return mod & mods;
}

void Keyboard::setKeyBind(VirtualKey vk, int k)
{
	virtualMap[vk] = k;
}

int Keyboard::getKeyBind(VirtualKey vk)
{
	return virtualMap[vk];
}

int Keyboard::getCurrentPressed()
{
	if (pressed.empty()) {
		return -1;
	}
	return pressed.front();
}

char * Keyboard::getKeyName(VirtualKey vk)
{
	return nameMap[vk];
}

const char * Keyboard::getRealKeyName(int key)
{
	const char* name = glfwGetKeyName(key, 0);
	return name;
}

const char * Keyboard::getRealKeyName(VirtualKey key)
{
	return getRealKeyName(virtualMap[key]);
}

void Keyboard::clearQueues()
{
	while (!pressed.empty()) {
		keys[pressed.front()] = KeyState::UP;
		pressed.pop();
	}

	while (!released.empty()) {
		keys[released.front()] = KeyState::UP;
		released.pop();
	}
}
