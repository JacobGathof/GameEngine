#include "AnimatedObject.h"


AnimatedObject::AnimatedObject(std::string& name, TextureType t, Vector2f& position, Vector2f& sc) : CollidableObject(name, t, position, sc)
{
	animationTimer.setTickLength(0.25f);
}

AnimatedObject::~AnimatedObject()
{
}

void AnimatedObject::setAction(SpriteSheet::AnimationState action)
{
	if (action != animationState) {
		animationState = action;
		SpriteSheet * sh = Res::get(texture);
		SpriteSheet::AnimationStruct str = sh->animations[action];
		animationRow = str.row;
		animationLoop = str.loop;
		animationColumn = 0;
		animationCurrentColumns = str.numColumns;

		animationTimer.setTickLength(0.25f * str.animSpeed);
		//TODO speed
	}

}

void AnimatedObject::draw()
{
	ShaderProgram* p = Res::get(ShaderType::ANIMATED_SHADER);
	SpriteSheet* sh = Res::get(texture);
	Model * m = Res::get(ModelType::MODEL_SQUARE_CENTERED);

	m->bind();
	sh->bind();

	p->bind();
	p->loadVector2f("translate", pos);
	p->loadVector2f("scale", scale);

	p->loadInteger("rows", sh->rows);
	p->loadInteger("columns", sh->columns);
	p->loadInteger("currentRow", animationRow);
	p->loadInteger("currentColumn", animationColumn);
	
	p->loadInteger("selected", selected);
	p->loadFloat("rotation", rotation);

	m->draw();
}


bool AnimatedObject::update(float delta_time)
{
	timer.update(delta_time);
	animationTimer.update(delta_time);

	if (animationTimer.tick()) {

		animationColumn = (animationColumn + 1) % animationCurrentColumns;
		if (animationColumn == 0 && !(animationLoop--)) {
			setAction(SpriteSheet::AnimationState::IDLE);
		}
	}

	return CollidableObject::update(delta_time);
}

