#include "gl3w.h"
#include "glfw3.h"
#include "Callbacks.h"
#include "Color.h"

class Window
{
public:

	static void init(char* title, int width, int height);
	static void destroy();
	static bool shouldClose();
	static void close();
	static void centerCursor();
	static bool isInitialized();
	static void swapBuffers();
	static void pollEvents();
	static void show();

	static void setCursorMode(int mode);
	static float getAspectRatio();
	static void setMaximize(bool m);
	static void toggleFullscreen();
	static void setSize(int width, int height);


	static int WINDOW_WIDTH;
	static int WINDOW_HEIGHT;

private:

	static GLFWwindow *window;
	static bool initialized;
	static Color clearColor;
	static char* WINDOW_TITLE;
	static bool fullscreen;

	static void setCallbacks();
	static void setWindowHints();
	static void initOpenGL();

	static int WINDOW_X;
	static int WINDOW_Y;

};