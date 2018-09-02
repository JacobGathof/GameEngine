#pragma once
#include "AbstractObjectComponent.h"
#include "Effect.h"
#include "List.h"

class EffectComponent : public AbstractObjectComponent
{
public:
	EffectComponent();
	~EffectComponent();

	static EffectComponent comp;
	static EffectComponent* getComponent();

	virtual void setParent(Object* obj);
	virtual bool update(float dt);

	void addEffect(Effect * eff);
	void removeEffect(Effect* eff);
	void activateEffects(bool b);
	void drawEffects();


protected:
	List<Effect *> effects;
};

