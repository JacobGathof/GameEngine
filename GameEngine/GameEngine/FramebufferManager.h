#pragma once
#include "Framebuffer.h"
#include <map>

enum class FramebufferType {
	DEFAULT,
	UI_BUFFER,
};


class FramebufferManager
{
public:

	static void init();
	static void clean();
	static Framebuffer* get(FramebufferType type);

private:

	static void addFramebuffer(FramebufferType frame, int id);
	static std::map<FramebufferType, Framebuffer*> buffers;

};

