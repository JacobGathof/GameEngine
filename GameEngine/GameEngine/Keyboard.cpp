#include "Keyboard.h"




Keyboard::Keyboard()
{
	virtualMap[VirtualKey::UP] = GLFW_KEY_W;
	virtualMap[VirtualKey::DOWN] = GLFW_KEY_S;
	virtualMap[VirtualKey::LEFT] = GLFW_KEY_A;
	virtualMap[VirtualKey::RIGHT] = GLFW_KEY_D;
	virtualMap[VirtualKey::SKILL_1] = GLFW_KEY_1;
	virtualMap[VirtualKey::SKILL_2] = GLFW_KEY_2;
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
