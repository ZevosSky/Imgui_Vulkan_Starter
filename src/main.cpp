/// @author Gary Yang
/// @date 6/18/2025
/// @copyright Copyright (c) 2025, Gary Yang
/// @license This project is released under the MIT License.

#include "stdafx.h"
#include "DependantsTest.h"
#include "Graphics.h"


int main() {

    // return RunDependantsTest();
    //  return WindowCreationTest();

    Graphics graphics{};

    try {
        graphics.run();
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << "\n";
        return 1;
    }


    return 0;
}