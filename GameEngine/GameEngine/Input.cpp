#include "Input.h"
#include "Window.h"
#include "UIManager.h"
#include "PlayerAI.h"
#include "WorldManipulator.h"

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

	if (keyboard.press(GLFW_KEY_TAB)) {
		UIManager::toggleCommandLine();
	}


	if (GameState::battleManager.battleState == NOBATTLE) {
		UIManager::handleMouseEvents(mouse);
		UIManager::handleKeyboardEvents(keyboard);
	}

	if (keyboard.press(GLFW_KEY_1)) {
		pause(false);
	}


	if (keyboard.press(GLFW_KEY_2)) {
		UIManager::setQuoteText(std::string("Testing\aF00 Quote Banner"));
	}

	if (keyboard.press(GLFW_KEY_3)) {
		GameState::inv->printInventory();
		GameState::inv->printCurrentInventory();
	}

	if (keyboard.press(GLFW_KEY_T)) {
		UIManager::toggleMenu();
	}

	if (keyboard.press(GLFW_KEY_Y)) {
		UIManager::setStatusVisible(false);
	}

	if (keyboard.press(GLFW_KEY_U)) {
		UIManager::setStatusVisible(true);
	}

	if (keyboard.down(GLFW_KEY_EQUAL)) {
		feedMouseScroll(-4);
	}
	if (keyboard.down(GLFW_KEY_MINUS)) {
		feedMouseScroll(4);
	}


	/*
	if (mouse.down(GLFW_MOUSE_BUTTON_LEFT)) {
		Vector2f pos = mouse.pos();

		unsigned char * data = new unsigned char[4];

		glReadPixels((int)pos.x, (int)pos.y, 1, 1, GL_RGBA, GL_BYTE, data);
		GameState::color = Color((float)data[0]/255.0f, (float)data[1] / 255.0f, (float)data[2] / 255.0f, 1);

		delete[] data;
	}
	*/




	WorldManipulator::process(mouse, keyboard, dt);
	ai->receiveInput(keyboard, mouse);

	Screen::updateScroll((float)mouse.getScroll() / 200.0f);

	mouse.update();
	keyboard.update();

}

void Input::feedKey(int key, int state, int mods){
	if (key < 0 || key > 512) return;
	keyboard.setKeyState(key, state);
	keyboard.setMods(mods, state);

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


