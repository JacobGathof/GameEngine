#include "gl3w.h"
#include "glfw3.h"
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


	class Callbacks {
	public:
		static void CursorPosCallback(GLFWwindow* window, double xpos, double ypos);
		static void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
		static void MouseCallback(GLFWwindow* window, int button, int action, int mods);
		static void WindowSizeCallback(GLFWwindow* window, int width, int height);
		static void ScrollCallback(GLFWwindow* window, double xoffset, double yoffset);
		static void WindowPosCallback(GLFWwindow* window, int x, int y);
		static void WindowFocusCallback(GLFWwindow* window, int focused);
	};


};