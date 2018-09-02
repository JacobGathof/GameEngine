#include "RoomFactory.h"
#include "BattleManager.h"
#include "Tag.h"
#include "Light.h"
#include "FastParticleSystem.h"
#include "GraphAction.h"
#include "CircleAI.h"
#include "Shadow.h"
#include "DebugAction.h"
#include "PlayMusicAction.h"
#include "CompositeAction.h"
#include "QuoteAction.h"
#include "TransitionAction.h"

#include "ParticleSystem.h"
#include "ToggleEffectAction.h"
#include "ShopWindowAction.h"
#include "CollidableComponent.h"
#include "AnimatedComponent.h"
#include "LightComponent.h"
#include "EffectComponent.h"
#include "AIComponent.h"
#include "InteractableComponent.h"


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
	Object * melody = new Object(ObjectData{ "Player", Vector2f(0, 0), Vector2f(256, 256), TextureType::SPRITESHEET_MELODY});
	
	AIComponent* aiComp = new AIComponent();
	aiComp->addAI(playerAi);
	melody->addComponent(aiComp);

	melody->addComponent(new AnimatedComponent());
	melody->addComponent(new CollidableComponent());
	melody->addComponent(new InteractableComponent());

	melody->persistent = true;
	LightComponent* comp = new LightComponent();
	comp->addLight(new Light(Vector2f(0, -128 + 8), Color(1, 1, 1, -.5), .5*Vector2f(128, 64)));
	melody->addComponent(comp);
	//GameState::battleManager = BattleManager(melody);
	//melody->addEffect(new Shadow());
	EffectComponent* ecomp = new EffectComponent();
	ecomp->addEffect(new Tag(std::string("Melody"), Vector2f(0, 32)));
	melody->addComponent(ecomp);
	//melody->addEffect(new Pulse());
	//melody->addEffect(new LightPath());
	//melody->addEffect(new FastParticleSystem(100000));

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
	Object* card1 = new Object(ObjectData{"", Vector2f(-512 + 64, -256 - 64), Vector2f(64, 64) , TextureType::T_CARD_GHOST});
	CollidableComponent* comp = new CollidableComponent();
	comp->setEnterTrigger(new TransitionAction());
	comp->setExitTrigger(new DebugAction("Exited Trigger"));
	card1->addComponent(comp);

	//melody->addEffect(new Light(Vector2f(0, 0), Color(0, .5, 0, 1)));
	
	Object * chest = new Object(ObjectData{ "", Vector2f(0, -256), Vector2f(128, 128), TextureType::TEXTURE_SLIME});
	InteractableComponent* icomp = new InteractableComponent();
	icomp->setInteraction(new QuoteAction(std::string("Quote Interaction")));
	//chest->addAI(new FollowAI(World::getInstance()->getWorldObject("Player")));
	chest->addComponent(icomp);
	LightComponent* lcomp = new LightComponent();
	lcomp->addLight(new Light(Vector2f(0, 0), Color(1,1,1,1), 4*Vector2f(256, 256)));
	lcomp->addLight(new Light(Vector2f(0, -64 + 8), Color(1, 1, 1, -.5), .5*Vector2f(256, 128)));
	chest->addComponent(lcomp);
	//chest->addEffect(new Tag(std::string("Slime"), Vector2f(0, 80)));

	/*
	chest->addEffect(new ParticleSystem<TexturedParticle>(10, 4,
		{	new DirectedVelocityComp(0,0),
			new SpeedComp(100,100),
			new RandColorComp(),
			new PosSpreadComp(50),
			new TextureComp(TextureType::T_MUSIC_NOTE),
		}));
	*/
	//chest->setEnterTrigger(new ToggleEffectAction(chest, true));
	//chest->setExitTrigger(new ToggleEffectAction(chest, false));
	//chest->activateEffects(false);

	//chest->addEffect(new FastParticleSystem(4096*4));

	Object * chest2 = new Object(ObjectData{ "nm", Vector2f(-256, 0), Vector2f(128, 128), TextureType::TEXTURE_SLIME });
	InteractableComponent* icomp2 = new InteractableComponent();
	icomp2->setInteraction(new GraphAction("res/script/test.txt"));
	chest2->addComponent(icomp2);


	Object* torch = new Object(ObjectData{"", Vector2f(128 - 64 * 4, 128 * 5), Vector2f(64, 64) , TextureType::T_CARD_4 });
	//torch->setAction(SpriteSheet::AnimationState::IDLE);
	//torch->addAI(new CircleAI(Vector2f(0, 0), 512+256, 1.0f));
	room->addObject(torch);


	
	//torch->addEffect(new Light(Vector2f(0, 0), Color(1,1,1,1), 4*Vector2f(128, 128)));
	//chest2->addEffect(new Tag(std::string("Horus?"), Vector2f(0, 80)));


	Object* card2 = new Object(ObjectData{"", Vector2f(-512 + 192, 256 + 64), Vector2f(64, 64) , TextureType::T_CARD_ACE});
	//card2->setInteraction(new ShopWindowAction(Res::get(CardType::UNLIMITED_WATERWORKS), true));



	Object* card3 = new Object(ObjectData{ "", Vector2f(-512 + 192 + 128, 256 + 64), Vector2f(64, 64) , TextureType::T_CARD_ACE});
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
	/*
	room->setTerrainMap(std::string("Clearing"));
	
	room->loadObjects(std::string("ObjectMaps/Clearing"));
	
	LivingObject * echo = new LivingObject(ObjectData{ "Echo", Vector2f(-920, -500), Vector2f(128, 128), TextureType::TEXTURE_MAVIS });
	echo->weight = Weight::GHOST;
	room->addObject(echo);
	
	*/
	room->addWorldObject(World::getInstance()->getWorldObject("Player"));
	return room;
}

Room* RoomFactory::createEastOfTown()
{
	Room * room = new Room();
	room->setTerrainMap(std::string("EastOfTown2.txt"));
	//room->loadObjects(std::string("Clearing"));
	
	return room;
}

void RoomFactory::AddTransitionObjects()
{

}
