#include "ShadowMap.h"
#include "World.h"
#include "Room.h"
#include "List.h"

ShadowMap::ShadowMap()
{

	model.init();
	model.bind();
	//vbo_pos =		model.addData(&pos[0], 0, 2, 0);
	vbo_intensity = model.addData(&itn[0], 0, 1, 1);
}


ShadowMap::~ShadowMap()
{
}

void ShadowMap::calculateShadowMap(Vector2f& pos)
{
	List<Object*> objects = World::getInstance()->getCurrentRoom()->getAllObjects();

	for (auto o : objects) {

		Hitbox* hb = o->hitboxes[0];
		
		//hb->getVertices();



	}



}

void ShadowMap::drawShadows()
{
}
