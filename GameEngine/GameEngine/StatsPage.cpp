#include "StatsPage.h"
#include "Screen.h"
#include "GameState.h"
#include "Text.h"

StatsPage::StatsPage()
{
	position = Vector2f(0, 0);
	timer.setTickLength(transitionTime);
	timer.setPauseOnTick(true);

	text = new Text(Vector2f(100, 100), std::string(""), Vector2f(128.0f, 128.0f), FontManager::get(FontType::DEFAULT));

	text->setPosition(startText);

	textUpdateTimer.setTickLength(0.1f);

}


StatsPage::~StatsPage(){
	delete text;
}

void StatsPage::draw()
{
	UIUtils::drawRectangle(Vector2f(10, 790), Vector2f(780, -100), Color(0xffffff88));
	UIUtils::drawRectangle(Vector2f(12, 788), Vector2f(776, -96), Color(0x44448844));
	UIUtils::drawRectangle(Vector2f(14, 786), Vector2f(772, -92), Color(0x44444f88));

	text->draw();
}

void StatsPage::update(float dt){
	timer.update(dt);
	position = Vector2f(800, 0) * timer.getCurrentTime() / transitionTime;
	//text.setPosition(Vector2f(800 * timer.getCurrentTime() / transitionTime,800));

	textUpdateTimer.update(dt);
	if (textUpdateTimer.tick()) {
		text->setText(std::string("Game FPS: ") + GameState::getGlobalDebug() + std::string(" \nTesting second line\n3rd\n4th"));
	}
}

void StatsPage::show(){
	timer.unpause();
}

void StatsPage::hide(){
	timer.unpause();
}

void StatsPage::handleMouseEvents(Mouse & mouse)
{
}

void StatsPage::handleKeyEvents(Keyboard & keyboard)
{
}
