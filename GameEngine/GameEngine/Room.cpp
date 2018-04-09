#include "Room.h"
#include "Object.h"
#include "CollisionUtil.h"

Room::Room()
{
	collisionObject = new Object(std::string("extra"), TextureType::TEXTURE_DEFAULT, Vector2f(0,0), Vector2f(1,1));
	init();
}


Room::~Room()
{
	for (Object * o : objects) {
		delete o;
	}
	for (Object * o : staticObjects) {
		delete o;
	}
	delete collisionObject;
	
	
}

void Room::update(float delta_time)
{
	for (auto o : objects) {
		o->update(delta_time);
	}

	for (auto o : staticObjects) {
		o->update(delta_time);
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
	terrain.draw(objectMap.at("Melody"));
}

void Room::drawObjects()
{
	for (Object * o : objects) {
		o->draw();
	}
	for (Object * o : staticObjects) {
		o->draw();
	}
	collisionObject->draw();
}

void Room::drawEffects()
{
	for (Object * o : objects) {
		o->drawEffects();
	}
}

void Room::drawHitboxes()
{
	for (Object * o : objects) {
		o->drawHitboxes();
	}
	for (Object *  o : staticObjects) {
		o->drawHitboxes();
	}
	collisionObject->drawHitboxes();
}

void Room::drawLights()
{
	for (int i = 0; i < 5; i++) {
		ShaderProgram* p = Res::get(ShaderType::LIGHT_SHADER);
		p->bind();
		p->loadVector2f("translate", Vector2f(0,1024*i));
		p->loadVector2f("scale", Vector2f(512, 512));
		p->loadColor("color", Color::Orange);
		Model * m = Res::get(ModelType::MODEL_SQUARE_CENTERED);
		m->bind();

		m->draw();
	}
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

		for (int k = 0; k < staticObjects.size(); k++) {
			Object * other = staticObjects.get(k);
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
	if (obj->isStatic) {
		staticObjects.add(obj);
	}
	else {
		objects.add(obj);
	}
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

Object * Room::getNearestObject(Vector2f& pos)
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

Object * Room::getObject(std::string& name)
{
	return objectMap.at(name);
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

bool Room::collision(Object * obj1, Object * obj2)
{
	for (int i = 0; i < obj1->numHitboxes(); i++) {
		Hitbox * one = obj1->getHitbox(i);
		for (int k = 0; k < obj2->numHitboxes(); k++) {
			Hitbox * two = obj2->getHitbox(k);
			
			if (one->getPos() == two->getPos()) {
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
			
			TextureType t = textureMap.at(values.get(0));
			float tileWidth = 50;
			float tileHeight = 50;
			float xPos = .9756f * FilesAndStrings::parseFloat(values.get(1)) - (terrain.width * tileWidth);
			
			float yPos = (terrain.height * tileHeight) - 1.2121f * FilesAndStrings::parseFloat(values.get(2));

			float xScale = FilesAndStrings::parseFloat(values.get(3));
			float yScale = FilesAndStrings::parseFloat(values.get(4));
			Object * o = new Object(values.get(0), t, Vector2f(xPos, yPos), Vector2f(xScale, yScale));
			o->isStatic = true;
			addObject(o);
			if (values.get(5) == std::string("Rect")) {
				Vector2f offset(FilesAndStrings::parseFloat(values.get(6)), FilesAndStrings::parseFloat(values.get(7)));
				Vector2f scale(FilesAndStrings::parseFloat(values.get(8)), FilesAndStrings::parseFloat(values.get(9)));
				Hitbox * hit = new RectHitbox(Rect(Vector2f(0, 0), scale), offset);
				o->addHitbox(hit);
			}
			//objects.add(&o);
		}
	}
}

List<Object*>& Room::getAllObjects()
{
	return objects;
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
}

