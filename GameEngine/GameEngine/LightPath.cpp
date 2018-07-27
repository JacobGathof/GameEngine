#include "LightPath.h"
#include "ResourceManager.h"
#include "Object.h"

LightPath::LightPath() : path(Vector2f(0,0), Vector2f(500,200), Vector2f(200,500), Vector2f(0,1000))
{
	model.init();

	float* positionData = new float[2 * 40 * 2];
	float* brightnessData = new float[2 * 40];

	for (int i = 0; i < 40; i++) {
		float t1 = (i) / 40.0f;
		Vector2f pos = path.positionAt(t1);
		Vector2f vel = path.velocityAt(t1).normalize();

		Vector2f pos2 = pos + 64 * Vector2f(-vel.y, vel.x);


		positionData[4 * i + 0] = pos[0];
		positionData[4 * i + 1] = pos[1];
		positionData[4 * i + 2] = pos2[0];
		positionData[4 * i + 3] = pos2[1];

		brightnessData[2 * i + 0] = 1;
		brightnessData[2 * i + 1] = 0;

	}


	model.addData(positionData, 2*40*2, 2, 0);
	model.addData(brightnessData, 2*40, 1, 1);


	delete[] positionData;
	delete[] brightnessData;
}


LightPath::~LightPath()
{
}

void LightPath::draw()
{

	model.bind();

	ShaderProgram* p = Res::get(ShaderType::TEST_SHADER_1);
	p->bind();
	p->loadVector2f("translate", Vector2f(0, 0));
	p->loadVector2f("scale", Vector2f(1, 1));

	glDrawArrays(GL_TRIANGLE_STRIP, 0, 80);


}

bool LightPath::update(float dt)
{
	return true;
}
