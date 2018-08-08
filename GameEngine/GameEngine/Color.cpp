#include "Color.h"



Color::Color() {
	data[0] = 1.0f;
	data[1] = 1.0f;
	data[2] = 1.0f;
	data[3] = 1.0f;
}

Color::Color(float r, float g, float b, float a) {
	data[0] = r;
	data[1] = g;
	data[2] = b;
	data[3] = a;
}

Color::Color(uint32_t hex) {
	data[0] = ((hex & 0xff000000) >> 24) / 255.0f;
	data[1] = ((hex & 0x00ff0000) >> 16) / 255.0f;
	data[2] = ((hex & 0x0000ff00) >> 8) / 255.0f;
	data[3] = ((hex & 0x000000ff) >> 0) / 255.0f;
}

Color::~Color()
{
}


float& Color::operator[](int i)
{
	return data[i];
}


void Color::operator=(Color & c)
{
	data[0] = c[0];
	data[1] = c[1];
	data[2] = c[2];
	data[3] = c[3];
}


Color& Color::operator+=(Color & c)
{
	data[0] += c[0];
	data[1] += c[1];
	data[2] += c[2];
	data[3] += c[3];
	return *this;
}


Color Color::operator+(Color & c)
{
	return Color(c[0] + data[0],
				c[1] + data[1],
				c[2] + data[2],
				c[3] + data[3]);
}

Color & Color::operator-=(Color & c)
{
	data[0] -= c[0];
	data[1] -= c[1];
	data[2] -= c[2];
	data[3] -= c[3];
	return *this;
}

Color Color::operator-(Color & c)
{
	return Color(data[0] - c[0],
				data[1] - c[1],
				data[2] - c[2],
				data[3] - c[3]);
}


Color Color::operator*(Color & c)
{
	return Color((c[0] * data[0]),
				 (c[1] * data[1]),
				 (c[2] * data[2]),
				 (c[3] * data[3]));
}

Color & Color::operator*=(float f)
{
	data[0] *= f;
	data[1] *= f;
	data[2] *= f;
	data[3] *= f;
	return *this;
}

Color Color::operator*(float f)
{
	return Color((f * data[0]),
				(f * data[1]),
				(f * data[2]),
				(f * data[3]));
}

Color & Color::operator/=(float f)
{
	data[0] /= f;
	data[1] /= f;
	data[2] /= f;
	data[3] /= f;
	return *this;
}

Color Color::operator/(float f)
{
	return Color((data[0]/f),
				(data[1]/f),
				(data[2]/f),
				(data[3]/f));
}

Color Color::operator^(float f)
{
	return Color(pow(data[0], f),
		pow(data[1], f),
		pow(data[2], f),
		pow(data[3], f));
}

Color Color::HSVtoRGB()
{
	/*
		vec4 K = vec4(1.0, 2.0 / 3.0, 1.0 / 3.0, 3.0);
		vec3 p = abs(fract(c.xxx + K.xyz) * 6.0 - K.www);
		return c.z * mix(K.xxx, clamp(p - K.xxx, 0.0, 1.0), c.y);
	*/

	float h = r;
	float s = g;
	float v = b;

	float chroma = v * s;
	float hp = h / 60;

	float x = chroma * (1 - abs(fmod(hp,2)-1));

	int hh = (int)hp;

	float rr = chroma * (hh % 5 == 0) + x * ((hh - 1) % 3 == 0);
	float gg = chroma * (((hh - 2) % 6) % 5 == 0) + x * (hh % 3 == 0);
	float bb = chroma * (((hh + 2) % 6) % 5 == 0) + x * ((hh - 2) % 3 == 0);

	float m = v - chroma;

	return Color(rr+m, gg+m, bb+m, a);
}





Color& Color::operator*=(Color & c)
{
	data[0] *= c[0];
	data[1] *= c[1];
	data[2] *= c[2];
	data[3] *= c[3];
	return *this;
}


/**
Blend two colors together in a specified ratio

@param c First color
@param c2 Second Color
@param f Weight given to blending (default .5)
@return the blended color
*/
Color Color::blend(Color c, Color c2, float f)
{
	return Color(c[0] * f + c2[0] * (1 - f),
		c[1] * f + c2[1] * (1 - f),
		c[2] * f + c2[2] * (1 - f),
		c[3] * f + c2[3] * (1 - f));
}

std::ostream& operator<<(std::ostream &os, Color &c) {
	return os << "<" << c[0] << "," << c[1] << "," << c[2] << "," << c[3] << ">";
}

Color Color::Red(0xff0000ff);
Color Color::Orange(0xff8800ff);
Color Color::Yellow(0xffff00ff);
Color Color::Green(0x00ff00ff);
Color Color::Blue(0x0000ffff);
Color Color::Purple(0xff00ffff);
Color Color::White(0xffffffff);
Color Color::Black(0x000000ff);
Color Color::Clear(0xffffff00);
Color Color::HalfClear(0xffffff88);

Color Color::DarkRed(0x880000ff);
Color Color::DarkOrange(0x884400ff);
Color Color::DarkYellow(0x888800ff);
Color Color::DarkGreen(0x008800ff);
Color Color::DarkBlue(0x000088ff);
Color Color::DarkPurple(0x880088ff);

Color Color::LightRed(0xff8888ff);
Color Color::LightOrange(0xffaa88ff);
Color Color::LightYellow(0xffff88ff);
Color Color::LightGreen(0x88ff88ff);
Color Color::LightBlue(0x8888ffff);
Color Color::LightPurple(0xff88ffff);

Color Color::LightGray(0xccccccff);
Color Color::Gray(0x888888ff);
Color Color::DarkGray(0x444444ff);

