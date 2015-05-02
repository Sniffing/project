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
CMAKE_SOURCE_DIR = /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples

# Include any dependencies generated for this target.
include cpp/CMakeFiles/example_calibration.dir/depend.make

# Include the progress variables for this target.
include cpp/CMakeFiles/example_calibration.dir/progress.make

# Include the compile flags for this target's objects.
include cpp/CMakeFiles/example_calibration.dir/flags.make

cpp/CMakeFiles/example_calibration.dir/calibration.cpp.o: cpp/CMakeFiles/example_calibration.dir/flags.make
cpp/CMakeFiles/example_calibration.dir/calibration.cpp.o: cpp/calibration.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object cpp/CMakeFiles/example_calibration.dir/calibration.cpp.o"
	cd /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/example_calibration.dir/calibration.cpp.o -c /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/calibration.cpp

cpp/CMakeFiles/example_calibration.dir/calibration.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/example_calibration.dir/calibration.cpp.i"
	cd /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/calibration.cpp > CMakeFiles/example_calibration.dir/calibration.cpp.i

cpp/CMakeFiles/example_calibration.dir/calibration.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/example_calibration.dir/calibration.cpp.s"
	cd /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/calibration.cpp -o CMakeFiles/example_calibration.dir/calibration.cpp.s

cpp/CMakeFiles/example_calibration.dir/calibration.cpp.o.requires:
.PHONY : cpp/CMakeFiles/example_calibration.dir/calibration.cpp.o.requires

cpp/CMakeFiles/example_calibration.dir/calibration.cpp.o.provides: cpp/CMakeFiles/example_calibration.dir/calibration.cpp.o.requires
	$(MAKE) -f cpp/CMakeFiles/example_calibration.dir/build.make cpp/CMakeFiles/example_calibration.dir/calibration.cpp.o.provides.build
.PHONY : cpp/CMakeFiles/example_calibration.dir/calibration.cpp.o.provides

cpp/CMakeFiles/example_calibration.dir/calibration.cpp.o.provides.build: cpp/CMakeFiles/example_calibration.dir/calibration.cpp.o

# Object files for target example_calibration
example_calibration_OBJECTS = \
"CMakeFiles/example_calibration.dir/calibration.cpp.o"

# External object files for target example_calibration
example_calibration_EXTERNAL_OBJECTS =

cpp/cpp-example-calibration: cpp/CMakeFiles/example_calibration.dir/calibration.cpp.o
cpp/cpp-example-calibration: cpp/CMakeFiles/example_calibration.dir/build.make
cpp/cpp-example-calibration: /usr/local/lib/libopencv_core.so.2.4.11
cpp/cpp-example-calibration: /usr/local/lib/libopencv_flann.so.2.4.11
cpp/cpp-example-calibration: /usr/local/lib/libopencv_imgproc.so.2.4.11
cpp/cpp-example-calibration: /usr/local/lib/libopencv_highgui.so.2.4.11
cpp/cpp-example-calibration: /usr/local/lib/libopencv_ml.so.2.4.11
cpp/cpp-example-calibration: /usr/local/lib/libopencv_video.so.2.4.11
cpp/cpp-example-calibration: /usr/local/lib/libopencv_objdetect.so.2.4.11
cpp/cpp-example-calibration: /usr/local/lib/libopencv_photo.so.2.4.11
cpp/cpp-example-calibration: /usr/local/lib/libopencv_nonfree.so.2.4.11
cpp/cpp-example-calibration: /usr/local/lib/libopencv_features2d.so.2.4.11
cpp/cpp-example-calibration: /usr/local/lib/libopencv_calib3d.so.2.4.11
cpp/cpp-example-calibration: /usr/local/lib/libopencv_legacy.so.2.4.11
cpp/cpp-example-calibration: /usr/local/lib/libopencv_contrib.so.2.4.11
cpp/cpp-example-calibration: /usr/local/lib/libopencv_stitching.so.2.4.11
cpp/cpp-example-calibration: /usr/local/lib/libopencv_videostab.so.2.4.11
cpp/cpp-example-calibration: /usr/local/lib/libopencv_nonfree.so.2.4.11
cpp/cpp-example-calibration: /usr/local/lib/libopencv_ocl.so.2.4.11
cpp/cpp-example-calibration: /usr/local/lib/libopencv_gpu.so.2.4.11
cpp/cpp-example-calibration: /usr/local/lib/libopencv_objdetect.so.2.4.11
cpp/cpp-example-calibration: /usr/local/lib/libopencv_photo.so.2.4.11
cpp/cpp-example-calibration: /usr/local/lib/libopencv_legacy.so.2.4.11
cpp/cpp-example-calibration: /usr/local/lib/libopencv_ml.so.2.4.11
cpp/cpp-example-calibration: /usr/local/lib/libopencv_video.so.2.4.11
cpp/cpp-example-calibration: /usr/local/lib/libopencv_calib3d.so.2.4.11
cpp/cpp-example-calibration: /usr/local/lib/libopencv_features2d.so.2.4.11
cpp/cpp-example-calibration: /usr/local/lib/libopencv_flann.so.2.4.11
cpp/cpp-example-calibration: /usr/local/lib/libopencv_highgui.so.2.4.11
cpp/cpp-example-calibration: /usr/local/lib/libopencv_imgproc.so.2.4.11
cpp/cpp-example-calibration: /usr/local/lib/libopencv_core.so.2.4.11
cpp/cpp-example-calibration: cpp/CMakeFiles/example_calibration.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable cpp-example-calibration"
	cd /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/example_calibration.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
cpp/CMakeFiles/example_calibration.dir/build: cpp/cpp-example-calibration
.PHONY : cpp/CMakeFiles/example_calibration.dir/build

cpp/CMakeFiles/example_calibration.dir/requires: cpp/CMakeFiles/example_calibration.dir/calibration.cpp.o.requires
.PHONY : cpp/CMakeFiles/example_calibration.dir/requires

cpp/CMakeFiles/example_calibration.dir/clean:
	cd /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp && $(CMAKE_COMMAND) -P CMakeFiles/example_calibration.dir/cmake_clean.cmake
.PHONY : cpp/CMakeFiles/example_calibration.dir/clean

cpp/CMakeFiles/example_calibration.dir/depend:
	cd /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/CMakeFiles/example_calibration.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : cpp/CMakeFiles/example_calibration.dir/depend

