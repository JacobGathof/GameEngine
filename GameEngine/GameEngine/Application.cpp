#include "Application.h"


Application::Application(){}
Application::~Application(){}


void Application::test() {

	std::cout << "-=-=-=-Running Tests-=-=-=-" << std::endl;


	Window::init("Hello World", 300, 300);


	ShaderProgram sh;
	sh.compileShader("res_test/defaultShader.vert", 0, "res_test/defaultShader.frag");
	Font font("res_test/font.fnt", "res_test/font.png");
	Texture tex("res_test/Calamity.png");



	while (!Window::shouldClose()) {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		Window::pollEvents();

		Window::swapBuffers();
	}

	Window::destroy();



	std::cout << "-=-=-=-Finished Tests-=-=-=-" << std::endl;

}


void Application::run()
{
	test();
}

int main() {
	Application app;
	app.run();

	system("pause");
	return 0;
}
