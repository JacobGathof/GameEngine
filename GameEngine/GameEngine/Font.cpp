#include "Font.h"



const float Font::textureScale = 512.0f;

Font::Font(char* fnt_filename, char* png_filename)
{
	texture = new Texture(png_filename, true);
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
	std::string str;

	file.open(filename, file.in | file.binary);

	if (!file.is_open()) {
		std::cout << "Error loading file: " << filename << std::endl;
	}

	char buffer[512];
	char item[64];

	for (int i = 0; i < 4; i++) {
		file.ignore(512, '\n');
	}

	while (!file.eof()) {

		std::stringstream line;
		std::vector<int> elements;

		file.getline(buffer, 512);
		if (buffer[0] != 'c') break;
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
	x = data[0] / textureScale;
	y = data[1] / textureScale;
	width = data[2] / textureScale;
	height = data[3] / textureScale;
	xoffset = data[4] / textureScale;
	yoffset = data[5] / textureScale;
	xadvance = (data[6]-8) / textureScale;
}

