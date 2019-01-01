#include <vector>
#include <string>

#include <chaiscript/chaiscript.hpp>

#include "raylib.h"

namespace chaiscript {
  namespace extras {
    namespace raylib {

      /**
       * Bootstrap a ChaiScript module with Box2D support.
       */
      ModulePtr bootstrap(ModulePtr m = std::make_shared<Module>())
      {
        m->add(fun([](int width, int height, const std::string& title) {
          InitWindow(width, height, title.c_str());
        }), "InitWindow");

        m->add(fun(&CloseWindow), "CloseWindow");

        return m;
      }
    }
  }
}