#pragma once
#include "Framebuffer.h"
#include <map>

enum class FramebufferType {
	DEFAULT,
	UI_BUFFER,
	PARTICLES_BUFFER,
};


class FramebufferManager
{
public:

	static void init();
	static void clean();
	static Framebuffer* get(FramebufferType type);
	static void updateSizes(int x, int y);

private:

	static void addFramebuffer(FramebufferType frame, int id);
	static std::map<FramebufferType, Framebuffer*> buffers;

};

