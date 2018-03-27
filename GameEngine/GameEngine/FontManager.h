#pragma once
#include "Font.h"
#include "IManager.h"
#include "ResourceType.h"

class FontManager : public IManager<Font, FontType>
{
public:
	virtual void init();

private:
	void addFont(FontType font, char* fnt, char* png);

};

