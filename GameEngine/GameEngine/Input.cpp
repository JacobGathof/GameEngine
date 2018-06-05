#include "Input.h"
#include "Window.h"
#include "UIManager.h"
#include "PlayerAI.h"


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

	if (keyboard.press(GLFW_KEY_1)) {
		pause(false);
	}

	if (keyboard.press(GLFW_KEY_GRAVE_ACCENT)) {
		Window::toggleFullscreen();
	}

	if (keyboard.press(GLFW_KEY_T)) {
		UIManager::toggleMenu();
	}

	if (keyboard.press(GLFW_KEY_TAB)) {
		UIManager::toggleCommandLine();
	}


	if (GameState::battleManager.battleState == NOBATTLE) {
		UIManager::handleMouseEvents(mouse);
		UIManager::handleKeyboardEvents(keyboard);
	}

	ai->receiveInput(keyboard);

	Screen::updateScroll((float)mouse.getScroll() / 200.0f);

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

void Input::feedMouseScroll(int scroll)
{
	mouse.setScroll(scroll);
}

void Input::pause(bool t)
{
	if (t) {
		GameState::applicationState.gamePaused = true;
	} else {
		GameState::applicationState.gamePaused = !GameState::applicationState.gamePaused;
	}
}


