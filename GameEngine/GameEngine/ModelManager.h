#pragma once
#include "Model.h"
#include "ResourceType.h"
#include "IManager.h"


class ModelManager : public IManager<Model, ModelType>
{
public:
	virtual void init();

private:
	void addModel(ModelType model, float* pos_data, int l1, float* uv_data, int l2);

};

