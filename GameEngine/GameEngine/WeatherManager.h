#pragma once

#include "Color.h"
#include "Timer.h"

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


	static void setState(int i);



	static void init();
	static void clean();

	static int weatherState;



	static void drawAmbientLight();

};

