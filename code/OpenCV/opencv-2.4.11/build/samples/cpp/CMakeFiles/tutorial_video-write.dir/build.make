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
CMAKE_BINARY_DIR = /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/build

# Include any dependencies generated for this target.
include samples/cpp/CMakeFiles/tutorial_video-write.dir/depend.make

# Include the progress variables for this target.
include samples/cpp/CMakeFiles/tutorial_video-write.dir/progress.make

# Include the compile flags for this target's objects.
include samples/cpp/CMakeFiles/tutorial_video-write.dir/flags.make

samples/cpp/CMakeFiles/tutorial_video-write.dir/tutorial_code/HighGUI/video-write/video-write.cpp.o: samples/cpp/CMakeFiles/tutorial_video-write.dir/flags.make
samples/cpp/CMakeFiles/tutorial_video-write.dir/tutorial_code/HighGUI/video-write/video-write.cpp.o: ../samples/cpp/tutorial_code/HighGUI/video-write/video-write.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object samples/cpp/CMakeFiles/tutorial_video-write.dir/tutorial_code/HighGUI/video-write/video-write.cpp.o"
	cd /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/build/samples/cpp && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/tutorial_video-write.dir/tutorial_code/HighGUI/video-write/video-write.cpp.o -c /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/tutorial_code/HighGUI/video-write/video-write.cpp

samples/cpp/CMakeFiles/tutorial_video-write.dir/tutorial_code/HighGUI/video-write/video-write.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tutorial_video-write.dir/tutorial_code/HighGUI/video-write/video-write.cpp.i"
	cd /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/build/samples/cpp && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/tutorial_code/HighGUI/video-write/video-write.cpp > CMakeFiles/tutorial_video-write.dir/tutorial_code/HighGUI/video-write/video-write.cpp.i

samples/cpp/CMakeFiles/tutorial_video-write.dir/tutorial_code/HighGUI/video-write/video-write.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tutorial_video-write.dir/tutorial_code/HighGUI/video-write/video-write.cpp.s"
	cd /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/build/samples/cpp && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/tutorial_code/HighGUI/video-write/video-write.cpp -o CMakeFiles/tutorial_video-write.dir/tutorial_code/HighGUI/video-write/video-write.cpp.s

samples/cpp/CMakeFiles/tutorial_video-write.dir/tutorial_code/HighGUI/video-write/video-write.cpp.o.requires:
.PHONY : samples/cpp/CMakeFiles/tutorial_video-write.dir/tutorial_code/HighGUI/video-write/video-write.cpp.o.requires

samples/cpp/CMakeFiles/tutorial_video-write.dir/tutorial_code/HighGUI/video-write/video-write.cpp.o.provides: samples/cpp/CMakeFiles/tutorial_video-write.dir/tutorial_code/HighGUI/video-write/video-write.cpp.o.requires
	$(MAKE) -f samples/cpp/CMakeFiles/tutorial_video-write.dir/build.make samples/cpp/CMakeFiles/tutorial_video-write.dir/tutorial_code/HighGUI/video-write/video-write.cpp.o.provides.build
.PHONY : samples/cpp/CMakeFiles/tutorial_video-write.dir/tutorial_code/HighGUI/video-write/video-write.cpp.o.provides

samples/cpp/CMakeFiles/tutorial_video-write.dir/tutorial_code/HighGUI/video-write/video-write.cpp.o.provides.build: samples/cpp/CMakeFiles/tutorial_video-write.dir/tutorial_code/HighGUI/video-write/video-write.cpp.o

# Object files for target tutorial_video-write
tutorial_video__write_OBJECTS = \
"CMakeFiles/tutorial_video-write.dir/tutorial_code/HighGUI/video-write/video-write.cpp.o"

# External object files for target tutorial_video-write
tutorial_video__write_EXTERNAL_OBJECTS =

bin/cpp-tutorial-video-write: samples/cpp/CMakeFiles/tutorial_video-write.dir/tutorial_code/HighGUI/video-write/video-write.cpp.o
bin/cpp-tutorial-video-write: samples/cpp/CMakeFiles/tutorial_video-write.dir/build.make
bin/cpp-tutorial-video-write: /usr/lib/x86_64-linux-gnu/libGLU.so
bin/cpp-tutorial-video-write: /usr/lib/x86_64-linux-gnu/libGL.so
bin/cpp-tutorial-video-write: /usr/lib/x86_64-linux-gnu/libSM.so
bin/cpp-tutorial-video-write: /usr/lib/x86_64-linux-gnu/libICE.so
bin/cpp-tutorial-video-write: /usr/lib/x86_64-linux-gnu/libX11.so
bin/cpp-tutorial-video-write: /usr/lib/x86_64-linux-gnu/libXext.so
bin/cpp-tutorial-video-write: lib/libopencv_core.so.2.4.11
bin/cpp-tutorial-video-write: lib/libopencv_flann.so.2.4.11
bin/cpp-tutorial-video-write: lib/libopencv_imgproc.so.2.4.11
bin/cpp-tutorial-video-write: lib/libopencv_highgui.so.2.4.11
bin/cpp-tutorial-video-write: lib/libopencv_ml.so.2.4.11
bin/cpp-tutorial-video-write: lib/libopencv_video.so.2.4.11
bin/cpp-tutorial-video-write: lib/libopencv_objdetect.so.2.4.11
bin/cpp-tutorial-video-write: lib/libopencv_photo.so.2.4.11
bin/cpp-tutorial-video-write: lib/libopencv_nonfree.so.2.4.11
bin/cpp-tutorial-video-write: lib/libopencv_features2d.so.2.4.11
bin/cpp-tutorial-video-write: lib/libopencv_calib3d.so.2.4.11
bin/cpp-tutorial-video-write: lib/libopencv_legacy.so.2.4.11
bin/cpp-tutorial-video-write: lib/libopencv_contrib.so.2.4.11
bin/cpp-tutorial-video-write: lib/libopencv_stitching.so.2.4.11
bin/cpp-tutorial-video-write: lib/libopencv_videostab.so.2.4.11
bin/cpp-tutorial-video-write: lib/libopencv_gpu.so.2.4.11
bin/cpp-tutorial-video-write: lib/libopencv_ocl.so.2.4.11
bin/cpp-tutorial-video-write: lib/libopencv_nonfree.so.2.4.11
bin/cpp-tutorial-video-write: lib/libopencv_ocl.so.2.4.11
bin/cpp-tutorial-video-write: lib/libopencv_gpu.so.2.4.11
bin/cpp-tutorial-video-write: lib/libopencv_objdetect.so.2.4.11
bin/cpp-tutorial-video-write: lib/libopencv_photo.so.2.4.11
bin/cpp-tutorial-video-write: lib/libopencv_legacy.so.2.4.11
bin/cpp-tutorial-video-write: lib/libopencv_ml.so.2.4.11
bin/cpp-tutorial-video-write: lib/libopencv_video.so.2.4.11
bin/cpp-tutorial-video-write: lib/libopencv_calib3d.so.2.4.11
bin/cpp-tutorial-video-write: lib/libopencv_features2d.so.2.4.11
bin/cpp-tutorial-video-write: lib/libopencv_flann.so.2.4.11
bin/cpp-tutorial-video-write: lib/libopencv_highgui.so.2.4.11
bin/cpp-tutorial-video-write: lib/libopencv_imgproc.so.2.4.11
bin/cpp-tutorial-video-write: lib/libopencv_core.so.2.4.11
bin/cpp-tutorial-video-write: samples/cpp/CMakeFiles/tutorial_video-write.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable ../../bin/cpp-tutorial-video-write"
	cd /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/build/samples/cpp && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tutorial_video-write.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
samples/cpp/CMakeFiles/tutorial_video-write.dir/build: bin/cpp-tutorial-video-write
.PHONY : samples/cpp/CMakeFiles/tutorial_video-write.dir/build

samples/cpp/CMakeFiles/tutorial_video-write.dir/requires: samples/cpp/CMakeFiles/tutorial_video-write.dir/tutorial_code/HighGUI/video-write/video-write.cpp.o.requires
.PHONY : samples/cpp/CMakeFiles/tutorial_video-write.dir/requires

samples/cpp/CMakeFiles/tutorial_video-write.dir/clean:
	cd /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/build/samples/cpp && $(CMAKE_COMMAND) -P CMakeFiles/tutorial_video-write.dir/cmake_clean.cmake
.PHONY : samples/cpp/CMakeFiles/tutorial_video-write.dir/clean

samples/cpp/CMakeFiles/tutorial_video-write.dir/depend:
	cd /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11 /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/build /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/build/samples/cpp /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/build/samples/cpp/CMakeFiles/tutorial_video-write.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : samples/cpp/CMakeFiles/tutorial_video-write.dir/depend

