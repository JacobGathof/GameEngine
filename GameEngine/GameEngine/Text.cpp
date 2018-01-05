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
	float scaleFactor = 512.0f;
	float posScale = scale[0] * (1.0f / scaleFactor);

	float centerDist = 0;
	Color def(0x000000);
	int counter = 0;

	int length = string.length();
	for (int i = 0; i < length; i++) {
		char c = string[i];

		if (c == '\n') {
			xPointer = 0;
			yPointer -= 1.25f * font->getCharacter('I')->height;
			continue;
		}
		if (c == '%') {
			def = Color(0x000000);
			continue;
		}
		if (c == '#') {
			std::string c = string.substr(i+1, 6)+"00";
			long long val = std::strtoll(c.c_str(), 0, 16);
			std::cout << c << ":" << val << std::endl;
			def = Color(val);
			i += 6;
			continue;
		}

		Font::Char* ch = font->getCharacter(c);

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

		xPointer += 1.0f*ch->xadvance;
		//centerDist += ch->xadvance*posScale;

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

		writeColor(col, def);


		for (int i = 0; i < 6; i++) {
			col[counter++] = def[0];
			col[counter++] = def[1];
			col[counter++] = def[2];
		}

	}
}

void Text::writeVertices(float * pos)
{
}

void Text::writeTexCoords(float * tex)
{
}

void Text::writeColor(float * col, Color& color)
{
}

void Text::updateVAO(float * pos, int plength, float * tex, int tlength, float* col, int clength)
{
	model.bind();
	model.updateData(vbo_pos, pos, plength);
	model.updateData(vbo_tex, tex, tlength);
	model.updateData(vbo_col, col, clength);

}

void Text::setText(std::string& newdata)
{
	length = newdata.length() * 6;
	data = newdata;

	int pos_size = length * 2;
	int tex_size = length * 2;
	int col_size = length * 3;
	float* pos = new float[pos_size];
	float* tex = new float[tex_size];
	float* col = new float[col_size];

	writeCharacterData(std::string(newdata), pos, tex, col);

	updateVAO(pos, pos_size, tex, tex_size, col, col_size);

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


