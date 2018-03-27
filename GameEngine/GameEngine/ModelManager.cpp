#include "ModelManager.h"


void ModelManager::init() {
	float d1_p[]{ 0,1,1,1,1,0,1,0,0,0,0,1 };
	float d1_t[]{ 0,0,1,0,1,1,1,1,0,1,0,0 };
	addModel(ModelType::MODEL_SQUARE, d1_p, 12, d1_t, 12);


	float d2_p[]{ -0.5f,0.5f,0.5f,0.5f,0.5f,-0.5f,0.5f,-0.5f,-0.5f,-0.5f,-0.5f,0.5f };
	float d2_t[]{ 0,0,1,0,1,1,1,1,0,1,0,0 };
	addModel(ModelType::MODEL_SQUARE_CENTERED, d2_p, 12, d2_t, 12);

}


void ModelManager::addModel(ModelType mt, float* pos_data, int l1, float* uv_data, int l2) {
	Model * model = new Model();
	model->init();
	model->bind();
	model->addData(pos_data, l1, 2, 0);
	model->addData(uv_data, l2, 2, 1);
	elements[mt] = model;
}
