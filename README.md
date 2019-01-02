<img src="logo/raylib_256x256.png" width=256>

# raylib-chaiscript

[ChaiScript](https://chaiscript.com) bindings for [raylib](https://www.raylib.com/), a simple and easy-to-use library to enjoy videogames programming (www.raylib.com)

raylib-chaiscript binding is self-contained in a header-only single file: [raylib.hpp](include/chaiscript/extras/raylib.hpp). Just include that file
in your project to allow loading and execution of raylib code written in ChaiScript. Check [code examples](examples) for reference.

Together with the binding, a raylib-chaiscript launcher is also provided: [rChaiScriptLauncher](tools/rChaiScriptLauncher/rChaiScriptLauncher.cpp). This launcher allows to run raylib-chaiscript
programs from command line, or just with *drag & drop* of .chai files into *rChaiScriptLauncher.exe*.

Note that launcher can also be compiled for other platforms, just need to link with ChaiScript library and raylib library. 
For more details, just check comments on [rChaiScriptLauncher.cpp](tools/rChaiScriptLauncher/rChaiScriptLauncher.cpp).

## Example

``` chaiscript
var screenWidth = 800
var screenHeight = 450
InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window")
SetTargetFPS(60)

while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(RAYWHITE)
    DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY)
    EndDrawing()
}
CloseWindow()        // Close window and OpenGL context
```

Check for more [examples](examples) organized by raylib modules.

## License

raylib-chaiscript is licensed under an unmodified zlib/libpng license, which is an OSI-certified, 
BSD-like license that allows static linking with closed source software. Check [LICENSE](LICENSE) for further details.
	
*Copyright (c) 2018 Rob Loach ([@RobLoach](https://twitter.com/RobLoach))*
