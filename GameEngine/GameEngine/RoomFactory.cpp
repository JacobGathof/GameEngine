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
#include "TransitionAction.h"

#include "ParticleSystem.h"
#include "ToggleEffectAction.h"
#include "ShopWindowAction.h"
#include "FireObject_TEST.h"
#include "LightPath.h"

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
	Player * melody = new Player(ObjectData{ "Player", Vector2f(0, 0), Vector2f(256, 256), TextureType::SPRITESHEET_MELODY}, playerAi);
	melody->persistent = true;
	melody->addEffect(new Light(Vector2f(0, 0), Color(1,1,1, 1), Vector2f(256, 256)));
	GameState::battleManager = BattleManager(melody);
	//melody->addEffect(new Shadow());
	melody->addEffect(new Tag(std::string("Melody"), Vector2f(0, 32)));
	//melody->addEffect(new LightPath());

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
	
	//Object* table = new Object(std::string(""), TextureType::ZH_WARDROBE, Vector2f(-512, 256), 4 * Vector2f(256, 64));
	CardObject* card1 = new CardObject(ObjectData{"", Vector2f(-512 + 64, -256 - 64), Vector2f(64, 64) , TextureType::T_CARD_GHOST}, Res::get(CardType::UNLIMITED_WATERWORKS));
	card1->setEnterTrigger(new TransitionAction());
	card1->setExitTrigger(new DebugAction("Exited Trigger"));


	//melody->addEffect(new Light(Vector2f(0, 0), Color(0, .5, 0, 1)));
	
	InteractableObject * chest = new InteractableObject(ObjectData{ "", Vector2f(0, -256), Vector2f(128, 128), TextureType::TEXTURE_SLIME});
	chest->setInteraction(new QuoteAction(std::string("Quote Interaction")));
	//chest->addAI(new FollowAI(World::getInstance()->getWorldObject("Player")));
	chest->addEffect(new Light(Vector2f(0, 0), Color(1,1,1,1), Vector2f(256, 256)));
	chest->addEffect(new Tag(std::string("Slime"), Vector2f(0, 80)));

	chest->addEffect(new ParticleSystem<TexturedParticle>(10, 4,
		{	new DirectedVelocityComp(0,0),
			new SpeedComp(100,100),
			new RandColorComp(),
			new PosSpreadComp(50),
			new TextureComp(TextureType::T_MUSIC_NOTE),
		}));
	chest->setEnterTrigger(new ToggleEffectAction(chest, true));
	chest->setExitTrigger(new ToggleEffectAction(chest, false));
	chest->activateEffects(false);

	//chest->addEffect(new FastParticleSystem(4096*4));

	LivingObject * chest2 = new LivingObject(ObjectData{ "nm", Vector2f(-256, 0), Vector2f(128, 128), TextureType::TEXTURE_SLIME });
	chest2->setInteraction(new GraphAction("res/script/test.txt"));


	InteractableObject* torch = new FireObject_TEST(ObjectData{"", Vector2f(128 - 64 * 4, 128 * 5), Vector2f(64, 64) , TextureType::T_CARD_4 });
	torch->setAction(SpriteSheet::AnimationState::IDLE);
	//torch->addAI(new CircleAI(Vector2f(0, 0), 512+256, 1.0f));
	room->addObject(torch);


	
	//torch->addEffect(new Light(Vector2f(0, 0), Color(1,1,1,1), 4*Vector2f(128, 128)));
	//chest2->addEffect(new Tag(std::string("Horus?"), Vector2f(0, 80)));


	CardObject* card2 = new CardObject(ObjectData{"", Vector2f(-512 + 192, 256 + 64), Vector2f(64, 64) , TextureType::T_CARD_ACE}, Res::get(CardType::UNLIMITED_WATERWORKS));
	//card2->setInteraction(new ShopWindowAction(Res::get(CardType::UNLIMITED_WATERWORKS), true));



	CardObject* card3 = new CardObject(ObjectData{ "", Vector2f(-512 + 192 + 128, 256 + 64), Vector2f(64, 64) , TextureType::T_CARD_ACE}, Res::get(CardType::DAWN));
	//card3->setInteraction(new ShopWindowAction(Res::get(CardType::DAWN), true));


	room->addWorldObject(World::getInstance()->getWorldObject("Player"));
	//room->addObject(table);
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
	
	room->loadObjects(std::string("ObjectMaps/Clearing"));
	
	LivingObject * echo = new LivingObject(ObjectData{ "Echo", Vector2f(-920, -500), Vector2f(128, 128), TextureType::TEXTURE_MAVIS });
	echo->weight = Weight::GHOST;
	room->addObject(echo);
	room->addWorldObject(World::getInstance()->getWorldObject("Player"));
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
