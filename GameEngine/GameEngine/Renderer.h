#pragma once
#include "ResourceManager.h"
#include "ParticleSystem.h"
#include "Water.h"

class Renderer
{
public:
	Renderer();
	~Renderer();

	static void draw();


private:

	static void drawWorld();
	static void drawEffects();
	static void drawUI();

	static void postProcess();

};

