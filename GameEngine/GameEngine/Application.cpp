#include "Application.h"



Application::Application()
{
}


Application::~Application()
{
}

void Application::run()
{
	std::cout << "Hello World" << std::endl;
}

int main() {
	Application app;
	app.run();

	system("pause");
	return 0;
}
