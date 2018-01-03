#pragma once
#include <string>
#include "Font.h"
#include "Vector2f.h"
#include "gl3w.h"
#include "Model.h"

#include "ShaderProgram.h"

class Text
{
public:
	Text(Vector2f& position, std::string& data, Vector2f& scale, Font* font);
	~Text();
	void setText(std::string& newdata);
	void setFont(Font* font);

	void render(ShaderProgram* shader);

private:
	unsigned int vao;
	unsigned int vbo_pos;
	unsigned int vbo_tex;
	Vector2f position;
	Vector2f scale;
	Font * font;
	Model model;

	std::string data;
	int length;

	void writeCharacterData(std::string& string, float * pos, float* tex);
	void updateVAO(float * pos, int plength, float * tex, int tlength);
};



