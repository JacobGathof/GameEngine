#include "AnimatedObject.h"


AnimatedObject::AnimatedObject(std::string& name, TextureType t, Vector2f& position, Vector2f& sc) : Object(name, t, position, sc)
{
	animationTimer.setTickLength(0.25f);
}

AnimatedObject::~AnimatedObject()
{
}

void AnimatedObject::setAction(SpriteSheet::AnimationState action)
{
	SpriteSheet * sh = Res::get(texture);
	SpriteSheet::AnimationStruct str = sh->animations[action];
	//TODO

}

void AnimatedObject::draw()
{
	ShaderProgram* p = Res::get(ShaderType::ANIMATED_SHADER);
	SpriteSheet* sh = Res::get(texture);
	Model * m = Res::get(ModelType::MODEL_SQUARE_CENTERED);

	p->bind();
	p->loadVector2f("translate", pos);
	p->loadVector2f("scale", scale);

	p->loadInteger("rows", sh->rows);
	p->loadInteger("columns", sh->columns);
	p->loadInteger("currentRow", animationRow);
	p->loadInteger("currentColumn", animationColumn);

	m->bind();
	sh->bind();

	m->draw();
}


bool AnimatedObject::update(float delta_time)
{
	timer.update(delta_time);
	animationTimer.update(delta_time);

	if (animationTimer.tick()) {
		animationColumn = (animationColumn + 1) % 3;
	}

	bool isFinished = Object::update(delta_time);
	if (aiQueue.size() == 0) {
		if (defaultAI != 0) {
			defaultAI->execute(this, delta_time);
		}
	}
	else {
		if (!aiQueue.get(0)->execute(this, delta_time)) {
			//If the current AI is done, remove it
			aiQueue.removeIndex(0);
		}
	}
	return isFinished;
}

bool AnimatedObject::collide(Object * o, Hitbox * h)
{
	return false;
}
