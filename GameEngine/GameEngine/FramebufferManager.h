#pragma once
#include "Framebuffer.h"
#include "IManager.h"
#include "ResourceType.h"


class FramebufferManager : public IManager<Framebuffer, FramebufferType>
{
public:

	virtual void init();
	void updateSizes(int x, int y);

private:

	void addFramebuffer(FramebufferType frame, int id);

};

