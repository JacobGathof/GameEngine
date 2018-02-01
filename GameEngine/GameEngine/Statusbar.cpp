#include "Statusbar.h"



Statusbar::Statusbar()
{
}


Statusbar::~Statusbar()
{
}

void Statusbar::draw()
{
	ShaderProgram* shader = Res::get(ShaderType::TEXTBOX_SHADER);
	Model * model = Res::get(ModelType::MODEL_SQUARE);

	model->bind();
	shader->bind();
	shader->loadVector2f("translate", Screen::toScreenCoordsUI(Vector2f(600, 790)));
	shader->loadVector2f("scale", Screen::toScreenCoordsUI(Vector2f(190, -100)));
	shader->loadColor("color", Color(0xffdddd88));
	model->draw();

	shader->loadVector2f("translate", Screen::toScreenCoordsUI(Vector2f(602, 788)));
	shader->loadVector2f("scale", Screen::toScreenCoordsUI(Vector2f(186, -96)));
	shader->loadColor("color", Color(0x44448844));
	model->draw();

	shader->loadVector2f("translate", Screen::toScreenCoordsUI(Vector2f(604, 786)));
	shader->loadVector2f("scale", Screen::toScreenCoordsUI(Vector2f(182, -92)));
	shader->loadColor("color", Color(0xffdddd88));
	model->draw();
}

void Statusbar::update(float dt)
{
}
