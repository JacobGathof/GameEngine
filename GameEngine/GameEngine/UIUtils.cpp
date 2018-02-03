#include "UIUtils.h"



UIUtils::UIUtils()
{
}


UIUtils::~UIUtils()
{
}

void UIUtils::drawRectangle(Vector2f pos, Vector2f scale, Color color)
{
	ShaderProgram* shader = Res::get(ShaderType::UI_SOLID_SHADER);
	Model * model = Res::get(ModelType::MODEL_SQUARE);

	model->bind();
	shader->bind();
	shader->loadVector2f("translate", Screen::toScreenCoordsUI(pos));
	shader->loadVector2f("scale", Screen::toScreenCoordsUI(scale));
	shader->loadColor("color", color);
	model->draw();

}

void UIUtils::drawImage(Vector2f pos, Vector2f scale, TextureType tex)
{
	ShaderProgram* shader = Res::get(ShaderType::UI_IMAGE_SHADER);
	Model * model = Res::get(ModelType::MODEL_SQUARE);
	Texture * texture = Res::get(tex);

	model->bind();
	shader->bind();
	texture->bind();

	shader->loadVector2f("translate", Screen::toScreenCoordsUI(pos));
	shader->loadVector2f("scale", Screen::toScreenCoordsUI(scale));

	model->draw();
}
