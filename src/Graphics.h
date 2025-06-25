//
// Created by Gary Yang on 6/23/2025.
//


#include "stdafx.h"

#ifndef CMAKELISTS_TXT_GRAPHICS_H
#define CMAKELISTS_TXT_GRAPHICS_H

class Graphics {

  public:



    void run() {
        initWindow();
        initVulkan();
        mainLoop();
        cleanup();
    }


  private:

    // === Methods ====
    void initWindow();

    void initVulkan();

    void mainLoop();

    void cleanup();

    void createInstance();

    // === Members ====
    GLFWwindow* m_window;
    VkInstance m_instance;



};

#endif // CMAKELISTS_TXT_GRAPHICS_H
