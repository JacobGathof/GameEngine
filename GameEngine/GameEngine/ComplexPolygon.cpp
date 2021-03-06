#include "ComplexPolygon.h"



ComplexPolygon::ComplexPolygon(std::initializer_list<Vector2f> vert)
{
	vertices.addAll(vert);

	for (int i = 1; i <= vertices.size(); i++) {
		Vector2f p1 = vertices.get(i % vertices.size());
		Vector2f p2 = vertices.get(i - 1);
		Vector2f vec((p1[0] - p2[0]), (p1[1] - p2[1]));
		Vector2f norm(vec[1], -vec[0]);
		normals.add(norm.normalize());
	}

	int size = vertices.size();
	float * f = new float[size * 2];

	int counter = 0;
	for (Vector2f v : vertices) {
		f[counter++] = v[0];
		f[counter++] = v[1];
	}

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 2 * size, f, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 2, GL_FLOAT, false, 0, 0);
	glEnableVertexAttribArray(0);

	delete[] f;
}

ComplexPolygon::ComplexPolygon()
{
}

ComplexPolygon::~ComplexPolygon()
{
	if (vboSet) {
		glDeleteBuffers(1, &vbo);
		glDeleteVertexArrays(1, &vao);
	}
}

void ComplexPolygon::draw()
{
	ShaderProgram* p = Res::get(ShaderType::RECTANGLE_SHADER);
	p->bind();
	p->loadVector2f("translate", pos);
	p->loadVector2f("scale", Vector2f(1,1));
	glBindVertexArray(vao);
	glDrawArrays(GL_LINE_LOOP, 0, vertices.size());
}

bool ComplexPolygon::contains(Vector2f & pt)
{
	return false;
}

List<Vector2f>& ComplexPolygon::getVertices()
{
	return vertices;
}

void ComplexPolygon::updatePos(Vector2f & p)
{
	if (p != pos) {
		for (Vector2f& vec : vertices) {
			vec += (p - pos);
		}
		pos = p;
	}
}
