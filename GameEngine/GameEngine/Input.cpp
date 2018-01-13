#include "Input.h"
#include "Window.h"

bool Input::keys[512];

Input::Input(){

}


Input::~Input(){

}

void Input::processInput(float dt){

	if (keys[GLFW_KEY_ESCAPE]) {
		Window::close();
	}

}

void Input::feedKey(int key, int state){
	if (key < 0 || key > 512) return;
	keys[key] = state;
}

