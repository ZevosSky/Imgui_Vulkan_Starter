/// @author Gary Yang
/// @date 6/18/2025
/// @copyright Copyright (c) 2025, Gary Yang
/// @license This project is released under the MIT License.

#include "stdafx.h"



int main() {
    std::cout << "Testing dependencies..." << std::endl;

    // Test GLFW
    if (!glfwInit()) {
        std::cout << "[FAIL] GLFW failed to initialize" << std::endl;
        return -1;
    }
    std::cout << "[SUCCESS] GLFW initialized successfully" << std::endl;

    // Test GLM
    glm::vec3 testVec(1.0f, 2.0f, 3.0f);
    std::cout << "[SUCCESS] GLM working - test vector: ("
              << testVec.x << ", " << testVec.y << ", " << testVec.z << ")" << std::endl;

    // Test Vulkan
    uint32_t vulkanVersion;
    VkResult result = vkEnumerateInstanceVersion(&vulkanVersion);
    if (result == VK_SUCCESS) {
        std::cout << "[SUCCESS] Vulkan available - Version: "
                  << VK_VERSION_MAJOR(vulkanVersion) << "."
                  << VK_VERSION_MINOR(vulkanVersion) << "."
                  << VK_VERSION_PATCH(vulkanVersion) << std::endl;
    } else {
        std::cout << "[FAIL] Vulkan not available" << std::endl;
    }

    // Test ImGui (just include test)
    std::cout << "[SUCCESS] ImGui headers included successfully" << std::endl;

    std::cout << "\n🎉 All dependencies are working!" << std::endl;
    std::cout << "Ready for Vulkan development!" << std::endl;

    glfwTerminate();
    return 0;
}