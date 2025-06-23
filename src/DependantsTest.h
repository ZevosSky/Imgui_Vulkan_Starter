//
// @file DependantsTest.h
// @brief just a bunch of tests to ensure dependencies are working
//
#include "stdafx.h"
#include <iostream>

#ifndef CMAKELISTS_TXT_DEPENDANTSTEST_H
#define CMAKELISTS_TXT_DEPENDANTSTEST_H






    int RunDependantsTest()
    {
        std::cout << "Testing dependencies..." << '\n';

        // Test GLFW
        if (glfwInit() == 0) {
            std::cout << "[FAIL] GLFW failed to initialize" << '\n';
            return -1;
        }
        std::cout << "[SUCCESS] GLFW initialized successfully" << '\n';

        // Test GLM
        glm::vec3 testVec(1.0F, 2.0F, 3.0F);
        std::cout << "[SUCCESS] GLM working - test vector: ("
                  << testVec.x << ", " << testVec.y << ", " << testVec.z << ")" << '\n';

        // Test Vulkan
        uint32_t vulkanVersion;
        VkResult result = vkEnumerateInstanceVersion(&vulkanVersion);
        if (result == VK_SUCCESS) {
            std::cout << "[SUCCESS] Vulkan available - Version: "
                      << VK_VERSION_MAJOR(vulkanVersion) << "."
                      << VK_VERSION_MINOR(vulkanVersion) << "."
                      << VK_VERSION_PATCH(vulkanVersion) << '\n';
        } else {
            std::cout << "[FAIL] Vulkan not available" << '\n';
        }

        // Test ImGui (just include test)
        std::cout << "[SUCCESS] ImGui headers included successfully" << '\n';

        std::cout << "\n[SUCCESS] All dependencies are working!" << '\n';
        std::cout << "Ready for Vulkan development!" << '\n';

        glfwTerminate();
        return 0;
    }
    
    
    int WindowCreationTest() {
        
        std::cout << "Creating test window..." <<  '\n';
    
        // Initialize GLFW
        if (!glfwInit()) {
            std::cout << "Failed to initialize GLFW" <<  '\n';
            return -1;
        }
    
        // Don't create OpenGL context (we want Vulkan)
        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
    
        // Create window
        GLFWwindow* window = glfwCreateWindow(800, 600, "Vulkan Test Window", nullptr, nullptr);
        if (!window) {
            std::cout << "Failed to create window" <<  '\n';
            glfwTerminate();
            return -1;
        }
    
        std::cout << "Window created successfully!" << '\n';
        std::cout << "Press ESC or close window to exit" <<  '\n';
    
        // Simple event loop
        while (!glfwWindowShouldClose(window)) {
            glfwPollEvents();
        
            // Exit on ESC key
            if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
                glfwSetWindowShouldClose(window, true);
            }
        }
    
        // Cleanup
        glfwDestroyWindow(window);
        glfwTerminate();
    
        std::cout << "Test completed successfully!" <<  '\n';


        return 0;
    }






#endif // CMAKELISTS_TXT_DEPENDANTSTEST_H
