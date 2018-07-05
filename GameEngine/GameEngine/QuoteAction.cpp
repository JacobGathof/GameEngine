#include "QuoteAction.h"
#include "UIManager.h"



QuoteAction::QuoteAction(std::string & s1)
{
	str = s1;
	first = true;
}

QuoteAction::~QuoteAction()
{
}

int QuoteAction::run(float dt)
{
	if (first) {
		first = false;
		UIManager::setQuoteText(str);
	}
	return !UIManager::isQuoteBannerVisible();
}

void QuoteAction::reset()
{
	first = true;
}
