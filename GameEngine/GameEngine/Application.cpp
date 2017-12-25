#include "Application.h"


Application::Application(){}
Application::~Application(){}


void Application::test() {

	std::cout << "-=-=-=-Running Tests-=-=-=-" << std::endl;

	Color red = Color::DarkRed;
	Color blue = Color::Blue;

	std::cout << red + blue << std::endl;
	std::cout << red * blue << std::endl;
	std::cout << Color::LightGreen << std::endl;

	std::cout << "-=-=-=-Finished Tests-=-=-=-" << std::endl;




	Window::init("Hello World", 300, 300);

	while (!Window::shouldClose()) {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		Window::pollEvents();

		Window::swapBuffers();
	}

	Window::destroy();





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
