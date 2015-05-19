# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/terence/finalyear/project/code/aruco-1.2.5

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/terence/finalyear/project/code/aruco-1.2.5/build

# Include any dependencies generated for this target.
include utils/CMakeFiles/aruco_create_board.dir/depend.make

# Include the progress variables for this target.
include utils/CMakeFiles/aruco_create_board.dir/progress.make

# Include the compile flags for this target's objects.
include utils/CMakeFiles/aruco_create_board.dir/flags.make

utils/CMakeFiles/aruco_create_board.dir/aruco_create_board.cpp.o: utils/CMakeFiles/aruco_create_board.dir/flags.make
utils/CMakeFiles/aruco_create_board.dir/aruco_create_board.cpp.o: ../utils/aruco_create_board.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/terence/finalyear/project/code/aruco-1.2.5/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object utils/CMakeFiles/aruco_create_board.dir/aruco_create_board.cpp.o"
	cd /home/terence/finalyear/project/code/aruco-1.2.5/build/utils && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/aruco_create_board.dir/aruco_create_board.cpp.o -c /home/terence/finalyear/project/code/aruco-1.2.5/utils/aruco_create_board.cpp

utils/CMakeFiles/aruco_create_board.dir/aruco_create_board.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/aruco_create_board.dir/aruco_create_board.cpp.i"
	cd /home/terence/finalyear/project/code/aruco-1.2.5/build/utils && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/terence/finalyear/project/code/aruco-1.2.5/utils/aruco_create_board.cpp > CMakeFiles/aruco_create_board.dir/aruco_create_board.cpp.i

utils/CMakeFiles/aruco_create_board.dir/aruco_create_board.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/aruco_create_board.dir/aruco_create_board.cpp.s"
	cd /home/terence/finalyear/project/code/aruco-1.2.5/build/utils && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/terence/finalyear/project/code/aruco-1.2.5/utils/aruco_create_board.cpp -o CMakeFiles/aruco_create_board.dir/aruco_create_board.cpp.s

utils/CMakeFiles/aruco_create_board.dir/aruco_create_board.cpp.o.requires:
.PHONY : utils/CMakeFiles/aruco_create_board.dir/aruco_create_board.cpp.o.requires

utils/CMakeFiles/aruco_create_board.dir/aruco_create_board.cpp.o.provides: utils/CMakeFiles/aruco_create_board.dir/aruco_create_board.cpp.o.requires
	$(MAKE) -f utils/CMakeFiles/aruco_create_board.dir/build.make utils/CMakeFiles/aruco_create_board.dir/aruco_create_board.cpp.o.provides.build
.PHONY : utils/CMakeFiles/aruco_create_board.dir/aruco_create_board.cpp.o.provides

utils/CMakeFiles/aruco_create_board.dir/aruco_create_board.cpp.o.provides.build: utils/CMakeFiles/aruco_create_board.dir/aruco_create_board.cpp.o

# Object files for target aruco_create_board
aruco_create_board_OBJECTS = \
"CMakeFiles/aruco_create_board.dir/aruco_create_board.cpp.o"

# External object files for target aruco_create_board
aruco_create_board_EXTERNAL_OBJECTS =

utils/aruco_create_board: utils/CMakeFiles/aruco_create_board.dir/aruco_create_board.cpp.o
utils/aruco_create_board: utils/CMakeFiles/aruco_create_board.dir/build.make
utils/aruco_create_board: src/libaruco.so.1.2.5
utils/aruco_create_board: /usr/local/lib/libopencv_videostab.so.2.4.11
utils/aruco_create_board: /usr/local/lib/libopencv_video.so.2.4.11
utils/aruco_create_board: /usr/local/lib/libopencv_ts.a
utils/aruco_create_board: /usr/local/lib/libopencv_superres.so.2.4.11
utils/aruco_create_board: /usr/local/lib/libopencv_stitching.so.2.4.11
utils/aruco_create_board: /usr/local/lib/libopencv_photo.so.2.4.11
utils/aruco_create_board: /usr/local/lib/libopencv_ocl.so.2.4.11
utils/aruco_create_board: /usr/local/lib/libopencv_objdetect.so.2.4.11
utils/aruco_create_board: /usr/local/lib/libopencv_nonfree.so.2.4.11
utils/aruco_create_board: /usr/local/lib/libopencv_ml.so.2.4.11
utils/aruco_create_board: /usr/local/lib/libopencv_legacy.so.2.4.11
utils/aruco_create_board: /usr/local/lib/libopencv_imgproc.so.2.4.11
utils/aruco_create_board: /usr/local/lib/libopencv_highgui.so.2.4.11
utils/aruco_create_board: /usr/local/lib/libopencv_gpu.so.2.4.11
utils/aruco_create_board: /usr/local/lib/libopencv_flann.so.2.4.11
utils/aruco_create_board: /usr/local/lib/libopencv_features2d.so.2.4.11
utils/aruco_create_board: /usr/local/lib/libopencv_core.so.2.4.11
utils/aruco_create_board: /usr/local/lib/libopencv_contrib.so.2.4.11
utils/aruco_create_board: /usr/local/lib/libopencv_calib3d.so.2.4.11
utils/aruco_create_board: /usr/lib/x86_64-linux-gnu/libGLU.so
utils/aruco_create_board: /usr/lib/x86_64-linux-gnu/libGL.so
utils/aruco_create_board: /usr/lib/x86_64-linux-gnu/libSM.so
utils/aruco_create_board: /usr/lib/x86_64-linux-gnu/libICE.so
utils/aruco_create_board: /usr/lib/x86_64-linux-gnu/libX11.so
utils/aruco_create_board: /usr/lib/x86_64-linux-gnu/libXext.so
utils/aruco_create_board: /usr/local/lib/libopencv_nonfree.so.2.4.11
utils/aruco_create_board: /usr/local/lib/libopencv_ocl.so.2.4.11
utils/aruco_create_board: /usr/local/lib/libopencv_gpu.so.2.4.11
utils/aruco_create_board: /usr/local/lib/libopencv_photo.so.2.4.11
utils/aruco_create_board: /usr/local/lib/libopencv_objdetect.so.2.4.11
utils/aruco_create_board: /usr/local/lib/libopencv_legacy.so.2.4.11
utils/aruco_create_board: /usr/local/lib/libopencv_video.so.2.4.11
utils/aruco_create_board: /usr/local/lib/libopencv_ml.so.2.4.11
utils/aruco_create_board: /usr/local/lib/libopencv_calib3d.so.2.4.11
utils/aruco_create_board: /usr/local/lib/libopencv_features2d.so.2.4.11
utils/aruco_create_board: /usr/local/lib/libopencv_highgui.so.2.4.11
utils/aruco_create_board: /usr/local/lib/libopencv_imgproc.so.2.4.11
utils/aruco_create_board: /usr/local/lib/libopencv_flann.so.2.4.11
utils/aruco_create_board: /usr/local/lib/libopencv_core.so.2.4.11
utils/aruco_create_board: utils/CMakeFiles/aruco_create_board.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable aruco_create_board"
	cd /home/terence/finalyear/project/code/aruco-1.2.5/build/utils && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/aruco_create_board.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
utils/CMakeFiles/aruco_create_board.dir/build: utils/aruco_create_board
.PHONY : utils/CMakeFiles/aruco_create_board.dir/build

utils/CMakeFiles/aruco_create_board.dir/requires: utils/CMakeFiles/aruco_create_board.dir/aruco_create_board.cpp.o.requires
.PHONY : utils/CMakeFiles/aruco_create_board.dir/requires

utils/CMakeFiles/aruco_create_board.dir/clean:
	cd /home/terence/finalyear/project/code/aruco-1.2.5/build/utils && $(CMAKE_COMMAND) -P CMakeFiles/aruco_create_board.dir/cmake_clean.cmake
.PHONY : utils/CMakeFiles/aruco_create_board.dir/clean

utils/CMakeFiles/aruco_create_board.dir/depend:
	cd /home/terence/finalyear/project/code/aruco-1.2.5/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/terence/finalyear/project/code/aruco-1.2.5 /home/terence/finalyear/project/code/aruco-1.2.5/utils /home/terence/finalyear/project/code/aruco-1.2.5/build /home/terence/finalyear/project/code/aruco-1.2.5/build/utils /home/terence/finalyear/project/code/aruco-1.2.5/build/utils/CMakeFiles/aruco_create_board.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : utils/CMakeFiles/aruco_create_board.dir/depend

