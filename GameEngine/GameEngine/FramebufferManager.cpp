#include "FramebufferManager.h"

std::map<FramebufferType, Framebuffer*> FramebufferManager::buffers;

void FramebufferManager::init() {
	addFramebuffer(FramebufferType::DEFAULT, 0);
	addFramebuffer(FramebufferType::UI_BUFFER, -1);
	addFramebuffer(FramebufferType::PARTICLES_BUFFER, -1);
	addFramebuffer(FramebufferType::WORLD_BUFFER, -1);
}

void FramebufferManager::clean() {
	for (auto f : buffers) {
		delete f.second;
	}
}

Framebuffer * FramebufferManager::get(FramebufferType type)
{
	return buffers[type];
}

void FramebufferManager::updateSizes(int x, int y)
{
	for (auto f : buffers) {
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
	buffers[frame] = buf;
}