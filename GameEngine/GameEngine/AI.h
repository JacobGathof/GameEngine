#pragma once
#include <iostream>

class Object;
class Player;


class AI
{
public:
	virtual bool execute(Object * obj, float dt)				{ return false; };

};

