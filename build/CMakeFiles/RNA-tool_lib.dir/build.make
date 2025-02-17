# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.31

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/shadu/Documents/projects/personal/RNA-tools

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/shadu/Documents/projects/personal/RNA-tools/build

# Include any dependencies generated for this target.
include CMakeFiles/RNA-tool_lib.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/RNA-tool_lib.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/RNA-tool_lib.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/RNA-tool_lib.dir/flags.make

CMakeFiles/RNA-tool_lib.dir/codegen:
.PHONY : CMakeFiles/RNA-tool_lib.dir/codegen

CMakeFiles/RNA-tool_lib.dir/source/lib.cpp.o: CMakeFiles/RNA-tool_lib.dir/flags.make
CMakeFiles/RNA-tool_lib.dir/source/lib.cpp.o: /home/shadu/Documents/projects/personal/RNA-tools/source/lib.cpp
CMakeFiles/RNA-tool_lib.dir/source/lib.cpp.o: CMakeFiles/RNA-tool_lib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/shadu/Documents/projects/personal/RNA-tools/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/RNA-tool_lib.dir/source/lib.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/RNA-tool_lib.dir/source/lib.cpp.o -MF CMakeFiles/RNA-tool_lib.dir/source/lib.cpp.o.d -o CMakeFiles/RNA-tool_lib.dir/source/lib.cpp.o -c /home/shadu/Documents/projects/personal/RNA-tools/source/lib.cpp

CMakeFiles/RNA-tool_lib.dir/source/lib.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/RNA-tool_lib.dir/source/lib.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shadu/Documents/projects/personal/RNA-tools/source/lib.cpp > CMakeFiles/RNA-tool_lib.dir/source/lib.cpp.i

CMakeFiles/RNA-tool_lib.dir/source/lib.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/RNA-tool_lib.dir/source/lib.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shadu/Documents/projects/personal/RNA-tools/source/lib.cpp -o CMakeFiles/RNA-tool_lib.dir/source/lib.cpp.s

CMakeFiles/RNA-tool_lib.dir/source/chord.cpp.o: CMakeFiles/RNA-tool_lib.dir/flags.make
CMakeFiles/RNA-tool_lib.dir/source/chord.cpp.o: /home/shadu/Documents/projects/personal/RNA-tools/source/chord.cpp
CMakeFiles/RNA-tool_lib.dir/source/chord.cpp.o: CMakeFiles/RNA-tool_lib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/shadu/Documents/projects/personal/RNA-tools/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/RNA-tool_lib.dir/source/chord.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/RNA-tool_lib.dir/source/chord.cpp.o -MF CMakeFiles/RNA-tool_lib.dir/source/chord.cpp.o.d -o CMakeFiles/RNA-tool_lib.dir/source/chord.cpp.o -c /home/shadu/Documents/projects/personal/RNA-tools/source/chord.cpp

CMakeFiles/RNA-tool_lib.dir/source/chord.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/RNA-tool_lib.dir/source/chord.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shadu/Documents/projects/personal/RNA-tools/source/chord.cpp > CMakeFiles/RNA-tool_lib.dir/source/chord.cpp.i

CMakeFiles/RNA-tool_lib.dir/source/chord.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/RNA-tool_lib.dir/source/chord.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shadu/Documents/projects/personal/RNA-tools/source/chord.cpp -o CMakeFiles/RNA-tool_lib.dir/source/chord.cpp.s

CMakeFiles/RNA-tool_lib.dir/source/chordProgression.cpp.o: CMakeFiles/RNA-tool_lib.dir/flags.make
CMakeFiles/RNA-tool_lib.dir/source/chordProgression.cpp.o: /home/shadu/Documents/projects/personal/RNA-tools/source/chordProgression.cpp
CMakeFiles/RNA-tool_lib.dir/source/chordProgression.cpp.o: CMakeFiles/RNA-tool_lib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/shadu/Documents/projects/personal/RNA-tools/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/RNA-tool_lib.dir/source/chordProgression.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/RNA-tool_lib.dir/source/chordProgression.cpp.o -MF CMakeFiles/RNA-tool_lib.dir/source/chordProgression.cpp.o.d -o CMakeFiles/RNA-tool_lib.dir/source/chordProgression.cpp.o -c /home/shadu/Documents/projects/personal/RNA-tools/source/chordProgression.cpp

CMakeFiles/RNA-tool_lib.dir/source/chordProgression.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/RNA-tool_lib.dir/source/chordProgression.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shadu/Documents/projects/personal/RNA-tools/source/chordProgression.cpp > CMakeFiles/RNA-tool_lib.dir/source/chordProgression.cpp.i

CMakeFiles/RNA-tool_lib.dir/source/chordProgression.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/RNA-tool_lib.dir/source/chordProgression.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shadu/Documents/projects/personal/RNA-tools/source/chordProgression.cpp -o CMakeFiles/RNA-tool_lib.dir/source/chordProgression.cpp.s

RNA-tool_lib: CMakeFiles/RNA-tool_lib.dir/source/lib.cpp.o
RNA-tool_lib: CMakeFiles/RNA-tool_lib.dir/source/chord.cpp.o
RNA-tool_lib: CMakeFiles/RNA-tool_lib.dir/source/chordProgression.cpp.o
RNA-tool_lib: CMakeFiles/RNA-tool_lib.dir/build.make
.PHONY : RNA-tool_lib

# Rule to build all files generated by this target.
CMakeFiles/RNA-tool_lib.dir/build: RNA-tool_lib
.PHONY : CMakeFiles/RNA-tool_lib.dir/build

CMakeFiles/RNA-tool_lib.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/RNA-tool_lib.dir/cmake_clean.cmake
.PHONY : CMakeFiles/RNA-tool_lib.dir/clean

CMakeFiles/RNA-tool_lib.dir/depend:
	cd /home/shadu/Documents/projects/personal/RNA-tools/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/shadu/Documents/projects/personal/RNA-tools /home/shadu/Documents/projects/personal/RNA-tools /home/shadu/Documents/projects/personal/RNA-tools/build /home/shadu/Documents/projects/personal/RNA-tools/build /home/shadu/Documents/projects/personal/RNA-tools/build/CMakeFiles/RNA-tool_lib.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/RNA-tool_lib.dir/depend

