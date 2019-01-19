find_package(chaiscript 6.0.0 QUIET)
if (NOT chaiscript_FOUND)
  include(FetchContent)
  FetchContent_Declare(
    chaiscript
    GIT_REPOSITORY https://github.com/ChaiScript/ChaiScript.git
    GIT_TAG ac0d7ce94925f8eac367533b276d9d7db13a77ae
  )
  FetchContent_GetProperties(chaiscript)
  if (NOT chaiscript_POPULATED) # Have we downloaded raylib yet?
    set(FETCHCONTENT_QUIET NO)
    FetchContent_Populate(chaiscript)
    set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
    set(BUILD_GAMES    OFF CACHE BOOL "" FORCE) # or games
    set(BUILD_TEST    OFF CACHE BOOL "" FORCE) # or tests
    set(BUILD_TESTING    OFF CACHE BOOL "" FORCE) # or tests
    add_subdirectory(${chaiscript_SOURCE_DIR} ${chaiscript_BINARY_DIR})
  endif()
endif()
