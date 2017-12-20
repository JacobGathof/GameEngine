#include "Color.h"


/**
Create a default color <1,1,1,1>
*/
Color::Color() {
	data[0] = 1.0f;
	data[1] = 1.0f;
	data[2] = 1.0f;
	data[3] = 1.0f;
}

/**
Create a color with the specified rbga values <r,g,b,a>
*/
Color::Color(float r, float g, float b, float a) {
	data[0] = r;
	data[1] = g;
	data[2] = b;
	data[3] = a;
}

/**
Create a color from an unsigned integer. 
Ex: Color(0x00ff00ff) = Green
*/
Color::Color(unsigned int hex) {
	data[0] = ((hex & 0xff000000) >> 24) / 255.0f;
	data[1] = ((hex & 0x00ff0000) >> 16) / 255.0f;
	data[2] = ((hex & 0x0000ff00) >> 8) / 255.0f;
	data[3] = ((hex & 0x000000ff) >> 0) / 255.0f;
}

Color::~Color()
{
}

/**
Get/set data at a specified index. <0,1,2,3> -> <r,g,b,a>  

@param i The index to look up
@return data at the given index
*/
float& Color::operator[](int i)
{
	return data[i];
}

/**
Set a color equal to another color
*/
void Color::operator=(Color & c)
{
	data[0] = c[0];
	data[1] = c[1];
	data[2] = c[2];
	data[3] = c[3];
}

/**
Element-wise addition between two colors
*/
Color& Color::operator+=(Color & c)
{
	data[0] += c[0];
	data[1] += c[1];
	data[2] += c[2];
	data[3] += c[3];
	return *this;
}

/**
Element-wise addition between two colors
*/
Color Color::operator+(Color & c)
{
	return Color(c[0] + data[0],
				c[1] + data[1],
				c[2] + data[2],
				c[3] + data[3]);
}

/**
Element-wise addition between two colors and average the result
*/
Color Color::operator*(Color & c)
{
	return Color((c[0] + data[0])/2,
				 (c[1] + data[1])/2,
				 (c[2] + data[2])/2,
				 (c[3] + data[3])/2);
}

/**
Element-wise addition between two colors and average the result
*/
Color& Color::operator*=(Color & c)
{
	data[0] += c[0]; data[0] /= 2;
	data[1] += c[1]; data[1] /= 2;
	data[2] += c[2]; data[2] /= 2;
	data[3] += c[3]; data[3] /= 2;
	return *this;
}


float Color::r(){ return data[0]; }
float Color::g(){ return data[1]; }
float Color::b(){ return data[2]; }
float Color::a(){ return data[3]; }


Color& Color::r(float r){
	data[0] = r;
	return *this;	
}

Color& Color::g(float g){
	data[1] = g;
	return *this;
}

Color& Color::b(float b){
	data[2] = b;
	return *this;
}

Color& Color::a(float a){
	data[3] = a;
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


const Color Color::Red(0xff0000ff);
const Color Color::Orange(0xff8800ff);
const Color Color::Yellow(0xffff00ff);
const Color Color::Green(0x00ff00ff);
const Color Color::Blue(0x0000ffff);
const Color Color::Purple(0xff00ffff);
const Color Color::White(0xffffffff);
const Color Color::Black(0x000000ff);
const Color Color::Clear(0xffffff00);
const Color Color::HalfClear(0xffffff88);

const Color Color::DarkRed(0x880000ff);
const Color Color::DarkOrange(0x884400ff);
const Color Color::DarkYellow(0x888800ff);
const Color Color::DarkGreen(0x008800ff);
const Color Color::DarkBlue(0x000088ff);
const Color Color::DarkPurple(0x880088ff);

const Color Color::LightRed(0xff8888ff);
const Color Color::LightOrange(0xffaa88ff);
const Color Color::LightYellow(0xffff88ff);
const Color Color::LightGreen(0x88ff88ff);
const Color Color::LightBlue(0x8888ffff);
const Color Color::LightPurple(0xff88ffff);


