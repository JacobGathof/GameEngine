#pragma once
class Condition
{
public:
	Condition(int arg1, int arg2);
	~Condition();

	bool evaluate();

private:
	int arg1;
	int arg2;

};

