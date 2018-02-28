#pragma once
#include "Text.h"
#include "Screen.h"
#include <queue>
#include "AbstractUIComponent.h"
#include "Timer.h"
#include "List.h"



class TextboxContent {
public:
	virtual void prepare() = 0;
	virtual void draw() = 0;

	virtual bool isDisplayingFullLength() = 0;
	virtual void displayFullLength() = 0;
	virtual void addLetter() = 0;
};


class PlainText : public TextboxContent {
public:
	PlainText(std::string& str);

	static void init();
	static void clean();

	virtual void prepare();
	virtual void draw();

	virtual bool isDisplayingFullLength();
	virtual void displayFullLength();
	virtual void addLetter();

private:
	static Text* text;
	std::string str;

};

class Choice : public TextboxContent {
public:
	Choice(List<std::string>& ch);
	~Choice();

	virtual void draw();
	virtual void prepare();

	virtual bool isDisplayingFullLength();
	virtual void displayFullLength();
	virtual void addLetter();

private:
	List<std::string>& choices;
	int choicePointer;
	int numChoices;
	Text* text1;
	Text* text2;
	Text* text3;
	Text* text4;
};


class Textbox : public AbstractUIComponent
{
public:
	Textbox();
	~Textbox();

	void draw();
	void update(float dt);
	void advanceText();
	void addTextToQueue(std::string& text);
	void addChoiceToQueue(List<std::string>& text);

	virtual void handleMouseEvents(Mouse& mouse);
	virtual void handleKeyEvents(Keyboard& keyboard);

	void show();
	void hide();

	bool isEmpty();
	bool hasNext();

private:

	std::queue<TextboxContent*> queue;
	Timer timer;

	bool visible = true;
	Vector2f textScale;
	Vector2f textStartPos;

	TextboxContent* current = 0;

};

