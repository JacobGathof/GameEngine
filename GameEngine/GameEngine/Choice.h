#pragma once
#include "Text.h"
#include "TextboxContent.h"
#include "List.h"
#include "Color.h"


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
