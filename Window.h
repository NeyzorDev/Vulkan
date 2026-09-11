#pragma once

#include <GLFW/glfw3.h>

#define WINDOWMGR Window::GetInstance()

class Window
{
public:
	~Window();

	Window(Window& other) = delete; // Window should not be cloneable.
	void operator=(const Window&) = delete; // Window should not be assignable.

	static Window* GetInstance();

	void Initialize();
	void MainLoop();
	void Shutdown();

	GLFWwindow* GetWindow();
	
private:
	Window();
	static Window* m_instance;

	GLFWwindow* m_window;
	uint16_t m_width, m_height;
};