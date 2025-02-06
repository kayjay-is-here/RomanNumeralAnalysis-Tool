# Parent project does not export its library target, so this CML implicitly
# depends on being added from it, i.e. the testing is done only from the build
# tree and is not feasible from an install location

project(RNA-toolTests LANGUAGES CXX)

# ---- Dependencies ----

find_package(Catch2 REQUIRED)
include(Catch)

# ---- Tests ----

add_executable(RNA-tool_test source/RNA-tool_test.cpp)
target_link_libraries(
    RNA-tool_test PRIVATE
    RNA-tool_lib
    Catch2::Catch2WithMain
)
target_compile_features(RNA-tool_test PRIVATE cxx_std_17)

catch_discover_tests(RNA-tool_test)

# ---- End-of-file commands ----

add_folders(Test)
