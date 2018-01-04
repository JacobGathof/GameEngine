#pragma once
#include "Texture.h"
#include <map>
#include <fstream>
#include <sstream>


// Bug 0002
// An incorrect font fnt file will crash the entire program, can not be silently avoided.
// Best solution would probably be a graceful shutdown

class Font
{
public:

	class Char{
		public:
			Char(int* data);
			int x, y, width, height, xoffset, yoffset, xadvance;
	};

	Font(char* fnt_filename, char* png_filename);
	~Font();

	void bind();
	Char* getCharacter(char c);


private:
	void loadFont(char* filename);
	std::map<char, Char*> characters;
	Texture* texture;

};

