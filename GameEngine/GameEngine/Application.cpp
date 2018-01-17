#include "Application.h"


Application::Application(){}
Application::~Application(){}

void Application::test() {

	std::cout << "-=-=-=-Running Tests-=-=-=-" << std::endl;


	Window::init("Hello World", 800, 800);

	ShaderManager::init();
	FontManager::init();
	ModelManager::init();

	Texture tex("res_test/Melody.png");
	ParticleSystem sys;

	Text text(Vector2f(-1, 1), std::string(
		"dolor ipsum dolor sit amet, "
		"consectetur adipiscing elit, "
		"sed do eiusmod tempor incididunt "
		"ut labore et dolore magna aliqua. "
		"Ut enim ad minim veniam, quis "
		"nostrud exercitation ullamco "
		"laboris nisi ut aliquip ex ea "
		"commodo consequat. Duis aute irure "
		"dolor in reprehenderit in voluptate "
		"velit esse cillum dolore eu fugiat "
		"nulla pariatur. Excepteur sint "
		"occaecat cupidatat non proident, "
		"sunt in culpa qui officia deserunt "
		"mollit anim id est laborum."

	) , Vector2f(0.25f, 0.25f), FontManager::get(FontType::DEFAULT));

	text.resetLength();

	Timer timer;
	timer.setTickLength(0.01f);


	// Code Toggle: Remove single "/" on the line below to hide window

	//*
	float dt;
	Window::show();
	while (!Window::shouldClose()) {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		Window::pollEvents();
		timer.update();
		dt = timer.getDeltaTime();

		sys.update(dt);

		if (timer.tick()) {
			text.addLetter();
		}

		if (Input::keys[GLFW_KEY_0]) {
			Input::keys[GLFW_KEY_0] = false;
			tex.eraseData();
		}


		ShaderManager::get(ShaderType::BASIC_SHADER)->bind();
		tex.bind();
		ModelManager::get(ModelType::MODEL_SQUARE)->bind();
		glDrawArrays(GL_TRIANGLES, 0, 6);


		sys.render();
		text.render();


		Input::processInput(dt);

		Window::swapBuffers();
	}
	/*/
		std::cout << "Here" 
	//*/

	ShaderManager::clean();
	FontManager::clean();
	ModelManager::clean();

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
