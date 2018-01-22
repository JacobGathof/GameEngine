#include "StatsPage.h"



StatsPage::StatsPage()
{
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
	shader->loadVector2f("pos", Vector2f(10, 790));
	shader->loadVector2f("scale", Vector2f(780, -100));
	shader->loadColor("color", Color(0xffffffdd));
	model->draw();

	shader->loadVector2f("pos", Vector2f(12, 788));
	shader->loadVector2f("scale", Vector2f(776, -96));
	shader->loadColor("color", Color(0x444488dd));
	model->draw();

	shader->loadVector2f("pos", Vector2f(14, 786));
	shader->loadVector2f("scale", Vector2f(772, -92));
	shader->loadColor("color", Color(0xffffffdd));
	model->draw();
}
