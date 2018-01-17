#include "Vector3f.h"



Vector3f::Vector3f() {
	data[0] = 0;
	data[1] = 0;
	data[2] = 0;
}

Vector3f::Vector3f(float x, float y, float z) {
	data[0] = x;
	data[1] = y;
	data[2] = z;
}

Vector3f::Vector3f(const Vector3f &v) {
	data[0] = v[0];
	data[1] = v[1];
	data[2] = v[2];
}

float Vector3f::operator[](int i) const {
	return data[i];
}

float& Vector3f::operator[](int i)
{
	return data[i];
}

Vector3f Vector3f::operator+(Vector3f & v) {
	return Vector3f(data[0] + v[0], data[1] + v[1], data[2] + v[2]);
}

Vector3f Vector3f::operator-(Vector3f & v) {
	return Vector3f(data[0] - v[0], data[1] - v[1], data[2] - v[2]);
}

Vector3f Vector3f::operator*(Vector3f & v) {
	return Vector3f(data[0] * v[0], data[1] * v[1], data[2] * v[2]);
}

Vector3f Vector3f::operator*(float f)
{
	return Vector3f(data[0] * f, data[1] * f, data[2] * f);
}

Vector3f Vector3f::operator/(Vector3f & v) {
	return Vector3f(data[0] / v[0], data[1] / v[1], data[2] / v[2]);
}

Vector3f& Vector3f::operator+=(Vector3f & v)
{
	data[0] += v[0];
	data[1] += v[1];
	data[2] += v[2];
	return *this;
}

Vector3f& Vector3f::operator-=(Vector3f & v)
{
	data[0] -= v[0];
	data[1] -= v[1];
	data[2] -= v[2];
	return *this;
}

Vector3f& Vector3f::operator*=(Vector3f & v)
{
	data[0] *= v[0];
	data[1] *= v[1];
	data[2] *= v[2];
	return *this;
}

Vector3f& Vector3f::operator/=(Vector3f & v)
{
	data[0] /= v[0];
	data[1] /= v[1];
	data[2] /= v[2];
	return *this;
}

Vector3f Vector3f::operator-()
{
	return Vector3f(-data[0], -data[1], -data[2]);
}

Vector3f Vector3f::normalize()
{
	Vector3f v = *this;
	return v * (1.0f / sqrt(v.dot(v)));
}

Vector3f& Vector3f::operator=(Vector3f & v)
{
	data[0] = v[0];
	data[1] = v[1];
	data[2] = v[2];
	return *this;
}

Vector3f Vector3f::operator^(Vector3f & v)
{
	Vector3f dest;
	dest[0] = data[1] * v[2] - data[2] * v[1];
	dest[1] = data[2] * v[0] - data[0] * v[2];
	dest[2] = data[0] * v[1] - data[1] * v[0];
	return dest;
}

float Vector3f::dot(Vector3f & v)
{
	return data[0] * v[0] + data[1] * v[1] + data[2] * v[2];
}

float Vector3f::length()
{
	return sqrt(data[0] * data[0] + data[1] * data[1] + data[2] * data[2]);
}


std::ostream& operator<<(std::ostream &os, Vector3f &v) {
	return os << "<" << v[0] << "," << v[1] << "," << v[2] << ">";
}

Vector3f operator*(float f, Vector3f & v)
{
	return Vector3f(v[0] * f, v[1] * f, v[2] * f);
}


Vector3f::~Vector3f() {

}
