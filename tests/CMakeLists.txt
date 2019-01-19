
# Add catch tests macro
macro(ADD_CATCH_TESTS executable)
  if (MSVC)
    file(TO_NATIVE_PATH "${QT_LIBRARY_DIR}" QT_LIB_PATH)
    set(NEWPATH "${QT_LIB_PATH};$ENV{PATH}")
  else()
    set(NEWPATH $ENV{PATH})
  endif()

  get_target_property(target_files ${executable} SOURCES)

  message("Files: ${target_files}")

  foreach(source ${target_files})
    if(NOT "${source}" MATCHES "/moc_.*cxx")
      string(REGEX MATCH .*cpp source "${source}")
      if(source)
        file(READ "${source}" contents)
        string(REGEX MATCHALL "TEST_CASE\\([ ]*\"[^\"]+\"" found_tests ${contents})
        foreach(hit ${found_tests})
          message("Found Test: ${hit}")
          string(REGEX REPLACE "TEST_CASE\\([ ]*(\"[^\"]+\").*" "\\1" test_name ${hit})
          add_test(${test_name} "${executable}" ${test_name})
          set_tests_properties(${test_name} PROPERTIES TIMEOUT 660 ENVIRONMENT "PATH=${NEWPATH}")
        endforeach()
      endif()
    endif()
  endforeach()
endmacro()

# Raylib Test
find_package(Raylib)
find_package(ChaiScript)

list(APPEND SOURCES catch.hpp raylib.cpp)
list(APPEND LIBS raylib)
add_executable(raylib_test raylib.cpp catch.hpp)
target_include_directories(raylib_test PUBLIC
    ${raylib_SOURCE_DIR}/src
    ${chaiscript_SOURCE_DIR}/include
)
target_link_libraries(raylib_test ${LIBS})
set_target_properties(raylib_test PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}"
)
ADD_CATCH_TESTS(raylib_test)
