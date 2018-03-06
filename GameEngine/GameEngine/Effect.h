#pragma once
class Effect
{
public:
	Effect();
	virtual ~Effect();

	virtual void draw();
	virtual void update(float delta_time);
};

