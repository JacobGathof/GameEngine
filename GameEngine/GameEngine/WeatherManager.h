#pragma once

#include "Color.h"
#include "Timer.h"
#include "RainParticleSystem.h"

class WeatherManager
{
public:

	static Color ambientDay;
	static Color ambientNight;
	static Color currentLight;

	static float light;
	static Timer lightningTimer;

	static int nextStrikeCounter;

	static void update(float dt);

	static void simulateLightning(float dt);


	static void drawWeatherEffects();


	static RainParticleSystem* sys;

	static void init();
	static void clean();

};

