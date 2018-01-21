#pragma once
#include <map>
#include "Model.h"


enum class ModelType {
	MODEL_SQUARE,
	MODEL_SQUARE_CENTERED,
};


class ModelManager
{
public:

	static void init();
	static void clean();
	static Model* get(ModelType type);

private:

	static void addModel(ModelType model, float* pos_data, int l1, float* uv_data, int l2);
	static std::map<ModelType, Model*> models;

};

