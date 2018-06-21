#pragma once
#include "Framebuffer.h"
#include "IManager.h"
#include "ResourceType.h"


class FramebufferManager : public IManager<Framebuffer, FramebufferType>
{
public:

	virtual void init();
	virtual Framebuffer* get(FramebufferType type);
	void updateSizes(int x, int y);
	void setTemporaryBuffer(FramebufferType type);
	void resetTempBuffer();

private:

	void addFramebuffer(FramebufferType frame, int id);
	FramebufferType currentBuffer;
};

