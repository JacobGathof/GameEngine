#include "Shadow.h"
#include "ResourceManager.h"
#include "Object.h"

Shadow::Shadow() : Light(Vector2f(0,0), Color(-1,-1,-1,1), 2*Vector2f(64,32))
{
}


Shadow::~Shadow()
{
}

bool Shadow::update(float dt)
{
	return Light::update(dt);
}
