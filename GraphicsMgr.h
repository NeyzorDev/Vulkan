#pragma once

#include <vulkan/vulkan.h>

#define GRAPHICSMGR GraphicsManager::GetInstance()

class GraphicsManager
{
public:
	~GraphicsManager();

	GraphicsManager(GraphicsManager& other) = delete; // GraphicsManager should not be cloneable.
	void operator=(const GraphicsManager&) = delete; // GraphicsManager should not be assignable.

	static GraphicsManager* GetInstance();

	bool Initialize();
	void Shutdown();


private:
	GraphicsManager() : m_VkInstance(nullptr) {};

	static GraphicsManager* m_instance;


	VkInstance m_VkInstance;
};

