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
CMAKE_SOURCE_DIR = /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11

# Include any dependencies generated for this target.
include apps/haartraining/CMakeFiles/opencv_haartraining.dir/depend.make

# Include the progress variables for this target.
include apps/haartraining/CMakeFiles/opencv_haartraining.dir/progress.make

# Include the compile flags for this target's objects.
include apps/haartraining/CMakeFiles/opencv_haartraining.dir/flags.make

apps/haartraining/CMakeFiles/opencv_haartraining.dir/haartraining.cpp.o: apps/haartraining/CMakeFiles/opencv_haartraining.dir/flags.make
apps/haartraining/CMakeFiles/opencv_haartraining.dir/haartraining.cpp.o: apps/haartraining/haartraining.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object apps/haartraining/CMakeFiles/opencv_haartraining.dir/haartraining.cpp.o"
	cd /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/apps/haartraining && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/opencv_haartraining.dir/haartraining.cpp.o -c /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/apps/haartraining/haartraining.cpp

apps/haartraining/CMakeFiles/opencv_haartraining.dir/haartraining.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opencv_haartraining.dir/haartraining.cpp.i"
	cd /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/apps/haartraining && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/apps/haartraining/haartraining.cpp > CMakeFiles/opencv_haartraining.dir/haartraining.cpp.i

apps/haartraining/CMakeFiles/opencv_haartraining.dir/haartraining.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opencv_haartraining.dir/haartraining.cpp.s"
	cd /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/apps/haartraining && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/apps/haartraining/haartraining.cpp -o CMakeFiles/opencv_haartraining.dir/haartraining.cpp.s

apps/haartraining/CMakeFiles/opencv_haartraining.dir/haartraining.cpp.o.requires:
.PHONY : apps/haartraining/CMakeFiles/opencv_haartraining.dir/haartraining.cpp.o.requires

apps/haartraining/CMakeFiles/opencv_haartraining.dir/haartraining.cpp.o.provides: apps/haartraining/CMakeFiles/opencv_haartraining.dir/haartraining.cpp.o.requires
	$(MAKE) -f apps/haartraining/CMakeFiles/opencv_haartraining.dir/build.make apps/haartraining/CMakeFiles/opencv_haartraining.dir/haartraining.cpp.o.provides.build
.PHONY : apps/haartraining/CMakeFiles/opencv_haartraining.dir/haartraining.cpp.o.provides

apps/haartraining/CMakeFiles/opencv_haartraining.dir/haartraining.cpp.o.provides.build: apps/haartraining/CMakeFiles/opencv_haartraining.dir/haartraining.cpp.o

# Object files for target opencv_haartraining
opencv_haartraining_OBJECTS = \
"CMakeFiles/opencv_haartraining.dir/haartraining.cpp.o"

# External object files for target opencv_haartraining
opencv_haartraining_EXTERNAL_OBJECTS =

bin/opencv_haartraining: apps/haartraining/CMakeFiles/opencv_haartraining.dir/haartraining.cpp.o
bin/opencv_haartraining: apps/haartraining/CMakeFiles/opencv_haartraining.dir/build.make
bin/opencv_haartraining: /usr/lib/x86_64-linux-gnu/libGLU.so
bin/opencv_haartraining: /usr/lib/x86_64-linux-gnu/libGL.so
bin/opencv_haartraining: /usr/lib/x86_64-linux-gnu/libSM.so
bin/opencv_haartraining: /usr/lib/x86_64-linux-gnu/libICE.so
bin/opencv_haartraining: /usr/lib/x86_64-linux-gnu/libX11.so
bin/opencv_haartraining: /usr/lib/x86_64-linux-gnu/libXext.so
bin/opencv_haartraining: lib/libopencv_core.so.2.4.11
bin/opencv_haartraining: lib/libopencv_imgproc.so.2.4.11
bin/opencv_haartraining: lib/libopencv_highgui.so.2.4.11
bin/opencv_haartraining: lib/libopencv_objdetect.so.2.4.11
bin/opencv_haartraining: lib/libopencv_calib3d.so.2.4.11
bin/opencv_haartraining: lib/libopencv_video.so.2.4.11
bin/opencv_haartraining: lib/libopencv_features2d.so.2.4.11
bin/opencv_haartraining: lib/libopencv_flann.so.2.4.11
bin/opencv_haartraining: lib/libopencv_legacy.so.2.4.11
bin/opencv_haartraining: lib/libopencv_haartraining_engine.a
bin/opencv_haartraining: /usr/lib/x86_64-linux-gnu/libGLU.so
bin/opencv_haartraining: /usr/lib/x86_64-linux-gnu/libGL.so
bin/opencv_haartraining: /usr/lib/x86_64-linux-gnu/libSM.so
bin/opencv_haartraining: /usr/lib/x86_64-linux-gnu/libICE.so
bin/opencv_haartraining: /usr/lib/x86_64-linux-gnu/libX11.so
bin/opencv_haartraining: /usr/lib/x86_64-linux-gnu/libXext.so
bin/opencv_haartraining: lib/libopencv_objdetect.so.2.4.11
bin/opencv_haartraining: lib/libopencv_legacy.so.2.4.11
bin/opencv_haartraining: lib/libopencv_calib3d.so.2.4.11
bin/opencv_haartraining: lib/libopencv_video.so.2.4.11
bin/opencv_haartraining: lib/libopencv_features2d.so.2.4.11
bin/opencv_haartraining: lib/libopencv_highgui.so.2.4.11
bin/opencv_haartraining: lib/libopencv_imgproc.so.2.4.11
bin/opencv_haartraining: lib/libopencv_flann.so.2.4.11
bin/opencv_haartraining: lib/libopencv_ml.so.2.4.11
bin/opencv_haartraining: lib/libopencv_core.so.2.4.11
bin/opencv_haartraining: apps/haartraining/CMakeFiles/opencv_haartraining.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable ../../bin/opencv_haartraining"
	cd /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/apps/haartraining && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/opencv_haartraining.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
apps/haartraining/CMakeFiles/opencv_haartraining.dir/build: bin/opencv_haartraining
.PHONY : apps/haartraining/CMakeFiles/opencv_haartraining.dir/build

apps/haartraining/CMakeFiles/opencv_haartraining.dir/requires: apps/haartraining/CMakeFiles/opencv_haartraining.dir/haartraining.cpp.o.requires
.PHONY : apps/haartraining/CMakeFiles/opencv_haartraining.dir/requires

apps/haartraining/CMakeFiles/opencv_haartraining.dir/clean:
	cd /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/apps/haartraining && $(CMAKE_COMMAND) -P CMakeFiles/opencv_haartraining.dir/cmake_clean.cmake
.PHONY : apps/haartraining/CMakeFiles/opencv_haartraining.dir/clean

apps/haartraining/CMakeFiles/opencv_haartraining.dir/depend:
	cd /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11 /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/apps/haartraining /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11 /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/apps/haartraining /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/apps/haartraining/CMakeFiles/opencv_haartraining.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : apps/haartraining/CMakeFiles/opencv_haartraining.dir/depend

