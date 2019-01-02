#ifndef CHAISCRIPT_EXTRAS_RAYLIB_HPP_
#define CHAISCRIPT_EXTRAS_RAYLIB_HPP_

#include <vector>
#include <string>

#include <chaiscript/chaiscript.hpp>

#include "raylib.h"

namespace chaiscript {
  namespace extras {
    namespace raylib {

      /**
       * Window-related functions
       */
      ModulePtr addWindow(ModulePtr m = std::make_shared<Module>()) {
        m->add(fun([](int width, int height, const std::string& title) {
          InitWindow(width, height, title.c_str());
        }), "InitWindow");
        m->add(fun(&CloseWindow), "CloseWindow");
        m->add(fun(&IsWindowReady), "IsWindowReady");
        m->add(fun(&WindowShouldClose), "WindowShouldClose");
        m->add(fun(&IsWindowMinimized), "IsWindowMinimized");
        m->add(fun(&ToggleFullscreen), "ToggleFullscreen");
        m->add(fun(&SetWindowIcon), "SetWindowIcon");
        m->add(fun([](const std::string& title) {
          SetWindowTitle(title.c_str());
        }), "SetWindowTitle");
        m->add(fun(&SetWindowPosition), "SetWindowPosition");
        m->add(fun(&SetWindowMonitor), "SetWindowMonitor");
        m->add(fun(&SetWindowMinSize), "SetWindowMinSize");
        m->add(fun(&SetWindowSize), "SetWindowSize");
        m->add(fun(&GetScreenWidth), "GetScreenWidth");
        m->add(fun(&GetScreenHeight), "GetScreenHeight");
        //void *GetWindowHandle(void);
        m->add(fun(&GetMonitorCount), "GetMonitorCount");
        m->add(fun(&GetMonitorWidth), "GetMonitorWidth");
        m->add(fun(&GetMonitorHeight), "GetMonitorHeight");
        m->add(fun(&GetMonitorPhysicalWidth), "GetMonitorPhysicalWidth");
        m->add(fun(&GetMonitorPhysicalHeight), "GetMonitorPhysicalHeight");
        m->add(fun([](int monitor) {
          return GetMonitorName(monitor);
        }), "GetMonitorName");

        return m;
      }

      /**
       * Cursor-related functions
       */
      ModulePtr addCursor(ModulePtr m = std::make_shared<Module>()) {
        m->add(fun(&ShowCursor), "ShowCursor");
        m->add(fun(&HideCursor), "HideCursor");
        m->add(fun(&IsCursorHidden), "IsCursorHidden");
        m->add(fun(&EnableCursor), "EnableCursor");
        m->add(fun(&DisableCursor), "DisableCursor");

        return m;
      }

      /**
       * Drawing-related functions
       */
      ModulePtr addDrawing(ModulePtr m = std::make_shared<Module>()) {
        m->add(fun(&ClearBackground), "ClearBackground");
        m->add(fun(&BeginDrawing), "BeginDrawing");
        m->add(fun(&EndDrawing), "EndDrawing");
        m->add(fun(&BeginMode2D), "BeginMode2D");
        m->add(fun(&EndMode2D), "EndMode2D");
        m->add(fun(&BeginMode3D), "BeginMode3D");
        m->add(fun(&EndMode3D), "EndMode3D");
        m->add(fun(&BeginTextureMode), "BeginTextureMode");
        m->add(fun(&EndTextureMode), "EndTextureMode");

        return m;
      }

      /**
       * Screen-space-related functions
       */
      ModulePtr addScreenSpace(ModulePtr m = std::make_shared<Module>()) {
        m->add(fun(&GetMouseRay), "GetMouseRay");
        m->add(fun(&GetWorldToScreen), "GetWorldToScreen");
        m->add(fun(&GetCameraMatrix), "GetCameraMatrix");

        return m;
      }

      /**
       * Time-related functions
       */
      ModulePtr addTime(ModulePtr m = std::make_shared<Module>()) {
        m->add(fun(&SetTargetFPS), "SetTargetFPS");
        m->add(fun(&GetFPS), "GetFPS");
        m->add(fun(&GetFrameTime), "GetFrameTime");
        m->add(fun(&GetTime), "GetTime");

        return m;
      }

      void addColorConst(ModulePtr m, Color color, const std::string& name) {
        const Color constcolor = color;
        m->add_global_const(const_var(constcolor), name);
      }

      /**
       * Structures Definition
       */
      ModulePtr addStructureDefinitions(ModulePtr m = std::make_shared<Module>()) {
        m->add(user_type<Vector2>(), "Vector2");
        m->add(constructor<Vector2()>(), "Vector2");
        m->add(constructor<Vector2(const Vector2 &)>(), "Vector2");
        m->add(fun(&Vector2::x), "x");
        m->add(fun(&Vector2::y), "y");

        m->add(user_type<Vector2>(), "Vector3");
        m->add(constructor<Vector3()>(), "Vector3");
        m->add(constructor<Vector3(const Vector3 &)>(), "Vector3");
        m->add(fun(&Vector3::x), "x");
        m->add(fun(&Vector3::y), "y");
        m->add(fun(&Vector3::z), "z");

        m->add(user_type<Vector4>(), "Vector4");
        m->add(constructor<Vector4()>(), "Vector4");
        m->add(constructor<Vector4(const Vector4 &)>(), "Vector4");
        m->add(fun(&Vector4::x), "x");
        m->add(fun(&Vector4::y), "y");
        m->add(fun(&Vector4::z), "z");
        m->add(fun(&Vector4::w), "w");

        m->add(user_type<Color>(), "Color");
        m->add(constructor<Color()>(), "Color");
        m->add(constructor<Color(const Color &)>(), "Color");
        m->add(fun(&Color::r), "r");
        m->add(fun(&Color::g), "g");
        m->add(fun(&Color::b), "b");
        m->add(fun(&Color::a), "a");

        // Color Constants
        addColorConst(m, LIGHTGRAY, "LIGHTGRAY");
        addColorConst(m, GRAY, "GRAY");
        addColorConst(m, DARKGRAY, "DARKGRAY");
        addColorConst(m, YELLOW, "YELLOW");
        addColorConst(m, GOLD, "GOLD");
        addColorConst(m, ORANGE, "ORANGE");
        addColorConst(m, PINK, "PINK");
        addColorConst(m, RED, "RED");
        addColorConst(m, MAROON, "MAROON");
        addColorConst(m, GREEN, "GREEN");
        addColorConst(m, LIME, "LIME");
        addColorConst(m, DARKGREEN, "DARKGREEN");
        addColorConst(m, SKYBLUE, "SKYBLUE");
        addColorConst(m, BLUE, "BLUE");
        addColorConst(m, DARKBLUE, "DARKBLUE");
        addColorConst(m, PURPLE, "PURPLE");
        addColorConst(m, VIOLET, "VIOLET");
        addColorConst(m, DARKPURPLE, "DARKPURPLE");
        addColorConst(m, BEIGE, "BEIGE");
        addColorConst(m, BROWN, "BROWN");
        addColorConst(m, DARKBROWN, "DARKBROWN");
        addColorConst(m, WHITE, "WHITE");
        addColorConst(m, BLACK, "BLACK");
        addColorConst(m, BLANK, "BLANK");
        addColorConst(m, MAGENTA, "MAGENTA");
        addColorConst(m, RAYWHITE, "RAYWHITE");

        m->add(user_type<Rectangle>(), "Rectangle");
        m->add(constructor<Rectangle()>(), "Rectangle");
        m->add(constructor<Rectangle(const Rectangle &)>(), "Rectangle");
        m->add(fun(&Rectangle::x), "x");
        m->add(fun(&Rectangle::y), "y");
        m->add(fun(&Rectangle::width), "width");
        m->add(fun(&Rectangle::height), "height");

        m->add(user_type<Image>(), "Image");
        m->add(constructor<Image()>(), "Image");
        m->add(constructor<Image(const Image &)>(), "Image");
        m->add(fun(&Image::width), "width");
        m->add(fun(&Image::height), "height");
        m->add(fun(&Image::mipmaps), "mipmaps");
        m->add(fun(&Image::format), "format");

        return m;
      }

      /**
       * Color-related functions
       */
      ModulePtr addColor(ModulePtr m = std::make_shared<Module>()) {
        m->add(fun(&ColorToInt), "ColorToInt");
        m->add(fun(&ColorNormalize), "ColorNormalize");
        m->add(fun(&ColorToHSV), "ColorToHSV");
        m->add(fun(&GetColor), "GetColor");
        m->add(fun(&Fade), "Fade");

        return m;
      }

      /**
       * Misc. functions
       */
      ModulePtr addMisc(ModulePtr m = std::make_shared<Module>()) {
        m->add(fun(&ShowLogo), "ShowLogo");
        m->add(fun(&ColorNormalize), "ColorNormalize");
        m->add(fun(&SetTraceLog), "SetTraceLog");
        m->add(fun([](const std::string& filename) {
          TakeScreenshot(filename.c_str());
        }), "TakeScreenshot");
        m->add(fun(&GetRandomValue), "GetRandomValue");

        return m;
      }

      /**
       * Text drawing functions
       */
      ModulePtr addTextDrawing(ModulePtr m = std::make_shared<Module>()) {
        m->add(fun(&DrawFPS), "DrawFPS");
        m->add(fun([](const std::string& text, int posX, int posY, int fontSize, Color color) {
          DrawText(text.c_str(), posX, posY, fontSize, color);
        }), "DrawText");

        return m;
      }

      /**
       * Bootstrap a ChaiScript module with raylib support.
       */
      ModulePtr bootstrap(ModulePtr m = std::make_shared<Module>())
      {
        addWindow(m);
        addCursor(m);
        addTime(m);
        addStructureDefinitions(m);
        addColor(m);
        addMisc(m);
        addDrawing(m);
        addScreenSpace(m);
        addTextDrawing(m);

        return m;
      }
    }
  }
}

#endif /* CHAISCRIPT_EXTRAS_RAYLIB_HPP_ */
