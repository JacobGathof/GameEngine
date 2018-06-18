#pragma once
class Object;

class Effect
{
public:
	Effect();
	virtual ~Effect();

	virtual void draw() = 0;
	virtual void update(float dt) = 0;
	void setParent(Object* o);
protected:
	Object * parent;
};

