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
CMAKE_SOURCE_DIR = /Users/astzls/CLionProjects/flooedACM1999WF

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/astzls/CLionProjects/flooedACM1999WF/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/flooedACM1999WF.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/flooedACM1999WF.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/flooedACM1999WF.dir/flags.make

CMakeFiles/flooedACM1999WF.dir/main.c.o: CMakeFiles/flooedACM1999WF.dir/flags.make
CMakeFiles/flooedACM1999WF.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/astzls/CLionProjects/flooedACM1999WF/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/flooedACM1999WF.dir/main.c.o"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/flooedACM1999WF.dir/main.c.o   -c /Users/astzls/CLionProjects/flooedACM1999WF/main.c

CMakeFiles/flooedACM1999WF.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/flooedACM1999WF.dir/main.c.i"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/astzls/CLionProjects/flooedACM1999WF/main.c > CMakeFiles/flooedACM1999WF.dir/main.c.i

CMakeFiles/flooedACM1999WF.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/flooedACM1999WF.dir/main.c.s"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/astzls/CLionProjects/flooedACM1999WF/main.c -o CMakeFiles/flooedACM1999WF.dir/main.c.s

# Object files for target flooedACM1999WF
flooedACM1999WF_OBJECTS = \
"CMakeFiles/flooedACM1999WF.dir/main.c.o"

# External object files for target flooedACM1999WF
flooedACM1999WF_EXTERNAL_OBJECTS =

flooedACM1999WF: CMakeFiles/flooedACM1999WF.dir/main.c.o
flooedACM1999WF: CMakeFiles/flooedACM1999WF.dir/build.make
flooedACM1999WF: CMakeFiles/flooedACM1999WF.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/astzls/CLionProjects/flooedACM1999WF/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable flooedACM1999WF"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/flooedACM1999WF.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/flooedACM1999WF.dir/build: flooedACM1999WF

.PHONY : CMakeFiles/flooedACM1999WF.dir/build

CMakeFiles/flooedACM1999WF.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/flooedACM1999WF.dir/cmake_clean.cmake
.PHONY : CMakeFiles/flooedACM1999WF.dir/clean

CMakeFiles/flooedACM1999WF.dir/depend:
	cd /Users/astzls/CLionProjects/flooedACM1999WF/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/astzls/CLionProjects/flooedACM1999WF /Users/astzls/CLionProjects/flooedACM1999WF /Users/astzls/CLionProjects/flooedACM1999WF/cmake-build-debug /Users/astzls/CLionProjects/flooedACM1999WF/cmake-build-debug /Users/astzls/CLionProjects/flooedACM1999WF/cmake-build-debug/CMakeFiles/flooedACM1999WF.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/flooedACM1999WF.dir/depend

