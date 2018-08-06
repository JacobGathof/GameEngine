#pragma once
#include "Text.h"
#include "TextboxContent.h"

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