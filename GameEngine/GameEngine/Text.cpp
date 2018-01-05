#include "Text.h"





Text::Text(Vector2f & p, std::string & dat, Vector2f& s, Font * f)
{
	data = dat;
	length = dat.length() * 6;
	position = p;
	scale = s;
	font = f;

	int pos_size = length * 2;
	int tex_size = length * 2;
	int col_size = length * 3;
	float *pos = new float[pos_size];
	float *tex = new float[tex_size];
	float *col = new float[col_size];

	writeCharacterData(std::string(data), pos, tex, col);

	model.init();
	model.bind();
	vbo_pos = model.addData(pos, pos_size, 2, 0);
	vbo_tex = model.addData(tex, tex_size, 2, 1);
	vbo_col = model.addData(col, col_size, 3, 2);

	delete[] pos;
	delete[] tex;
	delete[] col;
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
	float posScale = scale[0] * (1.0f / scaleFactor);

	float centerDist = 0;
	Color def(0x000000);

	int len = string.length();
	for (int i = 0; i < len; i++) {
		char c = string[i];

		if (c == '\n') {
			xPointer = 0;
			yPointer -= 1.25f * font->getCharacter('I')->height;
			length-=6;
			continue;
		}
		if (c == '%') {
			def = Color(0x000000);
			length-=6;
			continue;
		}
		if (c == '#') {
			std::string c = string.substr(i+1, 6)+"00";
			long long val = std::strtoll(c.c_str(), 0, 16);
			def = Color(val);
			i += 6;
			length -= 6*7;
			continue;
		}

		Font::Char* ch = font->getCharacter(c);

		writeVertices(pos, ch, xPointer, yPointer, posScale, vertexPointer);
		writeTexCoords(tex, ch, scaleFactor, texPointer);
		writeColor(col, def, colorPointer);

		xPointer += 1.0f*ch->xadvance;
		//centerDist += ch->xadvance*posScale;

	}
}

void Text::writeVertices(float* pos, Font::Char* ch, float xPointer, float yPointer, float posScale, int& vertexPointer){

	pos[vertexPointer++] = position[0] + (xPointer + ch->xoffset) * posScale;
	pos[vertexPointer++] = position[1] + (yPointer + -ch->height - ch->yoffset) * posScale;

	pos[vertexPointer++] = position[0] + (xPointer + ch->width + ch->xoffset) * posScale;
	pos[vertexPointer++] = position[1] + (yPointer + -ch->height - ch->yoffset) * posScale;

	pos[vertexPointer++] = position[0] + (xPointer + ch->width + ch->xoffset) * posScale;
	pos[vertexPointer++] = position[1] + (yPointer + -ch->yoffset) * posScale;

	pos[vertexPointer++] = position[0] + (xPointer + ch->width + ch->xoffset) * posScale;
	pos[vertexPointer++] = position[1] + (yPointer + -ch->yoffset) * posScale;

	pos[vertexPointer++] = position[0] + (xPointer + ch->xoffset) * posScale;
	pos[vertexPointer++] = position[1] + (yPointer + -ch->yoffset) * posScale;

	pos[vertexPointer++] = position[0] + (xPointer + ch->xoffset) * posScale;
	pos[vertexPointer++] = position[1] + (yPointer + -ch->height - ch->yoffset) * posScale;
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
	int newLength = newdata.length() * 6;
	data = newdata;

	int pos_size = newLength * 2;
	int tex_size = newLength * 2;
	int col_size = newLength * 3;
	float* pos = new float[pos_size];
	float* tex = new float[tex_size];
	float* col = new float[col_size];

	length = newLength;
	writeCharacterData(std::string(newdata), pos, tex, col);
	bool resize = newLength > length;

	updateVAO(pos, pos_size, tex, tex_size, col, col_size, resize);

	delete[] pos;
	delete[] tex;
	delete[] col;
}

void Text::setFont(Font * f){
	font = f;
}

void Text::render()
{
	ShaderManager::get(ShaderType::TEXT_SHADER)->bind();
	font->bind();
	model.bind();
	glDrawArrays(GL_TRIANGLES, 0, length);
}


