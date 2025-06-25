//
// Created by Gary Yang on 6/23/2025.
//

#include "Graphics.h"







void Graphics::initVulkan() {

    /* no opt for now */

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



