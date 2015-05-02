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
include c/CMakeFiles/example_motempl.dir/depend.make

# Include the progress variables for this target.
include c/CMakeFiles/example_motempl.dir/progress.make

# Include the compile flags for this target's objects.
include c/CMakeFiles/example_motempl.dir/flags.make

c/CMakeFiles/example_motempl.dir/motempl.c.o: c/CMakeFiles/example_motempl.dir/flags.make
c/CMakeFiles/example_motempl.dir/motempl.c.o: c/motempl.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object c/CMakeFiles/example_motempl.dir/motempl.c.o"
	cd /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/c && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/example_motempl.dir/motempl.c.o   -c /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/c/motempl.c

c/CMakeFiles/example_motempl.dir/motempl.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/example_motempl.dir/motempl.c.i"
	cd /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/c && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/c/motempl.c > CMakeFiles/example_motempl.dir/motempl.c.i

c/CMakeFiles/example_motempl.dir/motempl.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/example_motempl.dir/motempl.c.s"
	cd /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/c && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/c/motempl.c -o CMakeFiles/example_motempl.dir/motempl.c.s

c/CMakeFiles/example_motempl.dir/motempl.c.o.requires:
.PHONY : c/CMakeFiles/example_motempl.dir/motempl.c.o.requires

c/CMakeFiles/example_motempl.dir/motempl.c.o.provides: c/CMakeFiles/example_motempl.dir/motempl.c.o.requires
	$(MAKE) -f c/CMakeFiles/example_motempl.dir/build.make c/CMakeFiles/example_motempl.dir/motempl.c.o.provides.build
.PHONY : c/CMakeFiles/example_motempl.dir/motempl.c.o.provides

c/CMakeFiles/example_motempl.dir/motempl.c.o.provides.build: c/CMakeFiles/example_motempl.dir/motempl.c.o

# Object files for target example_motempl
example_motempl_OBJECTS = \
"CMakeFiles/example_motempl.dir/motempl.c.o"

# External object files for target example_motempl
example_motempl_EXTERNAL_OBJECTS =

c/c-example-motempl: c/CMakeFiles/example_motempl.dir/motempl.c.o
c/c-example-motempl: c/CMakeFiles/example_motempl.dir/build.make
c/c-example-motempl: /usr/local/lib/libopencv_core.so.2.4.11
c/c-example-motempl: /usr/local/lib/libopencv_flann.so.2.4.11
c/c-example-motempl: /usr/local/lib/libopencv_imgproc.so.2.4.11
c/c-example-motempl: /usr/local/lib/libopencv_highgui.so.2.4.11
c/c-example-motempl: /usr/local/lib/libopencv_ml.so.2.4.11
c/c-example-motempl: /usr/local/lib/libopencv_video.so.2.4.11
c/c-example-motempl: /usr/local/lib/libopencv_objdetect.so.2.4.11
c/c-example-motempl: /usr/local/lib/libopencv_photo.so.2.4.11
c/c-example-motempl: /usr/local/lib/libopencv_nonfree.so.2.4.11
c/c-example-motempl: /usr/local/lib/libopencv_features2d.so.2.4.11
c/c-example-motempl: /usr/local/lib/libopencv_calib3d.so.2.4.11
c/c-example-motempl: /usr/local/lib/libopencv_legacy.so.2.4.11
c/c-example-motempl: /usr/local/lib/libopencv_contrib.so.2.4.11
c/c-example-motempl: /usr/local/lib/libopencv_nonfree.so.2.4.11
c/c-example-motempl: /usr/local/lib/libopencv_gpu.so.2.4.11
c/c-example-motempl: /usr/local/lib/libopencv_photo.so.2.4.11
c/c-example-motempl: /usr/local/lib/libopencv_legacy.so.2.4.11
c/c-example-motempl: /usr/local/lib/libopencv_ocl.so.2.4.11
c/c-example-motempl: /usr/local/lib/libopencv_ml.so.2.4.11
c/c-example-motempl: /usr/local/lib/libopencv_video.so.2.4.11
c/c-example-motempl: /usr/local/lib/libopencv_objdetect.so.2.4.11
c/c-example-motempl: /usr/local/lib/libopencv_calib3d.so.2.4.11
c/c-example-motempl: /usr/local/lib/libopencv_features2d.so.2.4.11
c/c-example-motempl: /usr/local/lib/libopencv_flann.so.2.4.11
c/c-example-motempl: /usr/local/lib/libopencv_highgui.so.2.4.11
c/c-example-motempl: /usr/local/lib/libopencv_imgproc.so.2.4.11
c/c-example-motempl: /usr/local/lib/libopencv_core.so.2.4.11
c/c-example-motempl: c/CMakeFiles/example_motempl.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C executable c-example-motempl"
	cd /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/c && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/example_motempl.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
c/CMakeFiles/example_motempl.dir/build: c/c-example-motempl
.PHONY : c/CMakeFiles/example_motempl.dir/build

c/CMakeFiles/example_motempl.dir/requires: c/CMakeFiles/example_motempl.dir/motempl.c.o.requires
.PHONY : c/CMakeFiles/example_motempl.dir/requires

c/CMakeFiles/example_motempl.dir/clean:
	cd /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/c && $(CMAKE_COMMAND) -P CMakeFiles/example_motempl.dir/cmake_clean.cmake
.PHONY : c/CMakeFiles/example_motempl.dir/clean

c/CMakeFiles/example_motempl.dir/depend:
	cd /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/c /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/c /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/c/CMakeFiles/example_motempl.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : c/CMakeFiles/example_motempl.dir/depend

