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
include cpp/CMakeFiles/tutorial_Geometric_Transforms_Demo.dir/depend.make

# Include the progress variables for this target.
include cpp/CMakeFiles/tutorial_Geometric_Transforms_Demo.dir/progress.make

# Include the compile flags for this target's objects.
include cpp/CMakeFiles/tutorial_Geometric_Transforms_Demo.dir/flags.make

cpp/CMakeFiles/tutorial_Geometric_Transforms_Demo.dir/tutorial_code/ImgTrans/Geometric_Transforms_Demo.cpp.o: cpp/CMakeFiles/tutorial_Geometric_Transforms_Demo.dir/flags.make
cpp/CMakeFiles/tutorial_Geometric_Transforms_Demo.dir/tutorial_code/ImgTrans/Geometric_Transforms_Demo.cpp.o: cpp/tutorial_code/ImgTrans/Geometric_Transforms_Demo.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object cpp/CMakeFiles/tutorial_Geometric_Transforms_Demo.dir/tutorial_code/ImgTrans/Geometric_Transforms_Demo.cpp.o"
	cd /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/tutorial_Geometric_Transforms_Demo.dir/tutorial_code/ImgTrans/Geometric_Transforms_Demo.cpp.o -c /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/tutorial_code/ImgTrans/Geometric_Transforms_Demo.cpp

cpp/CMakeFiles/tutorial_Geometric_Transforms_Demo.dir/tutorial_code/ImgTrans/Geometric_Transforms_Demo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tutorial_Geometric_Transforms_Demo.dir/tutorial_code/ImgTrans/Geometric_Transforms_Demo.cpp.i"
	cd /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/tutorial_code/ImgTrans/Geometric_Transforms_Demo.cpp > CMakeFiles/tutorial_Geometric_Transforms_Demo.dir/tutorial_code/ImgTrans/Geometric_Transforms_Demo.cpp.i

cpp/CMakeFiles/tutorial_Geometric_Transforms_Demo.dir/tutorial_code/ImgTrans/Geometric_Transforms_Demo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tutorial_Geometric_Transforms_Demo.dir/tutorial_code/ImgTrans/Geometric_Transforms_Demo.cpp.s"
	cd /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/tutorial_code/ImgTrans/Geometric_Transforms_Demo.cpp -o CMakeFiles/tutorial_Geometric_Transforms_Demo.dir/tutorial_code/ImgTrans/Geometric_Transforms_Demo.cpp.s

cpp/CMakeFiles/tutorial_Geometric_Transforms_Demo.dir/tutorial_code/ImgTrans/Geometric_Transforms_Demo.cpp.o.requires:
.PHONY : cpp/CMakeFiles/tutorial_Geometric_Transforms_Demo.dir/tutorial_code/ImgTrans/Geometric_Transforms_Demo.cpp.o.requires

cpp/CMakeFiles/tutorial_Geometric_Transforms_Demo.dir/tutorial_code/ImgTrans/Geometric_Transforms_Demo.cpp.o.provides: cpp/CMakeFiles/tutorial_Geometric_Transforms_Demo.dir/tutorial_code/ImgTrans/Geometric_Transforms_Demo.cpp.o.requires
	$(MAKE) -f cpp/CMakeFiles/tutorial_Geometric_Transforms_Demo.dir/build.make cpp/CMakeFiles/tutorial_Geometric_Transforms_Demo.dir/tutorial_code/ImgTrans/Geometric_Transforms_Demo.cpp.o.provides.build
.PHONY : cpp/CMakeFiles/tutorial_Geometric_Transforms_Demo.dir/tutorial_code/ImgTrans/Geometric_Transforms_Demo.cpp.o.provides

cpp/CMakeFiles/tutorial_Geometric_Transforms_Demo.dir/tutorial_code/ImgTrans/Geometric_Transforms_Demo.cpp.o.provides.build: cpp/CMakeFiles/tutorial_Geometric_Transforms_Demo.dir/tutorial_code/ImgTrans/Geometric_Transforms_Demo.cpp.o

# Object files for target tutorial_Geometric_Transforms_Demo
tutorial_Geometric_Transforms_Demo_OBJECTS = \
"CMakeFiles/tutorial_Geometric_Transforms_Demo.dir/tutorial_code/ImgTrans/Geometric_Transforms_Demo.cpp.o"

# External object files for target tutorial_Geometric_Transforms_Demo
tutorial_Geometric_Transforms_Demo_EXTERNAL_OBJECTS =

cpp/cpp-tutorial-Geometric_Transforms_Demo: cpp/CMakeFiles/tutorial_Geometric_Transforms_Demo.dir/tutorial_code/ImgTrans/Geometric_Transforms_Demo.cpp.o
cpp/cpp-tutorial-Geometric_Transforms_Demo: cpp/CMakeFiles/tutorial_Geometric_Transforms_Demo.dir/build.make
cpp/cpp-tutorial-Geometric_Transforms_Demo: /usr/local/lib/libopencv_core.so.2.4.11
cpp/cpp-tutorial-Geometric_Transforms_Demo: /usr/local/lib/libopencv_flann.so.2.4.11
cpp/cpp-tutorial-Geometric_Transforms_Demo: /usr/local/lib/libopencv_imgproc.so.2.4.11
cpp/cpp-tutorial-Geometric_Transforms_Demo: /usr/local/lib/libopencv_highgui.so.2.4.11
cpp/cpp-tutorial-Geometric_Transforms_Demo: /usr/local/lib/libopencv_ml.so.2.4.11
cpp/cpp-tutorial-Geometric_Transforms_Demo: /usr/local/lib/libopencv_video.so.2.4.11
cpp/cpp-tutorial-Geometric_Transforms_Demo: /usr/local/lib/libopencv_objdetect.so.2.4.11
cpp/cpp-tutorial-Geometric_Transforms_Demo: /usr/local/lib/libopencv_photo.so.2.4.11
cpp/cpp-tutorial-Geometric_Transforms_Demo: /usr/local/lib/libopencv_nonfree.so.2.4.11
cpp/cpp-tutorial-Geometric_Transforms_Demo: /usr/local/lib/libopencv_features2d.so.2.4.11
cpp/cpp-tutorial-Geometric_Transforms_Demo: /usr/local/lib/libopencv_calib3d.so.2.4.11
cpp/cpp-tutorial-Geometric_Transforms_Demo: /usr/local/lib/libopencv_legacy.so.2.4.11
cpp/cpp-tutorial-Geometric_Transforms_Demo: /usr/local/lib/libopencv_contrib.so.2.4.11
cpp/cpp-tutorial-Geometric_Transforms_Demo: /usr/local/lib/libopencv_stitching.so.2.4.11
cpp/cpp-tutorial-Geometric_Transforms_Demo: /usr/local/lib/libopencv_videostab.so.2.4.11
cpp/cpp-tutorial-Geometric_Transforms_Demo: /usr/local/lib/libopencv_nonfree.so.2.4.11
cpp/cpp-tutorial-Geometric_Transforms_Demo: /usr/local/lib/libopencv_ocl.so.2.4.11
cpp/cpp-tutorial-Geometric_Transforms_Demo: /usr/local/lib/libopencv_gpu.so.2.4.11
cpp/cpp-tutorial-Geometric_Transforms_Demo: /usr/local/lib/libopencv_objdetect.so.2.4.11
cpp/cpp-tutorial-Geometric_Transforms_Demo: /usr/local/lib/libopencv_photo.so.2.4.11
cpp/cpp-tutorial-Geometric_Transforms_Demo: /usr/local/lib/libopencv_legacy.so.2.4.11
cpp/cpp-tutorial-Geometric_Transforms_Demo: /usr/local/lib/libopencv_ml.so.2.4.11
cpp/cpp-tutorial-Geometric_Transforms_Demo: /usr/local/lib/libopencv_video.so.2.4.11
cpp/cpp-tutorial-Geometric_Transforms_Demo: /usr/local/lib/libopencv_calib3d.so.2.4.11
cpp/cpp-tutorial-Geometric_Transforms_Demo: /usr/local/lib/libopencv_features2d.so.2.4.11
cpp/cpp-tutorial-Geometric_Transforms_Demo: /usr/local/lib/libopencv_flann.so.2.4.11
cpp/cpp-tutorial-Geometric_Transforms_Demo: /usr/local/lib/libopencv_highgui.so.2.4.11
cpp/cpp-tutorial-Geometric_Transforms_Demo: /usr/local/lib/libopencv_imgproc.so.2.4.11
cpp/cpp-tutorial-Geometric_Transforms_Demo: /usr/local/lib/libopencv_core.so.2.4.11
cpp/cpp-tutorial-Geometric_Transforms_Demo: cpp/CMakeFiles/tutorial_Geometric_Transforms_Demo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable cpp-tutorial-Geometric_Transforms_Demo"
	cd /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tutorial_Geometric_Transforms_Demo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
cpp/CMakeFiles/tutorial_Geometric_Transforms_Demo.dir/build: cpp/cpp-tutorial-Geometric_Transforms_Demo
.PHONY : cpp/CMakeFiles/tutorial_Geometric_Transforms_Demo.dir/build

cpp/CMakeFiles/tutorial_Geometric_Transforms_Demo.dir/requires: cpp/CMakeFiles/tutorial_Geometric_Transforms_Demo.dir/tutorial_code/ImgTrans/Geometric_Transforms_Demo.cpp.o.requires
.PHONY : cpp/CMakeFiles/tutorial_Geometric_Transforms_Demo.dir/requires

cpp/CMakeFiles/tutorial_Geometric_Transforms_Demo.dir/clean:
	cd /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp && $(CMAKE_COMMAND) -P CMakeFiles/tutorial_Geometric_Transforms_Demo.dir/cmake_clean.cmake
.PHONY : cpp/CMakeFiles/tutorial_Geometric_Transforms_Demo.dir/clean

cpp/CMakeFiles/tutorial_Geometric_Transforms_Demo.dir/depend:
	cd /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/CMakeFiles/tutorial_Geometric_Transforms_Demo.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : cpp/CMakeFiles/tutorial_Geometric_Transforms_Demo.dir/depend

