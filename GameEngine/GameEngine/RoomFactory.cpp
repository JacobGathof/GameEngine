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
#include "ForceComponent.h"

#include "StartScriptAction.h"


#include "RectHitbox.h"
#include "TextAction.h"
#include "Lamp.h"
#include "Sign.h"


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
	CollidableComponent * ccomp = new CollidableComponent();
	ccomp->weight = Weight::PLAYER;
	//ccomp->addHitbox(new CircleHitbox(128, Vector2f(0, 0)));
	melody->addComponent(ccomp);
	melody->addComponent(new InteractableComponent());

	melody->persistent = true;
	LightComponent* comp = new LightComponent();
	comp->addLight(new Light(Vector2f(0, -128 + 8), Color(1, 1, 1, -.5), .5*Vector2f(128, 64)));
	comp->addLight(new Light(Vector2f(0, 0), Color(1, 1, 1, 1), Vector2f(256, 256)));
	melody->addComponent(comp);
	//auto fcomp = new ForceComponent();
	//fcomp->addForce(new Force(Vector2f(100,0)));
	//melody->addComponent(fcomp);
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
	Hitbox * circ2 = new CircleHitbox(400, Vector2f(0, 0));
	//melody->addHitbox(circ);
	//melody->giveDeck(Res::get(DeckType::TEST));
	
	//Object* table = new Object(std::string(""), TextureType::ZH_WARDROBE, Vector2f(-512, 256), 4 * Vector2f(256, 64));
	Object* card1 = new Object(ObjectData{"", Vector2f(-512 + 64, -256 - 64), Vector2f(64, 64) , TextureType::T_CARD_GHOST});
	CollidableComponent* comp = new CollidableComponent();
	comp->setEnterTrigger(new TransitionAction());
	comp->setExitTrigger(new DebugAction("Exited Trigger"));
	card1->addComponent(comp);

	//melody->addEffect(new Light(Vector2f(0, 0), Color(0, .5, 0, 1)));
	
	Object * chest = new Object(ObjectData{ "slimew", Vector2f(0, -256), Vector2f(128, 128), TextureType::T_FIRE_SLIME});
	chest->addComponent(new AnimatedComponent());
	chest->getComponent<AnimatedComponent>()->setAction(SpriteSheet::AnimationState::IDLE);
	InteractableComponent* icomp = new InteractableComponent();
	icomp->setInteraction(new StartScriptAction(GraphType::TERNARY));
	//chest->addAI(new FollowAI(World::getInstance()->getWorldObject("Player")));
	chest->addComponent(icomp);
	LightComponent* lcomp = new LightComponent();
	//lcomp->addLight(new Light(Vector2f(0, 0), Color(1,1,1,1), 4*Vector2f(256, 256)));
	//lcomp->addLight(new Light(Vector2f(0, -64 + 8), Color(1, 1, 1, -.5), .5*Vector2f(256, 128)));
	chest->addComponent(lcomp);
	//chest->addEffect(new Tag(std::string("Slime"), Vector2f(0, 80)));
	EffectComponent* ecomp = new EffectComponent();
	
	ecomp->addEffect(new ParticleSystem<TexturedParticle>(10, 4,
		{	new DirectedVelocityComp(0,0),
			new SpeedComp(100,100),
			new RandColorComp(),
			new PosSpreadComp(50),
			new TextureComp(TextureType::T_MUSIC_NOTE),
		}));
	
	chest->addComponent(ecomp);


	CollidableComponent * ccomp = new CollidableComponent();
	ccomp->weight = Weight::PLAYER;
	chest->addComponent(ccomp);
	chest->addComponent(new ForceComponent());

	//chest->setEnterTrigger(new ToggleEffectAction(chest, true));
	//chest->setExitTrigger(new ToggleEffectAction(chest, false));
	//chest->activateEffects(false);

	//chest->addEffect(new FastParticleSystem(4096*4));

	Object * chest2 = new Object(ObjectData{ "slime_test", Vector2f(-256, 0), Vector2f(128, 128), TextureType::TEXTURE_SLIME });

	//CollidableComponent* ccomp2 = new CollidableComponent();
	//ccomp2->addHitbox(new RectHitbox(Rect(Vector2f(0, 0), Vector2f(128, 128)), Vector2f(0, 0)));
	//chest2->addComponent(ccomp2);
	InteractableComponent* icomp2 = new InteractableComponent();
	chest2->addComponent(icomp2);

	Object* torch = new Object(ObjectData{"", Vector2f(128 - 64 * 4, 128 * 5), Vector2f(64, 64) , TextureType::T_CARD_4 });
	//torch->setAction(SpriteSheet::AnimationState::IDLE);
	//torch->addAI(new CircleAI(Vector2f(0, 0), 512+256, 1.0f));
	room->addObject(torch);


	room->addObject(new Lamp(ObjectData{ "", Vector2f(256+256, 0), Vector2f(64, 64) , TextureType::T_CARD_4 }));
	
	//torch->addEffect(new Light(Vector2f(0, 0), Color(1,1,1,1), 4*Vector2f(128, 128)));
	//chest2->addEffect(new Tag(std::string("Horus?"), Vector2f(0, 80)));


	Object* card2 = new Object(ObjectData{"", Vector2f(-512 + 192, 256 + 64), Vector2f(64, 64) , TextureType::T_CARD_ACE});
	//card2->setInteraction(new ShopWindowAction(Res::get(CardType::UNLIMITED_WATERWORKS), true));



	Object* card3 = new Object(ObjectData{ "", Vector2f(-512 + 192 + 128, 256 + 64), Vector2f(64, 64) , TextureType::T_CARD_ACE});
	//card3->setInteraction(new ShopWindowAction(Res::get(CardType::DAWN), true));



	Object * sign = new Sign(ObjectData{ "sign", Vector2f(256, 0), Vector2f(128, 128), TextureType::T_SIGN_POST }, std::string("North Hyrule Village (3 miles)"));
	Object * sign2 = new Sign(ObjectData{ "sign", Vector2f(256+128, 0), Vector2f(128, 128), TextureType::T_SIGN_POST }, std::string("Why did the chicken cross the road?"));



	Object* stair = new Object(ObjectData{ "", Vector2f(256, 128), Vector2f(128, 128) , TextureType::TEXTURE_TEST_7 });
	stair->height = -100;
	//card3->setInteraction(new ShopWindowAction(Res::get(CardType::DAWN), true));


	room->addWorldObject(World::getInstance()->getWorldObject("Player"));
	//room->addObject(table);
	room->addObject(card1);
	room->addObject(card2);
	room->addObject(card3);
	room->addObject(chest);
	room->addObject(chest2);
	room->addObject(sign);
	room->addObject(sign2);
	room->addObject(stair);

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
