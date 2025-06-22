# Imgui_Vulkan_Starter
______________________________________
In progress vulkan test bench w/ imgui







## Prerequisites

Before cloning this project, you'll need to install the following on your machine:

### 1. Visual Studio 2022 (or MinGW)
- **Visual Studio Community 2022** (recommended): Download from [visualstudio.microsoft.com](https://visualstudio.microsoft.com/)
- Make sure to install the **C++ development workload**
- Alternative: MinGW-w64 if you prefer GCC

### 2. CMake
- Download from [cmake.org](https://cmake.org/download/)
- **Important**: During installation, check "Add CMake to system PATH"
- Verify installation: Open command prompt and run `cmake --version`

### 3. Vulkan SDK
- Download from [vulkan.lunarg.com](https://vulkan.lunarg.com/sdk/home)
- Install with default settings
- This is required for Vulkan development (headers, validation layers, tools)
- Restart your computer after installation

### 4. vcpkg (Package Manager)
```bash
# Navigate to a suitable location (NOT inside your project)
cd C:\dev\

# Clone vcpkg
git clone https://github.com/Microsoft/vcpkg.git
cd vcpkg

# Bootstrap vcpkg
.\bootstrap-vcpkg.bat

# Set environment variable (optional but recommended)
setx VCPKG_ROOT "C:\dev\vcpkg"
```

______________________________________________

## Project Setup

### 1. Clone the Repository
```bash
git clone <your-repo-url>
cd Imgui_Vulkan_Starter
```

### 2. IDE Setup

#### For CLion:
1. Open the project folder in CLion
2. Go to **File → Settings → Build, Execution, Deployment → Toolchains**
3. Add/configure **Visual Studio** toolchain
4. Go to **Build, Execution, Deployment → CMake**
5. Set **Toolchain** to your Visual Studio toolchain
6. Add CMake options:
   ```
   -DCMAKE_TOOLCHAIN_FILE=C:/dev/vcpkg/scripts/buildsystems/vcpkg.cmake
   ```
   (Replace with your vcpkg path)
7. Click **OK**

#### For Visual Studio:
1. Open the folder directly in Visual Studio
2. CMake should auto-configure
3. If not, edit `CMakeSettings.json` and add:
   ```json
   {
     "configurations": [
       {
         "name": "x64-Debug",
         "generator": "Ninja",
         "configurationType": "Debug",
         "buildRoot": "${projectDir}\\out\\build\\${name}",
         "installRoot": "${projectDir}\\out\\install\\${name}",
         "cmakeCommandArgs": "-DCMAKE_TOOLCHAIN_FILE=C:/dev/vcpkg/scripts/buildsystems/vcpkg.cmake",
         "buildCommandArgs": "",
         "ctestCommandArgs": ""
       }
     ]
   }
   ```

### 3. Build the Project
1. **First build will take longer** (vcpkg downloads and compiles dependencies)
2. Click build in your IDE or run:
   ```bash
   cmake -B build -S . -DCMAKE_TOOLCHAIN_FILE=C:/dev/vcpkg/scripts/buildsystems/vcpkg.cmake
   cmake --build build --config Release
   ```

## Dependencies Managed by vcpkg

This project automatically downloads and builds:
- **GLFW3** - Window management
- **Dear ImGui** - Immediate mode GUI
- **GLM** - OpenGL Mathematics library
- **Vulkan Memory Allocator** - GPU memory management



