#pragma once

class Object;

class AbstractObjectComponent
{
public:
	virtual void setParent(Object* obj);
	Object* getParent();

	virtual bool update(float dt) = 0;
protected:
	Object * parent;

};

