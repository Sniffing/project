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
include cpp/CMakeFiles/tutorial_Pyramids.dir/depend.make

# Include the progress variables for this target.
include cpp/CMakeFiles/tutorial_Pyramids.dir/progress.make

# Include the compile flags for this target's objects.
include cpp/CMakeFiles/tutorial_Pyramids.dir/flags.make

cpp/CMakeFiles/tutorial_Pyramids.dir/tutorial_code/ImgProc/Pyramids.cpp.o: cpp/CMakeFiles/tutorial_Pyramids.dir/flags.make
cpp/CMakeFiles/tutorial_Pyramids.dir/tutorial_code/ImgProc/Pyramids.cpp.o: cpp/tutorial_code/ImgProc/Pyramids.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object cpp/CMakeFiles/tutorial_Pyramids.dir/tutorial_code/ImgProc/Pyramids.cpp.o"
	cd /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/tutorial_Pyramids.dir/tutorial_code/ImgProc/Pyramids.cpp.o -c /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/tutorial_code/ImgProc/Pyramids.cpp

cpp/CMakeFiles/tutorial_Pyramids.dir/tutorial_code/ImgProc/Pyramids.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tutorial_Pyramids.dir/tutorial_code/ImgProc/Pyramids.cpp.i"
	cd /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/tutorial_code/ImgProc/Pyramids.cpp > CMakeFiles/tutorial_Pyramids.dir/tutorial_code/ImgProc/Pyramids.cpp.i

cpp/CMakeFiles/tutorial_Pyramids.dir/tutorial_code/ImgProc/Pyramids.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tutorial_Pyramids.dir/tutorial_code/ImgProc/Pyramids.cpp.s"
	cd /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/tutorial_code/ImgProc/Pyramids.cpp -o CMakeFiles/tutorial_Pyramids.dir/tutorial_code/ImgProc/Pyramids.cpp.s

cpp/CMakeFiles/tutorial_Pyramids.dir/tutorial_code/ImgProc/Pyramids.cpp.o.requires:
.PHONY : cpp/CMakeFiles/tutorial_Pyramids.dir/tutorial_code/ImgProc/Pyramids.cpp.o.requires

cpp/CMakeFiles/tutorial_Pyramids.dir/tutorial_code/ImgProc/Pyramids.cpp.o.provides: cpp/CMakeFiles/tutorial_Pyramids.dir/tutorial_code/ImgProc/Pyramids.cpp.o.requires
	$(MAKE) -f cpp/CMakeFiles/tutorial_Pyramids.dir/build.make cpp/CMakeFiles/tutorial_Pyramids.dir/tutorial_code/ImgProc/Pyramids.cpp.o.provides.build
.PHONY : cpp/CMakeFiles/tutorial_Pyramids.dir/tutorial_code/ImgProc/Pyramids.cpp.o.provides

cpp/CMakeFiles/tutorial_Pyramids.dir/tutorial_code/ImgProc/Pyramids.cpp.o.provides.build: cpp/CMakeFiles/tutorial_Pyramids.dir/tutorial_code/ImgProc/Pyramids.cpp.o

# Object files for target tutorial_Pyramids
tutorial_Pyramids_OBJECTS = \
"CMakeFiles/tutorial_Pyramids.dir/tutorial_code/ImgProc/Pyramids.cpp.o"

# External object files for target tutorial_Pyramids
tutorial_Pyramids_EXTERNAL_OBJECTS =

cpp/cpp-tutorial-Pyramids: cpp/CMakeFiles/tutorial_Pyramids.dir/tutorial_code/ImgProc/Pyramids.cpp.o
cpp/cpp-tutorial-Pyramids: cpp/CMakeFiles/tutorial_Pyramids.dir/build.make
cpp/cpp-tutorial-Pyramids: /usr/local/lib/libopencv_core.so.2.4.11
cpp/cpp-tutorial-Pyramids: /usr/local/lib/libopencv_flann.so.2.4.11
cpp/cpp-tutorial-Pyramids: /usr/local/lib/libopencv_imgproc.so.2.4.11
cpp/cpp-tutorial-Pyramids: /usr/local/lib/libopencv_highgui.so.2.4.11
cpp/cpp-tutorial-Pyramids: /usr/local/lib/libopencv_ml.so.2.4.11
cpp/cpp-tutorial-Pyramids: /usr/local/lib/libopencv_video.so.2.4.11
cpp/cpp-tutorial-Pyramids: /usr/local/lib/libopencv_objdetect.so.2.4.11
cpp/cpp-tutorial-Pyramids: /usr/local/lib/libopencv_photo.so.2.4.11
cpp/cpp-tutorial-Pyramids: /usr/local/lib/libopencv_nonfree.so.2.4.11
cpp/cpp-tutorial-Pyramids: /usr/local/lib/libopencv_features2d.so.2.4.11
cpp/cpp-tutorial-Pyramids: /usr/local/lib/libopencv_calib3d.so.2.4.11
cpp/cpp-tutorial-Pyramids: /usr/local/lib/libopencv_legacy.so.2.4.11
cpp/cpp-tutorial-Pyramids: /usr/local/lib/libopencv_contrib.so.2.4.11
cpp/cpp-tutorial-Pyramids: /usr/local/lib/libopencv_stitching.so.2.4.11
cpp/cpp-tutorial-Pyramids: /usr/local/lib/libopencv_videostab.so.2.4.11
cpp/cpp-tutorial-Pyramids: /usr/local/lib/libopencv_nonfree.so.2.4.11
cpp/cpp-tutorial-Pyramids: /usr/local/lib/libopencv_ocl.so.2.4.11
cpp/cpp-tutorial-Pyramids: /usr/local/lib/libopencv_gpu.so.2.4.11
cpp/cpp-tutorial-Pyramids: /usr/local/lib/libopencv_objdetect.so.2.4.11
cpp/cpp-tutorial-Pyramids: /usr/local/lib/libopencv_photo.so.2.4.11
cpp/cpp-tutorial-Pyramids: /usr/local/lib/libopencv_legacy.so.2.4.11
cpp/cpp-tutorial-Pyramids: /usr/local/lib/libopencv_ml.so.2.4.11
cpp/cpp-tutorial-Pyramids: /usr/local/lib/libopencv_video.so.2.4.11
cpp/cpp-tutorial-Pyramids: /usr/local/lib/libopencv_calib3d.so.2.4.11
cpp/cpp-tutorial-Pyramids: /usr/local/lib/libopencv_features2d.so.2.4.11
cpp/cpp-tutorial-Pyramids: /usr/local/lib/libopencv_flann.so.2.4.11
cpp/cpp-tutorial-Pyramids: /usr/local/lib/libopencv_highgui.so.2.4.11
cpp/cpp-tutorial-Pyramids: /usr/local/lib/libopencv_imgproc.so.2.4.11
cpp/cpp-tutorial-Pyramids: /usr/local/lib/libopencv_core.so.2.4.11
cpp/cpp-tutorial-Pyramids: cpp/CMakeFiles/tutorial_Pyramids.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable cpp-tutorial-Pyramids"
	cd /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tutorial_Pyramids.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
cpp/CMakeFiles/tutorial_Pyramids.dir/build: cpp/cpp-tutorial-Pyramids
.PHONY : cpp/CMakeFiles/tutorial_Pyramids.dir/build

cpp/CMakeFiles/tutorial_Pyramids.dir/requires: cpp/CMakeFiles/tutorial_Pyramids.dir/tutorial_code/ImgProc/Pyramids.cpp.o.requires
.PHONY : cpp/CMakeFiles/tutorial_Pyramids.dir/requires

cpp/CMakeFiles/tutorial_Pyramids.dir/clean:
	cd /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp && $(CMAKE_COMMAND) -P CMakeFiles/tutorial_Pyramids.dir/cmake_clean.cmake
.PHONY : cpp/CMakeFiles/tutorial_Pyramids.dir/clean

cpp/CMakeFiles/tutorial_Pyramids.dir/depend:
	cd /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/CMakeFiles/tutorial_Pyramids.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : cpp/CMakeFiles/tutorial_Pyramids.dir/depend

