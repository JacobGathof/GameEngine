#include "Text.h"

#include "Window.h"


Text::Text(Vector2f & p, std::string & dat, Vector2f& s, Font * f)
{
	position = p;
	scale = s;
	font = f;
	color = Color(0x000000ff);

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

	float maxHeight = 97.0f/512;

	float xPointer = 0;
	float yPointer = maxHeight;

	int vertexPointer = 0;
	int texPointer = 0;
	int colorPointer = 0;

	float posScale = 1.0f / maxHeight;

	float centerDist = 0;
	Color def(0x000000);

	int len = string.length();
	for (int i = 0; i < len; i++) {
		char c = string[i];

		if (c == '\n') {
			xPointer = 0;
			yPointer -= 1.25f * maxHeight;
			length--;
			continue;
		}
		if (c == ' ') {
			xPointer += font->getCharacter(' ')->xadvance;
			length--;
			continue;
		}

		Font::Char* ch = font->getCharacter(c);
		if (c == 0) {
			continue;
		}

		writeVertices(pos, ch, xPointer, yPointer, posScale, vertexPointer);
		writeTexCoords(tex, ch, texPointer);
		writeColor(col, def, colorPointer);

		xPointer += 1.0f*(ch->xadvance);

	}
}

void Text::writeVertices(float* pos, Font::Char* ch, float xPointer, float yPointer, float posScale, int& vertexPointer){

	pos[vertexPointer++] = (xPointer + ch->xoffset) * posScale;
	pos[vertexPointer++] = (yPointer - ch->height - ch->yoffset) * posScale;

	pos[vertexPointer++] = (xPointer + ch->width + ch->xoffset) * posScale;
	pos[vertexPointer++] = (yPointer - ch->height - ch->yoffset) * posScale;

	pos[vertexPointer++] = (xPointer + ch->width + ch->xoffset) * posScale;
	pos[vertexPointer++] = (yPointer + -ch->yoffset) * posScale;

	pos[vertexPointer++] = (xPointer + ch->width + ch->xoffset) * posScale;
	pos[vertexPointer++] = (yPointer + -ch->yoffset) * posScale;

	pos[vertexPointer++] = (xPointer + ch->xoffset) * posScale;
	pos[vertexPointer++] = (yPointer + -ch->yoffset) * posScale;

	pos[vertexPointer++] = (xPointer + ch->xoffset) * posScale;
	pos[vertexPointer++] = (yPointer - ch->height - ch->yoffset) * posScale;
}

void Text::writeTexCoords(float* tex, Font::Char* ch, int& texPointer)
{
	tex[texPointer++] = (ch->x);
	tex[texPointer++] = (ch->y + ch->height);

	tex[texPointer++] = (ch->x + ch->width);
	tex[texPointer++] = (ch->y + ch->height);

	tex[texPointer++] = (ch->x + ch->width);
	tex[texPointer++] = (ch->y);

	tex[texPointer++] = (ch->x + ch->width);
	tex[texPointer++] = (ch->y);

	tex[texPointer++] = (ch->x);
	tex[texPointer++] = (ch->y);

	tex[texPointer++] = (ch->x);
	tex[texPointer++] = (ch->y + ch->height);
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
	//newdata = TextUtils::processString(newdata, font);
	int newLength = newdata.length();
	data = newdata;
	displayableLength = newLength;

	int pos_size = newLength * 2 * 6;
	int tex_size = newLength * 2 * 6;
	int col_size = newLength * 3 * 6;
	float* pos = new float[pos_size];
	float* tex = new float[tex_size];
	float* col = new float[col_size];

	int templ = length;
	length = newLength;
	writeCharacterData(newdata, pos, tex, col);
	bool resize = newLength > templ;

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

void Text::draw()
{
	ShaderProgram * sh = ShaderManager::get(ShaderType::TEXT_SHADER);
	sh->bind();
	font->bind();
	model.bind();
	sh->loadVector2f("text_translate", Screen::toScreenCoordsUI(position));
	sh->loadVector2f("text_scale", Screen::toScreenCoordsUI(scale));
	sh->loadColor("text_color", color);

	glDrawArrays(GL_TRIANGLES, 0, displayableLength*6);
}

void Text::setColor(Color & col){
	color = col;
}

void Text::setPosition(Vector2f & v)
{
	position = v;
}

void Text::setScale(Vector2f & v)
{
	scale = v;
}

void Text::reloadData()
{
}


