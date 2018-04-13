#include "GraphLoader.h"
#include <algorithm>

GraphLoader::GraphLoader()
{
}


GraphLoader::~GraphLoader()
{
}

void GraphLoader::load(std::vector<Node*>& nodes, char * filename)
{
	rapidxml::xml_document<> doc;

	std::ifstream file;
	std::map<std::string, int> nodeNames;
	int nodeCounter = 0;

	file.open(filename, std::ios::in);
	std::stringstream buffer;
	buffer << file.rdbuf();
	file.close();
	std::string content(buffer.str());
	doc.parse<0>(&content[0]);

	rapidxml::xml_node<> *node = doc.first_node();
	while (node != 0) {
		nodeNames[node->first_attribute("id")->value()] = nodeCounter;
		nodeCounter++;
		node = node->next_sibling();
	}


	for (auto a : nodeNames) {
		std::cout << a.first << " " << a.second << std::endl;
	}
	std::cout << std::endl;

	int numberOfNodes = nodeNames.size();
	for (int i = 0; i < numberOfNodes; i++) {
		nodes.push_back(new Node());
	}

	nodeCounter = 0;
	node = doc.first_node();
	while(node != 0){
		rapidxml::xml_node<> *set = node->first_node();

		while (set != 0) {
			int state = 0;
			std::string setname = set->name();

			if (setname == "actions") {
				state = 0;
			}
			else if (setname == "conditions") {
				state = 1;
			}

			rapidxml::xml_node<> *item = set->first_node();

			while (item != 0) {
				if (state == 0) {
					handleCommand(nodes, nodeCounter, item);
				}
				else if (state == 1) {
					handleCondition(nodes, nodeCounter, nodeNames, item);
				}
				item = item->next_sibling();
			}
			set = set->next_sibling();
		}
		node = node->next_sibling();
		nodeCounter++;
	}

}

void GraphLoader::handleCommand(std::vector<Node*>& nodes, int nodePtr, rapidxml::xml_node<> *inst)
{
	AbstractScriptAction* act = 0;

	std::string cmd = inst->name();
	std::string val = inst->value();

	if (cmd == "text") {
		act = new TextAction(val);
	}

	else if (cmd == "choice") {
		List<std::string> li;
		rapidxml::xml_node<> *c = inst->first_node();
		while (c != 0) {
			li.add(c->value());
			c = c->next_sibling();
		}
		act = new TextChoiceAction(li);
	}

	else if (cmd == "fade") {
		std::string color = inst->first_attribute("color")->value();
		std::string time = inst->first_attribute("time")->value();
		std::string dir = inst->first_attribute("dir")->value();

		unsigned long col = std::stoul(color, 0, 16);
		float t = (float)std::atof(time.c_str());
		int i = (dir == "in") ? SCREEN_FADE_IN : SCREEN_FADE_OUT;
		act = new ScreenFadeAction(Color(col), t, i);
	}

	else if (cmd == "fade") {
		std::string color = inst->first_attribute("color")->value();
		std::string time = inst->first_attribute("time")->value();
		std::string dir = inst->first_attribute("dir")->value();

		unsigned long col = std::stoul(color, 0, 16);
		float t = (float)std::atof(time.c_str());
		int i = (dir == "in") ? SCREEN_FADE_IN : SCREEN_FADE_OUT;
		act = new ScreenFadeAction(Color(col), t, i);
	}
	else if (cmd == "setScreenPos") {
		char * xStr = inst->first_attribute("x")->value();
		char * yStr = inst->first_attribute("y")->value();
		float x = std::atof(xStr);
		float y = std::atof(yStr);

		act = new MoveCameraAction(x,y);

		//delete xStr;
		//delete yStr;
	}
	else if (cmd == "banner") {
		std::string super = inst->first_attribute("super")->value();
		std::string sub = inst->first_attribute("sub")->value();

		act = new BannerAction(super, sub);
	}

	else if (cmd == "quote") {
		std::replace(val.begin(), val.end(), '~', '\n');
		act = new QuoteAction(val);
	}

	if (act != 0) {
		nodes[nodePtr]->addAction(act);
	}
}

void GraphLoader::handleCondition(std::vector<Node*>& nodes, int nodePtr, std::map<std::string, int>& nodeNames, rapidxml::xml_node<> *inst)
{
	Edge* edge = 0;
	std::string cmd = inst->name();

	std::string next = inst->first_attribute("next")->value();
	int node = nodeNames[next];

	//I don't know if this is how we want to do it in the end (Most likely not), but it will work for now
	if (cmd == std::string("textEmpty")) {
		
		std::string onStr = inst->first_attribute("textbox")->value();
		bool on = (onStr == std::string("on"));
		int node = nodeNames[next];
		nodes[nodePtr]->addEdge(new Edge(new TextBoxCondition(on), nodes[node]));
		return;
	}

	if (cmd == "goto") {
		edge = new Edge(new Condition(), nodes[node]);
	}

	else if (cmd == "cond") {

		std::string match = inst->first_attribute("match")->value();
		std::string val = inst->first_attribute("val")->value();

	
		int cond = std::atoi(val.c_str());
		int b = (match == std::string("1")) ? 1 : 0;

		edge = new Edge(new ChoiceCondition(cond, b), nodes[node]);
	}


	if (edge != 0) {
		nodes[nodePtr]->addEdge(edge);
	}

	
}

List<std::string> GraphLoader::split(std::string & str, char delim)
{
	List<std::string> li;
	std::stringstream stream(str);
	std::string word;
	while (std::getline(stream, word, delim)) {
		li.add(word);
	}
	return li;
}
