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
CMAKE_SOURCE_DIR = /Users/tuhoo/Desktop/Learn_Qt_OpenCV/Chapter-02/RotatePlugin

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/tuhoo/Desktop/Learn_Qt_OpenCV/Chapter-02/RotatePlugin/build

# Include any dependencies generated for this target.
include CMakeFiles/RotatePlugin.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/RotatePlugin.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/RotatePlugin.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/RotatePlugin.dir/flags.make

CMakeFiles/RotatePlugin.dir/RotatePlugin_autogen/mocs_compilation.cpp.o: CMakeFiles/RotatePlugin.dir/flags.make
CMakeFiles/RotatePlugin.dir/RotatePlugin_autogen/mocs_compilation.cpp.o: RotatePlugin_autogen/mocs_compilation.cpp
CMakeFiles/RotatePlugin.dir/RotatePlugin_autogen/mocs_compilation.cpp.o: CMakeFiles/RotatePlugin.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/tuhoo/Desktop/Learn_Qt_OpenCV/Chapter-02/RotatePlugin/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/RotatePlugin.dir/RotatePlugin_autogen/mocs_compilation.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/RotatePlugin.dir/RotatePlugin_autogen/mocs_compilation.cpp.o -MF CMakeFiles/RotatePlugin.dir/RotatePlugin_autogen/mocs_compilation.cpp.o.d -o CMakeFiles/RotatePlugin.dir/RotatePlugin_autogen/mocs_compilation.cpp.o -c /Users/tuhoo/Desktop/Learn_Qt_OpenCV/Chapter-02/RotatePlugin/build/RotatePlugin_autogen/mocs_compilation.cpp

CMakeFiles/RotatePlugin.dir/RotatePlugin_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/RotatePlugin.dir/RotatePlugin_autogen/mocs_compilation.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/tuhoo/Desktop/Learn_Qt_OpenCV/Chapter-02/RotatePlugin/build/RotatePlugin_autogen/mocs_compilation.cpp > CMakeFiles/RotatePlugin.dir/RotatePlugin_autogen/mocs_compilation.cpp.i

CMakeFiles/RotatePlugin.dir/RotatePlugin_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/RotatePlugin.dir/RotatePlugin_autogen/mocs_compilation.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/tuhoo/Desktop/Learn_Qt_OpenCV/Chapter-02/RotatePlugin/build/RotatePlugin_autogen/mocs_compilation.cpp -o CMakeFiles/RotatePlugin.dir/RotatePlugin_autogen/mocs_compilation.cpp.s

CMakeFiles/RotatePlugin.dir/rotateplugin.cpp.o: CMakeFiles/RotatePlugin.dir/flags.make
CMakeFiles/RotatePlugin.dir/rotateplugin.cpp.o: /Users/tuhoo/Desktop/Learn_Qt_OpenCV/Chapter-02/RotatePlugin/rotateplugin.cpp
CMakeFiles/RotatePlugin.dir/rotateplugin.cpp.o: CMakeFiles/RotatePlugin.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/tuhoo/Desktop/Learn_Qt_OpenCV/Chapter-02/RotatePlugin/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/RotatePlugin.dir/rotateplugin.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/RotatePlugin.dir/rotateplugin.cpp.o -MF CMakeFiles/RotatePlugin.dir/rotateplugin.cpp.o.d -o CMakeFiles/RotatePlugin.dir/rotateplugin.cpp.o -c /Users/tuhoo/Desktop/Learn_Qt_OpenCV/Chapter-02/RotatePlugin/rotateplugin.cpp

CMakeFiles/RotatePlugin.dir/rotateplugin.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/RotatePlugin.dir/rotateplugin.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/tuhoo/Desktop/Learn_Qt_OpenCV/Chapter-02/RotatePlugin/rotateplugin.cpp > CMakeFiles/RotatePlugin.dir/rotateplugin.cpp.i

CMakeFiles/RotatePlugin.dir/rotateplugin.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/RotatePlugin.dir/rotateplugin.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/tuhoo/Desktop/Learn_Qt_OpenCV/Chapter-02/RotatePlugin/rotateplugin.cpp -o CMakeFiles/RotatePlugin.dir/rotateplugin.cpp.s

# Object files for target RotatePlugin
RotatePlugin_OBJECTS = \
"CMakeFiles/RotatePlugin.dir/RotatePlugin_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/RotatePlugin.dir/rotateplugin.cpp.o"

# External object files for target RotatePlugin
RotatePlugin_EXTERNAL_OBJECTS =

libRotatePlugin.1.0.0.dylib: CMakeFiles/RotatePlugin.dir/RotatePlugin_autogen/mocs_compilation.cpp.o
libRotatePlugin.1.0.0.dylib: CMakeFiles/RotatePlugin.dir/rotateplugin.cpp.o
libRotatePlugin.1.0.0.dylib: CMakeFiles/RotatePlugin.dir/build.make
libRotatePlugin.1.0.0.dylib: /usr/local/Qt-6.5.2/lib/QtCore.framework/Versions/A/QtCore
libRotatePlugin.1.0.0.dylib: CMakeFiles/RotatePlugin.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/tuhoo/Desktop/Learn_Qt_OpenCV/Chapter-02/RotatePlugin/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX shared library libRotatePlugin.dylib"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/RotatePlugin.dir/link.txt --verbose=$(VERBOSE)
	$(CMAKE_COMMAND) -E cmake_symlink_library libRotatePlugin.1.0.0.dylib libRotatePlugin.1.0.0.dylib libRotatePlugin.dylib

libRotatePlugin.dylib: libRotatePlugin.1.0.0.dylib
	@$(CMAKE_COMMAND) -E touch_nocreate libRotatePlugin.dylib

# Rule to build all files generated by this target.
CMakeFiles/RotatePlugin.dir/build: libRotatePlugin.dylib
.PHONY : CMakeFiles/RotatePlugin.dir/build

CMakeFiles/RotatePlugin.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/RotatePlugin.dir/cmake_clean.cmake
.PHONY : CMakeFiles/RotatePlugin.dir/clean

CMakeFiles/RotatePlugin.dir/depend:
	cd /Users/tuhoo/Desktop/Learn_Qt_OpenCV/Chapter-02/RotatePlugin/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/tuhoo/Desktop/Learn_Qt_OpenCV/Chapter-02/RotatePlugin /Users/tuhoo/Desktop/Learn_Qt_OpenCV/Chapter-02/RotatePlugin /Users/tuhoo/Desktop/Learn_Qt_OpenCV/Chapter-02/RotatePlugin/build /Users/tuhoo/Desktop/Learn_Qt_OpenCV/Chapter-02/RotatePlugin/build /Users/tuhoo/Desktop/Learn_Qt_OpenCV/Chapter-02/RotatePlugin/build/CMakeFiles/RotatePlugin.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/RotatePlugin.dir/depend

