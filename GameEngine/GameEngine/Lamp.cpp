#include "Lamp.h"
#include "CollidableComponent.h"
#include "InteractableComponent.h"
#include "LightComponent.h"
#include "AnimatedComponent.h"
#include "ToggleEffectAction.h"

#include "Light.h"
#include "RectHitbox.h"
#include "Rectangle.h"

Lamp::Lamp(ObjectData& data) : Object(data)
{
	auto cComp = new CollidableComponent();
	auto aComp = new AnimatedComponent();
	auto iComp = new InteractableComponent();
	auto lComp = new LightComponent();

	addComponent(cComp);
	addComponent(aComp);
	addComponent(lComp);
	addComponent(iComp);

	cComp->weight = Weight::LIGHT;
	cComp->addHitbox(new RectHitbox(Vector2f(64, 64), Vector2f(0,0)));
	aComp->setAction(SpriteSheet::AnimationState::IDLE);
	iComp->setInteraction(new ToggleEffectAction(this));
	lComp->addLight(new Light(Vector2f(0, 0), Color(1, 1, 1, 1), 4 * Vector2f(64, 64)));

}


Lamp::~Lamp()
{
}
