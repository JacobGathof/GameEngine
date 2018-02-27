#include "Input.h"
#include "Window.h"


Mouse Input::mouse;
Keyboard Input::keyboard;

PlayerAI * Input::ai;

Input::Input(){

}


Input::~Input(){

}

void Input::processInput(float dt) {
	
	if (keyboard.press(GLFW_KEY_ESCAPE)) {
		Window::close();
	}

	if (keyboard.press(GLFW_KEY_GRAVE_ACCENT)) {
		Window::toggleFullscreen();
	}

	UIManager::handleMouseEvents(mouse);

	ai->receiveInput(keyboard);

	mouse.update();
	keyboard.update();

}

void Input::feedKey(int key, int state){
	if (key < 0 || key > 512) return;
	keyboard.setKeyState(key, state);

}

void Input::init()
{

}

void Input::feedMousePosition(Vector2f & pos){
	mouse.setPosition(pos);
}

void Input::feedMouseEvent(int button, int action){
	mouse.setButton(button, action);
}


