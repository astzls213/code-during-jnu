# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/astzls/CLionProjects/betProbability

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/astzls/CLionProjects/betProbability/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/betProbability.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/betProbability.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/betProbability.dir/flags.make

CMakeFiles/betProbability.dir/main.c.o: CMakeFiles/betProbability.dir/flags.make
CMakeFiles/betProbability.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/astzls/CLionProjects/betProbability/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/betProbability.dir/main.c.o"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/betProbability.dir/main.c.o   -c /Users/astzls/CLionProjects/betProbability/main.c

CMakeFiles/betProbability.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/betProbability.dir/main.c.i"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/astzls/CLionProjects/betProbability/main.c > CMakeFiles/betProbability.dir/main.c.i

CMakeFiles/betProbability.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/betProbability.dir/main.c.s"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/astzls/CLionProjects/betProbability/main.c -o CMakeFiles/betProbability.dir/main.c.s

# Object files for target betProbability
betProbability_OBJECTS = \
"CMakeFiles/betProbability.dir/main.c.o"

# External object files for target betProbability
betProbability_EXTERNAL_OBJECTS =

betProbability: CMakeFiles/betProbability.dir/main.c.o
betProbability: CMakeFiles/betProbability.dir/build.make
betProbability: CMakeFiles/betProbability.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/astzls/CLionProjects/betProbability/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable betProbability"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/betProbability.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/betProbability.dir/build: betProbability

.PHONY : CMakeFiles/betProbability.dir/build

CMakeFiles/betProbability.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/betProbability.dir/cmake_clean.cmake
.PHONY : CMakeFiles/betProbability.dir/clean

CMakeFiles/betProbability.dir/depend:
	cd /Users/astzls/CLionProjects/betProbability/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/astzls/CLionProjects/betProbability /Users/astzls/CLionProjects/betProbability /Users/astzls/CLionProjects/betProbability/cmake-build-debug /Users/astzls/CLionProjects/betProbability/cmake-build-debug /Users/astzls/CLionProjects/betProbability/cmake-build-debug/CMakeFiles/betProbability.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/betProbability.dir/depend
