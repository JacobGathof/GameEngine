#include "RoomFactory.h"
#include "BattleManager.h"
#include "Tag.h"
#include "Light.h"
#include "FastParticleSystem.h"
#include "GraphAction.h"
#include "CircleAI.h"
#include "CardObject.h"
#include "Shadow.h"
#include "DebugAction.h"
#include "PlayMusicAction.h"
#include "CompositeAction.h"
#include "QuoteAction.h"

RoomFactory::RoomFactory(){}
RoomFactory::~RoomFactory(){}


void RoomFactory::CreateAllRooms()
{
	World * world = World::getInstance();
	addWorldObjects();


	world->addRoom(World::RoomNames::READING_ROOM, createReadingRoom());
	world->addRoom(World::RoomNames::CLEARING, createClearing());
	world->addRoom(World::RoomNames::EAST, createEastOfTown());

	AddTransitionObjects();
}

void RoomFactory::addWorldObjects()
{
	PlayerAI * playerAi = new PlayerAI();
	Input::ai = playerAi;
	Player * melody = new Player(std::string("Player"), TextureType::SPRITESHEET_MELODY, Vector2f(0, 0), Vector2f(256, 256), playerAi);
	melody->persistent = true;
	GameState::battleManager = BattleManager(melody);
	//melody->addEffect(new Shadow());
	//melody->addEffect(new Tag(std::string("Melody"), Vector2f(0, 100)));
	//melody->addEffect(new Light(Vector2f(0, 0), Color(1, 0, 0, 1), Vector2f(256, 256)));


	World::getInstance()->addWorldObject(melody);
}

Room* RoomFactory::createReadingRoom()
{
	Room * room = new Room();
	room->setTerrainMap(std::string("StoryTellingRoom"));
	//room->loadObjects(std::string("ObjectMaps/storyTellingRoom"));

	

	//Hitbox * circ = new ComplexHitbox(new ComplexPolygon({ Vector2f(-100,0), Vector2f(100,0), Vector2f(150,100), Vector2f(0,150), Vector2f(-150,100) }), Vector2f(0, 0));
	//Hitbox * rect = new RectHitbox(Rect(Vector2f(0, 0), Vector2f(150, 100)), Vector2f(-10, -90));
	Hitbox * circ2 = new CircleHitbox(Circle(Vector2f(0, 0), 400), Vector2f(0, 0));
	//melody->addHitbox(circ);
	//melody->giveDeck(Res::get(DeckType::TEST));
	
	Object* table = new Object(std::string(""), TextureType::ZH_WARDROBE, Vector2f(-512, 256), 4 * Vector2f(256, 64));
	CardObject* card1 = new CardObject(Res::get(CardType::UNLIMITED_WATERWORKS), Vector2f(-512+64, 256+64), Vector2f(64,64));
	card1->setEnterTrigger(new PlayMusicAction(AudioType::SOUND_A_NOTE));
	card1->setExitTrigger(new DebugAction("Exited Trigger"));

	//melody->addEffect(new Light(Vector2f(0, 0), Color(0, .5, 0, 1)));
	
	InteractableObject * chest = new InteractableObject(std::string(""), TextureType::TEXTURE_SLIME, Vector2f(0, -256), Vector2f(128, 128));
	chest->setInteraction(new QuoteAction(std::string("Quote Interaction")));
	//chest->addEffect(new Tag(std::string("Slime"), Vector2f(0, 80)));
	//chest->addEffect(new FastParticleSystem(4096*4));

	LivingObject * chest2 = new LivingObject(std::string("nm"), TextureType::TEXTURE_SLIME, Vector2f(-256, 0), Vector2f(128, 128));
	chest2->setInteraction(new GraphAction("res/script/test.txt"));

	//chest2->addEffect(new Tag(std::string("Horus?"), Vector2f(0, 80)));


	CardObject* card2 = new CardObject(Res::get(CardType::UNLIMITED_WATERWORKS), Vector2f(-512 + 192, 256 + 64), Vector2f(64, 64));
	card2->setEnterTrigger(new PlayMusicAction(AudioType::SOUND_A_NOTE));

	CardObject* card3 = new CardObject(Res::get(CardType::UNLIMITED_WATERWORKS), Vector2f(-512 + 192 + 128, 256 + 64), Vector2f(64, 64));
	card3->setEnterTrigger(new PlayMusicAction(AudioType::SOUND_A_NOTE));


	room->addWorldObject(World::getInstance()->getWorldObject("Player"));
	room->addObject(table);
	room->addObject(card1);
	room->addObject(card2);
	room->addObject(card3);
	room->addObject(chest);
	room->addObject(chest2);

	return room;
}

Room* RoomFactory::createClearing()
{
	Room * room = new Room();
	room->setTerrainMap(std::string("Clearing"));
	//room->loadObjects(std::string("ObjectMaps/Clearing"));

	LivingObject * echo = new LivingObject(std::string("Echo"),TextureType::TEXTURE_MAVIS, Vector2f(-920, -500), Vector2f(128, 128));
	echo->weight = Weight::GHOST;
	room->addObject(echo);
	
	return room;
}

Room* RoomFactory::createEastOfTown()
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
	
	return room;
}

void RoomFactory::AddTransitionObjects()
{

}
