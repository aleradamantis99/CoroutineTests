# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/alejandro/Projects/testCppCoro

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/alejandro/Projects/testCppCoro/build

# Include any dependencies generated for this target.
include CMakeFiles/JthreadExample.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/JthreadExample.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/JthreadExample.dir/flags.make

CMakeFiles/JthreadExample.dir/main_jthread.cpp.o: CMakeFiles/JthreadExample.dir/flags.make
CMakeFiles/JthreadExample.dir/main_jthread.cpp.o: ../main_jthread.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alejandro/Projects/testCppCoro/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/JthreadExample.dir/main_jthread.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/JthreadExample.dir/main_jthread.cpp.o -c /home/alejandro/Projects/testCppCoro/main_jthread.cpp

CMakeFiles/JthreadExample.dir/main_jthread.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/JthreadExample.dir/main_jthread.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alejandro/Projects/testCppCoro/main_jthread.cpp > CMakeFiles/JthreadExample.dir/main_jthread.cpp.i

CMakeFiles/JthreadExample.dir/main_jthread.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/JthreadExample.dir/main_jthread.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alejandro/Projects/testCppCoro/main_jthread.cpp -o CMakeFiles/JthreadExample.dir/main_jthread.cpp.s

# Object files for target JthreadExample
JthreadExample_OBJECTS = \
"CMakeFiles/JthreadExample.dir/main_jthread.cpp.o"

# External object files for target JthreadExample
JthreadExample_EXTERNAL_OBJECTS =

JthreadExample: CMakeFiles/JthreadExample.dir/main_jthread.cpp.o
JthreadExample: CMakeFiles/JthreadExample.dir/build.make
JthreadExample: CMakeFiles/JthreadExample.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/alejandro/Projects/testCppCoro/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable JthreadExample"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/JthreadExample.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/JthreadExample.dir/build: JthreadExample

.PHONY : CMakeFiles/JthreadExample.dir/build

CMakeFiles/JthreadExample.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/JthreadExample.dir/cmake_clean.cmake
.PHONY : CMakeFiles/JthreadExample.dir/clean

CMakeFiles/JthreadExample.dir/depend:
	cd /home/alejandro/Projects/testCppCoro/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/alejandro/Projects/testCppCoro /home/alejandro/Projects/testCppCoro /home/alejandro/Projects/testCppCoro/build /home/alejandro/Projects/testCppCoro/build /home/alejandro/Projects/testCppCoro/build/CMakeFiles/JthreadExample.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/JthreadExample.dir/depend

