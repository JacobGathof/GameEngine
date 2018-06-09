#include "TextUtils.h"
#include "Text.h"


TextUtils::TextUtils()
{
}


TextUtils::~TextUtils()
{
}


std::string TextUtils::processString(std::string & txt, Font* font, Vector2f& scale, float maxWidth)
{
	float length = 0;
	float maxLength = maxWidth;
	std::string newString;
	newString.resize(txt.size());
	int txtLength = txt.length();
	for (int i = 0; i < txtLength; i++) {
		if (txt[i] == '\n' || txt[i] == ' '){
			newString[i] = ' ';
		} else {
			newString[i] = txt[i];
		}
		Font::Char * c = font->getCharacter(txt[i]);
		if (c == 0)
			continue;
		length += Text::POS_SCALE * scale[0] * c->xadvance;

		if (length >= maxLength) {
			length = 0;
			backtrack(i, txt, newString);
		}
	}
	return newString;
}

void TextUtils::backtrack(int& i, std::string & txt, std::string & newString)
{
	for (int j = 0; j < i; j++) {
		char c = txt[i - j];
		if (c == ' ') {
			newString[i - j] = '\n';
			i = i - j;
			return;
		}
	}
}
