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
include CMakeFiles/InScheduleExample.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/InScheduleExample.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/InScheduleExample.dir/flags.make

CMakeFiles/InScheduleExample.dir/main_scheduleinside.cpp.o: CMakeFiles/InScheduleExample.dir/flags.make
CMakeFiles/InScheduleExample.dir/main_scheduleinside.cpp.o: ../main_scheduleinside.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alejandro/Projects/testCppCoro/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/InScheduleExample.dir/main_scheduleinside.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/InScheduleExample.dir/main_scheduleinside.cpp.o -c /home/alejandro/Projects/testCppCoro/main_scheduleinside.cpp

CMakeFiles/InScheduleExample.dir/main_scheduleinside.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/InScheduleExample.dir/main_scheduleinside.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alejandro/Projects/testCppCoro/main_scheduleinside.cpp > CMakeFiles/InScheduleExample.dir/main_scheduleinside.cpp.i

CMakeFiles/InScheduleExample.dir/main_scheduleinside.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/InScheduleExample.dir/main_scheduleinside.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alejandro/Projects/testCppCoro/main_scheduleinside.cpp -o CMakeFiles/InScheduleExample.dir/main_scheduleinside.cpp.s

# Object files for target InScheduleExample
InScheduleExample_OBJECTS = \
"CMakeFiles/InScheduleExample.dir/main_scheduleinside.cpp.o"

# External object files for target InScheduleExample
InScheduleExample_EXTERNAL_OBJECTS =

InScheduleExample: CMakeFiles/InScheduleExample.dir/main_scheduleinside.cpp.o
InScheduleExample: CMakeFiles/InScheduleExample.dir/build.make
InScheduleExample: CMakeFiles/InScheduleExample.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/alejandro/Projects/testCppCoro/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable InScheduleExample"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/InScheduleExample.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/InScheduleExample.dir/build: InScheduleExample

.PHONY : CMakeFiles/InScheduleExample.dir/build

CMakeFiles/InScheduleExample.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/InScheduleExample.dir/cmake_clean.cmake
.PHONY : CMakeFiles/InScheduleExample.dir/clean

CMakeFiles/InScheduleExample.dir/depend:
	cd /home/alejandro/Projects/testCppCoro/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/alejandro/Projects/testCppCoro /home/alejandro/Projects/testCppCoro /home/alejandro/Projects/testCppCoro/build /home/alejandro/Projects/testCppCoro/build /home/alejandro/Projects/testCppCoro/build/CMakeFiles/InScheduleExample.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/InScheduleExample.dir/depend

