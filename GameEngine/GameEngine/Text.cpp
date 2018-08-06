#include "Text.h"
#include "ResourceManager.h"

float Text::POS_SCALE = 512.0f / 97.0f;

Text::Text(Vector2f & p, std::string & dat, Vector2f& s, Font * f)
{
	position = p;
	scale = s;
	font = f;
	offset = Vector2f(0, 0);
	if (font == 0) {
		font = Res::get(FontType::DEFAULT);
	}
	color = Color(0xffffffff);

	model.init();
	model.bind();
	vbo_pos = model.addData(0, 0, 3, 0);
	vbo_tex = model.addData(0, 0, 2, 1);
	vbo_col = model.addData(0, 0, 4, 2);

	setText(dat);
}

Text::~Text() {}

void Text::writeCharacterData(std::string& string, float * pos, float * tex, float* col)
{
	if (font == 0) 
		return;

	float maxHeight = 1.0f / POS_SCALE;

	float xPointer = 0;
	float yPointer = maxHeight;

	int vertexPointer = 0;
	int texPointer = 0;
	int colorPointer = 0;
	int effects = 0;

	float posScale = POS_SCALE;

	float centerDist = 0;
	Color def = Color::Clear;
	totalWidth = 0;

	int len = string.length();
	for (int i = 0; i < len; i++) {
		char c = string[i];

		if (c == '\n') {
			xPointer = 0;
			yPointer -= 1.20f * maxHeight;
			length--;
			continue;
		}
		if (c == ' ') {
			xPointer += font->getCharacter(' ')->xadvance;
			length--;
			continue;
		}

		if (c == '\a') {
			length -= 4;
			i = processEscapeCharacters(string, i, def);
			continue;
		}

		if (c == '\b') {
			length--;
			def = Color::Clear;
			continue;
		}

		if (c == 0x0e) {
			length--;
			effects = 1;
			continue;
		}

		if (c == 0x0f) {
			length--;
			effects = 0;
			continue;
		}


		Font::Char* ch = font->getCharacter(c);
		if (c == 0) {
			continue;
		}

		writeVertices(pos, ch, xPointer, yPointer, posScale, vertexPointer, effects);
		writeTexCoords(tex, ch, texPointer);
		writeColor(col, def, colorPointer);

		xPointer += 1.0f*(ch->xadvance);

		totalWidth += ch->xadvance;
	}
	totalWidth = scale[0]*xPointer*posScale;
}

void Text::writeVertices(float* pos, Font::Char* ch, float xPointer, float yPointer, float posScale, int& vertexPointer, int effects){

	pos[vertexPointer++] = (xPointer + ch->xoffset) * posScale;
	pos[vertexPointer++] = (yPointer - ch->height - ch->yoffset) * posScale;
	pos[vertexPointer++] = effects;

	pos[vertexPointer++] = (xPointer + ch->width + ch->xoffset) * posScale;
	pos[vertexPointer++] = (yPointer - ch->height - ch->yoffset) * posScale;
	pos[vertexPointer++] = effects;

	pos[vertexPointer++] = (xPointer + ch->width + ch->xoffset) * posScale;
	pos[vertexPointer++] = (yPointer + -ch->yoffset) * posScale;
	pos[vertexPointer++] = effects;

	pos[vertexPointer++] = (xPointer + ch->width + ch->xoffset) * posScale;
	pos[vertexPointer++] = (yPointer + -ch->yoffset) * posScale;
	pos[vertexPointer++] = effects;

	pos[vertexPointer++] = (xPointer + ch->xoffset) * posScale;
	pos[vertexPointer++] = (yPointer + -ch->yoffset) * posScale;
	pos[vertexPointer++] = effects;

	pos[vertexPointer++] = (xPointer + ch->xoffset) * posScale;
	pos[vertexPointer++] = (yPointer - ch->height - ch->yoffset) * posScale;
	pos[vertexPointer++] = effects;
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
		col[colorPointer++] = color[3];
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

int Text::processEscapeCharacters(std::string & data, int pos, Color & color)
{
	char c1 = data[pos + 1];
	char c2 = data[pos + 2];
	char c3 = data[pos + 3];
	int r = (c1 >= 'A') ? (c1 - 'A' + 10) : (c1 - '0');
	int g = (c2 >= 'A') ? (c2 - 'A' + 10) : (c2 - '0');
	int b = (c3 >= 'A') ? (c3 - 'A' + 10) : (c3 - '0');
	color = Color(r / 16.0f, g / 16.0f, b / 16.0f, 1);
	return pos + 3;

}

void Text::setText(std::string& newdata)
{
	int newLength = newdata.length();
	data = newdata;
	displayableLength = newLength;

	int pos_size = newLength * 3 * 6;
	int tex_size = newLength * 2 * 6;
	int col_size = newLength * 4 * 6;
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
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	ShaderProgram * sh = Res::get(worldRelative ? ShaderType::TEXT_WORLD_SHADER : ShaderType::TEXT_SHADER);
	sh->bind();
	font->bind();
	model.bind();
	sh->loadVector2f("text_translate", position+offset);
	sh->loadVector2f("text_scale", scale);
	sh->loadColor("text_color", color);
	glDrawArrays(GL_TRIANGLES, 0, displayableLength*6);

}


void Text::setColor(Color & col){
	color = col;
}

void Text::setAlpha(float a)
{
	color[3] = a;
}

void Text::setOffset(Vector2f & v)
{
	offset = v;
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

void Text::center()
{
	offset = Vector2f(-totalWidth/2,-scale[1]/2);
}

void Text::centerDisplayable()
{
	offset = Vector2f(-getDisplayableWidth() / 2, -scale[1] / 2);
}

void Text::setWorldRelative(bool b)
{
	worldRelative = b;
}

bool Text::isDisplayingFullLength()
{
	return displayableLength >= length;
}

void Text::displayFullLength()
{
	displayableLength = length;
}

Vector2f & Text::getScale()
{
	return scale;
}

float Text::getWidth()
{
	return totalWidth;
}

float Text::getDisplayableWidth()
{
	return TextUtils::getWidth(data, font, scale, displayableLength);
}


