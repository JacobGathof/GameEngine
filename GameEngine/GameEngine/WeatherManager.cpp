#include "WeatherManager.h"
#include "Screen.h"

Color WeatherManager::ambientDay = Color::White;
Color WeatherManager::ambientNight = Color::DarkGray;
Color WeatherManager::currentLight;

float WeatherManager::light;
Timer WeatherManager::lightningTimer;

int WeatherManager::nextStrikeCounter = 5;

RainParticleSystem* WeatherManager::sys;

void WeatherManager::update(float dt)
{
	currentLight = Color::blend(ambientDay, ambientNight, (cos(lightningTimer.getTotalTime() / 5) + 1) / 2);
	currentLight = currentLight / 2;


	sys->update(dt);
	sys->position = Screen::offset;

	simulateLightning(dt);
}

void WeatherManager::simulateLightning(float dt)
{
	lightningTimer.update(dt);

	if (lightningTimer.tick()) {

		if (nextStrikeCounter == 0) {
			nextStrikeCounter = rand() % 7 + 2;
			light = ((float)(rand()) / RAND_MAX);
		}

		else {
			nextStrikeCounter--;
		}

	}

	light /= 1.025f;

	currentLight = Color::blend(ambientDay, ambientNight, (cos(lightningTimer.getTotalTime() / 5) + 1) / 2);
	currentLight = Color::blend(Color::White, currentLight, light);
	currentLight = currentLight / 2;

}

void WeatherManager::drawWeatherEffects()
{
	sys->draw();
}

void WeatherManager::init()
{
	lightningTimer.setTickLength(.5f);
	sys = new RainParticleSystem();
	sys->startColor = Color::Blue;
	sys->endColor = Color::Blue;
}

void WeatherManager::clean()
{
	delete sys;
}

