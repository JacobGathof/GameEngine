#include "BannerAction.h"


BannerAction::BannerAction(std::string & s1, std::string & s2)
{
	str1 = s1;
	str2 = s2;
	first = true;
}

BannerAction::~BannerAction()
{
}

int BannerAction::run(float dt)
{
	if (first) {
		first = false;
		UIManager::setBannerText(str1, str2);
	}
	return UIManager::playBannerAnimation(dt);
}

void BannerAction::reset()
{
}
