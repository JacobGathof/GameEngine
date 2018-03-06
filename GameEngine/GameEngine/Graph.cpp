#include "Graph.h"
#include "TextAction.h"
#include "TextChoiceAction.h"
#include "DebugAction.h"
#include "WaitAction.h"
#include "ScreenFadeAction.h"
#include "SetAction.h"
#include "PlayMusicAction.h"
#include "PauseMusicAction.h"
#include "MoveAction.h"

Graph::Graph()
{
	createGraph();
	current = nodes[0];
}


Graph::~Graph()
{
	for (auto n : nodes) {
		delete n;
	}
}

void Graph::update(float dt)
{
	Node* n = current->update(dt);
	if (n != 0) {
		current = n;
	}
}

void Graph::createGraph()
{
	nodes.push_back(new Node());
	nodes.push_back(new Node());

	nodes[0]->addAction(new TextAction(std::string("Hello World"), true));
	nodes[0]->addAction(new MoveAction("Melody", Vector2f(100, 2000)));
	nodes[0]->addAction(new TextAction(std::string("Reach the city steps tonight. Following the power lines. Met a man barside, with eclipses for eyes. The quick brown fox jumped over the lazy dog. I bless the rains down in Aaaaafrica")));
	nodes[0]->addAction(new TextChoiceAction({ std::string("Hello World4") , std::string("Hello World4") }));
	nodes[0]->addAction(new WaitAction(1.0f));
	nodes[0]->addAction(new ScreenFadeAction(Color::White, 2.0f, SCREEN_FADE_OUT));
	//nodes[0]->addAction(new PlayMusicAction(MusicType::SONG_FMAB_AGAIN));
	nodes[0]->addAction(new ScreenFadeAction(Color::White, 4.0f, SCREEN_FADE_IN));
	//nodes[0]->addAction(new PauseMusicAction(MusicType::SONG_FMAB_AGAIN));
	nodes[0]->addAction(new SetAction<float>(&GameState::ui_blue, 0.0f));
	nodes[0]->addAction(new DebugAction("Node 0 done"));

	nodes[0]->addEdge(new Edge(new Condition(2, 1), nodes[0]));
	nodes[0]->addEdge(new Edge(new Condition(1, 1), nodes[1]));




	nodes[1]->addAction(new TextAction(std::string("Hell0")));
	nodes[1]->addAction(new TextAction(std::string("Hello")));
	nodes[1]->addAction(new TextChoiceAction({ std::string("Hello World4") , std::string("Hello World4") }));
	nodes[1]->addAction(new WaitAction(2.0f));
	nodes[1]->addAction(new DebugAction("Node 1 done"));

	nodes[1]->addEdge(new Edge(new Condition(1, 1), nodes[1]));

}
