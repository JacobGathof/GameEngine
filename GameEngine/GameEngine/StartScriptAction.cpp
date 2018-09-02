#include "StartScriptAction.h"
#include "ScriptManager.h"


StartScriptAction::StartScriptAction(GraphType type)
{
	tp = type;
}


StartScriptAction::~StartScriptAction()
{
}

int StartScriptAction::run(float dt)
{
	Res::scriptManager->addScript(tp);
	return ACTION_COMPLETE;
}
