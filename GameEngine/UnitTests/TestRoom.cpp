#include "stdafx.h"
#include "TestRoom.h"


TestRoom::TestRoom()
{
}


TestRoom::~TestRoom()
{
}

bool TestRoom::collideTest(Object * obj, Object * obj2)
{
	return collision(obj, obj2);
}
