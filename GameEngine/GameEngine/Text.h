#pragma once
#include <string>
#include "Font.h"
#include "Vector2f.h"
#include "gl3w.h"
#include "Model.h"

#include "ShaderManager.h"
#include "TextUtils.h"

class Text
{
public:
	Text(Vector2f& position, std::string& data, Vector2f& scale, Font* font);
	~Text();
	void setText(std::string& newdata);
	void setFont(Font* font);
	void addLetter();
	void resetLength();

	void draw();

	void setColor(Color& col);
	void setPosition(Vector2f& v);
	void setScale(Vector2f& v);
	void reloadData();
	void center();

private:
	unsigned int vao;
	unsigned int vbo_pos;
	unsigned int vbo_tex;
	unsigned int vbo_col;
	Vector2f scale;
	Font * font;
	Model model;
	Vector2f position;
	Color color;

	std::string data;
	int length;
	int displayableLength;
	float totalWidth;

	void writeCharacterData(std::string& string, float * pos, float* tex, float * col);
	void writeVertices(float* pos, Font::Char* ch, float xPointer, float yPointer, float posScale, int& vertexPointer);
	void writeTexCoords(float* tex, Font::Char* ch, int& texPointer);
	void writeColor(float * col, Color& color, int& colorPointer);
	void updateVAO(float * pos, int plength, float * tex, int tlength, float* col, int clength, bool resize);
};



