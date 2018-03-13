#pragma once

class Timer
{
public:
	virtual void update(float dt);

	void setTimeMult(float f);
	void setTickLength(float f);
	bool tick();
	void pause();
	void unpause();
	bool isPaused();
	void setPauseOnTick(bool pot);
	void reset();
	float getTotalTime();
	float getCurrentTime();
	float getTickLength();

	Timer();
	~Timer();

protected:
	float totalTime = 0.0f;
	float currentTime = 0.0f;
	float timeMultiplier = 1.0f;

	float lastTick = 0.0f;
	float tickLength = 1.0f;

	bool tickActive = false;
	bool paused = false;
	bool pauseOnTick = false;
};

