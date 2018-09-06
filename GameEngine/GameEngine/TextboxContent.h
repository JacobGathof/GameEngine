#pragma once
#include "Keyboard.h"
#include "Vector2f.h"
#include "ResourceType.h"
#include <string>

struct TextboxContentData {
	std::string text = "";
	std::string name = "???";
	TextureType portrait = TextureType::TEXTURE_DEFAULT;
	Vector2f offset = Vector2f(0, 0);

	float time = -1;
	float textSpeed = 1;
	bool skippable = true;
	bool dialogue = false;
	bool centered = false;
	float scale = 1;
	bool instant = false;
};


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

