# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.27.1/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.27.1/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/tuhoo/Desktop/Learn_Qt_OpenCV/Chapter-02/ErodePlugin

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/tuhoo/Desktop/Learn_Qt_OpenCV/Chapter-02/ErodePlugin/build

# Utility rule file for ErodePlugin_autogen.

# Include any custom commands dependencies for this target.
include CMakeFiles/ErodePlugin_autogen.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/ErodePlugin_autogen.dir/progress.make

CMakeFiles/ErodePlugin_autogen:
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/tuhoo/Desktop/Learn_Qt_OpenCV/Chapter-02/ErodePlugin/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and UIC for target ErodePlugin"
	/opt/homebrew/Cellar/cmake/3.27.1/bin/cmake -E cmake_autogen /Users/tuhoo/Desktop/Learn_Qt_OpenCV/Chapter-02/ErodePlugin/build/CMakeFiles/ErodePlugin_autogen.dir/AutogenInfo.json ""

ErodePlugin_autogen: CMakeFiles/ErodePlugin_autogen
ErodePlugin_autogen: CMakeFiles/ErodePlugin_autogen.dir/build.make
.PHONY : ErodePlugin_autogen

# Rule to build all files generated by this target.
CMakeFiles/ErodePlugin_autogen.dir/build: ErodePlugin_autogen
.PHONY : CMakeFiles/ErodePlugin_autogen.dir/build

CMakeFiles/ErodePlugin_autogen.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ErodePlugin_autogen.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ErodePlugin_autogen.dir/clean

CMakeFiles/ErodePlugin_autogen.dir/depend:
	cd /Users/tuhoo/Desktop/Learn_Qt_OpenCV/Chapter-02/ErodePlugin/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/tuhoo/Desktop/Learn_Qt_OpenCV/Chapter-02/ErodePlugin /Users/tuhoo/Desktop/Learn_Qt_OpenCV/Chapter-02/ErodePlugin /Users/tuhoo/Desktop/Learn_Qt_OpenCV/Chapter-02/ErodePlugin/build /Users/tuhoo/Desktop/Learn_Qt_OpenCV/Chapter-02/ErodePlugin/build /Users/tuhoo/Desktop/Learn_Qt_OpenCV/Chapter-02/ErodePlugin/build/CMakeFiles/ErodePlugin_autogen.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/ErodePlugin_autogen.dir/depend

