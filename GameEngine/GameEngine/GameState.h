#pragma once
#include <string>
class GameState
{
public:
	GameState();
	~GameState();

	static std::string getGlobalDebug();
	static void setGlobalDebug(std::string str);

private:
	static std::string globalDebug;

};

