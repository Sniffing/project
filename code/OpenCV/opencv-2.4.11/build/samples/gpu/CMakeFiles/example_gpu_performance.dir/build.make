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
include samples/gpu/CMakeFiles/example_gpu_performance.dir/depend.make

# Include the progress variables for this target.
include samples/gpu/CMakeFiles/example_gpu_performance.dir/progress.make

# Include the compile flags for this target's objects.
include samples/gpu/CMakeFiles/example_gpu_performance.dir/flags.make

samples/gpu/CMakeFiles/example_gpu_performance.dir/performance/tests.cpp.o: samples/gpu/CMakeFiles/example_gpu_performance.dir/flags.make
samples/gpu/CMakeFiles/example_gpu_performance.dir/performance/tests.cpp.o: ../samples/gpu/performance/tests.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object samples/gpu/CMakeFiles/example_gpu_performance.dir/performance/tests.cpp.o"
	cd /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/build/samples/gpu && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/example_gpu_performance.dir/performance/tests.cpp.o -c /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/gpu/performance/tests.cpp

samples/gpu/CMakeFiles/example_gpu_performance.dir/performance/tests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/example_gpu_performance.dir/performance/tests.cpp.i"
	cd /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/build/samples/gpu && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/gpu/performance/tests.cpp > CMakeFiles/example_gpu_performance.dir/performance/tests.cpp.i

samples/gpu/CMakeFiles/example_gpu_performance.dir/performance/tests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/example_gpu_performance.dir/performance/tests.cpp.s"
	cd /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/build/samples/gpu && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/gpu/performance/tests.cpp -o CMakeFiles/example_gpu_performance.dir/performance/tests.cpp.s

samples/gpu/CMakeFiles/example_gpu_performance.dir/performance/tests.cpp.o.requires:
.PHONY : samples/gpu/CMakeFiles/example_gpu_performance.dir/performance/tests.cpp.o.requires

samples/gpu/CMakeFiles/example_gpu_performance.dir/performance/tests.cpp.o.provides: samples/gpu/CMakeFiles/example_gpu_performance.dir/performance/tests.cpp.o.requires
	$(MAKE) -f samples/gpu/CMakeFiles/example_gpu_performance.dir/build.make samples/gpu/CMakeFiles/example_gpu_performance.dir/performance/tests.cpp.o.provides.build
.PHONY : samples/gpu/CMakeFiles/example_gpu_performance.dir/performance/tests.cpp.o.provides

samples/gpu/CMakeFiles/example_gpu_performance.dir/performance/tests.cpp.o.provides.build: samples/gpu/CMakeFiles/example_gpu_performance.dir/performance/tests.cpp.o

samples/gpu/CMakeFiles/example_gpu_performance.dir/performance/performance.cpp.o: samples/gpu/CMakeFiles/example_gpu_performance.dir/flags.make
samples/gpu/CMakeFiles/example_gpu_performance.dir/performance/performance.cpp.o: ../samples/gpu/performance/performance.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object samples/gpu/CMakeFiles/example_gpu_performance.dir/performance/performance.cpp.o"
	cd /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/build/samples/gpu && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/example_gpu_performance.dir/performance/performance.cpp.o -c /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/gpu/performance/performance.cpp

samples/gpu/CMakeFiles/example_gpu_performance.dir/performance/performance.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/example_gpu_performance.dir/performance/performance.cpp.i"
	cd /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/build/samples/gpu && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/gpu/performance/performance.cpp > CMakeFiles/example_gpu_performance.dir/performance/performance.cpp.i

samples/gpu/CMakeFiles/example_gpu_performance.dir/performance/performance.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/example_gpu_performance.dir/performance/performance.cpp.s"
	cd /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/build/samples/gpu && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/gpu/performance/performance.cpp -o CMakeFiles/example_gpu_performance.dir/performance/performance.cpp.s

samples/gpu/CMakeFiles/example_gpu_performance.dir/performance/performance.cpp.o.requires:
.PHONY : samples/gpu/CMakeFiles/example_gpu_performance.dir/performance/performance.cpp.o.requires

samples/gpu/CMakeFiles/example_gpu_performance.dir/performance/performance.cpp.o.provides: samples/gpu/CMakeFiles/example_gpu_performance.dir/performance/performance.cpp.o.requires
	$(MAKE) -f samples/gpu/CMakeFiles/example_gpu_performance.dir/build.make samples/gpu/CMakeFiles/example_gpu_performance.dir/performance/performance.cpp.o.provides.build
.PHONY : samples/gpu/CMakeFiles/example_gpu_performance.dir/performance/performance.cpp.o.provides

samples/gpu/CMakeFiles/example_gpu_performance.dir/performance/performance.cpp.o.provides.build: samples/gpu/CMakeFiles/example_gpu_performance.dir/performance/performance.cpp.o

# Object files for target example_gpu_performance
example_gpu_performance_OBJECTS = \
"CMakeFiles/example_gpu_performance.dir/performance/tests.cpp.o" \
"CMakeFiles/example_gpu_performance.dir/performance/performance.cpp.o"

# External object files for target example_gpu_performance
example_gpu_performance_EXTERNAL_OBJECTS =

bin/performance_gpu: samples/gpu/CMakeFiles/example_gpu_performance.dir/performance/tests.cpp.o
bin/performance_gpu: samples/gpu/CMakeFiles/example_gpu_performance.dir/performance/performance.cpp.o
bin/performance_gpu: samples/gpu/CMakeFiles/example_gpu_performance.dir/build.make
bin/performance_gpu: /usr/lib/x86_64-linux-gnu/libGLU.so
bin/performance_gpu: /usr/lib/x86_64-linux-gnu/libGL.so
bin/performance_gpu: /usr/lib/x86_64-linux-gnu/libSM.so
bin/performance_gpu: /usr/lib/x86_64-linux-gnu/libICE.so
bin/performance_gpu: /usr/lib/x86_64-linux-gnu/libX11.so
bin/performance_gpu: /usr/lib/x86_64-linux-gnu/libXext.so
bin/performance_gpu: lib/libopencv_core.so.2.4.11
bin/performance_gpu: lib/libopencv_flann.so.2.4.11
bin/performance_gpu: lib/libopencv_imgproc.so.2.4.11
bin/performance_gpu: lib/libopencv_highgui.so.2.4.11
bin/performance_gpu: lib/libopencv_ml.so.2.4.11
bin/performance_gpu: lib/libopencv_video.so.2.4.11
bin/performance_gpu: lib/libopencv_objdetect.so.2.4.11
bin/performance_gpu: lib/libopencv_features2d.so.2.4.11
bin/performance_gpu: lib/libopencv_calib3d.so.2.4.11
bin/performance_gpu: lib/libopencv_legacy.so.2.4.11
bin/performance_gpu: lib/libopencv_contrib.so.2.4.11
bin/performance_gpu: lib/libopencv_gpu.so.2.4.11
bin/performance_gpu: lib/libopencv_superres.so.2.4.11
bin/performance_gpu: lib/libopencv_nonfree.so.2.4.11
bin/performance_gpu: lib/libopencv_gpu.so.2.4.11
bin/performance_gpu: lib/libopencv_legacy.so.2.4.11
bin/performance_gpu: lib/libopencv_photo.so.2.4.11
bin/performance_gpu: lib/libopencv_ocl.so.2.4.11
bin/performance_gpu: lib/libopencv_ml.so.2.4.11
bin/performance_gpu: lib/libopencv_video.so.2.4.11
bin/performance_gpu: lib/libopencv_objdetect.so.2.4.11
bin/performance_gpu: lib/libopencv_calib3d.so.2.4.11
bin/performance_gpu: lib/libopencv_features2d.so.2.4.11
bin/performance_gpu: lib/libopencv_flann.so.2.4.11
bin/performance_gpu: lib/libopencv_highgui.so.2.4.11
bin/performance_gpu: lib/libopencv_imgproc.so.2.4.11
bin/performance_gpu: lib/libopencv_core.so.2.4.11
bin/performance_gpu: samples/gpu/CMakeFiles/example_gpu_performance.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable ../../bin/performance_gpu"
	cd /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/build/samples/gpu && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/example_gpu_performance.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
samples/gpu/CMakeFiles/example_gpu_performance.dir/build: bin/performance_gpu
.PHONY : samples/gpu/CMakeFiles/example_gpu_performance.dir/build

samples/gpu/CMakeFiles/example_gpu_performance.dir/requires: samples/gpu/CMakeFiles/example_gpu_performance.dir/performance/tests.cpp.o.requires
samples/gpu/CMakeFiles/example_gpu_performance.dir/requires: samples/gpu/CMakeFiles/example_gpu_performance.dir/performance/performance.cpp.o.requires
.PHONY : samples/gpu/CMakeFiles/example_gpu_performance.dir/requires

samples/gpu/CMakeFiles/example_gpu_performance.dir/clean:
	cd /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/build/samples/gpu && $(CMAKE_COMMAND) -P CMakeFiles/example_gpu_performance.dir/cmake_clean.cmake
.PHONY : samples/gpu/CMakeFiles/example_gpu_performance.dir/clean

samples/gpu/CMakeFiles/example_gpu_performance.dir/depend:
	cd /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11 /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/gpu /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/build /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/build/samples/gpu /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/build/samples/gpu/CMakeFiles/example_gpu_performance.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : samples/gpu/CMakeFiles/example_gpu_performance.dir/depend

