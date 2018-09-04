#include "Room.h"
#include "CollisionUtil.h"
#include "CollidableComponent.h"
#include "InteractableComponent.h"
#include "LightComponent.h"
#include "EffectComponent.h"


Room::Room()
{
	init();
}


Room::~Room()
{
	for (auto a : allRoomObjects) {
		delete a;
	}
}

void Room::update(float dt)
{
	for (int i = 0; i < objects.size(); i++) {
		bool b = objects[i]->update(dt);
		if (!b) {
			eraseObject(objects[i]);
			removeObject(objects[i--]);
		}
	}
}

void Room::draw()
{
	drawTerrain();
	drawObjects();
	drawEffects();
	drawHitboxes();
}

void Room::drawTerrain()
{
	terrain.draw();
}

void Room::drawObjects() {
	for (auto a : objects) {
		a->draw();
	}
}

void Room::drawObjectsInverted()
{
	for (auto a : objects) {
		a->drawInverted();
	}
}

void Room::drawObjectsNegative()
{
	for (auto a : objects) {
		a->drawNegative();
	}
}

void Room::eraseProjection(Vector2f & center, float radius, Object* pass)
{
	for (auto a : objects) {
		if(a != pass)
			a->eraseProjection(center, radius);
	}
}

void Room::drawEffects()
{
	for (auto o : objects) {
		if (o->hasTrait<EffectComponent>()) {
			o->getComponent<EffectComponent>()->drawEffects();
		}
	}
}

void Room::drawHitboxes()
{
	for (auto o : objects) {
		if (o->hasTrait<CollidableComponent>()) {
			o->getComponent<CollidableComponent>()->drawHitboxes();
		}
	}
}

void Room::drawLights()
{
	for (auto a : objects) {
		if (a->hasTrait<LightComponent>()) {
			a->getComponent<LightComponent>()->drawLights();
		}
	
	}
}

void Room::checkCollisions()
{


	for (int i = 0; i < objects.size(); i++) {
		Object * current = objects.get(i);
		if (current->hasTrait<CollidableComponent>()) {
			for (int k = i + 1; k < objects.size(); k++) {
				Object * other = objects.get(k);
				if (other->hasTrait<CollidableComponent>()) {

					collision(current, other);

				}
			}
		}
	}
	
	
}

void Room::addObject(Object * obj)
{
	objects.add(obj);
	objectMap[obj->name] = obj;

	allRoomObjects.add(obj);
}

void Room::addWorldObject(Object * obj)
{
	objects.add(obj);
	objectMap[obj->name] = obj;
}

void Room::sortObjects()
{
	//std::sort(allRoomObjects.begin(), allRoomObjects.end(), [](Object* a, Object* b) { return (a->pos[1] < b->pos[1]); });
}

Object * Room::getNearestObject(Vector2f& pos)
{
	// TODO - This function will not return any object that the player is pixel-perfectly aligned with. i.e, the distance between them is exactly zero. 
	// In practice, this probably doesn't matter. But this is where the problem would be. 

	Object * nearest = 0;
	float nearestDist = -1;
	
	for (auto  obj : objects) {
		if (obj->hasTrait<InteractableComponent>()) {
			float dist = (pos - obj->pos).lengthSquared();
			if ((dist < nearestDist || nearestDist == -1) && (dist != 0)) {
				nearestDist = dist;
				nearest = obj;
			}
		}
	}
	return nearest;
}

Object * Room::getObject(std::string& name)
{
	return objectMap[name];
}

void Room::setTerrainMap(std::string& map)
{
	terrain.constructMap("TerrainMaps/" + map);
}


bool Room::collision(Object * obj1, Object * obj2)
{
	CollidableComponent* comp1 = obj1->getComponent<CollidableComponent>();
	CollidableComponent* comp2 = obj2->getComponent<CollidableComponent>();

	for (int i = 0; i < comp1->numHitboxes(); i++) {
		Hitbox * one = comp1->getHitbox(i);
		for (int k = 0; k < comp2->numHitboxes(); k++) {
			Hitbox * two = comp2->getHitbox(k);

			if (one->collide(two)) {

				comp1->trigger(obj1);
				comp2->trigger(obj2);
			
				
				CollisionUtil::one = obj1;
				CollisionUtil::two = obj2;
				Weight weight1 = comp1->weight;
				Weight weight2 = comp2->weight;
				
				if (weight1 == Weight::GHOST || weight2 == Weight::GHOST) {
					//Do Nothing
				}
				else if (weight1 > weight2) {
					CollisionUtil::unequalResolve(obj1, two, 5);
				}
				else if (weight2 > weight1) {
					CollisionUtil::unequalResolve(obj2, one, 5);
				}
				else {
					CollisionUtil::equalResolve(obj1, obj2, 5);
				}
				
			}
		}
	}

	return false;
	
}


void Room::loadObjects(std::string& filepath)
{
	std::string in = std::string("start");
	std::ifstream file;
	file.open(filepath, std::ios::in);
	if (file.is_open()) {
		while (std::getline(file, in)) {
			if (in == "end") {
				break;
			}
			
			List<std::string> values = FilesAndStrings::parseStrings(in, ' ');
			//Need to convert to floats
			TextureType t;
			try {
				t = textureMap.at(values.get(0));
			}
			catch (std::exception e) {
				std::cout << "couldn't load " << values.get(0) << std::endl;
				continue;
			}
			
			float tileWidth = 50;
			float tileHeight = 50;
			
			float mapWidthTiled = 1950;
			float mapHeightTiled = 1550;

			float xScale = 4 * FilesAndStrings::parseFloat(values.get(3));
			float yScale = 4 * FilesAndStrings::parseFloat(values.get(4));
			
			float xPos = 4.0f * (FilesAndStrings::parseFloat(values.get(1)) + (xScale / 8) - (mapWidthTiled / 2));

			float yPos = 4.0f * ((mapHeightTiled - FilesAndStrings::parseFloat(values.get(2))) + (yScale / 8) - (mapHeightTiled / 2));
			//std::cout << values.get(0) << "   " << xPos << "   " << yPos << std::endl;
			Object * o = new Object(values.get(0), t, Vector2f(xPos, yPos), Vector2f(xScale, yScale));
			o->isStatic = true;
			addObject(o);
			/*
			if (values.get(5) == std::string("Rect")) {
				Vector2f offset(FilesAndStrings::parseFloat(values.get(6)), FilesAndStrings::parseFloat(values.get(7)));
				Vector2f scale(FilesAndStrings::parseFloat(values.get(8)), FilesAndStrings::parseFloat(values.get(9)));
				Hitbox * hit = new RectHitbox(Rect(Vector2f(0, 0), scale), offset);
				//o->addHitbox(hit);
				//TODO: fix ^^^;
			}
			*/
			//objects.add(&o);
		}
	}
	else {
		std::cout << "Could not open Object File " << filepath << std::endl;
	}
}


void Room::eraseObject(Object * obj)
{
	allRoomObjects.remove(obj);
	delete obj;
}

void Room::removeObject(Object * obj)
{
	for (int i = 0; i < objects.size(); i++) {
		Object * o = objects.get(i);
		if (obj == o) {
			objects.removeIndex(i);
			return;
		}
	}
}


void Room::init()
{

	//These are the new ones
	textureMap.insert(std::pair<std::string, TextureType>(std::string("main_tree_pink_3"), TextureType::MAIN_TREE_PINK_3));
	textureMap.insert(std::pair<std::string, TextureType>(std::string("flower"), TextureType::FLOWER));
	textureMap.insert(std::pair<std::string, TextureType>(std::string("flower_2"), TextureType::FLOWER_2));
	textureMap.insert(std::pair<std::string, TextureType>(std::string("flower_3"), TextureType::FLOWER_3));
	textureMap.insert(std::pair<std::string, TextureType>(std::string("fallen_Tree"), TextureType::FALLEN_TREE));
	textureMap.insert(std::pair<std::string, TextureType>(std::string("mushroom"), TextureType::MUSHROOM));

}


