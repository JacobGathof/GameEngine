#pragma once
#include "AbstractObjectComponent.h"
#include "Light.h"
#include "List.h"

class LightComponent : public AbstractObjectComponent
{
public:
	LightComponent();
	~LightComponent();

	static LightComponent comp;
	static LightComponent* getComponent();

	virtual void setParent(Object* obj);
	virtual bool update(float dt);

	void addLight(Light* l);
	void removeLight(Light* l);
	void drawLights();


protected:
	List<Light *> lights;

};

