find_package(Raylib)
find_package(ChaiScript)

list(APPEND LIBS raylib)
list(APPEND SOURCES raylib-chaiscript.cpp)
add_executable(raylib-chaiscript ${SOURCES})
target_include_directories(raylib-chaiscript PUBLIC
    ${raylib_SOURCE_DIR}/src
    ${chaiscript_SOURCE_DIR}/include
)
target_link_libraries(raylib-chaiscript ${LIBS})
