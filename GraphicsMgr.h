#pragma once

#include <vulkan/vulkan.h>
#include <vector>
#include <optional>

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
	GraphicsManager() : m_vkInstance(VK_NULL_HANDLE), m_phyDevice(VK_NULL_HANDLE) {};
	
	struct QueueFamilyIndices 
	{
		std::optional<uint32_t> graphicsFamily;
		bool IsValid()
		{
			return graphicsFamily.has_value();
		}
	};

	void PickPhysicalDevice();
	void CreateLogicalDevice();
	bool IsDeviceSuitable(VkPhysicalDevice device);
	QueueFamilyIndices FindQueueFamilies(VkPhysicalDevice device);

	bool CheckVulkanExtensions();
	bool CheckValidationLayers();
	
	static GraphicsManager* m_instance;


	VkInstance m_vkInstance; 
	VkPhysicalDevice m_phyDevice;
	VkDevice m_device;

	VkQueue m_graphicsQueue;

	// Validation layers.
	const std::vector<const char*> validationLayers = 
	{
	"VK_LAYER_KHRONOS_validation"
	};

#ifdef NDEBUG
	const bool enableValidationLayers = false;
#else
	const bool enableValidationLayers = true;
#endif

};

