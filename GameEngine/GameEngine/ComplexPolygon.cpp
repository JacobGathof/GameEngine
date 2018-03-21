#include "ComplexPolygon.h"



ComplexPolygon::ComplexPolygon(std::initializer_list<Vector2f> vert)
{
	vertices.addAll(vert);
	int size = vertices.size();
	float * f = new float[size*2];

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
	glDeleteBuffers(1, &vbo);
	glDeleteVertexArrays(1, &vao);
}

void ComplexPolygon::draw()
{
	ShaderProgram* p = Res::get(ShaderType::RECTANGLE_SHADER);
	p->bind();
	p->loadVector2f("translate", base);
	p->loadVector2f("scale", Vector2f(1,1));
	glBindVertexArray(vao);
	glDrawArrays(GL_LINE_LOOP, 0, vertices.size());
}

bool ComplexPolygon::contains(Vector2f & pt)
{
	return false;
}

List<Vector2f> ComplexPolygon::getVertices()
{
	List<Vector2f> ret;
	for (Vector2f vec : vertices) {
		ret.add(vec + base);
	}

	return ret;
}
