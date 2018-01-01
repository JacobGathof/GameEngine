#include "Font.h"



Font::Font(char* fnt_filename, char* png_filename)
{
	texture = new Texture(png_filename);
	loadFont(fnt_filename);
}

void Font::bind(){
	texture->bind();
}

Font::Char* Font::getCharacter(char c)
{
	return characters[c];
}

void Font::loadFont(char * filename)
{
	std::ifstream file;
	file.open(filename, file.in | file.binary);
	std::string str;

	char buffer[512];
	char item[64];

	for (int i = 0; i < 4; i++) {
		file.ignore(512, '\n');
	}

	while (!file.eof()) {

		std::stringstream line;
		std::vector<int> elements;

		file.getline(buffer, 512);
		if (buffer[0] == 'k') break;
		line << buffer;

		line.ignore(7);
		while (!line.eof()) {

			line.getline(item, 64, '=');
			if (item[0] == '\0') continue;

			str.assign(item);
			str = str.substr(0, str.find(" "));

			elements.push_back(std::stoi(str));

		}

		Char * ch = new Char(&elements[1]);
		characters[(char)(elements[0])] = ch;
	}

	file.close();
}

Font::~Font()
{
	for (auto c : characters) {
		delete c.second;
	}
	delete texture;
}


Font::Char::Char(int* data)
{
	x = data[0];
	y = data[1];
	width = data[2];
	height = data[3];
	xoffset = data[4];
	yoffset = data[5];
	xadvance = data[6];
}
