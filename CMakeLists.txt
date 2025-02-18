cmake_minimum_required(VERSION 3.14)

include(cmake/prelude.cmake)

project(
    RNA-tool
    VERSION 0.1.0
    DESCRIPTION "Program I made for myself to convert a chord in a given chord progression into roman numerals. May be extended via feature creep"
    HOMEPAGE_URL "https://example.com/"
    LANGUAGES CXX
)

include(cmake/project-is-top-level.cmake)
include(cmake/variables.cmake)

# ---- Declare library ----
# Using a STATIC library to allow linking in both the main executable and tests.
add_library(
    RNA-tool_lib STATIC
    source/chord.cpp
    source/chordProgression.cpp
)

target_include_directories(
    RNA-tool_lib ${warning_guard}
    PUBLIC
    "$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/source>"
)

target_compile_features(RNA-tool_lib PUBLIC cxx_std_17)

SET(TARGET_H
    chord.hpp chordProgression.hpp)

SET(TARGET_SRC
    chord.cpp chordProgression.cpp)

# ---- Declare executable ----

add_executable(RNA-tool_exe source/main.cpp)
add_executable(RNA-tool::exe ALIAS RNA-tool_exe)

set_property(TARGET RNA-tool_exe PROPERTY OUTPUT_NAME RNA-tool)

target_compile_features(RNA-tool_exe PRIVATE cxx_std_17)

target_link_libraries(RNA-tool_exe PRIVATE RNA-tool_lib)

# ---- Install rules ----

if(NOT CMAKE_SKIP_INSTALL_RULES)
  include(cmake/install-rules.cmake)
endif()

# ---- Developer mode ----

if(NOT RNA-tool_DEVELOPER_MODE)
  return()
elseif(NOT PROJECT_IS_TOP_LEVEL)
  message(
      AUTHOR_WARNING
      "Developer mode is intended for developers of RNA-tool"
  )
endif()

