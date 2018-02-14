#include "FramebufferManager.h"

std::map<FramebufferType, Framebuffer*> FramebufferManager::buffers;

void FramebufferManager::init() {
	addFramebuffer(FramebufferType::DEFAULT, 0);
	addFramebuffer(FramebufferType::UI_BUFFER, -1);
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