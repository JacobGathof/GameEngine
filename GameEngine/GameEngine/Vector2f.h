#pragma once
#include <iostream>

class Vector2f
{
private:
	float data[2];

public:
	Vector2f();
	Vector2f(float v1, float v2);
	Vector2f(const Vector2f &v);
	Vector2f(float* v);

	float& operator[](int i);
	float operator[](int i) const;

	float dot(Vector2f &v);
	float distanceTo(Vector2f &v);
	float lengthSquared();
	float length();
	Vector2f reflect(Vector2f &n);
	Vector2f rotate(float angle);
	Vector2f normalize();
	Vector2f to(Vector2f &t);

	Vector2f operator+(const Vector2f &v) const;
	Vector2f operator-(const Vector2f &v) const;
	Vector2f operator*(const Vector2f &v) const;
	Vector2f operator/(const Vector2f &v) const;
	Vector2f operator+(float f) const;
	Vector2f operator-(float f) const;
	Vector2f operator*(float f) const;
	Vector2f operator/(float f) const;

	Vector2f& operator+=(const Vector2f &v);
	Vector2f& operator-=(const Vector2f &v);
	Vector2f& operator*=(const Vector2f &v);
	Vector2f& operator/=(const Vector2f &v);
	Vector2f& operator+=(float f);
	Vector2f& operator-=(float f);
	Vector2f& operator*=(float f);
	Vector2f& operator/=(float f);

	Vector2f& operator=(Vector2f &v);
	operator float*();

	friend std::ostream& operator<<(std::ostream &os, Vector2f &v);
	friend Vector2f operator*(float f, Vector2f& v);

	bool operator>(Vector2f& v);
	bool operator<(Vector2f& v);
	bool operator>=(Vector2f& v);
	bool operator<=(Vector2f& v);
	bool operator==(const Vector2f& v) const;
	bool equals(const Vector2f& v, float eps = 0) const;

	~Vector2f();
};


typedef Vector2f vec2;