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
	int numNewlines = 0;

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
			numNewlines++;
		}
	}

	if (numNewlines >= 5) {
		std::cout << "Warning - Line too long: " << txt << std::endl;
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

float TextUtils::getWidth(std::string & txt, Font * font, Vector2f & scale, int count)
{
	float length = 0;
	int ptr = 0;
	int validChars = 0;

	while(validChars < count){
		Font::Char * c = font->getCharacter(txt[ptr]);
		if (c != 0) {
			if (txt[ptr] != '\n' && txt[ptr] != ' ') {
				validChars++;
			}
			length += Text::POS_SCALE * scale[0] * c->xadvance;
		}
		ptr++;
	}

	return length;
}
