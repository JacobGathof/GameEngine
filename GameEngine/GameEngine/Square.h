#pragma once
#include "Shape.h"

class Square : public Shape
{
public:
	Square();
	~Square();

private:
	Vector2f center;

};

