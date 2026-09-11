#include "Window.h"


#define GLFW_INCLUDE_VULKAN


Window* Window::m_instance = nullptr;

Window::Window() : m_window(nullptr), m_width(800), m_height(600)
{
}

Window::~Window()
{
	delete m_instance;
}

Window* Window::GetInstance()
{
	if (m_instance == nullptr)
	{
		m_instance = new Window();
	}
	return m_instance;
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

void Window::Shutdown()
{
	glfwDestroyWindow(m_window);

	glfwTerminate();
}

GLFWwindow* Window::GetWindow()
{
	return m_window;
}