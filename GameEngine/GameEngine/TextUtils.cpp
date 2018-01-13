#include "TextUtils.h"



TextUtils::TextUtils()
{
}


TextUtils::~TextUtils()
{
}


std::string TextUtils::processString(std::string & txt, Font* font)
{
	int length = 0;
	int maxLength = 1024;
	std::string newString;
	for (int i = 0; i < txt.length(); i++) {
		if (txt[i] == '\n' || txt[i] == ' '){
			newString += ' ';
			length += 21;
		} else {
			newString += txt[i];
			length += font->getCharacter(txt[i])->xadvance-12;
		}

		if (length >= maxLength) {
			length = 0;
			backtrack(i, txt, newString);
		}
	}
	return newString;
}

void TextUtils::backtrack(int i, std::string & txt, std::string & newString)
{
	for (int j = 0; j < i; j++) {
		char c = txt[i - j];
		if (c == ' ') {
			newString.insert(newString.length() - j, "\n");
			return;
		}
	}
}
