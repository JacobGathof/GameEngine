#include "Input.h"
#include "Window.h"

bool Input::keys[512];
std::map<int, int> Input::keyBinds;

Input::Input(){

}


Input::~Input(){

}

void Input::processInput(float dt){

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
}

void Input::setupKeybinds(){
	for (int i = 0; i < 512; i++) {
		keyBinds[i] = i;
	}
}

