#include "RoomFactory.h"
#include "BattleManager.h"


World * RoomFactory::world = 0;
RoomFactory::RoomFactory()
{
}


RoomFactory::~RoomFactory()
{
}

void RoomFactory::CreateAllRooms()
{
	world = World::getInstance();
	ReadingRoom();
	Clearing();

	AddTransitionObjects();
}

void RoomFactory::ReadingRoom()
{
	Room * room = new Room();
	room->setTerrainMap(std::string("StoryTellingRoom"));
	room->loadObjects(std::string("ObjectMaps/storyTellingRoom"));

	PlayerAI * playerAi = new PlayerAI();
	Input::ai = playerAi;
	Player * melody = new Player(std::string("Player"), TextureType::SPRITESHEET_MELODY, Vector2f(100, -1500), Vector2f(256, 256), playerAi);
	melody->persistent = true;

	Hitbox * circ = new ComplexHitbox(new ComplexPolygon({ Vector2f(-100,0), Vector2f(100,0), Vector2f(150,100), Vector2f(0,150), Vector2f(-150,100) }), Vector2f(0, 0));
	Hitbox * rect = new RectHitbox(Rect(Vector2f(0, 0), Vector2f(150, 100)), Vector2f(-10, -90));
	Hitbox * circ2 = new CircleHitbox(Circle(Vector2f(0, 0), 100), Vector2f(0, 0));
	melody->addHitbox(circ);
	melody->giveDeck(DeckManager::getDeck(Decks::TEST));
	GameState::battleManager = BattleManager(melody);
	LivingObject * structure = new LivingObject(std::string("Structure"), TextureType::TEXTURE_MELODY, Vector2f(-2000, -300), Vector2f(256, 256), 100, 100);
	structure->addHitbox(circ2);
	TextInteractionObject * inter = new TextInteractionObject(std::string("Interacting"));
	structure->setInteraction(inter);
	/*
	FollowAI * follow = new FollowAI(melody);
	structure->moveSpeed = 600;
	*/
	
	
	Chest * chest = new Chest(std::string("Chest"), TextureType::TEXTURE_HORUS, Vector2f(-1000, 0), Vector2f(256, 256));
	Card * card = new Card(std::string("My Card"), std::string("Its Mine"), 0);
	chest->addItem(card);
	chest->isStatic = false;
	


	room->addObject(melody);
	room->addObject(structure);

	world->addRoom(std::string("Reading Room"), room);
}

void RoomFactory::Clearing()
{
	Room * room = new Room();
	room->setTerrainMap(std::string("Clearing"));
	room->loadObjects(std::string("ObjectMaps/Clearing"));

	LivingObject * echo = new LivingObject(std::string("Echo"),TextureType::TEXTURE_MAVIS, Vector2f(-920, -500), Vector2f(128, 128),100,100);
	echo->weight = Weight::GHOST;
	room->addObject(echo);
	
	world->addRoom(std::string("Clearing"), room);
}

void RoomFactory::EastOfTown2()
{
	Room * room = new Room();
	room->setTerrainMap(std::string("EastOfTown2.txt"));
	//room->loadObjects(std::string("Clearing"));

	room->addHitbox(Vector2f(1000, -400), Vector2f(2600, 1400));
	room->addHitbox(Vector2f(2270, 2700), Vector2f(50, 4800));
	room->addHitbox(Vector2f(-320, -600), Vector2f(30, 1600));
	room->addHitbox(Vector2f(-1900, -2000), Vector2f(3200, 1400));
	room->addHitbox(Vector2f(-4500, -2000), Vector2f(1200, 1400));
	room->addHitbox(Vector2f(-3480, -800), Vector2f(30, 1000));
	room->addHitbox(Vector2f(-3910, -800), Vector2f(30, 1000));
	world->addRoom(std::string("East of town 2"), room);
}

void RoomFactory::AddTransitionObjects()
{
	Room * readingRoom = world->getRoom(std::string("Reading Room"));
	Room * clearing = world->getRoom(std::string("Clearing"));

}
