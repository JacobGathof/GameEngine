#include "Vector2f.h"



Vector2f::Vector2f() {
	data[0] = 0;
	data[1] = 0;
}

Vector2f::Vector2f(float v1, float v2) {
	data[0] = v1;
	data[1] = v2;
}

Vector2f::Vector2f(const Vector2f &v) {
	data[0] = v[0];
	data[1] = v[1];
}

Vector2f::Vector2f(float * v) {
	data[0] = v[0];
	data[1] = v[1];
}

float Vector2f::operator[](int i) const {
	return data[i];
}

float& Vector2f::operator[](int i) {
	return data[i];
}

Vector2f Vector2f::operator+(const Vector2f & v) const {
	return Vector2f(data[0] + v[0], data[1] + v[1]);
}

Vector2f Vector2f::operator-(const Vector2f & v) const {
	return Vector2f(data[0] - v[0], data[1] - v[1]);
}

Vector2f Vector2f::operator*(const Vector2f & v) const {
	return Vector2f(data[0] * v[0], data[1] * v[1]);
}

Vector2f Vector2f::operator/(const Vector2f & v) const {
	return Vector2f(data[0] / v[0], data[1] / v[1]);
}

Vector2f Vector2f::operator+(float f) const
{
	return Vector2f(data[0] + f, data[1] + f);
}

Vector2f Vector2f::operator-(float f) const
{
	return Vector2f(data[0] - f, data[1] - f);
}

Vector2f Vector2f::operator*(float f) const {
	return Vector2f(data[0] * f, data[1] * f);
}

Vector2f Vector2f::operator/(float f) const {
	return Vector2f(data[0] / f, data[1] / f);
}

Vector2f& Vector2f::operator+=(const Vector2f & v) {
	data[0] += v[0];
	data[1] += v[1];
	return *this;
}

Vector2f& Vector2f::operator-=(const Vector2f & v) {
	data[0] -= v[0];
	data[1] -= v[1];
	return *this;
}

Vector2f& Vector2f::operator*=(const Vector2f & v) {
	data[0] *= v[0];
	data[1] *= v[1];
	return *this;
}

Vector2f& Vector2f::operator/=(const Vector2f & v) {
	data[0] /= v[0];
	data[1] /= v[1];
	return *this;
}

Vector2f& Vector2f::operator+=(float f) {
	data[0] += f;
	data[1] += f;
	return *this;
}

Vector2f& Vector2f::operator-=(float f) {
	data[0] -= f;
	data[1] -= f;
	return *this;
}

Vector2f & Vector2f::operator*=(float f) {
	data[0] *= f;
	data[1] *= f;
	return *this;
}

Vector2f & Vector2f::operator/=(float f) {
	data[0] /= f;
	data[1] /= f;
	return *this;
}

Vector2f & Vector2f::operator=(Vector2f & v) {
	data[0] = v[0];
	data[1] = v[1];
	return *this;
}

Vector2f::operator float*()
{
	return data;
}

float Vector2f::dot(Vector2f & v)
{
	return data[0] * v[0] + data[1] * v[1];
}

float Vector2f::lengthSquared()
{
	return data[0] * data[0] + data[1] * data[1];
}

float Vector2f::length()
{
	return sqrt(lengthSquared());
}

Vector2f Vector2f::reflect(Vector2f &n)
{
	Vector2f c = *this;
	Vector2f m = n.normalize();
	Vector2f r = (2 * (c.dot(m))*n);
	return c - r;
}

Vector2f Vector2f::rotate(float angle)
{
	float c = cos(angle);
	float s = sin(angle);
	return Vector2f(data[0] * c + data[1] * -s, data[0] * s + data[1] * c);
}

Vector2f Vector2f::normalize()
{
	float len = length();
	if (len <= 0.0001f)
		return Vector2f(0, 0);
	Vector2f v(data[0] / len, data[1] / len);
	return v;

}

Vector2f Vector2f::to(Vector2f & t)
{
	return (t - (*this)).normalize();
}

bool Vector2f::operator>(Vector2f & v)
{
	return data[0] > v[0] && data[1] > v[1];
}

bool Vector2f::operator<(Vector2f & v)
{
	return data[0] < v[0] && data[1] < v[1];
}

bool Vector2f::operator>=(Vector2f & v)
{
	return data[0] >= v[0] && data[1] >= v[1];
}

bool Vector2f::operator<=(Vector2f & v)
{
	return data[0] <= v[0] && data[1] <= v[1];
}

bool Vector2f::operator==(const Vector2f & v) const
{
	return data[0] == v[0] && data[1] == v[1];
}

bool Vector2f::equals(const Vector2f & v, float eps) const
{
	return abs(data[0] - v[0]) < eps && abs(data[1] - v[1]) < eps;
}

std::ostream& operator<<(std::ostream &os, Vector2f &v) {
	return os << "<" << v[0] << "," << v[1] << ">";
}

Vector2f operator*(float f, Vector2f & v)
{
	return Vector2f(v[0] * f, v[1] * f);
}


Vector2f::~Vector2f() {}
