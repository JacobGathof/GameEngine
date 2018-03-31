#include "Application.h"
#include <time.h>
#include "Renderer.h"
#include "Graph.h"
#include "AudioSystem.h"
#include "FastParticleSystem.h"
#include "SaveUtilities.h"
#include "Room.h"

Application::Application(){}
Application::~Application(){}


void Application::run()
{
	srand((unsigned int)time(0));

	SaveUtilities::init();
	SaveUtilities::loadGame();

	Window::init("The Echo Effect", 800, 800);
	AudioSystem::init();

	ResourceManager::init();
	Screen::init();
	Input::init();

	UIManager::init();

	//Rooms and the world
	World * world = World::getInstance();
	Room room;

	//Begin Init Room 1
	room.addHitbox(Vector2f(1000, -400), Vector2f(2600, 1400));
	room.addHitbox(Vector2f(2270, 2700), Vector2f(50, 4800));
	room.addHitbox(Vector2f(-320, -600), Vector2f(30, 1600));
	room.addHitbox(Vector2f(-1900, -2000), Vector2f(3200, 1400));
	room.addHitbox(Vector2f(-4500, -2000), Vector2f(1200, 1400));
	room.addHitbox(Vector2f(-3480, -800), Vector2f(30, 1000));
	room.addHitbox(Vector2f(-3910, -800), Vector2f(30, 1000));
	//End Init Room 1

	Room room2;
	room.setTerrainMap(std::string("eastOfTown2.txt"));
	// Start making objects here
	PlayerAI playerAi;
	Input::ai = &playerAi;
	Player melody(std::string("Melody"), TextureType::SPRITESHEET_MELODY, Vector2f(100,100), Vector2f(256,256), &playerAi);
	Hitbox * circ = new ComplexHitbox(new ComplexPolygon({Vector2f(-100,0), Vector2f(100,0), Vector2f(150,100), Vector2f(0,150), Vector2f(-150,100) }), Vector2f(0, 0));
	//Hitbox * circ = new RectHitbox(Rect(Vector2f(0, 0), Vector2f(200, 300)), Vector2f(0, 0));
	Hitbox * circ2 = new CircleHitbox(Circle(Vector2f(0,0), 100), Vector2f(0, 0));
	melody.addHitbox(circ);
	LivingObject structure(std::string("Structure"), TextureType::SPRITESHEET_MELODY, Vector2f(-500, -300), Vector2f(256, 256), 100, 100);
	structure.addHitbox(circ2);
	FollowAI follow(&melody);
	structure.moveSpeed = 600;
	//TransitionObject trans(TextureType::TEXTURE_TEST, Vector2f(-.5, .5), Vector2f(.5, .5), &room2);
	//Object structure2(TextureType::TEXTURE_TEST, Vector2f(-.5, 1), Vector2f(.5, .5));

	Object flo(std::string("name"), TextureType::TEXTURE_DAGON, Vector2f(0, 1024 + 512), Vector2f(256, 256));

	world->setCurrentRoom(&room);
	room.addObject(&melody);
	room.addObject(&flo);

	//room.addObject(&structure);
	//room.addObject(&trans);

	Res::get(ShaderType::TEXT_SHADER)->bind();
	Res::get(ShaderType::TEXT_SHADER)->loadFloat("aspect_ratio", Window::getAspectRatio());

	RainParticleSystem *sys = new RainParticleSystem();
	//sys->parentPosition = &melody.pos;
	//sys->startColor = Color::DarkBlue;
	//sys->endColor = Color::DarkPurple;

	melody.addEffect(sys);



	GameTimer timer;
	timer.setTickLength(1.0f);

	//Circle circ(Vector2f(0,0), 256.0f);

	Graph graph;


	float dt;
	Window::show();
	//Window::close();
	
	while (!Window::shouldClose()) {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		Window::pollEvents();
		timer.update();
		dt = timer.getDeltaTime();


		Screen::follow(melody.pos);
		GameState::setGlobalDebug(std::to_string(timer.FPS()));

		Input::processInput(dt);
		UIManager::update(dt);

		graph.update(dt);

		world->update(dt);


		Screen::updateUniforms();

		
		Res::get(ShaderType::BASIC_SHADER)->bind();
		Res::get(TextureType::TEXTURE_DEFAULT)->bind();
		Res::get(ModelType::MODEL_SQUARE_CENTERED)->bind();
		Res::get(ShaderType::BASIC_SHADER)->loadVector2f("translate", Vector2f(0, 0));
		Res::get(ShaderType::BASIC_SHADER)->loadVector2f("scale",Vector2f(32, 32));
		//Res::get(ModelType::MODEL_SQUARE_CENTERED)->draw();



		Res::get(ShaderType::PARTICLE_FAST_SHADER)->loadFloat("gameTime", timer.getGameTime());
		Res::get(ShaderType::WATER_SHADER)->bind();
		Res::get(ShaderType::WATER_SHADER)->loadFloat("gameTime", timer.getGameTime());


		Renderer::draw();

	
		Window::swapBuffers();
	}

	SaveUtilities::saveGame();

	World::clean();

	
	ResourceManager::clean();
	UIManager::clean();

	AudioSystem::clean();
	Window::destroy();

}

int main() {
	Application app;
	app.run();

	//system("pause");
	return 0;
}
