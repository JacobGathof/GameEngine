#include "FramebufferManager.h"



void FramebufferManager::init() {
	addFramebuffer(FramebufferType::DEFAULT, 0);
	addFramebuffer(FramebufferType::UI_BUFFER, -1);
	addFramebuffer(FramebufferType::EFFECTS_BUFFER, -1);
	addFramebuffer(FramebufferType::OBJECT_BUFFER, -1);
	addFramebuffer(FramebufferType::TERRAIN_BUFFER, -1);
	addFramebuffer(FramebufferType::EXTRA_BUFFER_1, -1);
}

void FramebufferManager::updateSizes(int x, int y)
{
	for (auto f : elements) {
		f.second->updateSize(x,y);
	}
}

void FramebufferManager::addFramebuffer(FramebufferType frame, int id)
{
	Framebuffer* buf;
	if (id == -1) {
		buf = new Framebuffer();
	}
	else {
		buf = new Framebuffer(id);
	}
	elements[frame] = buf;
}