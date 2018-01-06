#pragma once
#include <map>
#include "Font.h"


enum class FontType {
	DEFAULT,
	ITALIC
};


class FontManager
{
public:

	static void init();
	static void clean();
	static Font* get(FontType type);

private:

	static void addFont(FontType font, char* fnt, char* png);
	static std::map<FontType, Font*> fonts;

};

