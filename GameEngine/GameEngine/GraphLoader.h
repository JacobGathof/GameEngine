#pragma once
#include "Node.h"
#include <fstream>
#include <map>
#include <sstream>

#include "TextAction.h"
#include "TextChoiceAction.h"
#include "DebugAction.h"
#include "WaitAction.h"
#include "ScreenFadeAction.h"
#include "SetAction.h"
#include "PlayMusicAction.h"
#include "MoveAction.h"
#include "BannerAction.h"
#include "MoveCameraAction.h"
#include "QuoteAction.h"
#include "RoomChangeAction.h"

#include "rapidxml.hpp"

class GraphLoader
{
public:
	GraphLoader();
	~GraphLoader();
	static void load(std::vector<Node*>& nodes, char* filename);

private:
	static void handleCommand(std::vector<Node*>& nodes, int nodePtr, rapidxml::xml_node<> *inst);
	static void handleCondition(std::vector<Node*>& nodes, int nodePtr, std::map<std::string, int>& nodeNames, rapidxml::xml_node<> *inst);
	static List<std::string> split(std::string& str, char delim);
};

