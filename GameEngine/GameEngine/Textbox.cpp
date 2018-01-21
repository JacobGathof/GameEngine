#include "Textbox.h"



Textbox::Textbox() : text(Vector2f(), std::string(""), Vector2f(), 0)
{
}


Textbox::~Textbox()
{
}

void Textbox::draw(){
	ShaderProgram* shader = Res::get(ShaderType::TEXTBOX_SHADER);
	Model * model = Res::get(ModelType::MODEL_SQUARE);

	model->bind();
	shader->bind();
	shader->loadVector2f("pos", Vector2f(10, 10));
	shader->loadVector2f("scale", Vector2f(780, 400));
	shader->loadColor("color", Color(0x22222288));
	
	model->draw();

}

void Textbox::advanceText()
{
	std::string newText = textQueue.front();
	textQueue.pop();
	prepareText(newText);

	text.setText(newText);
}

void Textbox::addTextToQueue(std::string text){
	textQueue.push(text);
}

void Textbox::prepareText(std::string& nextText)
{
	nextText.append("*@*");
}
