#include "FilesAndStrings.h"



FilesAndStrings::FilesAndStrings()
{
}


FilesAndStrings::~FilesAndStrings()
{
}

List<std::string> FilesAndStrings::getFileContents(std::string& filename)
{
	std::string in = std::string("start");
	List<std::string> lines;
	std::ifstream file;
	file.open(filename, std::ios::in);
	if (file.is_open()) {
		while (std::getline(file, in)) {
			lines.add(in);
		}
	}
	return lines;
}

List<std::string> FilesAndStrings::parseStrings(std::string& line, char regex)
{
	List<std::string> values;
	std::string current;
	for (unsigned int i = 0; i < line.size(); i++) {
		char c = line[i];
		if (c == regex) {
			values.add(current);
			current = std::string("");
		}
		else {
			current += c;
		}
	}
	values.add(current);

	return values;
}

List<int> FilesAndStrings::parseInts(std::string& line, char regex)
{
	List<int> values;
	std::string current;
	for (unsigned int i = 0; i < line.size(); i++) {
		char c = line[i];
		if (c == regex) {
			values.add(parseInt(current));
			current = std::string("");
		}
		else {
			current += c;
		}
	}
	values.add(parseInt(current));

	return values;
}

List<float> FilesAndStrings::parseFloats(std::string& line, char regex)
{
	List<float> values;
	std::string current;
	for (unsigned int i = 0; i < line.size(); i++) {
		char c = line[i];
		if (c == regex) {
			values.add(parseFloat(current));
			current = std::string("");
		}
		else {
			current += c;
		}
	}
	values.add(parseFloat(current));

	return values;
}

int FilesAndStrings::parseInt(std::string & line)
{
	std::stringstream stream(line);
	int val;
	stream >> val;
	return val;
}

float FilesAndStrings::parseFloat(std::string & line)
{
	std::stringstream stream(line);
	float val;
	stream >> val;
	return val;
}
