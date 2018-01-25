#include "StatsPage.h"



StatsPage::StatsPage() : text(Vector2f(400, 400), std::string(""), Vector2f(256.0f, 256.0f), FontManager::get(FontType::DEFAULT))
{
	position = Vector2f(0, 0);
	timer.setTickLength(transitionTime);
	timer.setPauseOnTick(true);

	text.setText(std::string("Scrolling Page"));
}


StatsPage::~StatsPage()
{
}

void StatsPage::draw()
{
	ShaderProgram* shader = Res::get(ShaderType::TEXTBOX_SHADER);
	Model * model = Res::get(ModelType::MODEL_SQUARE);

	model->bind();
	shader->bind();
	shader->loadVector2f("pos", position+Vector2f(10, 790));
	shader->loadVector2f("scale", Vector2f(780, -100));
	shader->loadColor("color", Color(0xffffff44));
	model->draw();

	shader->loadVector2f("pos", position+Vector2f(12, 788));
	shader->loadVector2f("scale", Vector2f(776, -96));
	shader->loadColor("color", Color(0x44448844));
	model->draw();

	shader->loadVector2f("pos", position+Vector2f(14, 786));
	shader->loadVector2f("scale", Vector2f(772, -92));
	shader->loadColor("color", Color(0xffffff44));
	model->draw();

	text.draw();
}

void StatsPage::update(float dt){
	timer.update(dt);
	position = Vector2f(800, 0) * timer.getCurrentTime() / transitionTime;
	text.setPosition(Vector2f(800 * timer.getCurrentTime() / transitionTime,800));
}

void StatsPage::show(){
	timer.unpause();
}

void StatsPage::hide(){
	timer.unpause();
}
