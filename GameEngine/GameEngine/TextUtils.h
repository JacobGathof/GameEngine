#pragma once
#include <string>
#include "Font.h"

class TextUtils
{
public:
	TextUtils();
	~TextUtils();

	static std::string processString(std::string & txt, Font* font, Vector2f& scale, float maxWidth);
	static void backtrack(int& i, std::string & txt, std::string& newString);
};

