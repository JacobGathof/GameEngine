#include "Application.h"
#include <time.h>
#include "Renderer.h"
#include "Graph.h"
#include "AudioSystem.h"
#include "FastParticleSystem.h"


Application::Application(){}
Application::~Application(){}


void Application::run()
{
	srand((unsigned int)time(0));

	Window::init("The Echo Effect", 800, 800);
	AudioSystem::init();

	ResourceManager::init();
	Screen::init();
	Input::init();

	UIManager::init();


	//Rooms and the world
	World * world = World::getInstance();
	Room room;
	room.setTerrainMap("Clearing");
	room.loadObjects(std::string("ObjectMaps/Clearing"));

	//Begin Init Room 1
	/*
	room.addHitbox(Vector2f(1000, -400), Vector2f(2600, 1400));
	room.addHitbox(Vector2f(2270, 2700), Vector2f(50, 4800));
	room.addHitbox(Vector2f(-320, -600), Vector2f(30, 1600));
	room.addHitbox(Vector2f(-1900, -2000), Vector2f(3200, 1400));
	room.addHitbox(Vector2f(-4500, -2000), Vector2f(1200, 1400));
	room.addHitbox(Vector2f(-3480, -800), Vector2f(30, 1000));
	room.addHitbox(Vector2f(-3910, -800), Vector2f(30, 1000));
	*/
	//End Init Room 1

	Room room2;
	room2.setTerrainMap("eastOfTown2.txt");
	// Start making objects here
	PlayerAI playerAi;
	Input::ai = &playerAi;
	Player melody("Melody", TextureType::TEXTURE_MELODY, Vector2f(100,-1500), Vector2f(256,256), &playerAi);
	melody.persistent = true;
	Hitbox * circ = new ComplexHitbox(new ComplexPolygon({Vector2f(-100,0), Vector2f(100,0), Vector2f(150,100), Vector2f(0,150), Vector2f(-150,100) }), Vector2f(0, 0));
	Hitbox * rect = new RectHitbox(Rect(Vector2f(0, 0), Vector2f(150, 100)), Vector2f(-10, -90));
	Hitbox * circ2 = new CircleHitbox(Circle(Vector2f(0,0), 100), Vector2f(0, 0));
	melody.addHitbox(circ);
	LivingObject structure("Structure", TextureType::TEXTURE_MELODY, Vector2f(-2000, -300), Vector2f(256, 256), 100, 100);
	structure.addHitbox(circ2);
	FollowAI follow(&melody);
	structure.moveSpeed = 600;
	TransitionObject trans(TextureType::TEXTURE_TEST, Vector2f(-.5, .5), Vector2f(.5, .5), &room2);
	trans.addHitbox(rect);
	//Object structure2(TextureType::TEXTURE_TEST, Vector2f(-.5, 1), Vector2f(.5, .5));
	

	world->setCurrentRoom(&room);
	room.addObject(&melody);
	room.addObject(&structure);
	room.addObject(&trans);

	Res::get(ShaderType::TEXT_SHADER)->bind();
	Res::get(ShaderType::TEXT_SHADER)->loadFloat("aspect_ratio", Window::getAspectRatio());

	DefaultParticleSystem *sys = new DefaultParticleSystem();
	//sys->parentPosition = &melody.pos;
	sys->startColor = Color::DarkBlue;
	sys->endColor = Color::DarkPurple;


	melody.addEffect(sys);



	GameTimer timer;
	timer.setTickLength(1.0f);

	//Circle circ(Vector2f(0,0), 256.0f);

	Graph graph;


	float dt;
	Window::show();

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

		//sys.update(dt);
		//sys.draw();
		//circ.draw(timer.getGameTime());

		Screen::updateUniforms();

		
		Res::get(ShaderType::BASIC_SHADER)->bind();
		Res::get(TextureType::TEXTURE_DEFAULT)->bind();
		Res::get(ModelType::MODEL_SQUARE_CENTERED)->bind();
		Res::get(ShaderType::BASIC_SHADER)->loadVector2f("translate", Vector2f(0, 0));
		Res::get(ShaderType::BASIC_SHADER)->loadVector2f("scale",Vector2f(32, 32));
		Res::get(ModelType::MODEL_SQUARE_CENTERED)->draw();


		Res::get(ShaderType::PARTICLE_FAST_SHADER)->loadFloat("gameTime", timer.getGameTime());


		Renderer::draw();

	
		Window::swapBuffers();
	}
	ResourceManager::clean();
	UIManager::clean();

	AudioSystem::clean();
	Window::destroy();

}

int main() {
	Application app;
	app.run();

	system("pause");
	return 0;
}
