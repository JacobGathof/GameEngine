#include "OpenTextbox.h"


OpenTextbox::OpenTextbox(std::string text)
{
}

OpenTextbox::~OpenTextbox()
{
}

bool OpenTextbox::execute(LivingObject * obj, float dt)
{

	UIManager::addText(str);
	return true;
}
