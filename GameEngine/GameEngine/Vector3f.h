#pragma once
#include <iostream>

class Vector3f
{
private:
	float data[3];

public:
	Vector3f();
	Vector3f(float x, float y, float z);
	Vector3f(const Vector3f &v);

	float operator[](int i) const;
	float& operator[](int i);

	Vector3f operator+(Vector3f &v);
	Vector3f operator-(Vector3f &v);
	Vector3f operator*(Vector3f &v);
	Vector3f operator*(float f);
	Vector3f operator/(Vector3f &v);

	Vector3f& operator+=(Vector3f &v);
	Vector3f& operator-=(Vector3f &v);
	Vector3f& operator*=(Vector3f &v);
	Vector3f& operator/=(Vector3f &v);

	Vector3f operator-();
	Vector3f normalize();
	Vector3f& operator=(Vector3f &v);
	Vector3f operator^(Vector3f &v);

	float dot(Vector3f &v);
	float length();
	friend std::ostream& operator<<(std::ostream &os, Vector3f &v);

	friend Vector3f operator*(float f, Vector3f &v);

	~Vector3f();
};

typedef Vector3f vec3;