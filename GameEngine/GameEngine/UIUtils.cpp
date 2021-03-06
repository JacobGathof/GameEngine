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
	glBlendFunc(GL_ONE, GL_ZERO);
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

void UIUtils::drawImage(Vector2f & pos, Vector2f & scale, TextureType tex, Vector2f & offset, Color& color)
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
	shader->loadColor("color", color);


	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	model->draw();
	glBlendFunc(GL_ONE, GL_ZERO);
}

void UIUtils::drawBorder(Vector2f & pos, Vector2f & scale, Color & color, int offset, int spacing)
{
	//drawRectangle(pos, scale, color);
	drawRectangle(pos + Vector2f(offset, 0), Vector2f(spacing, scale[1]), color);
	drawRectangle(pos + Vector2f(scale[0], 0) - Vector2f(offset + spacing, 0), Vector2f(spacing, scale[1]), color);

	drawRectangle(pos + Vector2f(0, offset), Vector2f(scale[0], spacing), color);
	drawRectangle(pos + Vector2f(0, scale[1]) - Vector2f(0, offset + spacing), Vector2f(scale[0], spacing), color);
}

void UIUtils::drawLine(Vector2f & start, Vector2f & end, Color & color, float width)
{
	glLineWidth(width);

	ShaderProgram* shader = Res::get(ShaderType::UI_LINE_SHADER);
	Model * model = Res::get(ModelType::MODEL_SQUARE);

	model->bind();
	shader->bind();

	shader->loadVector2f("translate", Vector2f(0,0));
	shader->loadVector2f("scale", Vector2f(1,1));
	shader->loadColor("color", color);
	shader->loadVector2f("points[0]", start);
	shader->loadVector2f("points[1]", end);

	glDrawArrays(GL_LINES, 0, 2);

	glLineWidth(1.0);
}


