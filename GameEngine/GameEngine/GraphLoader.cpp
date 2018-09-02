#include "GraphLoader.h"
#include <algorithm>
#include "PauseAction.h"
#include "SetFlagAction.h"
#include "TextboxWaitAction.h"
#include "WaitForAction.h"

std::map<std::string, TextureType> GraphLoader::nameMap;

GraphLoader::GraphLoader()
{
}


GraphLoader::~GraphLoader()
{
}

void GraphLoader::load(std::vector<Node*>& nodes, std::map<std::string, int>& nodeNames, char * filename)
{

	nameMap["Melody"] = TextureType::T_CARD_5;
	nameMap["Echo"] = TextureType::T_CARD_3;



	rapidxml::xml_document<> doc;

	std::ifstream file;
	int nodeCounter = 0;

	file.open(filename, std::ios::in);
	
	std::stringstream buffer;
	buffer << file.rdbuf();
	
	file.close();
	std::string content(buffer.str());
	doc.parse<0>(&content[0]);
	
	rapidxml::xml_node<> *node = doc.first_node();
	
	while (node != 0) {
		std::string name = node->first_attribute("id")->value();
		
		std::transform(name.begin(), name.end(), name.begin(), ::toupper);

		nodeNames[name] = nodeCounter;
		nodeCounter++;
		node = node->next_sibling();
	}

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
	AbstractAction* act = 0;

	std::string cmd = inst->name();
	std::string val = inst->value();


	if (cmd == "text") {

		TextboxContentData content;
		content.text = val;

		auto n = inst->first_attribute("name");
		auto t = inst->first_attribute("time");

		auto x = inst->first_attribute("x"); 
		auto y = inst->first_attribute("y");

		auto s = inst->first_attribute("speed");
		auto sk = inst->first_attribute("noskip");

		auto f = inst->first_attribute("face");
		auto c = inst->first_attribute("center");

		auto sc = inst->first_attribute("scale");

		if (n != 0) {
			content.dialogue = true;
			content.name = n->value();
			content.portrait = nameMap[n->value()];
		}


		if (f != 0) {
			content.portrait = nameMap[f->value()];
		}


		if (t != 0) {
			content.time = std::atof(t->value());
		}

		if (s != 0) {
			content.textSpeed = std::atof(s->value());
		}

		if (sk != 0) {
			content.skippable = false;
		}

		if (c != 0) {
			content.centered = true;
		}

		if (sc != 0) {
			content.scale = std::atof(sc->value());
		}


		if (x != 0 && y != 0) {
			int xx = std::atoi(x->value());
			int yy = std::atoi(y->value());
			content.offset = Vector2f(xx, yy);
		}

		act = new TextAction(content);

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

	else if (cmd == "block") {
		act = new TextboxWaitAction();
	}


	else if (cmd == "waitfor") {
		auto n = inst->first_attribute("name");
		Condition* cond = new InteractCondition(n->value());
		act = new WaitForAction(cond);

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
		float x = (float)std::atof(xStr);
		float y = (float)std::atof(yStr);

		act = new MoveCameraAction(x,y);

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

	else if (cmd == "pause") {
		act = new PauseAction();
	}

	else if (cmd == "set") {
		std::string flag = inst->first_attribute("flag")->value();
		std::string b = inst->first_attribute("bool")->value();
		act = new SetFlagAction(flag, std::atoi(b.c_str()));
	}

	else if (cmd == "room") {
		std::string room = inst->first_attribute("name")->value();
		
		act = new RoomChangeAction(room);
	}
	else if (cmd == "follow") {
		std::string name = inst->first_attribute("name")->value();
		World * world = World::getInstance();
		Object * obj = world->getObject(name);
		if (obj == nullptr) {
			std::cout << "Couldn't Follow Object " << name << std::endl;
			return;
		}
		act = new ScreenFollowAction(obj);
	}
	else if (cmd == "moveObject") {
		std::string name = inst->first_attribute("name")->value();
		rapidxml::xml_attribute<char> * xStr = inst->first_attribute("x");
		rapidxml::xml_attribute<char> * yStr = inst->first_attribute("y");
		float x = 0.0f;
		if (xStr == nullptr) {
			x = World::getInstance()->getObject(name)->pos[0];
		}
		else {
			char * xVal = xStr->value();
			x = (float)std::atof(xVal);
		}
		float y = 0.0f;
		if (yStr == nullptr) {
			y = World::getInstance()->getObject(name)->pos[1];
		}
		else {
			char * yVal = yStr->value();
			y = (float)std::atof(yVal);
		}
		
		rapidxml::xml_attribute<char> * speed = inst->first_attribute("speed");
		rapidxml::xml_attribute<char> * conc = inst->first_attribute("concurrent");
		if (conc == nullptr || conc->value() == "false") {
			if (speed != nullptr) {
				act = new MoveAction(name, Vector2f(x, y), (float)std::atof(speed->value()));
			}
			else {
				act = new MoveAction(name, Vector2f(x, y));
			}
		}
		else {
			if (speed != nullptr) {
				
				act = new NonBlockingMove(name, Vector2f(x, y), (float)std::atof(speed->value()));
			}
			else {
				act = new NonBlockingMove(name, Vector2f(x, y));
			}
		}
	}
	
	else if (cmd == "wait") {
		char* time = inst->first_attribute("time")->value();
		float t = (float)std::atof(time);
		act = new WaitAction(t);
	}
	else if (cmd == "create") {
		std::string name = inst->first_attribute("object")->value();
		char * xStr = inst->first_attribute("x")->value();
		char * yStr = inst->first_attribute("y")->value();
		float x = std::atof(xStr);
		float y = std::atof(yStr);
		act = new SpawnAction(name, Vector2f(x,y));
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
	std::transform(next.begin(), next.end(), next.begin(), ::toupper);
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

	else if (cmd == "flag") {

		std::string b = inst->first_attribute("bool")->value();
		std::string flag = inst->first_attribute("flag")->value();


		int bb = (b == std::string("true")) ? 1 : 0;

		edge = new Edge(new FlagCondition(flag, bb), nodes[node]);
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
