#pragma once
class Object;

class Effect
{
public:
	Effect();
	virtual ~Effect();

	virtual void draw() = 0;
	virtual bool update(float dt) = 0;
	virtual void setActive(bool b);
	void setParent(Object* o);
protected:
	Object * parent;
	bool active = true;
};

