#pragma once
#include <iostream>


class Color
{
private:
	float data[4];
public:

	Color();
	Color(float r, float g, float b, float a);
	Color(uint32_t hex);
	~Color();

	float& operator[](int i);
	void operator=(Color& c);

	Color& operator+=(Color& c);
	Color operator+(Color& c);
	Color& operator-=(Color& c);
	Color operator-(Color& c);
	Color& operator*=(Color& c);
	Color operator*(Color& c);

	Color& operator*=(float f);
	Color operator*(float f);
	Color& operator/=(float f);
	Color operator/(float f);


	friend std::ostream& operator<<(std::ostream &os, Color &c);
	static Color blend(Color c, Color c2, float f = 0.5f);

	static Color Red, Orange, Yellow, Green, Blue, Purple, Black, White, Clear, HalfClear;
	static Color LightRed, LightOrange, LightYellow, LightGreen, LightBlue, LightPurple;
	static Color DarkRed, DarkOrange, DarkYellow, DarkGreen, DarkBlue, DarkPurple;
	static Color LightGray, Gray, DarkGray;
};


