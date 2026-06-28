#include "Window.h"



#define GLFW_INCLUDE_VULKAN


Window::Window() : m_width(800), m_height(600)
{
	m_window = nullptr;
}

void Window::Initialize()
{
	glfwInit();

	// Setting to a non OpenGL context.
	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	// Disabling resizable window.
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

	// Window creation. Fourth parameter specifies the monitor. Last parameter is only relevant to OpenGL.
	m_window = glfwCreateWindow(m_width, m_height, "Vulkan", nullptr, nullptr);

}

void Window::MainLoop()
{
	while (!glfwWindowShouldClose(m_window)) 
	{
		glfwPollEvents();
	}
}

void Window::Shutdown() {
	glfwDestroyWindow(m_window);

	glfwTerminate();
}
