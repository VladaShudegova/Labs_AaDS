# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.23

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/vladashudegova/dev/repos/Labs_AaDS/Lab2BinaryTree

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/vladashudegova/dev/repos/Labs_AaDS/Lab2BinaryTree/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Labs_Tree.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Labs_Tree.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Labs_Tree.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Labs_Tree.dir/flags.make

CMakeFiles/Labs_Tree.dir/main.cpp.o: CMakeFiles/Labs_Tree.dir/flags.make
CMakeFiles/Labs_Tree.dir/main.cpp.o: ../main.cpp
CMakeFiles/Labs_Tree.dir/main.cpp.o: CMakeFiles/Labs_Tree.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/vladashudegova/dev/repos/Labs_AaDS/Lab2BinaryTree/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Labs_Tree.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Labs_Tree.dir/main.cpp.o -MF CMakeFiles/Labs_Tree.dir/main.cpp.o.d -o CMakeFiles/Labs_Tree.dir/main.cpp.o -c /Users/vladashudegova/dev/repos/Labs_AaDS/Lab2BinaryTree/main.cpp

CMakeFiles/Labs_Tree.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Labs_Tree.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/vladashudegova/dev/repos/Labs_AaDS/Lab2BinaryTree/main.cpp > CMakeFiles/Labs_Tree.dir/main.cpp.i

CMakeFiles/Labs_Tree.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Labs_Tree.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/vladashudegova/dev/repos/Labs_AaDS/Lab2BinaryTree/main.cpp -o CMakeFiles/Labs_Tree.dir/main.cpp.s

CMakeFiles/Labs_Tree.dir/Node.cpp.o: CMakeFiles/Labs_Tree.dir/flags.make
CMakeFiles/Labs_Tree.dir/Node.cpp.o: ../Node.cpp
CMakeFiles/Labs_Tree.dir/Node.cpp.o: CMakeFiles/Labs_Tree.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/vladashudegova/dev/repos/Labs_AaDS/Lab2BinaryTree/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Labs_Tree.dir/Node.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Labs_Tree.dir/Node.cpp.o -MF CMakeFiles/Labs_Tree.dir/Node.cpp.o.d -o CMakeFiles/Labs_Tree.dir/Node.cpp.o -c /Users/vladashudegova/dev/repos/Labs_AaDS/Lab2BinaryTree/Node.cpp

CMakeFiles/Labs_Tree.dir/Node.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Labs_Tree.dir/Node.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/vladashudegova/dev/repos/Labs_AaDS/Lab2BinaryTree/Node.cpp > CMakeFiles/Labs_Tree.dir/Node.cpp.i

CMakeFiles/Labs_Tree.dir/Node.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Labs_Tree.dir/Node.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/vladashudegova/dev/repos/Labs_AaDS/Lab2BinaryTree/Node.cpp -o CMakeFiles/Labs_Tree.dir/Node.cpp.s

CMakeFiles/Labs_Tree.dir/BinaryTree.cpp.o: CMakeFiles/Labs_Tree.dir/flags.make
CMakeFiles/Labs_Tree.dir/BinaryTree.cpp.o: ../BinaryTree.cpp
CMakeFiles/Labs_Tree.dir/BinaryTree.cpp.o: CMakeFiles/Labs_Tree.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/vladashudegova/dev/repos/Labs_AaDS/Lab2BinaryTree/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Labs_Tree.dir/BinaryTree.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Labs_Tree.dir/BinaryTree.cpp.o -MF CMakeFiles/Labs_Tree.dir/BinaryTree.cpp.o.d -o CMakeFiles/Labs_Tree.dir/BinaryTree.cpp.o -c /Users/vladashudegova/dev/repos/Labs_AaDS/Lab2BinaryTree/BinaryTree.cpp

CMakeFiles/Labs_Tree.dir/BinaryTree.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Labs_Tree.dir/BinaryTree.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/vladashudegova/dev/repos/Labs_AaDS/Lab2BinaryTree/BinaryTree.cpp > CMakeFiles/Labs_Tree.dir/BinaryTree.cpp.i

CMakeFiles/Labs_Tree.dir/BinaryTree.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Labs_Tree.dir/BinaryTree.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/vladashudegova/dev/repos/Labs_AaDS/Lab2BinaryTree/BinaryTree.cpp -o CMakeFiles/Labs_Tree.dir/BinaryTree.cpp.s

CMakeFiles/Labs_Tree.dir/BinaryTreeTester.cpp.o: CMakeFiles/Labs_Tree.dir/flags.make
CMakeFiles/Labs_Tree.dir/BinaryTreeTester.cpp.o: ../BinaryTreeTester.cpp
CMakeFiles/Labs_Tree.dir/BinaryTreeTester.cpp.o: CMakeFiles/Labs_Tree.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/vladashudegova/dev/repos/Labs_AaDS/Lab2BinaryTree/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Labs_Tree.dir/BinaryTreeTester.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Labs_Tree.dir/BinaryTreeTester.cpp.o -MF CMakeFiles/Labs_Tree.dir/BinaryTreeTester.cpp.o.d -o CMakeFiles/Labs_Tree.dir/BinaryTreeTester.cpp.o -c /Users/vladashudegova/dev/repos/Labs_AaDS/Lab2BinaryTree/BinaryTreeTester.cpp

CMakeFiles/Labs_Tree.dir/BinaryTreeTester.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Labs_Tree.dir/BinaryTreeTester.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/vladashudegova/dev/repos/Labs_AaDS/Lab2BinaryTree/BinaryTreeTester.cpp > CMakeFiles/Labs_Tree.dir/BinaryTreeTester.cpp.i

CMakeFiles/Labs_Tree.dir/BinaryTreeTester.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Labs_Tree.dir/BinaryTreeTester.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/vladashudegova/dev/repos/Labs_AaDS/Lab2BinaryTree/BinaryTreeTester.cpp -o CMakeFiles/Labs_Tree.dir/BinaryTreeTester.cpp.s

# Object files for target Labs_Tree
Labs_Tree_OBJECTS = \
"CMakeFiles/Labs_Tree.dir/main.cpp.o" \
"CMakeFiles/Labs_Tree.dir/Node.cpp.o" \
"CMakeFiles/Labs_Tree.dir/BinaryTree.cpp.o" \
"CMakeFiles/Labs_Tree.dir/BinaryTreeTester.cpp.o"

# External object files for target Labs_Tree
Labs_Tree_EXTERNAL_OBJECTS =

Labs_Tree: CMakeFiles/Labs_Tree.dir/main.cpp.o
Labs_Tree: CMakeFiles/Labs_Tree.dir/Node.cpp.o
Labs_Tree: CMakeFiles/Labs_Tree.dir/BinaryTree.cpp.o
Labs_Tree: CMakeFiles/Labs_Tree.dir/BinaryTreeTester.cpp.o
Labs_Tree: CMakeFiles/Labs_Tree.dir/build.make
Labs_Tree: CMakeFiles/Labs_Tree.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/vladashudegova/dev/repos/Labs_AaDS/Lab2BinaryTree/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable Labs_Tree"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Labs_Tree.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Labs_Tree.dir/build: Labs_Tree
.PHONY : CMakeFiles/Labs_Tree.dir/build

CMakeFiles/Labs_Tree.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Labs_Tree.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Labs_Tree.dir/clean

CMakeFiles/Labs_Tree.dir/depend:
	cd /Users/vladashudegova/dev/repos/Labs_AaDS/Lab2BinaryTree/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/vladashudegova/dev/repos/Labs_AaDS/Lab2BinaryTree /Users/vladashudegova/dev/repos/Labs_AaDS/Lab2BinaryTree /Users/vladashudegova/dev/repos/Labs_AaDS/Lab2BinaryTree/cmake-build-debug /Users/vladashudegova/dev/repos/Labs_AaDS/Lab2BinaryTree/cmake-build-debug /Users/vladashudegova/dev/repos/Labs_AaDS/Lab2BinaryTree/cmake-build-debug/CMakeFiles/Labs_Tree.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Labs_Tree.dir/depend

