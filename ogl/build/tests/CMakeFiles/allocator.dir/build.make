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
CMAKE_COMMAND = /opt/homebrew/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/ray.clinton/graphics/ogl/glfw-3.4

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/ray.clinton/graphics/ogl/build

# Include any dependencies generated for this target.
include tests/CMakeFiles/allocator.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include tests/CMakeFiles/allocator.dir/compiler_depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/allocator.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/allocator.dir/flags.make

tests/CMakeFiles/allocator.dir/codegen:
.PHONY : tests/CMakeFiles/allocator.dir/codegen

tests/CMakeFiles/allocator.dir/allocator.c.o: tests/CMakeFiles/allocator.dir/flags.make
tests/CMakeFiles/allocator.dir/allocator.c.o: /Users/ray.clinton/graphics/ogl/glfw-3.4/tests/allocator.c
tests/CMakeFiles/allocator.dir/allocator.c.o: tests/CMakeFiles/allocator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/ray.clinton/graphics/ogl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object tests/CMakeFiles/allocator.dir/allocator.c.o"
	cd /Users/ray.clinton/graphics/ogl/build/tests && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT tests/CMakeFiles/allocator.dir/allocator.c.o -MF CMakeFiles/allocator.dir/allocator.c.o.d -o CMakeFiles/allocator.dir/allocator.c.o -c /Users/ray.clinton/graphics/ogl/glfw-3.4/tests/allocator.c

tests/CMakeFiles/allocator.dir/allocator.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/allocator.dir/allocator.c.i"
	cd /Users/ray.clinton/graphics/ogl/build/tests && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/ray.clinton/graphics/ogl/glfw-3.4/tests/allocator.c > CMakeFiles/allocator.dir/allocator.c.i

tests/CMakeFiles/allocator.dir/allocator.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/allocator.dir/allocator.c.s"
	cd /Users/ray.clinton/graphics/ogl/build/tests && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/ray.clinton/graphics/ogl/glfw-3.4/tests/allocator.c -o CMakeFiles/allocator.dir/allocator.c.s

# Object files for target allocator
allocator_OBJECTS = \
"CMakeFiles/allocator.dir/allocator.c.o"

# External object files for target allocator
allocator_EXTERNAL_OBJECTS =

tests/allocator: tests/CMakeFiles/allocator.dir/allocator.c.o
tests/allocator: tests/CMakeFiles/allocator.dir/build.make
tests/allocator: src/libglfw3.a
tests/allocator: tests/CMakeFiles/allocator.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/ray.clinton/graphics/ogl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable allocator"
	cd /Users/ray.clinton/graphics/ogl/build/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/allocator.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/allocator.dir/build: tests/allocator
.PHONY : tests/CMakeFiles/allocator.dir/build

tests/CMakeFiles/allocator.dir/clean:
	cd /Users/ray.clinton/graphics/ogl/build/tests && $(CMAKE_COMMAND) -P CMakeFiles/allocator.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/allocator.dir/clean

tests/CMakeFiles/allocator.dir/depend:
	cd /Users/ray.clinton/graphics/ogl/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/ray.clinton/graphics/ogl/glfw-3.4 /Users/ray.clinton/graphics/ogl/glfw-3.4/tests /Users/ray.clinton/graphics/ogl/build /Users/ray.clinton/graphics/ogl/build/tests /Users/ray.clinton/graphics/ogl/build/tests/CMakeFiles/allocator.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : tests/CMakeFiles/allocator.dir/depend

