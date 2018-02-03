#include "StatsPage.h"



StatsPage::StatsPage()
{
	position = Vector2f(0, 0);
	timer.setTickLength(transitionTime);
	timer.setPauseOnTick(true);

	text = new Text(Vector2f(100, 100), std::string(""), Vector2f(128.0f, 128.0f), FontManager::get(FontType::DEFAULT));

	text->setPosition(startText);

	textUpdateTimer.setTickLength(0.1f);

}


StatsPage::~StatsPage(){
	delete text;
}

void StatsPage::draw()
{
	ShaderProgram* shader = Res::get(ShaderType::UI_SOLID_SHADER);
	Model * model = Res::get(ModelType::MODEL_SQUARE);

	model->bind();
	shader->bind();
	shader->loadVector2f("translate", Screen::toScreenCoordsUI(Vector2f(10, 790)));
	shader->loadVector2f("scale", Screen::toScreenCoordsUI(Vector2f(780, -100)));
	shader->loadColor("color", Color(0xffffff88));
	model->draw();

	shader->loadVector2f("translate", Screen::toScreenCoordsUI(Vector2f(12, 788)));
	shader->loadVector2f("scale", Screen::toScreenCoordsUI(Vector2f(776, -96)));
	shader->loadColor("color", Color(0x44448844));
	model->draw();

	shader->loadVector2f("translate", Screen::toScreenCoordsUI(Vector2f(14, 786)));
	shader->loadVector2f("scale", Screen::toScreenCoordsUI(Vector2f(772, -92)));
	shader->loadColor("color", Color(0xffffff88));
	model->draw();

	text->draw();
}

void StatsPage::update(float dt){
	timer.update(dt);
	position = Vector2f(800, 0) * timer.getCurrentTime() / transitionTime;
	//text.setPosition(Vector2f(800 * timer.getCurrentTime() / transitionTime,800));

	textUpdateTimer.update(dt);
	if (textUpdateTimer.tick()) {
		text->setText(std::string("Game FPS: ") + GameState::getGlobalDebug() + std::string(" \nTesting second line\n3rd\n4th"));
	}
}

void StatsPage::show(){
	timer.unpause();
}

void StatsPage::hide(){
	timer.unpause();
}
