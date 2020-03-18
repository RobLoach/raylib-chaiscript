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
        m->add(fun(&InitWindow), "InitWindow");
        m->add(fun(&WindowShouldClose), "WindowShouldClose");
        m->add(fun(&CloseWindow), "CloseWindow");
        m->add(fun(&IsWindowReady), "IsWindowReady");
        m->add(fun(&IsWindowMinimized), "IsWindowMinimized");
        m->add(fun(&IsWindowResized), "IsWindowResized");
        m->add(fun(&IsWindowHidden), "IsWindowHidden");
        m->add(fun(&ToggleFullscreen), "ToggleFullscreen");
        m->add(fun(&UnhideWindow), "UnhideWindow");
        m->add(fun(&UnhideWindow), "ShowWindow");
        m->add(fun(&HideWindow), "HideWindow");
        m->add(fun(&SetWindowIcon), "SetWindowIcon");
        m->add(fun(&SetWindowTitle), "SetWindowTitle");
        m->add(fun(&SetWindowPosition), "SetWindowPosition");
        m->add(fun(&SetWindowMonitor), "SetWindowMonitor");
        m->add(fun(&SetWindowMinSize), "SetWindowMinSize");
        m->add(fun(&SetWindowSize), "SetWindowSize");
        //void *GetWindowHandle(void);
        m->add(fun(&GetScreenWidth), "GetScreenWidth");
        m->add(fun(&GetScreenHeight), "GetScreenHeight");
        m->add(fun(&GetMonitorCount), "GetMonitorCount");
        m->add(fun(&GetMonitorWidth), "GetMonitorWidth");
        m->add(fun(&GetMonitorHeight), "GetMonitorHeight");
        m->add(fun(&GetMonitorPhysicalWidth), "GetMonitorPhysicalWidth");
        m->add(fun(&GetMonitorPhysicalHeight), "GetMonitorPhysicalHeight");
        m->add(fun(&GetMonitorName), "GetMonitorName");
        m->add(fun(&GetClipboardText), "GetClipboardText");
        m->add(fun(&SetClipboardText), "SetClipboardText");

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

      inline void addColorConst(ModulePtr m, Color color, const std::string& name) {
        const Color constcolor = color;
        m->add_global_const(const_var(constcolor), name);
      }

      /**
       * Structures Definition
       */
      ModulePtr addStructureDefinitions(ModulePtr m = std::make_shared<Module>()) {
        // TODO: Add a helpful constructor for each object.
        m->add(user_type<Vector2>(), "Vector2");
        m->add(constructor<Vector2()>(), "Vector2");
        m->add(constructor<Vector2(const Vector2 &)>(), "Vector2");
        m->add(fun([](float x, float y) {
            return Vector2{x, y};
        }), "Vector2");
        m->add(fun(&Vector2::x), "x");
        m->add(fun(&Vector2::y), "y");

        m->add(user_type<Vector2>(), "Vector3");
        m->add(constructor<Vector3()>(), "Vector3");
        m->add(constructor<Vector3(const Vector3 &)>(), "Vector3");
        m->add(fun([](float x, float y, float z) {
            return Vector3{x, y, z};
        }), "Vector3");
        m->add(fun(&Vector3::x), "x");
        m->add(fun(&Vector3::y), "y");
        m->add(fun(&Vector3::z), "z");

        m->add(user_type<Vector4>(), "Vector4");
        m->add(constructor<Vector4()>(), "Vector4");
        m->add(constructor<Vector4(const Vector4 &)>(), "Vector4");
        m->add(fun([](float x, float y, float z, float w) {
            return Vector4{x, y, z, w};
        }), "Vector4");
        m->add(fun(&Vector4::x), "x");
        m->add(fun(&Vector4::y), "y");
        m->add(fun(&Vector4::z), "z");
        m->add(fun(&Vector4::w), "w");

        m->add(user_type<Matrix>(), "Matrix");
        m->add(constructor<Matrix()>(), "Matrix");
        m->add(constructor<Matrix(const Matrix &)>(), "Matrix");
        m->add(fun([](
            float m0, float m4, float m8, float m12,
            float m1, float m5, float m9, float m13,
            float m2, float m6, float m10, float m14,
            float m3, float m7, float m11, float m15) {
            return Matrix{
                m0, m4, m8, m12,
                m1, m5, m9, m13,
                m2, m6, m10, m14,
                m3, m7, m11, m15
            };
        }), "Matrix");
        m->add(fun(&Matrix::m0), "m0");
        m->add(fun(&Matrix::m1), "m1");
        m->add(fun(&Matrix::m2), "m2");
        m->add(fun(&Matrix::m3), "m3");
        m->add(fun(&Matrix::m4), "m4");
        m->add(fun(&Matrix::m5), "m5");
        m->add(fun(&Matrix::m6), "m6");
        m->add(fun(&Matrix::m7), "m7");
        m->add(fun(&Matrix::m8), "m8");
        m->add(fun(&Matrix::m9), "m9");
        m->add(fun(&Matrix::m10), "m10");
        m->add(fun(&Matrix::m11), "m11");
        m->add(fun(&Matrix::m12), "m12");
        m->add(fun(&Matrix::m13), "m13");
        m->add(fun(&Matrix::m14), "m14");
        m->add(fun(&Matrix::m15), "m15");

        m->add(user_type<Color>(), "Color");
        m->add(constructor<Color()>(), "Color");
        m->add(constructor<Color(const Color &)>(), "Color");
        m->add(fun([](unsigned char r, unsigned char g, unsigned char b, unsigned char a) {
            return Color{r, g, b, a};
        }), "Color");
        m->add(fun([](unsigned char r, unsigned char g, unsigned char b) {
            return Color{r, g, b, 255};
        }), "Color");
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
        m->add(fun([](float x, float y, float width, float height) {
            return Rectangle{x, y, width, height};
        }), "Rectangle");
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

        m->add(user_type<Texture>(), "Texture");
        m->add(constructor<Texture()>(), "Texture");
        m->add(constructor<Texture(const Texture &)>(), "Texture");
        m->add(fun(&Texture::id), "id");
        m->add(fun(&Texture::width), "width");
        m->add(fun(&Texture::height), "height");
        m->add(fun(&Texture::mipmaps), "mipmaps");
        m->add(fun(&Texture::format), "format");

        m->add(user_type<RenderTexture>(), "RenderTexture");
        m->add(constructor<RenderTexture()>(), "RenderTexture");
        m->add(constructor<RenderTexture(const RenderTexture &)>(), "RenderTexture");
        m->add(fun(&RenderTexture::id), "id");
        m->add(fun(&RenderTexture::texture), "texture");
        m->add(fun(&RenderTexture::depth), "depth");

        m->add(user_type<NPatchInfo>(), "NPatchInfo");
        m->add(constructor<NPatchInfo()>(), "NPatchInfo");
        m->add(constructor<NPatchInfo(const NPatchInfo &)>(), "NPatchInfo");
        m->add(fun(&NPatchInfo::sourceRec), "sourceRec");
        m->add(fun(&NPatchInfo::left), "left");
        m->add(fun(&NPatchInfo::top), "top");
        m->add(fun(&NPatchInfo::right), "right");
        m->add(fun(&NPatchInfo::bottom), "bottom");
        m->add(fun(&NPatchInfo::type), "type");

        m->add(user_type<CharInfo>(), "CharInfo");
        m->add(constructor<CharInfo()>(), "CharInfo");
        m->add(constructor<CharInfo(const CharInfo &)>(), "CharInfo");
        m->add(fun(&CharInfo::value), "value");
        m->add(fun(&CharInfo::offsetX), "offsetX");
        m->add(fun(&CharInfo::offsetY), "offsetY");
        m->add(fun(&CharInfo::advanceX), "advanceX");
        m->add(fun(&CharInfo::image), "image");

        m->add(user_type<Font>(), "Font");
        m->add(constructor<Font()>(), "Font");
        m->add(constructor<Font(const Font &)>(), "Font");
        m->add(fun(&Font::texture), "texture");
        m->add(fun(&Font::baseSize), "baseSize");
        m->add(fun(&Font::charsCount), "charsCount");
        m->add(fun(&Font::chars), "chars");

        m->add(user_type<Camera3D>(), "Camera3D");
        m->add(constructor<Camera3D()>(), "Camera3D");
        m->add(constructor<Camera3D(const Camera3D &)>(), "Camera3D");
        m->add(fun(&Camera3D::position), "position");
        m->add(fun(&Camera3D::target), "target");
        m->add(fun(&Camera3D::up), "up");
        m->add(fun(&Camera3D::fovy), "fovy");
        m->add(fun(&Camera3D::type), "type");

        m->add(user_type<Camera>(), "Camera");
        m->add(constructor<Camera()>(), "Camera");
        m->add(constructor<Camera(const Camera &)>(), "Camera");
        m->add(fun(&Camera::position), "position");
        m->add(fun(&Camera::target), "target");
        m->add(fun(&Camera::up), "up");
        m->add(fun(&Camera::fovy), "fovy");
        m->add(fun(&Camera::type), "type");

        m->add(user_type<Camera2D>(), "Camera2D");
        m->add(constructor<Camera2D()>(), "Camera2D");
        m->add(constructor<Camera2D(const Camera2D &)>(), "Camera2D");
        m->add(fun(&Camera2D::offset), "offset");
        m->add(fun(&Camera2D::target), "target");
        m->add(fun(&Camera2D::rotation), "rotation");
        m->add(fun(&Camera2D::zoom), "zoom");

        // TODO: Add Mesh, Shader, Material, Model, RayHitInfo

        m->add(user_type<MaterialMap>(), "MaterialMap");
        m->add(constructor<MaterialMap()>(), "MaterialMap");
        m->add(constructor<MaterialMap(const MaterialMap &)>(), "MaterialMap");
        m->add(fun(&MaterialMap::texture), "texture");
        m->add(fun(&MaterialMap::color), "color");
        m->add(fun(&MaterialMap::value), "value");

        m->add(user_type<Ray>(), "Ray");
        m->add(constructor<Ray()>(), "Ray");
        m->add(constructor<Ray(const Ray &)>(), "Ray");
        m->add(fun(&Ray::position), "position");
        m->add(fun(&Ray::direction), "direction");

        m->add(user_type<BoundingBox>(), "BoundingBox");
        m->add(constructor<BoundingBox()>(), "BoundingBox");
        m->add(constructor<BoundingBox(const BoundingBox &)>(), "BoundingBox");
        m->add(fun(&BoundingBox::min), "min");
        m->add(fun(&BoundingBox::max), "max");

        m->add(user_type<Wave>(), "Wave");
        m->add(constructor<Wave()>(), "Wave");
        m->add(constructor<Wave(const Wave &)>(), "Wave");
        m->add(fun(&Wave::sampleCount), "sampleCount");
        m->add(fun(&Wave::sampleRate), "sampleRate");
        m->add(fun(&Wave::sampleSize), "sampleSize");
        m->add(fun(&Wave::channels), "channels");

        m->add(user_type<Sound>(), "Sound");
        m->add(constructor<Sound()>(), "Sound");
        m->add(constructor<Sound(const Sound &)>(), "Sound");
        m->add(fun(&Sound::sampleCount), "sampleCount");
        m->add(fun(&Sound::stream), "stream");

        m->add(user_type<AudioStream>(), "AudioStream");
        m->add(constructor<AudioStream()>(), "AudioStream");
        m->add(constructor<AudioStream(const AudioStream &)>(), "AudioStream");
        m->add(fun(&AudioStream::sampleRate), "sampleRate");
        m->add(fun(&AudioStream::sampleSize), "sampleSize");
        m->add(fun(&AudioStream::channels), "channels");

        m->add(user_type<VrDeviceInfo>(), "VrDeviceInfo");
        m->add(constructor<VrDeviceInfo()>(), "VrDeviceInfo");
        m->add(constructor<VrDeviceInfo(const VrDeviceInfo &)>(), "VrDeviceInfo");
        m->add(fun(&VrDeviceInfo::hResolution), "hResolution");
        m->add(fun(&VrDeviceInfo::vResolution), "vResolution");
        m->add(fun(&VrDeviceInfo::hScreenSize), "hScreenSize");
        m->add(fun(&VrDeviceInfo::vScreenSize), "vScreenSize");
        m->add(fun(&VrDeviceInfo::vScreenCenter), "vScreenCenter");
        m->add(fun(&VrDeviceInfo::eyeToScreenDistance), "eyeToScreenDistance");
        m->add(fun(&VrDeviceInfo::lensSeparationDistance), "lensSeparationDistance");
        m->add(fun(&VrDeviceInfo::interpupillaryDistance), "interpupillaryDistance");
        m->add(fun(&VrDeviceInfo::lensDistortionValues), "lensDistortionValues");
        m->add(fun(&VrDeviceInfo::chromaAbCorrection), "chromaAbCorrection");

        return m;
      }

      inline void addConst(ModulePtr m, const int val, const std::string& name) {
        m->add_global_const(const_var(val), name);
      }

      ModulePtr addEnums(ModulePtr m = std::make_shared<Module>()) {
        // System config flags
        addConst(m, FLAG_RESERVED, "FLAG_RESERVED");
        addConst(m, FLAG_FULLSCREEN_MODE, "FLAG_FULLSCREEN_MODE");
        addConst(m, FLAG_WINDOW_RESIZABLE, "FLAG_WINDOW_RESIZABLE");
        addConst(m, FLAG_WINDOW_UNDECORATED, "FLAG_WINDOW_UNDECORATED");
        addConst(m, FLAG_WINDOW_TRANSPARENT, "FLAG_WINDOW_TRANSPARENT");
        addConst(m, FLAG_WINDOW_HIDDEN, "FLAG_WINDOW_HIDDEN");
        addConst(m, FLAG_WINDOW_ALWAYS_RUN, "FLAG_WINDOW_ALWAYS_RUN");
        addConst(m, FLAG_MSAA_4X_HINT, "FLAG_MSAA_4X_HINT");
        addConst(m, FLAG_VSYNC_HINT, "FLAG_VSYNC_HINT");

        // Trace log type
        addConst(m, LOG_ALL, "LOG_ALL");
        addConst(m, LOG_TRACE, "LOG_TRACE");
        addConst(m, LOG_DEBUG, "LOG_DEBUG");
        addConst(m, LOG_INFO, "LOG_INFO");
        addConst(m, LOG_WARNING, "LOG_WARNING");
        addConst(m, LOG_ERROR, "LOG_ERROR");
        addConst(m, LOG_FATAL, "LOG_FATAL");
        addConst(m, LOG_NONE, "LOG_NONE");

        // Keyboard keys
        addConst(m, KEY_APOSTROPHE, "KEY_APOSTROPHE");
        addConst(m, KEY_COMMA, "KEY_COMMA");
        addConst(m, KEY_MINUS, "KEY_MINUS");
        addConst(m, KEY_PERIOD, "KEY_PERIOD");
        addConst(m, KEY_SLASH, "KEY_SLASH");
        addConst(m, KEY_ZERO, "KEY_ZERO");
        addConst(m, KEY_ONE, "KEY_ONE");
        addConst(m, KEY_TWO, "KEY_TWO");
        addConst(m, KEY_THREE, "KEY_THREE");
        addConst(m, KEY_FOUR, "KEY_FOUR");
        addConst(m, KEY_FIVE, "KEY_FIVE");
        addConst(m, KEY_SIX, "KEY_SIX");
        addConst(m, KEY_SEVEN, "KEY_SEVEN");
        addConst(m, KEY_EIGHT, "KEY_EIGHT");
        addConst(m, KEY_NINE, "KEY_NINE");
        addConst(m, KEY_SEMICOLON, "KEY_SEMICOLON");
        addConst(m, KEY_EQUAL, "KEY_EQUAL");
        addConst(m, KEY_A, "KEY_A");
        addConst(m, KEY_B, "KEY_B");
        addConst(m, KEY_C, "KEY_C");
        addConst(m, KEY_D, "KEY_D");
        addConst(m, KEY_E, "KEY_E");
        addConst(m, KEY_F, "KEY_F");
        addConst(m, KEY_G, "KEY_G");
        addConst(m, KEY_H, "KEY_H");
        addConst(m, KEY_I, "KEY_I");
        addConst(m, KEY_J, "KEY_J");
        addConst(m, KEY_K, "KEY_K");
        addConst(m, KEY_L, "KEY_L");
        addConst(m, KEY_M, "KEY_M");
        addConst(m, KEY_N, "KEY_N");
        addConst(m, KEY_O, "KEY_O");
        addConst(m, KEY_P, "KEY_P");
        addConst(m, KEY_Q, "KEY_Q");
        addConst(m, KEY_R, "KEY_R");
        addConst(m, KEY_S, "KEY_S");
        addConst(m, KEY_T, "KEY_T");
        addConst(m, KEY_U, "KEY_U");
        addConst(m, KEY_V, "KEY_V");
        addConst(m, KEY_W, "KEY_W");
        addConst(m, KEY_X, "KEY_X");
        addConst(m, KEY_Y, "KEY_Y");
        addConst(m, KEY_Z, "KEY_Z");

        // Function keys
        addConst(m, KEY_SPACE, "KEY_SPACE");
        addConst(m, KEY_ESCAPE, "KEY_ESCAPE");
        addConst(m, KEY_ENTER, "KEY_ENTER");
        addConst(m, KEY_TAB, "KEY_TAB");
        addConst(m, KEY_BACKSPACE, "KEY_BACKSPACE");
        addConst(m, KEY_INSERT, "KEY_INSERT");
        addConst(m, KEY_DELETE, "KEY_DELETE");
        addConst(m, KEY_RIGHT, "KEY_RIGHT");
        addConst(m, KEY_LEFT, "KEY_LEFT");
        addConst(m, KEY_DOWN, "KEY_DOWN");
        addConst(m, KEY_UP, "KEY_UP");
        addConst(m, KEY_PAGE_UP, "KEY_PAGE_UP");
        addConst(m, KEY_PAGE_DOWN, "KEY_PAGE_DOWN");
        addConst(m, KEY_HOME, "KEY_HOME");
        addConst(m, KEY_END, "KEY_END");
        addConst(m, KEY_CAPS_LOCK, "KEY_CAPS_LOCK");
        addConst(m, KEY_SCROLL_LOCK, "KEY_SCROLL_LOCK");
        addConst(m, KEY_NUM_LOCK, "KEY_NUM_LOCK");
        addConst(m, KEY_PRINT_SCREEN, "KEY_PRINT_SCREEN");
        addConst(m, KEY_PAUSE, "KEY_PAUSE");
        addConst(m, KEY_F1, "KEY_F1");
        addConst(m, KEY_F2, "KEY_F2");
        addConst(m, KEY_F3, "KEY_F3");
        addConst(m, KEY_F4, "KEY_F4");
        addConst(m, KEY_F5, "KEY_F5");
        addConst(m, KEY_F6, "KEY_F6");
        addConst(m, KEY_F7, "KEY_F7");
        addConst(m, KEY_F8, "KEY_F8");
        addConst(m, KEY_F9, "KEY_F9");
        addConst(m, KEY_F10, "KEY_F10");
        addConst(m, KEY_F11, "KEY_F11");
        addConst(m, KEY_F12, "KEY_F12");
        addConst(m, KEY_LEFT_SHIFT, "KEY_LEFT_SHIFT");
        addConst(m, KEY_LEFT_CONTROL, "KEY_LEFT_CONTROL");
        addConst(m, KEY_LEFT_ALT, "KEY_LEFT_ALT");
        addConst(m, KEY_LEFT_SUPER, "KEY_LEFT_SUPER");
        addConst(m, KEY_RIGHT_SHIFT, "KEY_RIGHT_SHIFT");
        addConst(m, KEY_RIGHT_CONTROL, "KEY_RIGHT_CONTROL");
        addConst(m, KEY_RIGHT_ALT, "KEY_RIGHT_ALT");
        addConst(m, KEY_RIGHT_SUPER, "KEY_RIGHT_SUPER");
        addConst(m, KEY_KB_MENU, "KEY_KB_MENU");
        addConst(m, KEY_LEFT_BRACKET, "KEY_LEFT_BRACKET");
        addConst(m, KEY_BACKSLASH, "KEY_BACKSLASH");
        addConst(m, KEY_RIGHT_BRACKET, "KEY_RIGHT_BRACKET");
        addConst(m, KEY_GRAVE, "KEY_GRAVE");

        // Keypad keys
        addConst(m, KEY_KP_0, "KEY_KP_0");
        addConst(m, KEY_KP_1, "KEY_KP_1");
        addConst(m, KEY_KP_2, "KEY_KP_2");
        addConst(m, KEY_KP_3, "KEY_KP_3");
        addConst(m, KEY_KP_4, "KEY_KP_4");
        addConst(m, KEY_KP_5, "KEY_KP_5");
        addConst(m, KEY_KP_6, "KEY_KP_6");
        addConst(m, KEY_KP_7, "KEY_KP_7");
        addConst(m, KEY_KP_8, "KEY_KP_8");
        addConst(m, KEY_KP_9, "KEY_KP_9");
        addConst(m, KEY_KP_DECIMAL, "KEY_KP_DECIMAL");
        addConst(m, KEY_KP_DIVIDE, "KEY_KP_DIVIDE");
        addConst(m, KEY_KP_MULTIPLY, "KEY_KP_MULTIPLY");
        addConst(m, KEY_KP_SUBTRACT, "KEY_KP_SUBTRACT");
        addConst(m, KEY_KP_ADD, "KEY_KP_ADD");
        addConst(m, KEY_KP_ENTER, "KEY_KP_ENTER");
        addConst(m, KEY_KP_EQUAL, "KEY_KP_EQUAL");

        // Android buttons
        addConst(m, KEY_BACK, "KEY_BACK");
        addConst(m, KEY_MENU, "KEY_MENU");
        addConst(m, KEY_VOLUME_UP, "KEY_VOLUME_UP");
        addConst(m, KEY_VOLUME_DOWN, "KEY_VOLUME_DOWN");

        // Mouse buttons
        addConst(m, MOUSE_LEFT_BUTTON, "MOUSE_LEFT_BUTTON");
        addConst(m, MOUSE_RIGHT_BUTTON, "MOUSE_RIGHT_BUTTON");
        addConst(m, MOUSE_MIDDLE_BUTTON, "MOUSE_MIDDLE_BUTTON");

        // Gamepad number
        addConst(m, GAMEPAD_PLAYER1, "GAMEPAD_PLAYER1");
        addConst(m, GAMEPAD_PLAYER2, "GAMEPAD_PLAYER2");
        addConst(m, GAMEPAD_PLAYER3, "GAMEPAD_PLAYER3");
        addConst(m, GAMEPAD_PLAYER4, "GAMEPAD_PLAYER4");

        // GamepadButton
        addConst(m, GAMEPAD_BUTTON_UNKNOWN, "GAMEPAD_BUTTON_UNKNOWN");
        addConst(m, GAMEPAD_BUTTON_LEFT_FACE_UP, "GAMEPAD_BUTTON_LEFT_FACE_UP");
        addConst(m, GAMEPAD_BUTTON_LEFT_FACE_RIGHT, "GAMEPAD_BUTTON_LEFT_FACE_RIGHT");
        addConst(m, GAMEPAD_BUTTON_LEFT_FACE_DOWN, "GAMEPAD_BUTTON_LEFT_FACE_DOWN");
        addConst(m, GAMEPAD_BUTTON_LEFT_FACE_LEFT, "GAMEPAD_BUTTON_LEFT_FACE_LEFT");
        addConst(m, GAMEPAD_BUTTON_RIGHT_FACE_UP, "GAMEPAD_BUTTON_RIGHT_FACE_UP");
        addConst(m, GAMEPAD_BUTTON_RIGHT_FACE_RIGHT, "GAMEPAD_BUTTON_RIGHT_FACE_RIGHT");
        addConst(m, GAMEPAD_BUTTON_RIGHT_FACE_DOWN, "GAMEPAD_BUTTON_RIGHT_FACE_DOWN");
        addConst(m, GAMEPAD_BUTTON_RIGHT_FACE_LEFT, "GAMEPAD_BUTTON_RIGHT_FACE_LEFT");
        addConst(m, GAMEPAD_BUTTON_LEFT_TRIGGER_1, "GAMEPAD_BUTTON_LEFT_TRIGGER_1");
        addConst(m, GAMEPAD_BUTTON_LEFT_TRIGGER_2, "GAMEPAD_BUTTON_LEFT_TRIGGER_2");
        addConst(m, GAMEPAD_BUTTON_RIGHT_TRIGGER_1, "GAMEPAD_BUTTON_RIGHT_TRIGGER_1");
        addConst(m, GAMEPAD_BUTTON_RIGHT_TRIGGER_2, "GAMEPAD_BUTTON_RIGHT_TRIGGER_2");
        addConst(m, GAMEPAD_BUTTON_MIDDLE_LEFT, "GAMEPAD_BUTTON_MIDDLE_LEFT");
        addConst(m, GAMEPAD_BUTTON_MIDDLE, "GAMEPAD_BUTTON_MIDDLE");
        addConst(m, GAMEPAD_BUTTON_MIDDLE_RIGHT, "GAMEPAD_BUTTON_MIDDLE_RIGHT");
        addConst(m, GAMEPAD_BUTTON_LEFT_THUMB, "GAMEPAD_BUTTON_LEFT_THUMB");
        addConst(m, GAMEPAD_BUTTON_RIGHT_THUMB, "GAMEPAD_BUTTON_RIGHT_THUMB");

        // GamepadAxis
        addConst(m, GAMEPAD_AXIS_UNKNOWN, "GAMEPAD_AXIS_UNKNOWN");
        addConst(m, GAMEPAD_AXIS_LEFT_X, "GAMEPAD_AXIS_LEFT_X");
        addConst(m, GAMEPAD_AXIS_LEFT_Y, "GAMEPAD_AXIS_LEFT_Y");
        addConst(m, GAMEPAD_AXIS_RIGHT_X, "GAMEPAD_AXIS_RIGHT_X");
        addConst(m, GAMEPAD_AXIS_RIGHT_Y, "GAMEPAD_AXIS_RIGHT_Y");
        addConst(m, GAMEPAD_AXIS_LEFT_TRIGGER, "GAMEPAD_AXIS_LEFT_TRIGGER");
        addConst(m, GAMEPAD_AXIS_RIGHT_TRIGGER, "GAMEPAD_AXIS_RIGHT_TRIGGER");

        // TODO: Add ShaderUniformDataType, MaterialMapType, TexmapIndex, PixelFormat, TextureFilterMode.

        // ShaderLocationIndex
        addConst(m, LOC_VERTEX_POSITION, "LOC_VERTEX_POSITION");
        addConst(m, LOC_VERTEX_TEXCOORD01, "LOC_VERTEX_TEXCOORD01");
        addConst(m, LOC_VERTEX_TEXCOORD02, "LOC_VERTEX_TEXCOORD02");
        addConst(m, LOC_VERTEX_NORMAL, "LOC_VERTEX_NORMAL");
        addConst(m, LOC_VERTEX_TANGENT, "LOC_VERTEX_TANGENT");
        addConst(m, LOC_VERTEX_COLOR, "LOC_VERTEX_COLOR");
        addConst(m, LOC_MATRIX_MVP, "LOC_MATRIX_MVP");
        addConst(m, LOC_MATRIX_MODEL, "LOC_MATRIX_MODEL");
        addConst(m, LOC_MATRIX_VIEW, "LOC_MATRIX_VIEW");
        addConst(m, LOC_MATRIX_PROJECTION, "LOC_MATRIX_PROJECTION");
        addConst(m, LOC_VECTOR_VIEW, "LOC_VECTOR_VIEW");
        addConst(m, LOC_COLOR_DIFFUSE, "LOC_COLOR_DIFFUSE");
        addConst(m, LOC_COLOR_SPECULAR, "LOC_COLOR_SPECULAR");
        addConst(m, LOC_COLOR_AMBIENT, "LOC_COLOR_AMBIENT");
        addConst(m, LOC_MAP_ALBEDO, "LOC_MAP_ALBEDO");
        addConst(m, LOC_MAP_METALNESS, "LOC_MAP_METALNESS");
        addConst(m, LOC_MAP_NORMAL, "LOC_MAP_NORMAL");
        addConst(m, LOC_MAP_ROUGHNESS, "LOC_MAP_ROUGHNESS");
        addConst(m, LOC_MAP_OCCLUSION, "LOC_MAP_OCCLUSION");
        addConst(m, LOC_MAP_EMISSION, "LOC_MAP_EMISSION");
        addConst(m, LOC_MAP_HEIGHT, "LOC_MAP_HEIGHT");
        addConst(m, LOC_MAP_CUBEMAP, "LOC_MAP_CUBEMAP");
        addConst(m, LOC_MAP_IRRADIANCE, "LOC_MAP_IRRADIANCE");
        addConst(m, LOC_MAP_PREFILTER, "LOC_MAP_PREFILTER");
        addConst(m, LOC_MAP_BRDF, "LOC_MAP_BRDF");
        addConst(m, LOC_MAP_DIFFUSE, "LOC_MAP_DIFFUSE");
        addConst(m, LOC_MAP_SPECULAR, "LOC_MAP_SPECULAR");

        // Texture parameters: wrap mode
        addConst(m, WRAP_REPEAT, "WRAP_REPEAT");
        addConst(m, WRAP_CLAMP, "WRAP_CLAMP");
        addConst(m, WRAP_MIRROR_REPEAT, "WRAP_MIRROR_REPEAT");
        addConst(m, WRAP_MIRROR_CLAMP, "WRAP_MIRROR_CLAMP");

        // Font type, defines generation method
        addConst(m, FONT_DEFAULT, "FONT_DEFAULT");
        addConst(m, FONT_BITMAP, "FONT_BITMAP");
        addConst(m, FONT_SDF, "FONT_SDF");

        // Color blending modes (pre-defined)
        addConst(m, BLEND_ALPHA, "BLEND_ALPHA");
        addConst(m, BLEND_ADDITIVE, "BLEND_ADDITIVE");
        addConst(m, BLEND_MULTIPLIED, "BLEND_MULTIPLIED");

        // Gestures type
        addConst(m, GESTURE_NONE, "GESTURE_NONE");
        addConst(m, GESTURE_TAP, "GESTURE_TAP");
        addConst(m, GESTURE_DOUBLETAP, "GESTURE_DOUBLETAP");
        addConst(m, GESTURE_HOLD, "GESTURE_HOLD");
        addConst(m, GESTURE_DRAG, "GESTURE_DRAG");
        addConst(m, GESTURE_SWIPE_RIGHT, "GESTURE_SWIPE_RIGHT");
        addConst(m, GESTURE_SWIPE_LEFT, "GESTURE_SWIPE_LEFT");
        addConst(m, GESTURE_SWIPE_UP, "GESTURE_SWIPE_UP");
        addConst(m, GESTURE_SWIPE_DOWN, "GESTURE_SWIPE_DOWN");
        addConst(m, GESTURE_PINCH_IN, "GESTURE_PINCH_IN");
        addConst(m, GESTURE_PINCH_OUT, "GESTURE_PINCH_OUT");

        // Camera system modes
        addConst(m, CAMERA_CUSTOM, "CAMERA_CUSTOM");
        addConst(m, CAMERA_FREE, "CAMERA_FREE");
        addConst(m, CAMERA_ORBITAL, "CAMERA_ORBITAL");
        addConst(m, CAMERA_FIRST_PERSON, "CAMERA_FIRST_PERSON");
        addConst(m, CAMERA_THIRD_PERSON, "CAMERA_THIRD_PERSON");

        // Camera projection modes
        addConst(m, CAMERA_PERSPECTIVE, "CAMERA_PERSPECTIVE");
        addConst(m, CAMERA_ORTHOGRAPHIC, "CAMERA_ORTHOGRAPHIC");

        // Type of n-patch
        addConst(m, NPT_9PATCH, "NPT_9PATCH");
        addConst(m, NPT_3PATCH_VERTICAL, "NPT_3PATCH_VERTICAL");
        addConst(m, NPT_3PATCH_HORIZONTAL, "NPT_3PATCH_HORIZONTAL");

        return m;
      }

      /**
       * Color-related functions
       */
      ModulePtr addColor(ModulePtr m = std::make_shared<Module>()) {
        m->add(fun(&ColorToInt), "ColorToInt");
        m->add(fun(&ColorNormalize), "ColorNormalize");
        m->add(fun(&ColorToHSV), "ColorToHSV");
        m->add(fun(&ColorFromHSV), "ColorFromHSV");
        m->add(fun(&GetColor), "GetColor");
        m->add(fun(&Fade), "Fade");

        return m;
      }

      /**
       * Misc. functions
       */
      ModulePtr addMisc(ModulePtr m = std::make_shared<Module>()) {
        m->add(fun(&SetConfigFlags), "SetConfigFlags");
        m->add(fun(&SetTraceLogLevel), "SetTraceLogLevel");
        m->add(fun(&SetTraceLogExit), "SetTraceLogExit");
        // TODO: Fix SetTraceLogCallback and TraceLog
        //m->add(fun(&SetTraceLogCallback), "SetTraceLogCallback");
        //m->add(fun(&TraceLog), "TraceLog");
        m->add(fun(&TakeScreenshot), "TakeScreenshot");
        m->add(fun(&GetRandomValue), "GetRandomValue");

        return m;
      }

      /**
       * Files management functions
       */
      ModulePtr addFilesManagement(ModulePtr m = std::make_shared<Module>()) {
        m->add(fun(&LoadFileData), "LoadFileData");
        m->add(fun(&SaveFileData), "SaveFileData");
        m->add(fun(&LoadFileText), "LoadFileText");
        m->add(fun(&SaveFileText), "SaveFileText");
        m->add(fun(&FileExists), "FileExists");
        m->add(fun(&IsFileExtension), "IsFileExtension");
        m->add(fun(&DirectoryExists), "DirectoryExists");
        m->add(fun(&GetExtension), "GetExtension");
        m->add(fun(&GetFileName), "GetFileName");
        m->add(fun(&GetFileNameWithoutExt), "GetFileNameWithoutExt");
        m->add(fun(&GetDirectoryPath), "GetDirectoryPath");
        m->add(fun(&GetPrevDirectoryPath), "GetPrevDirectoryPath");
        m->add(fun(&GetWorkingDirectory), "GetWorkingDirectory");
        // TODO: Add GetDirectoryFiles
        // RLAPI char **GetDirectoryFiles(const char *dirPath, int *count);  // Get filenames in a directory path (memory should be freed)
        m->add(fun(&ClearDirectoryFiles), "ClearDirectoryFiles");
        m->add(fun(&ChangeDirectory), "ChangeDirectory");
        m->add(fun(&IsFileDropped), "IsFileDropped");
        // TODO: Add GetDroppedFiles
        // RLAPI char **GetDroppedFiles(int *count);                         // Get dropped files names (memory should be freed)
        m->add(fun(&ClearDroppedFiles), "ClearDroppedFiles");
        m->add(fun(&GetFileModTime), "GetFileModTime");

        m->add(fun(&CompressData), "CompressData");
        m->add(fun(&DecompressData), "DecompressData");

        m->add(fun(&LoadText), "LoadText");
        return m;
      }

      /**
       * Persistent storage management
       */
      ModulePtr addPersistentStorage(ModulePtr m = std::make_shared<Module>()) {
        m->add(fun(&SaveStorageValue), "SaveStorageValue");
        m->add(fun(&LoadStorageValue), "LoadStorageValue");
        m->add(fun(&OpenURL), "OpenURL");

        return m;
      }

      /**
       * Input-related functions: keyboard
       */
      ModulePtr addInputRelatedFunctionsKeyboard(ModulePtr m = std::make_shared<Module>()) {
        m->add(fun(&IsKeyPressed), "IsKeyPressed");
        m->add(fun(&IsKeyDown), "IsKeyDown");
        m->add(fun(&IsKeyReleased), "IsKeyReleased");
        m->add(fun(&IsKeyUp), "IsKeyUp");
        m->add(fun(&SetExitKey), "SetExitKey");
        m->add(fun(&GetKeyPressed), "GetKeyPressed");

        return m;
      }

      /**
       * Input-related functions: gamepads
       */
      ModulePtr addInputRelatedFunctionsGamepads(ModulePtr m = std::make_shared<Module>()) {
        m->add(fun(&IsGamepadAvailable), "IsGamepadAvailable");
        m->add(fun(&IsGamepadName), "IsGamepadName");
        m->add(fun(&GetGamepadName), "GetGamepadName");
        m->add(fun(&IsGamepadButtonPressed), "IsGamepadButtonPressed");
        m->add(fun(&IsGamepadButtonDown), "IsGamepadButtonDown");
        m->add(fun(&IsGamepadButtonReleased), "IsGamepadButtonReleased");
        m->add(fun(&IsGamepadButtonUp), "IsGamepadButtonUp");
        m->add(fun(&GetGamepadButtonPressed), "GetGamepadButtonPressed");
        m->add(fun(&GetGamepadAxisCount), "GetGamepadAxisCount");
        m->add(fun(&GetGamepadAxisMovement), "GetGamepadAxisMovement");

        return m;
      }

      /**
       * Input-related functions: mouse
       */
      ModulePtr addInputRelatedFunctionsMouse(ModulePtr m = std::make_shared<Module>()) {
        m->add(fun(&IsMouseButtonPressed), "IsMouseButtonPressed");
        m->add(fun(&IsMouseButtonDown), "IsMouseButtonDown");
        m->add(fun(&IsMouseButtonReleased), "IsMouseButtonReleased");
        m->add(fun(&IsMouseButtonUp), "IsMouseButtonUp");
        m->add(fun(&GetMouseX), "GetMouseX");
        m->add(fun(&GetMouseY), "GetMouseY");
        m->add(fun(&GetMousePosition), "GetMousePosition");
        m->add(fun(&SetMousePosition), "SetMousePosition");
        m->add(fun(&SetMouseOffset), "SetMouseOffset");
        m->add(fun(&SetMouseScale), "SetMouseScale");
        m->add(fun(&GetMouseWheelMove), "GetMouseWheelMove");

        return m;
      }

      /**
       * Input-related functions: touch
       */
      ModulePtr addInputRelatedFunctionsTouch(ModulePtr m = std::make_shared<Module>()) {
        m->add(fun(&GetTouchX), "GetTouchX");
        m->add(fun(&GetTouchY), "GetTouchY");
        m->add(fun(&GetTouchPosition), "GetTouchPosition");

        return m;
      }

      /**
       * Gestures and Touch Handling Functions (Module: gestures)
       */
      ModulePtr addGestures(ModulePtr m = std::make_shared<Module>()) {
        m->add(fun(&SetGesturesEnabled), "SetGesturesEnabled");
        m->add(fun(&IsGestureDetected), "IsGestureDetected");
        m->add(fun(&GetGestureDetected), "GetGestureDetected");
        m->add(fun(&GetTouchPointsCount), "GetTouchPointsCount");
        m->add(fun(&GetGestureHoldDuration), "GetGestureHoldDuration");
        m->add(fun(&GetGestureDragVector), "GetGestureDragVector");
        m->add(fun(&GetGestureDragAngle), "GetGestureDragAngle");
        m->add(fun(&GetGesturePinchVector), "GetGesturePinchVector");
        m->add(fun(&GetGesturePinchAngle), "GetGesturePinchAngle");

        return m;
      }

      /**
       * Camera System Functions (Module: camera)
       */
      ModulePtr addCamera(ModulePtr m = std::make_shared<Module>()) {
        m->add(fun(&SetCameraMode), "SetCameraMode");
        m->add(fun(&UpdateCamera), "UpdateCamera");

        m->add(fun(&SetCameraPanControl), "SetCameraPanControl");
        m->add(fun(&SetCameraAltControl), "SetCameraAltControl");
        m->add(fun(&SetCameraSmoothZoomControl), "SetCameraSmoothZoomControl");
        m->add(fun(&SetCameraMoveControls), "SetCameraMoveControls");

        return m;
      }

      /**
       * Basic Shapes Drawing Functions (Module: shapes)
       */
      ModulePtr addShapes(ModulePtr m = std::make_shared<Module>()) {
        m->add(fun(&DrawPixel), "DrawPixel");
        m->add(fun(&DrawPixelV), "DrawPixelV");
        m->add(fun(&DrawLine), "DrawLine");
        m->add(fun(&DrawLineV), "DrawLineV");
        m->add(fun(&DrawLineEx), "DrawLineEx");
        m->add(fun(&DrawLineBezier), "DrawLineBezier");
        m->add(fun(&DrawLineStrip), "DrawLineStrip");
        m->add(fun(&DrawCircle), "DrawCircle");
        m->add(fun(&DrawCircleSector), "DrawCircleSector");
        m->add(fun(&DrawCircleSectorLines), "DrawCircleSectorLines");
        m->add(fun(&DrawCircleGradient), "DrawCircleGradient");
        m->add(fun(&DrawCircleV), "DrawCircleV");
        m->add(fun(&DrawCircleLines), "DrawCircleLines");
        m->add(fun(&DrawEllipse), "DrawEllipse");
        m->add(fun(&DrawEllipseLines), "DrawEllipseLines");
        m->add(fun(&DrawRing), "DrawRing");
        m->add(fun(&DrawRingLines), "DrawRingLines");
        m->add(fun(&DrawRectangle), "DrawRectangle");
        m->add(fun(&DrawRectangleV), "DrawRectangleV");
        m->add(fun(&DrawRectangleRec), "DrawRectangleRec");
        m->add(fun(&DrawRectanglePro), "DrawRectanglePro");
        m->add(fun(&DrawRectangleGradientV), "DrawRectangleGradientV");
        m->add(fun(&DrawRectangleGradientH), "DrawRectangleGradientH");
        m->add(fun(&DrawRectangleGradientEx), "DrawRectangleGradientEx");
        m->add(fun(&DrawRectangleLines), "DrawRectangleLines");
        m->add(fun(&DrawRectangleLinesEx), "DrawRectangleLinesEx");
        m->add(fun(&DrawRectangleRounded), "DrawRectangleRounded");
        m->add(fun(&DrawRectangleRoundedLines), "DrawRectangleRoundedLines");
        m->add(fun(&DrawTriangle), "DrawTriangle");
        m->add(fun(&DrawTriangleLines), "DrawTriangleLines");
        m->add(fun(&DrawTriangleFan), "DrawTriangleFan");
        m->add(fun(&DrawTriangleStrip), "DrawTriangleStrip");
        m->add(fun(&DrawPoly), "DrawPoly");
        m->add(fun(&DrawPolyLines), "DrawPolyLines");

        m->add(fun(&CheckCollisionRecs), "CheckCollisionRecs");
        m->add(fun(&CheckCollisionCircles), "CheckCollisionCircles");
        m->add(fun(&CheckCollisionCircleRec), "CheckCollisionCircleRec");
        m->add(fun(&GetCollisionRec), "GetCollisionRec");
        m->add(fun(&CheckCollisionPointRec), "CheckCollisionPointRec");
        m->add(fun(&CheckCollisionPointCircle), "CheckCollisionPointCircle");
        m->add(fun(&CheckCollisionPointTriangle), "CheckCollisionPointTriangle");

        return m;
      }

      /**
       * Texture Loading and Drawing Functions (Module: textures)
       */
      ModulePtr addTextures(ModulePtr m = std::make_shared<Module>()) {
        m->add(fun(&LoadImage), "LoadImage");
        m->add(fun(&LoadImageEx), "LoadImageEx");
        m->add(fun(&LoadImagePro), "LoadImagePro");
        m->add(fun(&LoadImageRaw), "LoadImageRaw");
        m->add(fun(&ExportImage), "ExportImage");
        m->add(fun(&ExportImageAsCode), "ExportImageAsCode");
        m->add(fun(&LoadTexture), "LoadTexture");
        m->add(fun(&LoadTextureFromImage), "LoadTextureFromImage");
        m->add(fun(&LoadTextureCubemap), "LoadTextureCubemap");
        m->add(fun(&LoadRenderTexture), "LoadRenderTexture");
        m->add(fun(&UnloadImage), "UnloadImage");
        m->add(fun(&UnloadTexture), "UnloadTexture");
        m->add(fun(&UnloadRenderTexture), "UnloadRenderTexture");
        m->add(fun(&GetImageData), "GetImageData");
        m->add(fun(&GetImageDataNormalized), "GetImageDataNormalized");
        m->add(fun(&GetPixelDataSize), "GetPixelDataSize");
        m->add(fun(&GetTextureData), "GetTextureData");
        m->add(fun(&GetScreenData), "GetScreenData");
        m->add(fun(&UpdateTexture), "UpdateTexture");

        // Image manipulation functions
        m->add(fun(&ImageCopy), "ImageCopy");
        m->add(fun(&ImageFromImage), "ImageFromImage");
        m->add(fun(&ImageToPOT), "ImageToPOT");
        m->add(fun(&ImageFormat), "ImageFormat");
        m->add(fun(&ImageAlphaMask), "ImageAlphaMask");
        m->add(fun(&ImageAlphaClear), "ImageAlphaClear");
        m->add(fun(&ImageAlphaCrop), "ImageAlphaCrop");
        m->add(fun(&ImageAlphaPremultiply), "ImageAlphaPremultiply");
        m->add(fun(&ImageCrop), "ImageCrop");
        m->add(fun(&ImageResize), "ImageResize");
        m->add(fun(&ImageResizeNN), "ImageResizeNN");
        m->add(fun(&ImageResizeCanvas), "ImageResizeCanvas");
        m->add(fun(&ImageMipmaps), "ImageMipmaps");
        m->add(fun(&ImageDither), "ImageDither");
        m->add(fun(&ImageExtractPalette), "*ImageExtractPalette");
        m->add(fun(&ImageText), "ImageText");
        m->add(fun(&ImageTextEx), "ImageTextEx");
        m->add(fun(&ImageDraw), "ImageDraw");
        m->add(fun(&ImageDrawRectangle), "ImageDrawRectangle");
        m->add(fun(&ImageDrawRectangleLines), "ImageDrawRectangleLines");
        m->add(fun(&ImageDrawText), "ImageDrawText");
        m->add(fun(&ImageDrawTextEx), "ImageDrawTextEx");
        m->add(fun(&ImageFlipVertical), "ImageFlipVertical");
        m->add(fun(&ImageFlipHorizontal), "ImageFlipHorizontal");
        m->add(fun(&ImageRotateCW), "ImageRotateCW");
        m->add(fun(&ImageRotateCCW), "ImageRotateCCW");
        m->add(fun(&ImageColorTint), "ImageColorTint");
        m->add(fun(&ImageColorInvert), "ImageColorInvert");
        m->add(fun(&ImageColorGrayscale), "ImageColorGrayscale");
        m->add(fun(&ImageColorContrast), "ImageColorContrast");
        m->add(fun(&ImageColorBrightness), "ImageColorBrightness");
        m->add(fun(&ImageColorReplace), "ImageColorReplace");

        // Image generation functions
        m->add(fun(&GenImageColor), "GenImageColor");
        m->add(fun(&GenImageGradientV), "GenImageGradientV");
        m->add(fun(&GenImageGradientH), "GenImageGradientH");
        m->add(fun(&GenImageGradientRadial), "GenImageGradientRadial");
        m->add(fun(&GenImageChecked), "GenImageChecked");
        m->add(fun(&GenImageWhiteNoise), "GenImageWhiteNoise");
        m->add(fun(&GenImagePerlinNoise), "GenImagePerlinNoise");
        m->add(fun(&GenImageCellular), "GenImageCellular");

        // Texture2D configuration functions
        m->add(fun(&GenTextureMipmaps), "GenTextureMipmaps");
        m->add(fun(&SetTextureFilter), "SetTextureFilter");
        m->add(fun(&SetTextureWrap), "SetTextureWrap");

        // Texture2D drawing functions
        m->add(fun(&DrawTexture), "DrawTexture");
        m->add(fun(&DrawTextureV), "DrawTextureV");
        m->add(fun(&DrawTextureEx), "DrawTextureEx");
        m->add(fun(&DrawTextureRec), "DrawTextureRec");
        m->add(fun(&DrawTextureQuad), "DrawTextureQuad");
        m->add(fun(&DrawTexturePro), "DrawTexturePro");
        m->add(fun(&DrawTextureNPatch), "DrawTextureNPatch");

        return m;
      }

      /**
       * Adds the TextFormat functions.
       */
      void addTextFormat(ModulePtr m, const std::string& name) {
        // TODO: Figure out a clean method to have the variable arguments.
        m->add(fun([](std::string text) { return TextFormat(text.c_str()); }), name);
        m->add(fun([](std::string text, std::string arg1) { return TextFormat(text.c_str(), arg1.c_str()); }), name);
        m->add(fun([](std::string text, std::string arg1, std::string arg2) { return TextFormat(text.c_str(), arg1.c_str(), arg2.c_str()); }), name);
        m->add(fun([](std::string text, std::string arg1, std::string arg2, std::string arg3) { return TextFormat(text.c_str(), arg1.c_str(), arg2.c_str(), arg3.c_str()); }), name);
        m->add(fun([](std::string text, int arg1) { return TextFormat(text.c_str(), arg1); }), name);
        m->add(fun([](std::string text, int arg1, int arg2) { return TextFormat(text.c_str(), arg1, arg2); }), name);
        m->add(fun([](std::string text, int arg1, int arg2, int arg3) { return TextFormat(text.c_str(), arg1, arg2, arg3); }), name);

      }

      /**
       * Font Loading and Text Drawing Functions (Module: text)
       */
      ModulePtr addText(ModulePtr m = std::make_shared<Module>()) {
        // Font loading/unloading functions
        m->add(fun(&GetFontDefault), "GetFontDefault");
        m->add(fun(&LoadFont), "LoadFont");
        m->add(fun(&LoadFontEx), "LoadFontEx");
        m->add(fun(&LoadFontFromImage), "LoadFontFromImage");
        m->add(fun(&LoadFontData), "LoadFontData");
        m->add(fun(&GenImageFontAtlas), "GenImageFontAtlas");
        m->add(fun(&UnloadFont), "UnloadFont");

        // Text drawing functions
        m->add(fun(&DrawFPS), "DrawFPS");
        m->add(fun(&DrawText), "DrawText");
        m->add(fun(&DrawTextEx), "DrawTextEx");
        m->add(fun(&DrawTextRec), "DrawTextRec");
        m->add(fun(&DrawTextRecEx), "DrawTextRecEx");
        m->add(fun(&DrawTextCodepoint), "DrawTextCodepoint");

        // Text misc. functions
        m->add(fun(&MeasureText), "MeasureText");
        m->add(fun(&MeasureTextEx), "MeasureTextEx");
        m->add(fun(&GetGlyphIndex), "GetGlyphIndex");

        // Text strings management functions
        m->add(fun(&TextCopy), "TextCopy");
        m->add(fun(&TextIsEqual), "TextIsEqual");
        m->add(fun(&TextLength), "TextLength");
        // TODO: m->add(fun(&TextFormat), "TextFormat");
        addTextFormat(m, "TextFormat");
        addTextFormat(m, "FormatText");
        m->add(fun(&TextSubtext), "TextSubtext");
        m->add(fun(&TextReplace), "TextReplace");
        m->add(fun(&TextInsert), "TextInsert");
        m->add(fun(&TextJoin), "TextJoin");
        m->add(fun(&TextSplit), "TextSplit");
        m->add(fun(&TextAppend), "TextAppend");
        m->add(fun(&TextFindIndex), "TextFindIndex");
        m->add(fun(&TextToUpper), "TextToUpper");
        m->add(fun(&TextToLower), "TextToLower");
        m->add(fun(&TextToPascal), "TextToPascal");
        m->add(fun(&TextToInteger), "TextToInteger");
        m->add(fun(&TextToUtf8), "TextToUtf8");

        m->add(fun(&GetCodepoints), "GetCodepoints");
        m->add(fun(&GetCodepointsCount), "GetCodepointsCount");
        m->add(fun(&GetNextCodepoint), "GetNextCodepoint");
        m->add(fun(&CodepointToUtf8), "CodepointToUtf8");

        return m;
      }

      /**
       * Basic 3d Shapes Drawing Functions (Module: models)
       */
      ModulePtr addModels(ModulePtr m = std::make_shared<Module>()) {
        // Basic geometric 3D shapes drawing functions
        m->add(fun(&DrawLine3D), "DrawLine3D");
        m->add(fun(&DrawPoint3D), "DrawPoint3D");
        m->add(fun(&DrawCircle3D), "DrawCircle3D");
        m->add(fun(&DrawCube), "DrawCube");
        m->add(fun(&DrawCubeV), "DrawCubeV");
        m->add(fun(&DrawCubeWires), "DrawCubeWires");
        m->add(fun(&DrawCubeWiresV), "DrawCubeWiresV");
        m->add(fun(&DrawCubeTexture), "DrawCubeTexture");
        m->add(fun(&DrawSphere), "DrawSphere");
        m->add(fun(&DrawSphereEx), "DrawSphereEx");
        m->add(fun(&DrawSphereWires), "DrawSphereWires");
        m->add(fun(&DrawCylinder), "DrawCylinder");
        m->add(fun(&DrawCylinderWires), "DrawCylinderWires");
        m->add(fun(&DrawPlane), "DrawPlane");
        m->add(fun(&DrawRay), "DrawRay");
        m->add(fun(&DrawGrid), "DrawGrid");
        m->add(fun(&DrawGizmo), "DrawGizmo");

        return m;
      }

      /**
       * Model 3d Loading and Drawing Functions (Module: models)
       */
      ModulePtr addModelsLoading(ModulePtr m = std::make_shared<Module>()) {
        // Model loading/unloading functions
        m->add(fun(&LoadModel), "LoadModel");
        m->add(fun(&LoadModelFromMesh), "LoadModelFromMesh");
        m->add(fun(&UnloadModel), "UnloadModel");

        // Mesh loading/unloading functions
        m->add(fun(&LoadMeshes), "LoadMeshes");
        m->add(fun(&ExportMesh), "ExportMesh");
        m->add(fun(&UnloadMesh), "UnloadMesh");

        // Material loading/unloading functions
        m->add(fun(&LoadMaterials), "LoadMaterials");
        m->add(fun(&LoadMaterialDefault), "LoadMaterialDefault");
        m->add(fun(&UnloadMaterial), "UnloadMaterial");
        m->add(fun(&SetMaterialTexture), "SetMaterialTexture");
        m->add(fun(&SetModelMeshMaterial), "SetModelMeshMaterial");

        // Model animations loading/unloading functions
        m->add(fun(&LoadModelAnimations), "LoadModelAnimations");
        m->add(fun(&UpdateModelAnimation), "UpdateModelAnimation");
        m->add(fun(&UnloadModelAnimation), "UnloadModelAnimation");
        m->add(fun(&IsModelAnimationValid), "IsModelAnimationValid");

        // Mesh generation functions
        m->add(fun(&GenMeshPoly), "GenMeshPoly");
        m->add(fun(&GenMeshPlane), "GenMeshPlane");
        m->add(fun(&GenMeshCube), "GenMeshCube");
        m->add(fun(&GenMeshSphere), "GenMeshSphere");
        m->add(fun(&GenMeshHemiSphere), "GenMeshHemiSphere");
        m->add(fun(&GenMeshCylinder), "GenMeshCylinder");
        m->add(fun(&GenMeshTorus), "GenMeshTorus");
        m->add(fun(&GenMeshKnot), "GenMeshKnot");
        m->add(fun(&GenMeshHeightmap), "GenMeshHeightmap");
        m->add(fun(&GenMeshCubicmap), "GenMeshCubicmap");

        // Mesh manipulation functions
        m->add(fun(&MeshBoundingBox), "MeshBoundingBox");
        m->add(fun(&MeshTangents), "MeshTangents");
        m->add(fun(&MeshBinormals), "MeshBinormals");

        // Model drawing functions
        m->add(fun(&DrawModel), "DrawModel");
        m->add(fun(&DrawModelEx), "DrawModelEx");
        m->add(fun(&DrawModelWires), "DrawModelWires");
        m->add(fun(&DrawModelWiresEx), "DrawModelWiresEx");
        m->add(fun(&DrawBoundingBox), "DrawBoundingBox");
        m->add(fun(&DrawBillboard), "DrawBillboard");
        m->add(fun(&DrawBillboardRec), "DrawBillboardRec");

        // Collision detection functions
        m->add(fun(&CheckCollisionSpheres), "CheckCollisionSpheres");
        m->add(fun(&CheckCollisionBoxes), "CheckCollisionBoxes");
        m->add(fun(&CheckCollisionBoxSphere), "CheckCollisionBoxSphere");
        m->add(fun(&CheckCollisionRaySphere), "CheckCollisionRaySphere");
        m->add(fun(&CheckCollisionRaySphereEx), "CheckCollisionRaySphereEx");
        m->add(fun(&CheckCollisionRayBox), "CheckCollisionRayBox");
        m->add(fun(&GetCollisionRayModel), "GetCollisionRayModel");
        m->add(fun(&GetCollisionRayTriangle), "GetCollisionRayTriangle");
        m->add(fun(&GetCollisionRayGround), "GetCollisionRayGround");

        return m;
      }

      /**
       * Shaders System Functions (Module: rlgl)
       */
      ModulePtr addRlgl(ModulePtr m = std::make_shared<Module>()) {
        m->add(fun(&LoadShader), "LoadShader");
        m->add(fun(&LoadShaderCode), "LoadShaderCode");
        m->add(fun(&UnloadShader), "UnloadShader");
        m->add(fun(&GetShaderDefault), "GetShaderDefault");
        m->add(fun(&GetTextureDefault), "GetTextureDefault");
        m->add(fun(&GetShapesTexture), "GetShapesTexture");
        m->add(fun(&GetShapesTextureRec), "GetShapesTextureRec");
        m->add(fun(&SetShapesTexture), "SetShapesTexture");
        m->add(fun(&GetShaderLocation), "GetShaderLocation");
        m->add(fun(&SetShaderValue), "SetShaderValue");
        m->add(fun(&SetShaderValueV), "SetShaderValueV");
        m->add(fun(&SetShaderValueMatrix), "SetShaderValueMatrix");
        m->add(fun(&SetShaderValueTexture), "SetShaderValueTexture");
        m->add(fun(&SetMatrixProjection), "SetMatrixProjection");
        m->add(fun(&SetMatrixModelview), "SetMatrixModelview");
        m->add(fun(&GetMatrixModelview), "GetMatrixModelview");
        m->add(fun(&GetMatrixProjection), "GetMatrixProjection");
        m->add(fun(&GenTextureCubemap), "GenTextureCubemap");
        m->add(fun(&GenTextureIrradiance), "GenTextureIrradiance");
        m->add(fun(&GenTexturePrefilter), "GenTexturePrefilter");
        m->add(fun(&GenTextureBRDF), "GenTextureBRDF");
        m->add(fun(&BeginShaderMode), "BeginShaderMode");
        m->add(fun(&EndShaderMode), "EndShaderMode");
        m->add(fun(&BeginBlendMode), "BeginBlendMode");
        m->add(fun(&EndBlendMode), "EndBlendMode");
        m->add(fun(&InitVrSimulator), "InitVrSimulator");
        m->add(fun(&CloseVrSimulator), "CloseVrSimulator");
        m->add(fun(&UpdateVrTracking), "UpdateVrTracking");
        m->add(fun(&SetVrConfiguration), "SetVrConfiguration");
        m->add(fun(&IsVrSimulatorReady), "IsVrSimulatorReady");
        m->add(fun(&ToggleVrMode), "ToggleVrMode");
        m->add(fun(&BeginVrDrawing), "BeginVrDrawing");
        m->add(fun(&EndVrDrawing), "EndVrDrawing");

        return m;
      }

      /**
       * Audio Loading and Playing Functions (Module: audio)
       */
      ModulePtr addAudio(ModulePtr m = std::make_shared<Module>()) {
        m->add(fun(&InitAudioDevice), "InitAudioDevice");
        m->add(fun(&CloseAudioDevice), "CloseAudioDevice");
        m->add(fun(&IsAudioDeviceReady), "IsAudioDeviceReady");
        m->add(fun(&SetMasterVolume), "SetMasterVolume");
        m->add(fun(&LoadWave), "LoadWave");
        m->add(fun(&LoadSound), "LoadSound");
        m->add(fun(&LoadSoundFromWave), "LoadSoundFromWave");
        m->add(fun(&UpdateSound), "UpdateSound");
        m->add(fun(&UnloadWave), "UnloadWave");
        m->add(fun(&UnloadSound), "UnloadSound");
        m->add(fun(&ExportWave), "ExportWave");
        m->add(fun(&ExportWaveAsCode), "ExportWaveAsCode");
        m->add(fun(&PlaySound), "PlaySound");
        m->add(fun(&StopSound), "StopSound");
        m->add(fun(&PauseSound), "PauseSound");
        m->add(fun(&ResumeSound), "ResumeSound");
        m->add(fun(&PlaySoundMulti), "PlaySoundMulti");
        m->add(fun(&StopSoundMulti), "StopSoundMulti");
        m->add(fun(&GetSoundsPlaying), "GetSoundsPlaying");
        m->add(fun(&IsSoundPlaying), "IsSoundPlaying");
        m->add(fun(&SetSoundVolume), "SetSoundVolume");
        m->add(fun(&SetSoundPitch), "SetSoundPitch");
        m->add(fun(&WaveFormat), "WaveFormat");
        m->add(fun(&WaveCopy), "WaveCopy");
        m->add(fun(&WaveCrop), "WaveCrop");
        m->add(fun(&*GetWaveData), "*GetWaveData");
        /* TODO: Add Music
        m->add(fun(&LoadMusicStream), "LoadMusicStream");
        m->add(fun(&UnloadMusicStream), "UnloadMusicStream");
        m->add(fun(&PlayMusicStream), "PlayMusicStream");
        m->add(fun(&UpdateMusicStream), "UpdateMusicStream");
        m->add(fun(&StopMusicStream), "StopMusicStream");
        m->add(fun(&PauseMusicStream), "PauseMusicStream");
        m->add(fun(&ResumeMusicStream), "ResumeMusicStream");
        m->add(fun(&IsMusicPlaying), "IsMusicPlaying");
        m->add(fun(&SetMusicVolume), "SetMusicVolume");
        m->add(fun(&SetMusicPitch), "SetMusicPitch");
        m->add(fun(&SetMusicLoopCount), "SetMusicLoopCount");
        m->add(fun(&GetMusicTimeLength), "GetMusicTimeLength");
        m->add(fun(&GetMusicTimePlayed), "GetMusicTimePlayed");
        */
        m->add(fun(&InitAudioStream), "InitAudioStream");
        m->add(fun(&UpdateAudioStream), "UpdateAudioStream");
        m->add(fun(&CloseAudioStream), "CloseAudioStream");
        m->add(fun(&IsAudioStreamProcessed), "IsAudioStreamProcessed");
        m->add(fun(&PlayAudioStream), "PlayAudioStream");
        m->add(fun(&PauseAudioStream), "PauseAudioStream");
        m->add(fun(&ResumeAudioStream), "ResumeAudioStream");
        m->add(fun(&IsAudioStreamPlaying), "IsAudioStreamPlaying");
        m->add(fun(&StopAudioStream), "StopAudioStream");
        m->add(fun(&SetAudioStreamVolume), "SetAudioStreamVolume");
        m->add(fun(&SetAudioStreamPitch), "SetAudioStreamPitch");
        m->add(fun(&SetAudioStreamBufferSizeDefault), "SetAudioStreamBufferSizeDefault");

        return m;
      }

      /**
       * Bootstrap a ChaiScript module with raylib support.
       */
      ModulePtr bootstrap(ModulePtr m = std::make_shared<Module>())
      {
        // Allow converting between strings and char*.
        m->add(chaiscript::type_conversion<const std::string&, const char *>([](const std::string& input) { return input.c_str(); }));
        m->add(chaiscript::type_conversion<const char *, const std::string&>([](const char* input) { return std::string(input); }));

        // Add all the raylib functions.
        addWindow(m);
        addCursor(m);
        addTime(m);
        addStructureDefinitions(m);
        addColor(m);
        addMisc(m);
        addDrawing(m);
        addScreenSpace(m);
        addFilesManagement(m);
        addPersistentStorage(m);
        addInputRelatedFunctionsKeyboard(m);
        addInputRelatedFunctionsGamepads(m);
        addInputRelatedFunctionsMouse(m);
        addInputRelatedFunctionsTouch(m);
        addGestures(m);
        addCamera(m);
        addShapes(m);
        addTextures(m);
        addText(m);
        addModels(m);
        addModelsLoading(m);
        addRlgl(m);
        addAudio(m);
        addEnums(m);

        return m;
      }
    }
  }
}

#endif /* CHAISCRIPT_EXTRAS_RAYLIB_HPP_ */
