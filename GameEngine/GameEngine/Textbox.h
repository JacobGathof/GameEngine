#pragma once
#include "Text.h"
#include <queue>
#include "AbstractUIComponent.h"
#include "Timer.h"
#include "List.h"



class TextboxContent {
public:
	virtual void prepare() = 0;
	virtual void finish() = 0;
	virtual void draw() = 0;

	virtual bool isDisplayingFullLength() = 0;
	virtual void displayFullLength() = 0;
	virtual void addLetter() = 0;

	virtual void handleKeyEvents(Keyboard& keyboard);
};


class PlainText : public TextboxContent {
public:
	PlainText(std::string& str);

	static void init();
	static void clean();

	virtual void prepare();
	virtual void draw();
	virtual void finish();

	virtual bool isDisplayingFullLength();
	virtual void displayFullLength();
	virtual void addLetter();

	virtual void handleKeyEvents(Keyboard& keyboard);

private:
	static Text* text;
	std::string str;

};

class Choice : public TextboxContent {
public:
	Choice(List<std::string>& ch);
	~Choice();

	static void init();
	static void clean();

	virtual void draw();
	virtual void prepare();
	virtual void finish();

	virtual bool isDisplayingFullLength();
	virtual void displayFullLength();
	virtual void addLetter();

	virtual void handleKeyEvents(Keyboard& keyboard);

private:
	List<std::string>& choices;
	int choicePointer;
	int numChoices;
	static Text* texts[4];
	static Color defaultColor;
	static Color selectedColor;
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

