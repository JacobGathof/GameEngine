#include "WorldManipulator.h"
#include "GameState.h"


Object* WorldManipulator::currentObject;
Light* WorldManipulator::currentEffect;
Vector2f WorldManipulator::pos1;
Vector2f WorldManipulator::pos2;

void WorldManipulator::process(Mouse & mouse, Keyboard & keyboard, float dt)
{
	return;
	World* world = World::getInstance();



	if (mouse.click()) {
		pos1 = Screen::toWorldCoords(mouse.pos());
		currentObject = new Object(std::string(), TextureType::TEXTURE_DEFAULT, pos1, Vector2f(0, 0));
		currentEffect = new Light(Vector2f(0, 0), Color(0,0,GameState::ui_blue,1), Vector2f(0, 0));

		currentObject->addEffect(currentEffect);
		world->addObject(currentObject);
	}

	if (mouse.down()) {
		pos2 = Screen::toWorldCoords(mouse.pos());
		float f = (pos2 - pos1).length();
		currentEffect->setScale(Vector2f(f,f));
	}

}
