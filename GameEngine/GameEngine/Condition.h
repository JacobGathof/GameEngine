#pragma once
#include <string>

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

class TextBoxCondition : public Condition
{
public:
	TextBoxCondition(bool On);
	virtual bool evaluate();

	bool on;

};


class FlagCondition : public Condition
{
public:
	FlagCondition(std::string str, bool val);
	virtual bool evaluate();

	std::string str;
	bool val;

};



class InteractCondition : public Condition {
public:
	InteractCondition(std::string name);
	virtual bool evaluate();

	std::string name;

};