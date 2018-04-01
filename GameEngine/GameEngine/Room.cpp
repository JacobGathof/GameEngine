#include "Room.h"



Room::Room()
{
	collisionObject = new Object("extra", TextureType::TEXTURE_DEFAULT, Vector2f(0,0), Vector2f(1,1));
	init();
}


Room::~Room()
{
	for (Object * o : objects) {
		//delete o;
	}
	delete collisionObject;
	
	
}

void Room::update(float delta_time)
{
	for (auto o : objects) {
		o->update(delta_time);
	}
}

void Room::draw()
{
	terrain.draw(objectMap.at("Melody"));
	for (Object * o : objects) {
		o->draw();
	}
	collisionObject->draw();
}

void Room::checkCollisions()
{
	for (int i = 0; i < objects.size(); i++) {
		Object * current = objects.get(i);
		for (int k = i; k < objects.size(); k++) {
			Object * other = objects.get(k);
			if (collision(current, other)) {
				
			}
		}
		if (collision(current, collisionObject)) {
			current->collide(collisionObject, twoCarry);
		}

		/*
		for (int k = i+1; (k < objects.size() && (current->pos[1] < objects[k]->pos[1] + objects[k]->scale[1])); k++) {
			Object * obj = objects.get(k);
			if (collision(current, obj)) {
				current->collide(obj);
				obj->collide(current);
			}
			
		}
		*/
	}
	
	
}

void Room::addObject(Object * obj)
{
	objects.add(obj);
	objectMap.insert(std::pair<std::string, Object *>(obj->name, obj));
}

void Room::sort()
{
	for (int i = 1; i < objects.size(); i++) {
		if (objects[i]->pos[1] > objects[i - 1]->pos[1]) {
			sortPlace(objects[i], i);
		}
	}
}

Object * Room::getNearestObject(Vector2f pos)
{
	Object * nearest = nullptr;
	float nearestDist = 1000000;
	for (Object * obj : objects) {
		float dist = pos.distanceTo(obj->pos);
		if (dist < nearestDist && dist != 0) {
			nearestDist = dist;
			nearest = obj;
		}
	}
	return nearest;
}

Object * Room::getObject(std::string name)
{
	std::cout << objectMap.size() << std::endl;
	return objectMap.at(name);
}

void Room::setTerrainMap(std::string map)
{
	terrain.constructMap("TerrainMaps/" + map);
}

void Room::addHitbox(Vector2f pos, Vector2f scale)
{
	Hitbox * hit = new RectHitbox(Rect(pos,scale), pos);
	collisionObject->addHitbox(hit);
}

bool Room::collision(Object * obj1, Object * obj2)
{
	for (int i = 0; i < obj1->numHitboxes(); i++) {
		Hitbox * one = obj1->getHitbox(i);
		for (int k = 0; k < obj2->numHitboxes(); k++) {
			Hitbox * two = obj2->getHitbox(k);
			if (one->pos == two->pos) {
				continue;
			}
			if (one->collide(two)) {
				CollisionUtil::one = obj1;
				CollisionUtil::two = obj2;
				obj1->collide(obj2, two);
				obj2->collide(obj1, one);
			}
		}
	}
	return false;
}

void Room::sortPlace(Object * obj, int index)
{
	objects.removeIndex(index);
	for (int i = 0; i < objects.size(); i++) {
		if (obj->pos[1] > objects[i]->pos[1]) {
			objects.add(obj, i);
			return;
		}
	}
}

void Room::loadObjects(std::string filepath)
{
	std::string in = std::string("start");
	std::ifstream file;
	file.open(filepath, std::ios::in);
	if (file.is_open()) {
		while (std::getline(file, in)) {
			if (in == "end") {
				break;
			}
			
			List<std::string> values = parseValues(in);
			//Need to convert to floats
			
			TextureType t = textureMap.at(values.get(0));
			float tileWidth = 50;
			float tileHeight = 50;
			float xPos = .9756f * parseInt(values.get(1)) - (terrain.width * tileWidth);
			
			float yPos = (terrain.height * tileHeight) - 1.2121f * parseInt(values.get(2));

			float xScale = parseInt(values.get(3));
			float yScale = parseInt(values.get(4));
			std::cout << xScale << "   " << yScale << std::endl;
			Object * o = new Object(values.get(0), t, Vector2f(xPos, yPos), Vector2f(xScale, yScale));
			addObject(o);
			//objects.add(&o);
		}
	}
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
}

List<std::string> Room::parseValues(std::string line)
{
	List<std::string> values;
	std::string current;
	for (int i = 0; i < line.size(); i++) {
		char c = line[i];
		if (c == ' ') {
			values.add(current);
			current = std::string("");
		}
		else {
			current += c;
		}
	}
	values.add(current);

	return values;
}

int Room::parseInt(std::string line)
{
	std::stringstream stream(line);
	int val;
	stream >> val;
	return val;
}
