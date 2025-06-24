//
// Created by Gary Yang on 6/23/2025.
/// // @author Gary Yang
// /// @date 6/23/2025
// /// @copyright Copyright (c) 2025, Gary Yang
// /// @license This project is released under the MIT License.
// /// @description Just wrapping / turning imgui into a component-based interface
//

#include "stdafx.h"




#ifndef CMAKELISTS_TXT_INTERFACE_H
#define CMAKELISTS_TXT_INTERFACE_H

class interface {

  public:
    interface();
        // Constructor code here


    ~interface() ;


    void initialize();

    void render();

    void cleanup();

    // Add more methods as needed for the interface functionality

  private:

    GLFWwindow* window; // Pointer to the GLFW window
    ImGuiContext* imguiContext; // Pointer to the ImGui context




};

#endif // CMAKELISTS_TXT_INTERFACE_H
