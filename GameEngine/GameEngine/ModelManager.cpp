#include "ModelManager.h"

std::map<ModelType, Model*> ModelManager::models;

void ModelManager::init() {
	float d1_p[]{ 0,1,1,1,1,0,1,0,0,0,0,1 };
	float d1_t[]{ 0,0,1,0,1,1,1,1,0,1,0,0 };
	addModel(ModelType::MODEL_SQUARE, d1_p, 12, d1_t, 12);
}

void ModelManager::clean() {
	for (auto f : models) {
		delete f.second;
	}
}

Model * ModelManager::get(ModelType type)
{
	return models[type];
}

void ModelManager::addModel(ModelType mt, float* pos_data, int l1, float* uv_data, int l2) {
	Model * model = new Model();
	model->init();
	model->bind();
	model->addData(pos_data, l1, 2, 0);
	model->addData(uv_data, l2, 2, 1);
	models[mt] = model;
}
