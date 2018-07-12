#pragma once
#include <queue>
#include "AbstractAction.h"

class GlobalActionInvoker
{

public:

	static void init();
	static void clean();

	static void update(float dt);

	static void createActionSet();
	static void endActionSet();
	static void addAction(AbstractAction* act);

private:

	class ActionSet {
		public:
			~ActionSet();
			void addAction(AbstractAction* act);
			bool update(float dt);
		private:
			std::queue<AbstractAction*> actionQueue;
	};

	static ActionSet* currentSet;
	static ActionSet* catchAllSet;
	static std::vector<ActionSet*> sets;

};

