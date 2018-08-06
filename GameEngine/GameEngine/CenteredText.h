#pragma once
#include "Text.h"
#include "TextboxContent.h"


class CenteredText : public TextboxContent {
public:

	CenteredText(TextboxContentData& data);

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
	static Vector2f textStartPosition;

	static float textEffectiveWidth;

	TextboxContentData data;
	std::string textData;

};
