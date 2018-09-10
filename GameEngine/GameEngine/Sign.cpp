#include "Sign.h"
#include "CollidableComponent.h"
#include "InteractableComponent.h"
#include "LightComponent.h"
#include "AnimatedComponent.h"
#include "ToggleEffectAction.h"


#include "RectHitbox.h"
#include "TextAction.h"


Sign::Sign(ObjectData & data, std::string & text) : Object(data)
{
	auto cComp = new CollidableComponent();
	auto iComp = new InteractableComponent();

	addComponent(cComp);
	addComponent(iComp);

	cComp->weight = Weight::GHOST;
	cComp->addHitbox(new RectHitbox(2*Vector2f(64, 64), Vector2f(0, 0)));
	TextboxContentData t;
	t.centered = true;
	t.text = text;
	t.instant = true;
	iComp->setInteraction(new TextAction(t));
}

Sign::~Sign()
{
}
