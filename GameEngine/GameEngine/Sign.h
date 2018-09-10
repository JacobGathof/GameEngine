#pragma once
#include "Object.h"

class Sign : public Object
{
public:
	Sign(ObjectData& data, std::string& text);
	~Sign();
};

