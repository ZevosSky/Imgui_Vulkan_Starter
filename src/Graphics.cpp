//
// Created by Gary Yang on 6/23/2025.
//

#include "Graphics.h"
#include "version.h"






void Graphics::initVulkan() {
    createInstance();
}


void Graphics::initWindow() {

    if (glfwInit() == GLFW_FALSE) {throw std::runtime_error("Failed to initialize GLFW");}

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    const uint32_t WIDTH = 800;
    const uint32_t HEIGHT = 600;

    m_window = glfwCreateWindow(WIDTH, HEIGHT, "Vulkan", nullptr, nullptr);

    if (m_window == nullptr) {
        throw std::runtime_error("Failed to create GLFW window");
    }
}

void Graphics::mainLoop() {
    while (!glfwWindowShouldClose(m_window)) {  // NOLINT(clang-tidy)
        glfwPollEvents();
    }
}
void Graphics::cleanup() {
    glfwDestroyWindow(m_window);
    glfwTerminate();
}

void Graphics::createInstance() {
VkApplicationInfo appInfo{};
    appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    appInfo.pApplicationName = "Vulkan Test";
    appInfo.applicationVersion = VK_MAKE_API_VERSION(VERSION_MAJOR, VERSION_MINOR, VERSION_PATCH, 0U);
    appInfo.pEngineName = "Pillow Fort";
    appInfo.engineVersion = VK_MAKE_API_VERSION(VERSION_MAJOR, VERSION_MINOR, VERSION_PATCH, 0U);
    // no need to set the pNext field, as we are not

    VkInstanceCreateInfo createInfo{};
    createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    createInfo.pApplicationInfo = &appInfo;




}
