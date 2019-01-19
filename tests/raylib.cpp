#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "catch.hpp"

#include <string>
#include <chaiscript/chaiscript.hpp>
#include <raylib.h>

/**
 * Load the Raylib library.
 */
#include "chaiscript/extras/raylib.hpp"

TEST_CASE( "raylib-chaiscript functions work", "[raylib]" ) {

  auto raylib = chaiscript::extras::raylib::bootstrap();

  // Create the ChaiScript environment.
  chaiscript::ChaiScript chai;

  // Add the library to the ChaiScript instance.
  chai.add(raylib);

  // Window
  chai.eval(R""(
  	var windowReady = IsWindowReady()
  )"");
  CHECK(chai.eval<bool>("windowReady") == false);

  // Colors
  chai.eval(R""(
    var hotPink = PINK;
  )"");
  CHECK(chai.eval<unsigned char>("hotPink.g") == 109);

  // Enums
  chai.eval(R""(
    var period = KEY_PERIOD;
  )"");
  CHECK(chai.eval<int>("period") == KEY_PERIOD);
}
