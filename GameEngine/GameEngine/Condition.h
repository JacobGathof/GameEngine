#pragma once
class Condition
{
public:
	Condition();

	virtual bool evaluate();
};



class IntCondition : public Condition
{
public:
	IntCondition(int arg1, int arg2);
	virtual bool evaluate();

	int arg1;
	int arg2;
};



class ChoiceCondition : public Condition
{
public:
	ChoiceCondition(int arg1, bool match = true);
	virtual bool evaluate();

	int arg1;
	bool match;

};