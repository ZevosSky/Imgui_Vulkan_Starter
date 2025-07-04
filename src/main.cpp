/// @author Gary Yang
/// @date 6/18/2025
/// @copyright Copyright (c) 2025, Gary Yang
/// @license This project is released under the MIT License.

#include "stdafx.h"
#include "DependantsTest.h"
#include "Graphics.h"
#include "SystemManager.h"

static auto g_running = true; //Clang-Tidy: NOLINT(cppcoreguidelines-avoid-non-const-global-variables)

int main() {

    // return RunDependantsTest();
    //  return WindowCreationTest();


#ifdef SYSTEMS // FOR THE FUTURE

    SystemManager sysM;

    //===| Add systems here |===

    //-- Example: sysM.addSystem<Graphics>();

    sysM.initAll();

    while (g_running) {
        sysM.updateAll();
    }

    sysM.shutdownAll();
#endif



    Graphics graphics{};

    try {
        graphics.run();
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << "\n";
        return 1;
    }


    return 0;
}