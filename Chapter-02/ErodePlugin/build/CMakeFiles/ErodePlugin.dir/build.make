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

# Include any dependencies generated for this target.
include CMakeFiles/ErodePlugin.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/ErodePlugin.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/ErodePlugin.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ErodePlugin.dir/flags.make

CMakeFiles/ErodePlugin.dir/ErodePlugin_autogen/mocs_compilation.cpp.o: CMakeFiles/ErodePlugin.dir/flags.make
CMakeFiles/ErodePlugin.dir/ErodePlugin_autogen/mocs_compilation.cpp.o: ErodePlugin_autogen/mocs_compilation.cpp
CMakeFiles/ErodePlugin.dir/ErodePlugin_autogen/mocs_compilation.cpp.o: CMakeFiles/ErodePlugin.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/tuhoo/Desktop/Learn_Qt_OpenCV/Chapter-02/ErodePlugin/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ErodePlugin.dir/ErodePlugin_autogen/mocs_compilation.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ErodePlugin.dir/ErodePlugin_autogen/mocs_compilation.cpp.o -MF CMakeFiles/ErodePlugin.dir/ErodePlugin_autogen/mocs_compilation.cpp.o.d -o CMakeFiles/ErodePlugin.dir/ErodePlugin_autogen/mocs_compilation.cpp.o -c /Users/tuhoo/Desktop/Learn_Qt_OpenCV/Chapter-02/ErodePlugin/build/ErodePlugin_autogen/mocs_compilation.cpp

CMakeFiles/ErodePlugin.dir/ErodePlugin_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/ErodePlugin.dir/ErodePlugin_autogen/mocs_compilation.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/tuhoo/Desktop/Learn_Qt_OpenCV/Chapter-02/ErodePlugin/build/ErodePlugin_autogen/mocs_compilation.cpp > CMakeFiles/ErodePlugin.dir/ErodePlugin_autogen/mocs_compilation.cpp.i

CMakeFiles/ErodePlugin.dir/ErodePlugin_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/ErodePlugin.dir/ErodePlugin_autogen/mocs_compilation.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/tuhoo/Desktop/Learn_Qt_OpenCV/Chapter-02/ErodePlugin/build/ErodePlugin_autogen/mocs_compilation.cpp -o CMakeFiles/ErodePlugin.dir/ErodePlugin_autogen/mocs_compilation.cpp.s

CMakeFiles/ErodePlugin.dir/erode_plugin.cpp.o: CMakeFiles/ErodePlugin.dir/flags.make
CMakeFiles/ErodePlugin.dir/erode_plugin.cpp.o: /Users/tuhoo/Desktop/Learn_Qt_OpenCV/Chapter-02/ErodePlugin/erode_plugin.cpp
CMakeFiles/ErodePlugin.dir/erode_plugin.cpp.o: CMakeFiles/ErodePlugin.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/tuhoo/Desktop/Learn_Qt_OpenCV/Chapter-02/ErodePlugin/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/ErodePlugin.dir/erode_plugin.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ErodePlugin.dir/erode_plugin.cpp.o -MF CMakeFiles/ErodePlugin.dir/erode_plugin.cpp.o.d -o CMakeFiles/ErodePlugin.dir/erode_plugin.cpp.o -c /Users/tuhoo/Desktop/Learn_Qt_OpenCV/Chapter-02/ErodePlugin/erode_plugin.cpp

CMakeFiles/ErodePlugin.dir/erode_plugin.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/ErodePlugin.dir/erode_plugin.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/tuhoo/Desktop/Learn_Qt_OpenCV/Chapter-02/ErodePlugin/erode_plugin.cpp > CMakeFiles/ErodePlugin.dir/erode_plugin.cpp.i

CMakeFiles/ErodePlugin.dir/erode_plugin.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/ErodePlugin.dir/erode_plugin.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/tuhoo/Desktop/Learn_Qt_OpenCV/Chapter-02/ErodePlugin/erode_plugin.cpp -o CMakeFiles/ErodePlugin.dir/erode_plugin.cpp.s

# Object files for target ErodePlugin
ErodePlugin_OBJECTS = \
"CMakeFiles/ErodePlugin.dir/ErodePlugin_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/ErodePlugin.dir/erode_plugin.cpp.o"

# External object files for target ErodePlugin
ErodePlugin_EXTERNAL_OBJECTS =

libErodePlugin.1.0.0.dylib: CMakeFiles/ErodePlugin.dir/ErodePlugin_autogen/mocs_compilation.cpp.o
libErodePlugin.1.0.0.dylib: CMakeFiles/ErodePlugin.dir/erode_plugin.cpp.o
libErodePlugin.1.0.0.dylib: CMakeFiles/ErodePlugin.dir/build.make
libErodePlugin.1.0.0.dylib: /usr/local/Qt-6.5.2/lib/QtWidgets.framework/Versions/A/QtWidgets
libErodePlugin.1.0.0.dylib: /usr/local/Qt-6.5.2/lib/QtGui.framework/Versions/A/QtGui
libErodePlugin.1.0.0.dylib: /usr/local/Qt-6.5.2/lib/QtCore.framework/Versions/A/QtCore
libErodePlugin.1.0.0.dylib: CMakeFiles/ErodePlugin.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/tuhoo/Desktop/Learn_Qt_OpenCV/Chapter-02/ErodePlugin/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX shared library libErodePlugin.dylib"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ErodePlugin.dir/link.txt --verbose=$(VERBOSE)
	$(CMAKE_COMMAND) -E cmake_symlink_library libErodePlugin.1.0.0.dylib libErodePlugin.1.dylib libErodePlugin.dylib

libErodePlugin.1.dylib: libErodePlugin.1.0.0.dylib
	@$(CMAKE_COMMAND) -E touch_nocreate libErodePlugin.1.dylib

libErodePlugin.dylib: libErodePlugin.1.0.0.dylib
	@$(CMAKE_COMMAND) -E touch_nocreate libErodePlugin.dylib

# Rule to build all files generated by this target.
CMakeFiles/ErodePlugin.dir/build: libErodePlugin.dylib
.PHONY : CMakeFiles/ErodePlugin.dir/build

CMakeFiles/ErodePlugin.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ErodePlugin.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ErodePlugin.dir/clean

CMakeFiles/ErodePlugin.dir/depend:
	cd /Users/tuhoo/Desktop/Learn_Qt_OpenCV/Chapter-02/ErodePlugin/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/tuhoo/Desktop/Learn_Qt_OpenCV/Chapter-02/ErodePlugin /Users/tuhoo/Desktop/Learn_Qt_OpenCV/Chapter-02/ErodePlugin /Users/tuhoo/Desktop/Learn_Qt_OpenCV/Chapter-02/ErodePlugin/build /Users/tuhoo/Desktop/Learn_Qt_OpenCV/Chapter-02/ErodePlugin/build /Users/tuhoo/Desktop/Learn_Qt_OpenCV/Chapter-02/ErodePlugin/build/CMakeFiles/ErodePlugin.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/ErodePlugin.dir/depend

