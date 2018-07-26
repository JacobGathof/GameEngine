#pragma once
#include "InteractableObject.h"

class FireObject_TEST : public InteractableObject
{
public:
	FireObject_TEST(ObjectData& data);
	~FireObject_TEST();

	virtual void onEnterTrigger();

};

