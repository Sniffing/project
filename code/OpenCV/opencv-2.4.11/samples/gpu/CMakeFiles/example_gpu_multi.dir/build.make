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
include gpu/CMakeFiles/example_gpu_multi.dir/depend.make

# Include the progress variables for this target.
include gpu/CMakeFiles/example_gpu_multi.dir/progress.make

# Include the compile flags for this target's objects.
include gpu/CMakeFiles/example_gpu_multi.dir/flags.make

gpu/CMakeFiles/example_gpu_multi.dir/multi.cpp.o: gpu/CMakeFiles/example_gpu_multi.dir/flags.make
gpu/CMakeFiles/example_gpu_multi.dir/multi.cpp.o: gpu/multi.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object gpu/CMakeFiles/example_gpu_multi.dir/multi.cpp.o"
	cd /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/gpu && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/example_gpu_multi.dir/multi.cpp.o -c /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/gpu/multi.cpp

gpu/CMakeFiles/example_gpu_multi.dir/multi.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/example_gpu_multi.dir/multi.cpp.i"
	cd /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/gpu && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/gpu/multi.cpp > CMakeFiles/example_gpu_multi.dir/multi.cpp.i

gpu/CMakeFiles/example_gpu_multi.dir/multi.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/example_gpu_multi.dir/multi.cpp.s"
	cd /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/gpu && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/gpu/multi.cpp -o CMakeFiles/example_gpu_multi.dir/multi.cpp.s

gpu/CMakeFiles/example_gpu_multi.dir/multi.cpp.o.requires:
.PHONY : gpu/CMakeFiles/example_gpu_multi.dir/multi.cpp.o.requires

gpu/CMakeFiles/example_gpu_multi.dir/multi.cpp.o.provides: gpu/CMakeFiles/example_gpu_multi.dir/multi.cpp.o.requires
	$(MAKE) -f gpu/CMakeFiles/example_gpu_multi.dir/build.make gpu/CMakeFiles/example_gpu_multi.dir/multi.cpp.o.provides.build
.PHONY : gpu/CMakeFiles/example_gpu_multi.dir/multi.cpp.o.provides

gpu/CMakeFiles/example_gpu_multi.dir/multi.cpp.o.provides.build: gpu/CMakeFiles/example_gpu_multi.dir/multi.cpp.o

# Object files for target example_gpu_multi
example_gpu_multi_OBJECTS = \
"CMakeFiles/example_gpu_multi.dir/multi.cpp.o"

# External object files for target example_gpu_multi
example_gpu_multi_EXTERNAL_OBJECTS =

gpu/gpu-example-multi: gpu/CMakeFiles/example_gpu_multi.dir/multi.cpp.o
gpu/gpu-example-multi: gpu/CMakeFiles/example_gpu_multi.dir/build.make
gpu/gpu-example-multi: /usr/local/lib/libopencv_core.so.2.4.11
gpu/gpu-example-multi: /usr/local/lib/libopencv_flann.so.2.4.11
gpu/gpu-example-multi: /usr/local/lib/libopencv_imgproc.so.2.4.11
gpu/gpu-example-multi: /usr/local/lib/libopencv_highgui.so.2.4.11
gpu/gpu-example-multi: /usr/local/lib/libopencv_ml.so.2.4.11
gpu/gpu-example-multi: /usr/local/lib/libopencv_video.so.2.4.11
gpu/gpu-example-multi: /usr/local/lib/libopencv_objdetect.so.2.4.11
gpu/gpu-example-multi: /usr/local/lib/libopencv_features2d.so.2.4.11
gpu/gpu-example-multi: /usr/local/lib/libopencv_calib3d.so.2.4.11
gpu/gpu-example-multi: /usr/local/lib/libopencv_legacy.so.2.4.11
gpu/gpu-example-multi: /usr/local/lib/libopencv_contrib.so.2.4.11
gpu/gpu-example-multi: /usr/local/lib/libopencv_gpu.so.2.4.11
gpu/gpu-example-multi: /usr/local/lib/libopencv_superres.so.2.4.11
gpu/gpu-example-multi: /usr/local/lib/libopencv_nonfree.so.2.4.11
gpu/gpu-example-multi: /usr/local/lib/libopencv_gpu.so.2.4.11
gpu/gpu-example-multi: /usr/local/lib/libopencv_legacy.so.2.4.11
gpu/gpu-example-multi: /usr/local/lib/libopencv_photo.so.2.4.11
gpu/gpu-example-multi: /usr/local/lib/libopencv_ocl.so.2.4.11
gpu/gpu-example-multi: /usr/local/lib/libopencv_ml.so.2.4.11
gpu/gpu-example-multi: /usr/local/lib/libopencv_video.so.2.4.11
gpu/gpu-example-multi: /usr/local/lib/libopencv_objdetect.so.2.4.11
gpu/gpu-example-multi: /usr/local/lib/libopencv_calib3d.so.2.4.11
gpu/gpu-example-multi: /usr/local/lib/libopencv_features2d.so.2.4.11
gpu/gpu-example-multi: /usr/local/lib/libopencv_flann.so.2.4.11
gpu/gpu-example-multi: /usr/local/lib/libopencv_highgui.so.2.4.11
gpu/gpu-example-multi: /usr/local/lib/libopencv_imgproc.so.2.4.11
gpu/gpu-example-multi: /usr/local/lib/libopencv_core.so.2.4.11
gpu/gpu-example-multi: gpu/CMakeFiles/example_gpu_multi.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable gpu-example-multi"
	cd /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/gpu && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/example_gpu_multi.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
gpu/CMakeFiles/example_gpu_multi.dir/build: gpu/gpu-example-multi
.PHONY : gpu/CMakeFiles/example_gpu_multi.dir/build

gpu/CMakeFiles/example_gpu_multi.dir/requires: gpu/CMakeFiles/example_gpu_multi.dir/multi.cpp.o.requires
.PHONY : gpu/CMakeFiles/example_gpu_multi.dir/requires

gpu/CMakeFiles/example_gpu_multi.dir/clean:
	cd /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/gpu && $(CMAKE_COMMAND) -P CMakeFiles/example_gpu_multi.dir/cmake_clean.cmake
.PHONY : gpu/CMakeFiles/example_gpu_multi.dir/clean

gpu/CMakeFiles/example_gpu_multi.dir/depend:
	cd /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/gpu /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/gpu /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/gpu/CMakeFiles/example_gpu_multi.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : gpu/CMakeFiles/example_gpu_multi.dir/depend

