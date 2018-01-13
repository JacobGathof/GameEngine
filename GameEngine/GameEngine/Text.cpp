#include "Text.h"


#include "Window.h"


Text::Text(Vector2f & p, std::string & dat, Vector2f& s, Font * f)
{
	position = p;
	scale = s;
	font = f;

	model.init();
	model.bind();
	vbo_pos = model.addData(0, 0, 2, 0);
	vbo_tex = model.addData(0, 0, 2, 1);
	vbo_col = model.addData(0, 0, 3, 2);

	setText(dat);
}

Text::~Text() {}

void Text::writeCharacterData(std::string& string, float * pos, float * tex, float* col)
{

	if (font == 0) 
		return;

	float xPointer = 0;
	float yPointer = 0;

	int vertexPointer = 0;
	int texPointer = 0;
	int colorPointer = 0;

	float scaleFactor = 512.0f;
	float posScale = 1.0f;


	float centerDist = 0;
	Color def(0x000000);

	int len = string.length();
	for (int i = 0; i < len; i++) {
		char c = string[i];

		if (c == '\n') {
			xPointer = 0;
			yPointer -= 1.25f * font->getCharacter('I')->height;
			length--;
			continue;
		}
		if (c == ' ') {
			xPointer += font->getCharacter(' ')->xadvance - 8;
			length--;
			continue;
		}

		Font::Char* ch = font->getCharacter(c);
		if (c == 0) {
			continue;
		}

		writeVertices(pos, ch, xPointer, yPointer, posScale, vertexPointer);
		writeTexCoords(tex, ch, scaleFactor, texPointer);
		writeColor(col, def, colorPointer);

		int kerning = 0;

		xPointer += 1.0f*(ch->xadvance-8);

	}
}

void Text::writeVertices(float* pos, Font::Char* ch, float xPointer, float yPointer, float posScale, int& vertexPointer){

	pos[vertexPointer++] = (xPointer + ch->xoffset) * posScale;
	pos[vertexPointer++] = (yPointer + -ch->height - ch->yoffset) * posScale;

	pos[vertexPointer++] = (xPointer + ch->width + ch->xoffset) * posScale;
	pos[vertexPointer++] = (yPointer + -ch->height - ch->yoffset) * posScale;

	pos[vertexPointer++] = (xPointer + ch->width + ch->xoffset) * posScale;
	pos[vertexPointer++] = (yPointer + -ch->yoffset) * posScale;

	pos[vertexPointer++] = (xPointer + ch->width + ch->xoffset) * posScale;
	pos[vertexPointer++] = (yPointer + -ch->yoffset) * posScale;

	pos[vertexPointer++] = (xPointer + ch->xoffset) * posScale;
	pos[vertexPointer++] = (yPointer + -ch->yoffset) * posScale;

	pos[vertexPointer++] = (xPointer + ch->xoffset) * posScale;
	pos[vertexPointer++] = (yPointer + -ch->height - ch->yoffset) * posScale;
}

void Text::writeTexCoords(float* tex, Font::Char* ch, float scaleFactor, int& texPointer)
{
	tex[texPointer++] = (ch->x) / scaleFactor;
	tex[texPointer++] = (ch->y + ch->height) / scaleFactor;

	tex[texPointer++] = (ch->x + ch->width) / scaleFactor;
	tex[texPointer++] = (ch->y + ch->height) / scaleFactor;

	tex[texPointer++] = (ch->x + ch->width) / scaleFactor;
	tex[texPointer++] = (ch->y) / scaleFactor;

	tex[texPointer++] = (ch->x + ch->width) / scaleFactor;
	tex[texPointer++] = (ch->y) / scaleFactor;

	tex[texPointer++] = (ch->x) / scaleFactor;
	tex[texPointer++] = (ch->y) / scaleFactor;

	tex[texPointer++] = (ch->x) / scaleFactor;
	tex[texPointer++] = (ch->y + ch->height) / scaleFactor;
}

void Text::writeColor(float * col, Color& color, int& colorPointer)
{
	for (int i = 0; i < 6; i++) {
		col[colorPointer++] = color[0];
		col[colorPointer++] = color[1];
		col[colorPointer++] = color[2];
	}
}

void Text::updateVAO(float * pos, int plength, float * tex, int tlength, float* col, int clength, bool resize)
{
	model.bind();
	if (resize) {
		model.resizeData(vbo_pos, pos, plength);
		model.resizeData(vbo_tex, tex, tlength);
		model.resizeData(vbo_col, col, clength);
	}
	else {
		model.updateData(vbo_pos, pos, plength);
		model.updateData(vbo_tex, tex, tlength);
		model.updateData(vbo_col, col, clength);
	}
}

void Text::setText(std::string& newdata)
{
	newdata = TextUtils::processString(newdata, font);
	int newLength = newdata.length();
	data = newdata;
	displayableLength = newLength;

	int pos_size = newLength * 2 * 6;
	int tex_size = newLength * 2 * 6;
	int col_size = newLength * 3 * 6;
	float* pos = new float[pos_size];
	float* tex = new float[tex_size];
	float* col = new float[col_size];

	length = newLength;
	writeCharacterData(newdata, pos, tex, col);
	bool resize = newLength > length;

	updateVAO(pos, pos_size, tex, tex_size, col, col_size, resize);

	delete[] pos;
	delete[] tex;
	delete[] col;
}

void Text::setFont(Font * f){
	font = f;
}

void Text::addLetter()
{
	if (displayableLength < length) {
		displayableLength++;
	}
}

void Text::resetLength()
{
	displayableLength = 0;
}

void Text::render()
{
	ShaderProgram * sh = ShaderManager::get(ShaderType::TEXT_SHADER);
	sh->bind();
	font->bind();
	model.bind();
	sh->loadVector2f("text_translate", position);
	sh->loadVector2f("text_scale", scale);

	glDrawArrays(GL_TRIANGLES, 0, displayableLength*6);
}


