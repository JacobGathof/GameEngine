#include "OpenTextboxWithChoice.h"
#include "LivingObject.h"


OpenTextboxWithChoice::OpenTextboxWithChoice(std::string text)
{
}

OpenTextboxWithChoice::~OpenTextboxWithChoice()
{
}

bool OpenTextboxWithChoice::execute(LivingObject * obj, float dt)
{
	UIManager::addText(str);

	//wait for some value before returning true
	return true;
}
