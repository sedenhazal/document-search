# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

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
CMAKE_COMMAND = /snap/cmake/697/bin/cmake

# The command to remove a file.
RM = /snap/cmake/697/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/hazalg/Documents/document-search/googletests

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/hazalg/Documents/document-search/googletests

# Include any dependencies generated for this target.
include CMakeFiles/executeSearchTest.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/executeSearchTest.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/executeSearchTest.dir/flags.make

CMakeFiles/executeSearchTest.dir/search_test.cpp.o: CMakeFiles/executeSearchTest.dir/flags.make
CMakeFiles/executeSearchTest.dir/search_test.cpp.o: search_test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hazalg/Documents/document-search/googletests/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/executeSearchTest.dir/search_test.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/executeSearchTest.dir/search_test.cpp.o -c /home/hazalg/Documents/document-search/googletests/search_test.cpp

CMakeFiles/executeSearchTest.dir/search_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/executeSearchTest.dir/search_test.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hazalg/Documents/document-search/googletests/search_test.cpp > CMakeFiles/executeSearchTest.dir/search_test.cpp.i

CMakeFiles/executeSearchTest.dir/search_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/executeSearchTest.dir/search_test.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hazalg/Documents/document-search/googletests/search_test.cpp -o CMakeFiles/executeSearchTest.dir/search_test.cpp.s

# Object files for target executeSearchTest
executeSearchTest_OBJECTS = \
"CMakeFiles/executeSearchTest.dir/search_test.cpp.o"

# External object files for target executeSearchTest
executeSearchTest_EXTERNAL_OBJECTS =

executeSearchTest: CMakeFiles/executeSearchTest.dir/search_test.cpp.o
executeSearchTest: CMakeFiles/executeSearchTest.dir/build.make
executeSearchTest: /usr/lib/libgtest.a
executeSearchTest: CMakeFiles/executeSearchTest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/hazalg/Documents/document-search/googletests/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable executeSearchTest"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/executeSearchTest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/executeSearchTest.dir/build: executeSearchTest

.PHONY : CMakeFiles/executeSearchTest.dir/build

CMakeFiles/executeSearchTest.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/executeSearchTest.dir/cmake_clean.cmake
.PHONY : CMakeFiles/executeSearchTest.dir/clean

CMakeFiles/executeSearchTest.dir/depend:
	cd /home/hazalg/Documents/document-search/googletests && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/hazalg/Documents/document-search/googletests /home/hazalg/Documents/document-search/googletests /home/hazalg/Documents/document-search/googletests /home/hazalg/Documents/document-search/googletests /home/hazalg/Documents/document-search/googletests/CMakeFiles/executeSearchTest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/executeSearchTest.dir/depend
