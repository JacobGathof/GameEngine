#include "ShadowMap.h"
#include "World.h"
#include "Room.h"
#include "List.h"

#include <algorithm>

bool myfunction(ShadowPoint i, ShadowPoint j) { 
	return (atan2(i.v[1], i.v[0]) < atan2(j.v[1], j.v[0])); 
}

bool sorter(Vector2f i, Vector2f j) {
	return (atan2(i[1], i[0]) < atan2(j[1], j[0]));
}

ShadowMap::ShadowMap()
{
	model.init();
	model.bind();

	float* pp = {0};

	vbo_pos = model.addData(pp, 0 * 2, 2, 0);
	vbo_int = model.addData(pp, 0 * 1, 1, 1);
}


ShadowMap::~ShadowMap()
{
}

void ShadowMap::calculateShadowMap(Vector2f& pos)
{
	List<Object*> objects = World::getInstance()->getCurrentRoom()->getStaticObjects();

	points.clear();
	lineSegments.clear();


	lineSegments.add(Segment{ pos + Vector2f(800,800), pos + Vector2f(-800, 800) });
	lineSegments.add(Segment{ pos + Vector2f(-800,800), pos + Vector2f(-800, -800) });
	lineSegments.add(Segment{ pos + Vector2f(-800,-800), pos + Vector2f(800, -800) });
	lineSegments.add(Segment{ pos + Vector2f(800,-800), pos + Vector2f(800, 800) });

	for (auto o : objects) {

		Hitbox* hb = o->hitboxes[0];
		List<Vector2f> vertices = hb->getShape()->getVertices();
		for (int i = 0; i < vertices.size(); i++) {
			vertices[i] += o->pos;
		}

		if (vertices.size() < 2) continue;

		for(int i = 0; i < vertices.size()-1; i++) {
			lineSegments.add(Segment{ vertices[i], vertices[i+1] });
		}
		lineSegments.add(Segment{ vertices[vertices.size()-1], vertices[0]});

	}

	for (auto s : lineSegments) {
		
		testRay(s.start, pos);
		testRay(s.end, pos);

		testRay(s.start + Vector2f(0.001f,0), pos);
		testRay(s.start + Vector2f(-0.001f, 0), pos);
		testRay(s.end + Vector2f(0.001f, 0), pos);
		testRay(s.end + Vector2f(-0.001f, 0), pos);

		//testRay(s.start + Vector2f(0,0.001f), pos);
		//testRay(s.start + Vector2f(0,-0.001f), pos);
		//testRay(s.end + Vector2f(0,0.001f), pos);
		//testRay(s.end + Vector2f(0,-0.001f), pos);

	}


	//points.push_back(ShadowPoint{ min + pos,1 });
	//points.push_back(ShadowPoint{ pos, .5f });

	//points.push_back(ShadowPoint{ max + pos, 1 });
	//points.push_back(ShadowPoint{ pos, .5f });

	for (int i = 0; i < points.size(); i++) {
		points[i].v -= pos;
	}

	std::sort(points.begin(), points.end(), myfunction);

	for (int i = 0; i < points.size(); i++) {
		points[i].v += pos;
	}


	float max = -1;
	for (int i = 0; i < points.size(); i++) {
		max = (points[i].in > max) ? points[i].in : max;
	}

	for (int i = 0; i < points.size(); i++) {
		points[i].in /= 2*max;
	}


	points.insert(points.end()-1, points[0]);
	points.insert(points.begin(), ShadowPoint{ pos, 1.0f });



	float * p = new float[points.size()*2];
	float * in = new float[points.size()];

	int size = points.size();
	for (int i = 0; i < size; i++) {
		p[2 * i + 0] = points[i].v[0];
		p[2 * i + 1] = points[i].v[1];

		in[i] = points[i].in;
	}

	model.resizeData(vbo_pos, p, size * 2);
	model.resizeData(vbo_int, in, size);

	delete[] p;
	delete[] in;

}

void ShadowMap::drawShadows()
{
	model.bind();
	ShaderProgram* p = Res::get(ShaderType::SHADOW_SHADER);
	p->bind();
	p->loadVector2f("translate", Vector2f(0,0));
	p->loadVector2f("scale", Vector2f(1, 1));
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glLineWidth(1.0f);
	glDrawArrays(GL_TRIANGLE_FAN, 0, points.size());
	//glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

}

void ShadowMap::testRay(Vector2f point, Vector2f pos)
{
	float min = -1;
	Vector2f first = point;
	min = first.distanceTo(pos);
	Vector2f pt = first;

	for (auto ss : lineSegments) {
		Vector2f r_d = (first - pos);
		Vector2f r_p = pos;

		Vector2f s_p = ss.start;
		Vector2f s_d = ss.end - ss.start;

		float r_dx = r_d[0];
		float r_dy = r_d[1];
		float s_dx = s_d[0];
		float s_dy = s_d[1];

		float r_px = r_p[0];
		float r_py = r_p[1];
		float s_px = s_p[0];
		float s_py = s_p[1];

		float T2 = (r_dx*(s_py - r_py) + r_dy * (r_px - s_px)) / (s_dx*r_dy - s_dy * r_dx);
		float T1 = (s_px + s_dx * T2 - r_px) / r_dx;

		if (T2 >= 0 && T2 <= 1 && T1 > 0 && T1 < min) {
			min = T1;
			pt = Vector2f(r_px + r_dx * T1, r_py + r_dy * T1);
		}
	}

	points.push_back(ShadowPoint{ pt, 1.0f / (pt - pos).length() });


}
