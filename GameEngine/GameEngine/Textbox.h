#pragma once
#include "Text.h"
#include <queue>
#include "AbstractUIComponent.h"
#include "Timer.h"
#include "List.h"

#define TEXT_SPEED 0.05f

struct TextboxContentData {
	std::string text = "";
	std::string name = "???";
	TextureType portrait = TextureType::TEXTURE_DEFAULT;
	Vector2f offset = Vector2f(0,0);

	float time = -1;
	float textSpeed = 1;
	bool skippable = true;
	bool dialogue = false;
};


class TextboxContent {
public:
	virtual void prepare() = 0;
	virtual void finish() = 0;
	virtual void draw() = 0;

	virtual bool isDisplayingFullLength() = 0;
	virtual void displayFullLength() = 0;
	virtual void addLetter() = 0;

	virtual void handleKeyEvents(Keyboard& keyboard) {};
};




class CompositeText : public TextboxContent {
public:

	CompositeText(TextboxContentData& data);

	static void init();
	static void clean();

	virtual void prepare();
	virtual void draw();
	virtual void finish();

	static void resize();

	virtual bool isDisplayingFullLength();
	virtual void displayFullLength();
	virtual void addLetter();

private:
	static Text* text;
	static Text* speakerName;

	static Vector2f imagePosition;
	static Vector2f imageScale;
	static Vector2f textStartPosition;

	static Vector2f namePosition;
	static Vector2f nameScale;

	static float textEffectiveWidth;
	static bool currentDialogue;

	TextboxContentData data;

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
	static void resize();

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

	TextboxContent* createContentFromData(TextboxContentData& data);
	void addText(TextboxContentData& data);
	void addTextContentToQueue(TextboxContent* content);

	void addChoiceToQueue(List<std::string>& text);


	virtual void handleMouseEvents(Mouse& mouse);
	virtual void handleKeyEvents(Keyboard& keyboard);
	virtual void resize(int x, int y);

	void show();
	void hide();

	bool isEmpty();
	bool hasNext();

	static void setTextSpeed(float multiplier);
	static void initAdvanceTimer(float time);
	static void setSkippable(bool skippable);
	static void resetTextboxOptions();

	static Timer advanceTimer;
	static Timer timer;
	static bool skippable;

	static Vector2f textScale;
	static Vector2f contentPosition;
	static Vector2f contentScale;

private:

	void advanceText();

	std::queue<TextboxContent*> queue;

	bool visible = true;

	TextboxContent* current = 0;

};

