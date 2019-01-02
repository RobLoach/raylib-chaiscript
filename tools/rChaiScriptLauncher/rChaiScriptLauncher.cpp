/*******************************************************************************************
*
*   rChaiScriptLauncher v0.0.1 - raylib ChaiScript Launcher
*
*   DEPENDENCIES:
*
*   raylib 2.0 - This program uses latest raylib version (www.raylib.com)
*   ChaiScript >= 5.x  - http://chaiscript.com
*
*   COMPILATION (GCC):
*
*     mkdir build
*     cd build
*     cmake ..
*     make
*
*   USAGE:
*
*     Just launch your raylib .lua file from command line:
*       ./rChaiScriptLauncher core_basic_window.chai
*
*     or drag & drop your .chai file over rChaiScriptLauncher.exe
*
*
*   LICENSE: zlib/libpng
*
*   Copyright (c) 2018 Rob Loach (@RobLoach)
*
*   This software is provided "as-is", without any express or implied warranty. In no event
*   will the authors be held liable for any damages arising from the use of this software.
*
*   Permission is granted to anyone to use this software for any purpose, including commercial
*   applications, and to alter it and redistribute it freely, subject to the following restrictions:
*
*     1. The origin of this software must not be misrepresented; you must not claim that you
*     wrote the original software. If you use this software in a product, an acknowledgment
*     in the product documentation would be appreciated but is not required.
*
*     2. Altered source versions must be plainly marked as such, and must not be misrepresented
*     as being the original software.
*
*     3. This notice may not be removed or altered from any source distribution.
*
********************************************************************************************/

#include "../../include/chaiscript/extras/raylib.hpp"

int main(int argc, char *argv[])
{
    if (argc > 1)
    {
        if (IsFileExtension(argv[1], ".chai"))
        {
            // Create the ChaiScript environment.
            chaiscript::ChaiScript chai;

            // Load the ChaiScript module.
            auto raylib = chaiscript::extras::raylib::bootstrap();

            // Add the library to the ChaiScript instance.
            chai.add(raylib);

            // Execute the script.
            chai.eval_file(argv[1]);
        }
    }

    return 0;
}
