#include "GraphicsMgr.h"

#include <GLFW/glfw3.h>
#include <vector>
#include <iostream>
#include <stdexcept>

GraphicsManager* GraphicsManager::m_instance = nullptr;

GraphicsManager::~GraphicsManager()
{
    delete m_instance;
}

GraphicsManager* GraphicsManager::GetInstance()
{
    if (m_instance == nullptr)
    {
        m_instance = new GraphicsManager();
    }
    return m_instance;
}


bool GraphicsManager::Initialize()
{
	/*
	This data is technically optional, but it may provide some useful 
	information to the driver in order to optimize our specific application.
	*/
	VkApplicationInfo appInfo{};
	appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
	appInfo.pApplicationName = "Hello Triangle";
	appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
	appInfo.pEngineName = "No Engine";
	appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
	appInfo.apiVersion = VK_API_VERSION_1_0;

	// This tells the Vulkan driver which global extensions and validation layers we want to use.
	VkInstanceCreateInfo createInfo{};
	createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
	createInfo.pApplicationInfo = &appInfo;

	// GLFW has a handy builtin function that returns the extension(s) it needs
	uint32_t glfwExtensionCount = 0;
	const char** glfwExtensions;

	glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);
	//TODO: Remove glfw from GraphicsMgr? Can we abstract it?

	createInfo.enabledExtensionCount = glfwExtensionCount;
	createInfo.ppEnabledExtensionNames = glfwExtensions;

	// Global validation layers to enable. Leave these empty for now.
	createInfo.enabledLayerCount = 0;

	// Create an instance.
	VkResult result = vkCreateInstance(&createInfo, nullptr, &m_VkInstance);

	if (result != VK_SUCCESS)
	{
		throw std::runtime_error("Failed to create Vulkan instance!");
	}

	// Print Available Extensions.
	uint32_t extensionCount = 0;
	vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);

	std::vector<VkExtensionProperties> extensions(extensionCount);

	vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, extensions.data());

	std::cout << "Available extensions:\n";

	for (const auto& extension : extensions) {
		std::cout << " - " << extension.extensionName << '\n';
	}

	// Extensions in glfwExtensions should be in this list.
	// TODO: Check the extensions and print out the results.
    return 0;
}


void GraphicsManager::Shutdown()
{
	vkDestroyInstance(m_VkInstance, nullptr);
}