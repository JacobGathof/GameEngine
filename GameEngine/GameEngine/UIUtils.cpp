#include "UIUtils.h"
#include "ResourceManager.h"


UIUtils::UIUtils()
{
}


UIUtils::~UIUtils()
{
}

void UIUtils::drawRectangle(Vector2f& pos, Vector2f& scale, Color& color)
{
	//glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	ShaderProgram* shader = Res::get(ShaderType::UI_SOLID_SHADER);
	Model * model = Res::get(ModelType::MODEL_SQUARE);

	model->bind();
	shader->bind();
	shader->loadVector2f("translate", pos);
	shader->loadVector2f("scale", scale);
	shader->loadColor("color", color);
	model->draw();

}

void UIUtils::drawRectangleIcon(Vector2f& pos, Vector2f& scale, Color colors[3], float spacing)
{
	drawRectangle(pos, scale, colors[0]);
	drawRectangle(pos + spacing, scale - 2*spacing, colors[1]);
	drawRectangle(pos + 2*spacing, scale - 4*spacing, colors[2]);

}

void UIUtils::drawImage(Vector2f& pos, Vector2f& scale, TextureType tex)
{
	drawImage(pos, scale, tex, Vector2f(0, 0));
}

void UIUtils::drawImage(Vector2f & pos, Vector2f & scale, TextureType tex, Vector2f & offset)
{
	ShaderProgram* shader = Res::get(ShaderType::UI_IMAGE_SHADER);
	Model * model = Res::get(ModelType::MODEL_SQUARE);
	SpriteSheet * texture = Res::get(tex);

	model->bind();
	shader->bind();
	texture->bind();

	shader->loadVector2f("translate", pos);
	shader->loadVector2f("scale", scale);
	shader->loadVector2f("dim", Vector2f(texture->columns, texture->rows));
	shader->loadVector2f("offset", offset);


	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	model->draw();
	glBlendFunc(GL_ONE, GL_ZERO);
}
