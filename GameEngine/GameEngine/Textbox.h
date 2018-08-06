#pragma once
#include <queue>
#include "AbstractUIComponent.h"
#include "Timer.h"
#include "List.h"
#include "TextboxContent.h"

//#include "CenteredText.h"


#define TEXT_SPEED 0.05f








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

