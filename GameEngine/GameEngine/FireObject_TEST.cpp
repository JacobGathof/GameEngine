#include "FireObject_TEST.h"

#include "ParticleSystem.h"

FireObject_TEST::FireObject_TEST(ObjectData& data) : InteractableObject(data)
{
}


FireObject_TEST::~FireObject_TEST()
{
}

void FireObject_TEST::onEnterTrigger()
{
	triggerSubject->addEffect(new ParticleSystem<LightParticle>(30, 30, {
		new RandomVelocityComp(),
		new SpeedComp(100,100),
		new ColorComp(Color::Red, Color::Yellow),
		new PosSpreadComp(0),
	}));
}
