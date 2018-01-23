#include "Input.h"
#include "Window.h"

bool Input::keys[512];
std::map<int, int> Input::keyBinds;
std::vector<char> Input::keysDown;

Input::Input(){

}


Input::~Input(){

}

void Input::processInput(float dt){
	keysDown.clear();

	if (keys[GLFW_KEY_ESCAPE]) {
		Window::close();
	}

	if (keys[GLFW_KEY_T]) {
		keys[GLFW_KEY_T] = false;
		std::cout << "Hi" << std::endl;
	}

	if (keys[GLFW_KEY_W]) {
		keysDown.push_back('w');
	}

	if (keys[GLFW_KEY_S]) {
		keysDown.push_back('s');
	}

	if (keys[GLFW_KEY_D]) {
		keysDown.push_back('d');
	}

	if (keys[GLFW_KEY_A]) {
		keysDown.push_back('a');
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

