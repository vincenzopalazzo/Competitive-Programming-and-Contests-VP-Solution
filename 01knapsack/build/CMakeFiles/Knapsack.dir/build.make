# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /home/vincent/Github/Competitive-Programming-and-Contests-VP-Solution/01knapsack

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/vincent/Github/Competitive-Programming-and-Contests-VP-Solution/01knapsack/build

# Include any dependencies generated for this target.
include CMakeFiles/Knapsack.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Knapsack.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Knapsack.dir/flags.make

CMakeFiles/Knapsack.dir/src/MainSite.cpp.o: CMakeFiles/Knapsack.dir/flags.make
CMakeFiles/Knapsack.dir/src/MainSite.cpp.o: ../src/MainSite.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vincent/Github/Competitive-Programming-and-Contests-VP-Solution/01knapsack/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Knapsack.dir/src/MainSite.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Knapsack.dir/src/MainSite.cpp.o -c /home/vincent/Github/Competitive-Programming-and-Contests-VP-Solution/01knapsack/src/MainSite.cpp

CMakeFiles/Knapsack.dir/src/MainSite.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Knapsack.dir/src/MainSite.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vincent/Github/Competitive-Programming-and-Contests-VP-Solution/01knapsack/src/MainSite.cpp > CMakeFiles/Knapsack.dir/src/MainSite.cpp.i

CMakeFiles/Knapsack.dir/src/MainSite.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Knapsack.dir/src/MainSite.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vincent/Github/Competitive-Programming-and-Contests-VP-Solution/01knapsack/src/MainSite.cpp -o CMakeFiles/Knapsack.dir/src/MainSite.cpp.s

CMakeFiles/Knapsack.dir/src/MainSite.cpp.o.requires:

.PHONY : CMakeFiles/Knapsack.dir/src/MainSite.cpp.o.requires

CMakeFiles/Knapsack.dir/src/MainSite.cpp.o.provides: CMakeFiles/Knapsack.dir/src/MainSite.cpp.o.requires
	$(MAKE) -f CMakeFiles/Knapsack.dir/build.make CMakeFiles/Knapsack.dir/src/MainSite.cpp.o.provides.build
.PHONY : CMakeFiles/Knapsack.dir/src/MainSite.cpp.o.provides

CMakeFiles/Knapsack.dir/src/MainSite.cpp.o.provides.build: CMakeFiles/Knapsack.dir/src/MainSite.cpp.o


# Object files for target Knapsack
Knapsack_OBJECTS = \
"CMakeFiles/Knapsack.dir/src/MainSite.cpp.o"

# External object files for target Knapsack
Knapsack_EXTERNAL_OBJECTS =

Knapsack: CMakeFiles/Knapsack.dir/src/MainSite.cpp.o
Knapsack: CMakeFiles/Knapsack.dir/build.make
Knapsack: CMakeFiles/Knapsack.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/vincent/Github/Competitive-Programming-and-Contests-VP-Solution/01knapsack/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Knapsack"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Knapsack.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Knapsack.dir/build: Knapsack

.PHONY : CMakeFiles/Knapsack.dir/build

CMakeFiles/Knapsack.dir/requires: CMakeFiles/Knapsack.dir/src/MainSite.cpp.o.requires

.PHONY : CMakeFiles/Knapsack.dir/requires

CMakeFiles/Knapsack.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Knapsack.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Knapsack.dir/clean

CMakeFiles/Knapsack.dir/depend:
	cd /home/vincent/Github/Competitive-Programming-and-Contests-VP-Solution/01knapsack/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/vincent/Github/Competitive-Programming-and-Contests-VP-Solution/01knapsack /home/vincent/Github/Competitive-Programming-and-Contests-VP-Solution/01knapsack /home/vincent/Github/Competitive-Programming-and-Contests-VP-Solution/01knapsack/build /home/vincent/Github/Competitive-Programming-and-Contests-VP-Solution/01knapsack/build /home/vincent/Github/Competitive-Programming-and-Contests-VP-Solution/01knapsack/build/CMakeFiles/Knapsack.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Knapsack.dir/depend

