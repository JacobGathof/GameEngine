#include "Room.h"
#include "CollidableObject.h"
#include "InteractableObject.h"
#include "CollisionUtil.h"

Room::Room()
{
	collisionObject = new CollidableObject(std::string("extra"), TextureType::TEXTURE_DEFAULT, Vector2f(0,0), Vector2f(1,1));
	init();
}


Room::~Room()
{
	if (collisionObject != 0) {
		delete collisionObject;
	}
	for (auto a : allRoomObjects) {
		delete a;
	}
}

void Room::update(float dt)
{
	for (int i = 0; i < simpleObjects.size(); i++) {
		bool b = simpleObjects[i]->update(dt);
		if (!b) {
			removeObject(simpleObjects[i--]);
		}
	}
	for (int i = 0; i < collidableObjects.size(); i++) {
		bool b = collidableObjects[i]->update(dt);
		if (!b) {
			removeCollidableObject(collidableObjects[i--]);
		}
	}
	for (int i = 0; i < interactableObjects.size(); i++) {
		bool b = interactableObjects[i]->update(dt);
		if (!b) {
			removeInteractableObject(interactableObjects[i--]);
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
	for (auto a : simpleObjects) {
		a->draw();
	}
	for (auto a : collidableObjects) {
		a->draw();
	}
	for (auto a : interactableObjects) {
		a->draw();
	}
	collisionObject->draw();
}

void Room::drawObjectsInverted()
{
	for (auto a : simpleObjects) {
		a->drawInverted();
	}
	for (auto a : collidableObjects) {
		a->drawInverted();
	}
	for (auto a : interactableObjects) {
		a->drawInverted();
	}
}

void Room::drawEffects()
{
	for (auto a : simpleObjects) {
		a->drawEffects();
	}
	for (auto a : collidableObjects) {
		a->drawEffects();
	}
	for (auto a : interactableObjects) {
		a->drawEffects();
	}
}

void Room::drawHitboxes()
{
	for (auto o : collidableObjects) {
		o->drawHitboxes();
	}
	for (auto o : interactableObjects) {
		o->drawHitboxes();
	}
	collisionObject->drawHitboxes();
}

void Room::drawLights()
{
	
}

void Room::checkCollisions()
{

	
	for (int i = 0; i < collidableObjects.size(); i++) {
		CollidableObject * current = collidableObjects.get(i);

		for (int k = i + 1; k < collidableObjects.size(); k++) {
			CollidableObject * other = collidableObjects.get(k);
			if (collision(current, other)) {
				return;
			}
		}
	}

	for (int i = 0; i < collidableObjects.size(); i++) {
		CollidableObject * current = collidableObjects.get(i);

		for (int k = 0; k < interactableObjects.size(); k++) {
			CollidableObject * other = interactableObjects.get(k);
			if (collision(current, other)) {
				return;
			}
		}
	}

	for (int i = 0; i < interactableObjects.size(); i++) {
		CollidableObject * current = interactableObjects.get(i);

		for (int k = i + 1; k < interactableObjects.size(); k++) {
			CollidableObject * other = interactableObjects.get(k);
			if (collision(current, other)) {
				return;
			}
		}
	}

	

		/*
		for (int k = i+1; (k < objects.size() && (current->pos[1] < objects[k]->pos[1] + objects[k]->scale[1])); k++) {
			Object * obj = objects.get(k);
			if (collision(current, obj)) {
				current->collide(obj);
				obj->collide(current);
			}

		}

	}

	*/
	
	
}

void Room::addObject(Object * obj)
{
	simpleObjects.add(obj);
	objectMap[obj->name] = obj;

	allRoomObjects.add(obj);
}

void Room::addObject(CollidableObject * obj)
{
	collidableObjects.add(obj);
	objectMap[obj->name]= obj;
	allRoomObjects.add(obj);
}

void Room::addObject(InteractableObject * obj)
{
	interactableObjects.add(obj);
	objectMap[obj->name] = obj;
	allRoomObjects.add(obj);
}

void Room::addWorldObject(InteractableObject * obj)
{
	interactableObjects.add(obj);
}

void Room::sortObjects()
{
	//std::sort(allRoomObjects.begin(), allRoomObjects.end(), [](Object* a, Object* b) { return (a->pos[1] < b->pos[1]); });
}

InteractableObject * Room::getNearestObject(Vector2f& pos)
{
	InteractableObject * nearest = 0;
	float nearestDist = -1;
	
	for (auto  obj : interactableObjects) {
		float dist = (pos - obj->pos).lengthSquared();
		if ((dist < nearestDist || nearestDist == -1) && (dist != 0)) {
			nearestDist = dist;
			nearest = obj;
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

void Room::addHitbox(Vector2f& pos, Vector2f& scale)
{
	Hitbox * hit = new RectHitbox(Rect(pos,scale), pos);
	collisionObject->addHitbox(hit);
}

bool Room::collision(CollidableObject * obj1, CollidableObject * obj2)
{
	for (int i = 0; i < obj1->numHitboxes(); i++) {
		Hitbox * one = obj1->getHitbox(i);
		for (int k = 0; k < obj2->numHitboxes(); k++) {
			Hitbox * two = obj2->getHitbox(k);
			
			if (one->collide(two)) {

				obj1->collide(obj2);
				obj2->collide(obj1);

				/*
				CollisionUtil::one = obj1;
				CollisionUtil::two = obj2;
				bool cont1 = obj1->collide(obj2, two);
				bool cont2 = obj2->collide(obj1, one);
				Weight weight1 = obj1->weight;
				Weight weight2 = obj2->weight;
				
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
				
				if (!(cont1 && cont2)) {
					return true;
				}
				*/
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


void Room::removeObject(Object * obj)
{
	for (int i = 0; i < simpleObjects.size(); i++) {
		Object * o = simpleObjects.get(i);
		if (obj == o) {
			simpleObjects.removeIndex(i);
			return;
		}
	}
}

void Room::removeCollidableObject(CollidableObject * obj)
{
	for (int i = 0; i < collidableObjects.size(); i++) {
		CollidableObject * o = collidableObjects.get(i);
		if (obj == o) {
			collidableObjects.removeIndex(i);
			return;
		}
	}
}

void Room::removeInteractableObject(InteractableObject * obj)
{
	for (int i = 0; i < interactableObjects.size(); i++) {
		InteractableObject * o = interactableObjects.get(i);
		if (obj == o) {
			interactableObjects.removeIndex(i);
			return;
		}
	}
}



List<InteractableObject*>& Room::getInteractableObjects()
{
	return interactableObjects;
}

List<CollidableObject*>& Room::getCollidableObjects()
{
	return collidableObjects;
}


void Room::init()
{
	textureMap.insert(std::pair<std::string, TextureType>(std::string("BRIDGEHORIZ"), TextureType::BRIDGEHORIZ));
	textureMap.insert(std::pair<std::string, TextureType>(std::string("LARGE_TREE"), TextureType::LARGE_TREE));
	textureMap.insert(std::pair<std::string, TextureType>(std::string("PINK_FLOWERS_2"), TextureType::PINK_FLOWERS_2));
	textureMap.insert(std::pair<std::string, TextureType>(std::string("BLUE_FLOWERS_2"), TextureType::BLUE_FLOWERS_2));
	textureMap.insert(std::pair<std::string, TextureType>(std::string("PINK_FLOWERS"), TextureType::PINK_FLOWERS));
	textureMap.insert(std::pair<std::string, TextureType>(std::string("SMALL_LEAF_SHRUB"), TextureType::SMALL_LEAF_SHRUB));
	textureMap.insert(std::pair<std::string, TextureType>(std::string("TALL_GRASS"), TextureType::TALL_GRASS));
	textureMap.insert(std::pair<std::string, TextureType>(std::string("ROCK"), TextureType::ROCK));
	textureMap.insert(std::pair<std::string, TextureType>(std::string("MUSHROOMS"), TextureType::MUSHROOMS));
	textureMap.insert(std::pair<std::string, TextureType>(std::string("LOG"), TextureType::LOG));
	textureMap.insert(std::pair<std::string, TextureType>(std::string("BLUE_FLOWERS"), TextureType::BLUE_FLOWERS));
	textureMap.insert(std::pair<std::string, TextureType>(std::string("ZH-WARDROBE"), TextureType::ZH_WARDROBE));
	textureMap.insert(std::pair<std::string, TextureType>(std::string("ZF-GILGAMESH"), TextureType::ZF_GILGAMESH));
	textureMap.insert(std::pair<std::string, TextureType>(std::string("ZI_ZMELODY_BOOK"), TextureType::ZI_ZMELODY_BOOK));
	textureMap.insert(std::pair<std::string, TextureType>(std::string("ZH-HORIZONTAL_TABLE"), TextureType::ZH_HORIZONTAL_TABLE));
	textureMap.insert(std::pair<std::string, TextureType>(std::string("ZH-NIGHT_WINDOW_LARGE"), TextureType::ZH_NIGHT_WINDOW_LARGE));
	textureMap.insert(std::pair<std::string, TextureType>(std::string("ZH-TOMATO_BASKET"), TextureType::ZH_TOMATO_BASKET));
	textureMap.insert(std::pair<std::string, TextureType>(std::string("ZH-WATER_GLASS"), TextureType::ZH_WATER_GLASS));
	textureMap.insert(std::pair<std::string, TextureType>(std::string("ZH-BREAD_BASKET"), TextureType::ZH_BREAD_BASKET));
	textureMap.insert(std::pair<std::string, TextureType>(std::string("ZH-CANDLE_POST"), TextureType::ZH_CANDLE_POST));

	//These are the new ones
	textureMap.insert(std::pair<std::string, TextureType>(std::string("main_tree_pink_3"), TextureType::MAIN_TREE_PINK_3));
	textureMap.insert(std::pair<std::string, TextureType>(std::string("flower"), TextureType::FLOWER));
	textureMap.insert(std::pair<std::string, TextureType>(std::string("flower_2"), TextureType::FLOWER_2));
	textureMap.insert(std::pair<std::string, TextureType>(std::string("flower_3"), TextureType::FLOWER_3));
	textureMap.insert(std::pair<std::string, TextureType>(std::string("fallen_Tree"), TextureType::FALLEN_TREE));
	textureMap.insert(std::pair<std::string, TextureType>(std::string("mushroom"), TextureType::MUSHROOM));
}


