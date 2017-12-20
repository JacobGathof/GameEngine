#pragma once
#include <iostream>



class Color
{
private:
	float data[4];
public:

	Color();
	Color(float r, float g, float b, float a);
	Color(unsigned int hex);
	~Color();

	float& operator[](int i);
	void operator=(Color& c);

	Color& operator+=(Color& c);
	Color operator+(Color& c);

	Color& operator*=(Color& c);
	Color operator*(Color& c);

	float r();			
	float g();			
	float b();			
	float a();
	Color& r(float r);	
	Color& g(float g);	
	Color& b(float b);	
	Color& a(float a);

	friend std::ostream& operator<<(std::ostream &os, Color &c);
	static Color blend(Color c, Color c2, float f = 0.5f);

	static const Color Red, Orange, Yellow, Green, Blue, Purple, Black, White, Clear, HalfClear;
	static const Color LightRed, LightOrange, LightYellow, LightGreen, LightBlue, LightPurple;
	static const Color DarkRed, DarkOrange, DarkYellow, DarkGreen, DarkBlue, DarkPurple;
};


