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
	
	static GraphicsManager* m_instance;

	struct QueueFamilyIndices 
	{
		std::optional<uint32_t> graphicsFamily;
		std::optional<uint32_t> presentFamily;

		bool IsValid()
		{
			return graphicsFamily.has_value() && presentFamily.has_value();
		}
	};

	struct SwapChainSupportDetails
	{
		VkSurfaceCapabilitiesKHR capabilities;
		std::vector<VkSurfaceFormatKHR> formats;
		std::vector<VkPresentModeKHR> presentModes;
	};

	bool CheckVulkanExtensions();
	bool CheckDeviceExtensionSupport(VkPhysicalDevice device);
	bool CheckValidationLayers();

	void PickPhysicalDevice();
	void CreateLogicalDevice();
	bool IsDeviceSuitable(VkPhysicalDevice device);
	QueueFamilyIndices FindQueueFamilies(VkPhysicalDevice device);

	void CreateVulkanSurface();
	SwapChainSupportDetails QuerySwapChainSupport(VkPhysicalDevice device);
	
	void CreateSwapChain();
	VkSurfaceFormatKHR ChooseSwapSurfaceFormat(const std::vector<VkSurfaceFormatKHR>& availableFormats);
	VkPresentModeKHR ChooseSwapPresentMode(const std::vector<VkPresentModeKHR>& availablePresentModes);
	VkExtent2D ChooseSwapExtent(const VkSurfaceCapabilitiesKHR& capabilities);

	void CreateImageViews();

	void CreateRenderPass();

	void CreateGraphicsPipeline();
	VkShaderModule CreateShaderModule(const std::vector<char>& code);

	void CreateFramebuffers();


	VkInstance m_vkInstance; 
	VkPhysicalDevice m_phyDevice;
	VkDevice m_device;
	VkSwapchainKHR m_swapChain;
	std::vector<VkImage> m_swapChainImages;
	VkFormat m_swapChainImageFormat;
	VkExtent2D m_swapChainExtent;

	std::vector<VkImageView> m_swapChainImageViews;

	VkQueue m_graphicsQueue;
	VkQueue presentQueue;

	VkSurfaceKHR m_surface;

	VkRenderPass m_renderPass;
	VkPipelineLayout m_pipelineLayout;
	VkPipeline m_graphicsPipeline;


	std::vector<VkFramebuffer> m_swapChainFramebuffers;

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


	// Device extensions.
	const std::vector<const char*> deviceExtensions =
	{
	VK_KHR_SWAPCHAIN_EXTENSION_NAME
	};
};

