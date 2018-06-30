#include "SetFlagAction.h"
#include "GameState.h"


SetFlagAction::SetFlagAction(std::string& s, bool v)
{
	str = s;
	val = v;
}

SetFlagAction::~SetFlagAction()
{
}

int SetFlagAction::run(float dt)
{
	GameState::flags[str] = val;
	return 1;
}
