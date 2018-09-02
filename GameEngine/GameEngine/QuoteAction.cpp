#include "QuoteAction.h"
#include "UIManager.h"
#include "GlobalActionInvoker.h"


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




QuoteActionWrapper::QuoteActionWrapper(std::string & s1)
{
	str = s1;
}

QuoteActionWrapper::~QuoteActionWrapper()
{
}

int QuoteActionWrapper::run(float dt)
{
	if (!UIManager::isQuoteBannerVisible()) {
		GlobalActionInvoker::addActionSet({ new QuoteAction(str) });
	}
	return 1;
}
