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

    void initWindow();

    void initVulkan();

    void mainLoop();

    void cleanup();


    GLFWwindow* m_window;



};

#endif // CMAKELISTS_TXT_GRAPHICS_H
