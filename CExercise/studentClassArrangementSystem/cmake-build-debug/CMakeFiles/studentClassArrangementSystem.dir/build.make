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
CMAKE_SOURCE_DIR = /Users/astzls/CLionProjects/studentClassArrangementSystem

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/astzls/CLionProjects/studentClassArrangementSystem/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/studentClassArrangementSystem.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/studentClassArrangementSystem.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/studentClassArrangementSystem.dir/flags.make

CMakeFiles/studentClassArrangementSystem.dir/main.c.o: CMakeFiles/studentClassArrangementSystem.dir/flags.make
CMakeFiles/studentClassArrangementSystem.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/astzls/CLionProjects/studentClassArrangementSystem/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/studentClassArrangementSystem.dir/main.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/studentClassArrangementSystem.dir/main.c.o   -c /Users/astzls/CLionProjects/studentClassArrangementSystem/main.c

CMakeFiles/studentClassArrangementSystem.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/studentClassArrangementSystem.dir/main.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/astzls/CLionProjects/studentClassArrangementSystem/main.c > CMakeFiles/studentClassArrangementSystem.dir/main.c.i

CMakeFiles/studentClassArrangementSystem.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/studentClassArrangementSystem.dir/main.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/astzls/CLionProjects/studentClassArrangementSystem/main.c -o CMakeFiles/studentClassArrangementSystem.dir/main.c.s

CMakeFiles/studentClassArrangementSystem.dir/systemOperation.c.o: CMakeFiles/studentClassArrangementSystem.dir/flags.make
CMakeFiles/studentClassArrangementSystem.dir/systemOperation.c.o: ../systemOperation.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/astzls/CLionProjects/studentClassArrangementSystem/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/studentClassArrangementSystem.dir/systemOperation.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/studentClassArrangementSystem.dir/systemOperation.c.o   -c /Users/astzls/CLionProjects/studentClassArrangementSystem/systemOperation.c

CMakeFiles/studentClassArrangementSystem.dir/systemOperation.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/studentClassArrangementSystem.dir/systemOperation.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/astzls/CLionProjects/studentClassArrangementSystem/systemOperation.c > CMakeFiles/studentClassArrangementSystem.dir/systemOperation.c.i

CMakeFiles/studentClassArrangementSystem.dir/systemOperation.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/studentClassArrangementSystem.dir/systemOperation.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/astzls/CLionProjects/studentClassArrangementSystem/systemOperation.c -o CMakeFiles/studentClassArrangementSystem.dir/systemOperation.c.s

# Object files for target studentClassArrangementSystem
studentClassArrangementSystem_OBJECTS = \
"CMakeFiles/studentClassArrangementSystem.dir/main.c.o" \
"CMakeFiles/studentClassArrangementSystem.dir/systemOperation.c.o"

# External object files for target studentClassArrangementSystem
studentClassArrangementSystem_EXTERNAL_OBJECTS =

studentClassArrangementSystem: CMakeFiles/studentClassArrangementSystem.dir/main.c.o
studentClassArrangementSystem: CMakeFiles/studentClassArrangementSystem.dir/systemOperation.c.o
studentClassArrangementSystem: CMakeFiles/studentClassArrangementSystem.dir/build.make
studentClassArrangementSystem: CMakeFiles/studentClassArrangementSystem.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/astzls/CLionProjects/studentClassArrangementSystem/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable studentClassArrangementSystem"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/studentClassArrangementSystem.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/studentClassArrangementSystem.dir/build: studentClassArrangementSystem

.PHONY : CMakeFiles/studentClassArrangementSystem.dir/build

CMakeFiles/studentClassArrangementSystem.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/studentClassArrangementSystem.dir/cmake_clean.cmake
.PHONY : CMakeFiles/studentClassArrangementSystem.dir/clean

CMakeFiles/studentClassArrangementSystem.dir/depend:
	cd /Users/astzls/CLionProjects/studentClassArrangementSystem/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/astzls/CLionProjects/studentClassArrangementSystem /Users/astzls/CLionProjects/studentClassArrangementSystem /Users/astzls/CLionProjects/studentClassArrangementSystem/cmake-build-debug /Users/astzls/CLionProjects/studentClassArrangementSystem/cmake-build-debug /Users/astzls/CLionProjects/studentClassArrangementSystem/cmake-build-debug/CMakeFiles/studentClassArrangementSystem.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/studentClassArrangementSystem.dir/depend

