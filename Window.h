#pragma once

#include <GLFW/glfw3.h>

class Window
{
public:
	Window();

	void Initialize();
	void MainLoop();
	void Shutdown();
	
private:
	GLFWwindow* m_window;
	uint16_t m_width, m_height;
};