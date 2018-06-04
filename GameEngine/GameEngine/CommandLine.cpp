#include "CommandLine.h"
#include "FilesAndStrings.h"


CommandLine::CommandLine()
{
	position = Vector2f(0,0);
	scale = Vector2f(800,40);
	text = new Text(position + Vector2f(scale[1] / 2, scale[1] / 4), std::string(""), Vector2f(scale[1] / 2.0f, scale[1] / 2.0f), 0);
	text->setColor(Color::White);
}


CommandLine::~CommandLine()
{
	delete text;
}

void CommandLine::toggle()
{
	visible = !visible;
}

void CommandLine::draw()
{
	if (!visible)
		return;

	UIUtils::drawRectangle(position, scale, Color(0x888888ff));
	UIUtils::drawRectangle(position + Vector2f(2, 2), scale - Vector2f(4, 4), Color(0xaaaaaaff));
	UIUtils::drawRectangle(position + Vector2f(4, 4), scale - Vector2f(8, 8), Color(0x000000ff));

	text->draw();
}

void CommandLine::update(float dt)
{
}

void CommandLine::handleKeyEvents(Keyboard & keyboard)
{
	if (!visible)
		return;


	int key = keyboard.getCurrentPressed();
	if ((key <= 'Z' && key >= 'A' || key == ' ')) {
		str += (char)key;
		text->setText(str);
		keyboard.clearQueues();
	}
	if (key == GLFW_KEY_BACKSPACE && !str.empty()) {
		str.erase(str.end() - 1);
		text->setText(str);
	}

	if (key == GLFW_KEY_ENTER) {
		handleCommand(str);
		pastCommands.push(str);
		str = "";
		text->setText(str);
	}



}

void CommandLine::handleCommand(std::string s)
{
	List<std::string> li = FilesAndStrings::parseStrings(s, ' ');

	if (li[0] == "P") {
		std::cout << li.subList(1);
	}



}
