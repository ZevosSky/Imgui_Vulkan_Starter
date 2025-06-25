cmake_minimum_required(VERSION 3.20)
project(vulkan-imgui-starter VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find packages
find_package(glfw3 CONFIG REQUIRED)
find_package(imgui CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)
find_package(VulkanMemoryAllocator CONFIG REQUIRED)
find_package(Vulkan REQUIRED)


# Add executable
add_executable(${PROJECT_NAME}
        src/main.cpp
        src/stdafx.h
        src/DependantsTest.h
        src/interface.cpp
        src/interface.h
        src/Graphics.cpp
        src/Graphics.h
        src/Shader.cpp
        src/Shader.h
        src/VertexShader.cpp
        src/VertexShader.h
        src/FragmentShader.cpp
        src/FragmentShader.h
        src/ComputeShader.cpp
        src/ComputeShader.h
        src/version.h

        # Add your source files here
)



# Link libraries
target_link_libraries(${PROJECT_NAME} PRIVATE
        glfw
        imgui::imgui
        glm::glm
        GPUOpen::VulkanMemoryAllocator
        Vulkan::Vulkan
)

