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
