#pragma once
#include "ResourceManager.h"
#include "ParticleSystem.h"
#include "Water.h"

class Renderer
{
public:
	Renderer();
	~Renderer();

	static Water water;

	static void draw();
};

