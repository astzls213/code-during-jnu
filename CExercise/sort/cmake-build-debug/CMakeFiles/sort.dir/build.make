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
CMAKE_SOURCE_DIR = /Users/astzls/CLionProjects/sort

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/astzls/CLionProjects/sort/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/sort.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/sort.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/sort.dir/flags.make

CMakeFiles/sort.dir/main.c.o: CMakeFiles/sort.dir/flags.make
CMakeFiles/sort.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/astzls/CLionProjects/sort/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/sort.dir/main.c.o"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/sort.dir/main.c.o   -c /Users/astzls/CLionProjects/sort/main.c

CMakeFiles/sort.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/sort.dir/main.c.i"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/astzls/CLionProjects/sort/main.c > CMakeFiles/sort.dir/main.c.i

CMakeFiles/sort.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/sort.dir/main.c.s"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/astzls/CLionProjects/sort/main.c -o CMakeFiles/sort.dir/main.c.s

CMakeFiles/sort.dir/QuickSort.c.o: CMakeFiles/sort.dir/flags.make
CMakeFiles/sort.dir/QuickSort.c.o: ../QuickSort.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/astzls/CLionProjects/sort/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/sort.dir/QuickSort.c.o"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/sort.dir/QuickSort.c.o   -c /Users/astzls/CLionProjects/sort/QuickSort.c

CMakeFiles/sort.dir/QuickSort.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/sort.dir/QuickSort.c.i"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/astzls/CLionProjects/sort/QuickSort.c > CMakeFiles/sort.dir/QuickSort.c.i

CMakeFiles/sort.dir/QuickSort.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/sort.dir/QuickSort.c.s"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/astzls/CLionProjects/sort/QuickSort.c -o CMakeFiles/sort.dir/QuickSort.c.s

CMakeFiles/sort.dir/InsertionSort.c.o: CMakeFiles/sort.dir/flags.make
CMakeFiles/sort.dir/InsertionSort.c.o: ../InsertionSort.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/astzls/CLionProjects/sort/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/sort.dir/InsertionSort.c.o"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/sort.dir/InsertionSort.c.o   -c /Users/astzls/CLionProjects/sort/InsertionSort.c

CMakeFiles/sort.dir/InsertionSort.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/sort.dir/InsertionSort.c.i"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/astzls/CLionProjects/sort/InsertionSort.c > CMakeFiles/sort.dir/InsertionSort.c.i

CMakeFiles/sort.dir/InsertionSort.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/sort.dir/InsertionSort.c.s"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/astzls/CLionProjects/sort/InsertionSort.c -o CMakeFiles/sort.dir/InsertionSort.c.s

# Object files for target sort
sort_OBJECTS = \
"CMakeFiles/sort.dir/main.c.o" \
"CMakeFiles/sort.dir/QuickSort.c.o" \
"CMakeFiles/sort.dir/InsertionSort.c.o"

# External object files for target sort
sort_EXTERNAL_OBJECTS =

sort: CMakeFiles/sort.dir/main.c.o
sort: CMakeFiles/sort.dir/QuickSort.c.o
sort: CMakeFiles/sort.dir/InsertionSort.c.o
sort: CMakeFiles/sort.dir/build.make
sort: CMakeFiles/sort.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/astzls/CLionProjects/sort/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable sort"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sort.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/sort.dir/build: sort

.PHONY : CMakeFiles/sort.dir/build

CMakeFiles/sort.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/sort.dir/cmake_clean.cmake
.PHONY : CMakeFiles/sort.dir/clean

CMakeFiles/sort.dir/depend:
	cd /Users/astzls/CLionProjects/sort/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/astzls/CLionProjects/sort /Users/astzls/CLionProjects/sort /Users/astzls/CLionProjects/sort/cmake-build-debug /Users/astzls/CLionProjects/sort/cmake-build-debug /Users/astzls/CLionProjects/sort/cmake-build-debug/CMakeFiles/sort.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/sort.dir/depend

