#include "FramebufferManager.h"



void FramebufferManager::init() {
	addFramebuffer(FramebufferType::DEFAULT, 0);
	addFramebuffer(FramebufferType::UI_BUFFER, -1);
	addFramebuffer(FramebufferType::PARTICLES_BUFFER, -1);
	addFramebuffer(FramebufferType::WORLD_BUFFER, -1);
	addFramebuffer(FramebufferType::LIGHT_BUFFER, -1);
}

Framebuffer * FramebufferManager::get(FramebufferType type)
{
	currentBuffer = type;
	return elements[type];
}

void FramebufferManager::updateSizes(int x, int y)
{
	for (auto f : elements) {
		f.second->updateSize(x,y);
	}
}

void FramebufferManager::setTemporaryBuffer(FramebufferType type)
{
	elements[type]->bind();
}

void FramebufferManager::resetTempBuffer()
{
	elements[currentBuffer]->bind();
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