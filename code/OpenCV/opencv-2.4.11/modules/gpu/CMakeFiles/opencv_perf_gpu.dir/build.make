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
include modules/gpu/CMakeFiles/opencv_perf_gpu.dir/depend.make

# Include the progress variables for this target.
include modules/gpu/CMakeFiles/opencv_perf_gpu.dir/progress.make

# Include the compile flags for this target's objects.
include modules/gpu/CMakeFiles/opencv_perf_gpu.dir/flags.make

modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_filters.cpp.o: modules/gpu/CMakeFiles/opencv_perf_gpu.dir/flags.make
modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_filters.cpp.o: modules/gpu/perf/perf_filters.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_filters.cpp.o"
	cd /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/gpu && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS)  -Winvalid-pch -o CMakeFiles/opencv_perf_gpu.dir/perf/perf_filters.cpp.o -c /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/gpu/perf/perf_filters.cpp

modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_filters.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opencv_perf_gpu.dir/perf/perf_filters.cpp.i"
	cd /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/gpu && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS)  -Winvalid-pch -E /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/gpu/perf/perf_filters.cpp > CMakeFiles/opencv_perf_gpu.dir/perf/perf_filters.cpp.i

modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_filters.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opencv_perf_gpu.dir/perf/perf_filters.cpp.s"
	cd /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/gpu && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS)  -Winvalid-pch -S /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/gpu/perf/perf_filters.cpp -o CMakeFiles/opencv_perf_gpu.dir/perf/perf_filters.cpp.s

modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_filters.cpp.o.requires:
.PHONY : modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_filters.cpp.o.requires

modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_filters.cpp.o.provides: modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_filters.cpp.o.requires
	$(MAKE) -f modules/gpu/CMakeFiles/opencv_perf_gpu.dir/build.make modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_filters.cpp.o.provides.build
.PHONY : modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_filters.cpp.o.provides

modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_filters.cpp.o.provides.build: modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_filters.cpp.o

modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_main.cpp.o: modules/gpu/CMakeFiles/opencv_perf_gpu.dir/flags.make
modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_main.cpp.o: modules/gpu/perf/perf_main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_main.cpp.o"
	cd /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/gpu && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS)  -Winvalid-pch -o CMakeFiles/opencv_perf_gpu.dir/perf/perf_main.cpp.o -c /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/gpu/perf/perf_main.cpp

modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opencv_perf_gpu.dir/perf/perf_main.cpp.i"
	cd /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/gpu && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS)  -Winvalid-pch -E /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/gpu/perf/perf_main.cpp > CMakeFiles/opencv_perf_gpu.dir/perf/perf_main.cpp.i

modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opencv_perf_gpu.dir/perf/perf_main.cpp.s"
	cd /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/gpu && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS)  -Winvalid-pch -S /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/gpu/perf/perf_main.cpp -o CMakeFiles/opencv_perf_gpu.dir/perf/perf_main.cpp.s

modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_main.cpp.o.requires:
.PHONY : modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_main.cpp.o.requires

modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_main.cpp.o.provides: modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_main.cpp.o.requires
	$(MAKE) -f modules/gpu/CMakeFiles/opencv_perf_gpu.dir/build.make modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_main.cpp.o.provides.build
.PHONY : modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_main.cpp.o.provides

modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_main.cpp.o.provides.build: modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_main.cpp.o

modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_denoising.cpp.o: modules/gpu/CMakeFiles/opencv_perf_gpu.dir/flags.make
modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_denoising.cpp.o: modules/gpu/perf/perf_denoising.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_denoising.cpp.o"
	cd /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/gpu && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS)  -Winvalid-pch -o CMakeFiles/opencv_perf_gpu.dir/perf/perf_denoising.cpp.o -c /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/gpu/perf/perf_denoising.cpp

modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_denoising.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opencv_perf_gpu.dir/perf/perf_denoising.cpp.i"
	cd /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/gpu && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS)  -Winvalid-pch -E /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/gpu/perf/perf_denoising.cpp > CMakeFiles/opencv_perf_gpu.dir/perf/perf_denoising.cpp.i

modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_denoising.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opencv_perf_gpu.dir/perf/perf_denoising.cpp.s"
	cd /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/gpu && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS)  -Winvalid-pch -S /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/gpu/perf/perf_denoising.cpp -o CMakeFiles/opencv_perf_gpu.dir/perf/perf_denoising.cpp.s

modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_denoising.cpp.o.requires:
.PHONY : modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_denoising.cpp.o.requires

modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_denoising.cpp.o.provides: modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_denoising.cpp.o.requires
	$(MAKE) -f modules/gpu/CMakeFiles/opencv_perf_gpu.dir/build.make modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_denoising.cpp.o.provides.build
.PHONY : modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_denoising.cpp.o.provides

modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_denoising.cpp.o.provides.build: modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_denoising.cpp.o

modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_core.cpp.o: modules/gpu/CMakeFiles/opencv_perf_gpu.dir/flags.make
modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_core.cpp.o: modules/gpu/perf/perf_core.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_core.cpp.o"
	cd /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/gpu && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS)  -Winvalid-pch -o CMakeFiles/opencv_perf_gpu.dir/perf/perf_core.cpp.o -c /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/gpu/perf/perf_core.cpp

modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_core.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opencv_perf_gpu.dir/perf/perf_core.cpp.i"
	cd /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/gpu && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS)  -Winvalid-pch -E /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/gpu/perf/perf_core.cpp > CMakeFiles/opencv_perf_gpu.dir/perf/perf_core.cpp.i

modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_core.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opencv_perf_gpu.dir/perf/perf_core.cpp.s"
	cd /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/gpu && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS)  -Winvalid-pch -S /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/gpu/perf/perf_core.cpp -o CMakeFiles/opencv_perf_gpu.dir/perf/perf_core.cpp.s

modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_core.cpp.o.requires:
.PHONY : modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_core.cpp.o.requires

modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_core.cpp.o.provides: modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_core.cpp.o.requires
	$(MAKE) -f modules/gpu/CMakeFiles/opencv_perf_gpu.dir/build.make modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_core.cpp.o.provides.build
.PHONY : modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_core.cpp.o.provides

modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_core.cpp.o.provides.build: modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_core.cpp.o

modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_matop.cpp.o: modules/gpu/CMakeFiles/opencv_perf_gpu.dir/flags.make
modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_matop.cpp.o: modules/gpu/perf/perf_matop.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/CMakeFiles $(CMAKE_PROGRESS_5)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_matop.cpp.o"
	cd /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/gpu && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS)  -Winvalid-pch -o CMakeFiles/opencv_perf_gpu.dir/perf/perf_matop.cpp.o -c /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/gpu/perf/perf_matop.cpp

modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_matop.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opencv_perf_gpu.dir/perf/perf_matop.cpp.i"
	cd /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/gpu && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS)  -Winvalid-pch -E /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/gpu/perf/perf_matop.cpp > CMakeFiles/opencv_perf_gpu.dir/perf/perf_matop.cpp.i

modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_matop.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opencv_perf_gpu.dir/perf/perf_matop.cpp.s"
	cd /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/gpu && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS)  -Winvalid-pch -S /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/gpu/perf/perf_matop.cpp -o CMakeFiles/opencv_perf_gpu.dir/perf/perf_matop.cpp.s

modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_matop.cpp.o.requires:
.PHONY : modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_matop.cpp.o.requires

modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_matop.cpp.o.provides: modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_matop.cpp.o.requires
	$(MAKE) -f modules/gpu/CMakeFiles/opencv_perf_gpu.dir/build.make modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_matop.cpp.o.provides.build
.PHONY : modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_matop.cpp.o.provides

modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_matop.cpp.o.provides.build: modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_matop.cpp.o

modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_features2d.cpp.o: modules/gpu/CMakeFiles/opencv_perf_gpu.dir/flags.make
modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_features2d.cpp.o: modules/gpu/perf/perf_features2d.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/CMakeFiles $(CMAKE_PROGRESS_6)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_features2d.cpp.o"
	cd /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/gpu && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS)  -Winvalid-pch -o CMakeFiles/opencv_perf_gpu.dir/perf/perf_features2d.cpp.o -c /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/gpu/perf/perf_features2d.cpp

modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_features2d.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opencv_perf_gpu.dir/perf/perf_features2d.cpp.i"
	cd /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/gpu && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS)  -Winvalid-pch -E /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/gpu/perf/perf_features2d.cpp > CMakeFiles/opencv_perf_gpu.dir/perf/perf_features2d.cpp.i

modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_features2d.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opencv_perf_gpu.dir/perf/perf_features2d.cpp.s"
	cd /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/gpu && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS)  -Winvalid-pch -S /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/gpu/perf/perf_features2d.cpp -o CMakeFiles/opencv_perf_gpu.dir/perf/perf_features2d.cpp.s

modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_features2d.cpp.o.requires:
.PHONY : modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_features2d.cpp.o.requires

modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_features2d.cpp.o.provides: modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_features2d.cpp.o.requires
	$(MAKE) -f modules/gpu/CMakeFiles/opencv_perf_gpu.dir/build.make modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_features2d.cpp.o.provides.build
.PHONY : modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_features2d.cpp.o.provides

modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_features2d.cpp.o.provides.build: modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_features2d.cpp.o

modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_calib3d.cpp.o: modules/gpu/CMakeFiles/opencv_perf_gpu.dir/flags.make
modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_calib3d.cpp.o: modules/gpu/perf/perf_calib3d.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/CMakeFiles $(CMAKE_PROGRESS_7)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_calib3d.cpp.o"
	cd /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/gpu && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS)  -Winvalid-pch -o CMakeFiles/opencv_perf_gpu.dir/perf/perf_calib3d.cpp.o -c /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/gpu/perf/perf_calib3d.cpp

modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_calib3d.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opencv_perf_gpu.dir/perf/perf_calib3d.cpp.i"
	cd /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/gpu && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS)  -Winvalid-pch -E /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/gpu/perf/perf_calib3d.cpp > CMakeFiles/opencv_perf_gpu.dir/perf/perf_calib3d.cpp.i

modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_calib3d.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opencv_perf_gpu.dir/perf/perf_calib3d.cpp.s"
	cd /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/gpu && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS)  -Winvalid-pch -S /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/gpu/perf/perf_calib3d.cpp -o CMakeFiles/opencv_perf_gpu.dir/perf/perf_calib3d.cpp.s

modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_calib3d.cpp.o.requires:
.PHONY : modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_calib3d.cpp.o.requires

modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_calib3d.cpp.o.provides: modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_calib3d.cpp.o.requires
	$(MAKE) -f modules/gpu/CMakeFiles/opencv_perf_gpu.dir/build.make modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_calib3d.cpp.o.provides.build
.PHONY : modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_calib3d.cpp.o.provides

modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_calib3d.cpp.o.provides.build: modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_calib3d.cpp.o

modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_imgproc.cpp.o: modules/gpu/CMakeFiles/opencv_perf_gpu.dir/flags.make
modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_imgproc.cpp.o: modules/gpu/perf/perf_imgproc.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/CMakeFiles $(CMAKE_PROGRESS_8)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_imgproc.cpp.o"
	cd /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/gpu && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS)  -Winvalid-pch -o CMakeFiles/opencv_perf_gpu.dir/perf/perf_imgproc.cpp.o -c /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/gpu/perf/perf_imgproc.cpp

modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_imgproc.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opencv_perf_gpu.dir/perf/perf_imgproc.cpp.i"
	cd /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/gpu && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS)  -Winvalid-pch -E /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/gpu/perf/perf_imgproc.cpp > CMakeFiles/opencv_perf_gpu.dir/perf/perf_imgproc.cpp.i

modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_imgproc.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opencv_perf_gpu.dir/perf/perf_imgproc.cpp.s"
	cd /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/gpu && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS)  -Winvalid-pch -S /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/gpu/perf/perf_imgproc.cpp -o CMakeFiles/opencv_perf_gpu.dir/perf/perf_imgproc.cpp.s

modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_imgproc.cpp.o.requires:
.PHONY : modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_imgproc.cpp.o.requires

modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_imgproc.cpp.o.provides: modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_imgproc.cpp.o.requires
	$(MAKE) -f modules/gpu/CMakeFiles/opencv_perf_gpu.dir/build.make modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_imgproc.cpp.o.provides.build
.PHONY : modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_imgproc.cpp.o.provides

modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_imgproc.cpp.o.provides.build: modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_imgproc.cpp.o

modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_objdetect.cpp.o: modules/gpu/CMakeFiles/opencv_perf_gpu.dir/flags.make
modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_objdetect.cpp.o: modules/gpu/perf/perf_objdetect.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/CMakeFiles $(CMAKE_PROGRESS_9)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_objdetect.cpp.o"
	cd /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/gpu && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS)  -Winvalid-pch -o CMakeFiles/opencv_perf_gpu.dir/perf/perf_objdetect.cpp.o -c /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/gpu/perf/perf_objdetect.cpp

modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_objdetect.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opencv_perf_gpu.dir/perf/perf_objdetect.cpp.i"
	cd /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/gpu && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS)  -Winvalid-pch -E /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/gpu/perf/perf_objdetect.cpp > CMakeFiles/opencv_perf_gpu.dir/perf/perf_objdetect.cpp.i

modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_objdetect.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opencv_perf_gpu.dir/perf/perf_objdetect.cpp.s"
	cd /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/gpu && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS)  -Winvalid-pch -S /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/gpu/perf/perf_objdetect.cpp -o CMakeFiles/opencv_perf_gpu.dir/perf/perf_objdetect.cpp.s

modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_objdetect.cpp.o.requires:
.PHONY : modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_objdetect.cpp.o.requires

modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_objdetect.cpp.o.provides: modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_objdetect.cpp.o.requires
	$(MAKE) -f modules/gpu/CMakeFiles/opencv_perf_gpu.dir/build.make modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_objdetect.cpp.o.provides.build
.PHONY : modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_objdetect.cpp.o.provides

modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_objdetect.cpp.o.provides.build: modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_objdetect.cpp.o

modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_labeling.cpp.o: modules/gpu/CMakeFiles/opencv_perf_gpu.dir/flags.make
modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_labeling.cpp.o: modules/gpu/perf/perf_labeling.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/CMakeFiles $(CMAKE_PROGRESS_10)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_labeling.cpp.o"
	cd /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/gpu && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS)  -Winvalid-pch -o CMakeFiles/opencv_perf_gpu.dir/perf/perf_labeling.cpp.o -c /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/gpu/perf/perf_labeling.cpp

modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_labeling.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opencv_perf_gpu.dir/perf/perf_labeling.cpp.i"
	cd /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/gpu && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS)  -Winvalid-pch -E /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/gpu/perf/perf_labeling.cpp > CMakeFiles/opencv_perf_gpu.dir/perf/perf_labeling.cpp.i

modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_labeling.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opencv_perf_gpu.dir/perf/perf_labeling.cpp.s"
	cd /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/gpu && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS)  -Winvalid-pch -S /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/gpu/perf/perf_labeling.cpp -o CMakeFiles/opencv_perf_gpu.dir/perf/perf_labeling.cpp.s

modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_labeling.cpp.o.requires:
.PHONY : modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_labeling.cpp.o.requires

modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_labeling.cpp.o.provides: modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_labeling.cpp.o.requires
	$(MAKE) -f modules/gpu/CMakeFiles/opencv_perf_gpu.dir/build.make modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_labeling.cpp.o.provides.build
.PHONY : modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_labeling.cpp.o.provides

modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_labeling.cpp.o.provides.build: modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_labeling.cpp.o

modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_video.cpp.o: modules/gpu/CMakeFiles/opencv_perf_gpu.dir/flags.make
modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_video.cpp.o: modules/gpu/perf/perf_video.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/CMakeFiles $(CMAKE_PROGRESS_11)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_video.cpp.o"
	cd /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/gpu && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS)  -Winvalid-pch -o CMakeFiles/opencv_perf_gpu.dir/perf/perf_video.cpp.o -c /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/gpu/perf/perf_video.cpp

modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_video.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opencv_perf_gpu.dir/perf/perf_video.cpp.i"
	cd /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/gpu && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS)  -Winvalid-pch -E /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/gpu/perf/perf_video.cpp > CMakeFiles/opencv_perf_gpu.dir/perf/perf_video.cpp.i

modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_video.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opencv_perf_gpu.dir/perf/perf_video.cpp.s"
	cd /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/gpu && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS)  -Winvalid-pch -S /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/gpu/perf/perf_video.cpp -o CMakeFiles/opencv_perf_gpu.dir/perf/perf_video.cpp.s

modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_video.cpp.o.requires:
.PHONY : modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_video.cpp.o.requires

modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_video.cpp.o.provides: modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_video.cpp.o.requires
	$(MAKE) -f modules/gpu/CMakeFiles/opencv_perf_gpu.dir/build.make modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_video.cpp.o.provides.build
.PHONY : modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_video.cpp.o.provides

modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_video.cpp.o.provides.build: modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_video.cpp.o

# Object files for target opencv_perf_gpu
opencv_perf_gpu_OBJECTS = \
"CMakeFiles/opencv_perf_gpu.dir/perf/perf_filters.cpp.o" \
"CMakeFiles/opencv_perf_gpu.dir/perf/perf_main.cpp.o" \
"CMakeFiles/opencv_perf_gpu.dir/perf/perf_denoising.cpp.o" \
"CMakeFiles/opencv_perf_gpu.dir/perf/perf_core.cpp.o" \
"CMakeFiles/opencv_perf_gpu.dir/perf/perf_matop.cpp.o" \
"CMakeFiles/opencv_perf_gpu.dir/perf/perf_features2d.cpp.o" \
"CMakeFiles/opencv_perf_gpu.dir/perf/perf_calib3d.cpp.o" \
"CMakeFiles/opencv_perf_gpu.dir/perf/perf_imgproc.cpp.o" \
"CMakeFiles/opencv_perf_gpu.dir/perf/perf_objdetect.cpp.o" \
"CMakeFiles/opencv_perf_gpu.dir/perf/perf_labeling.cpp.o" \
"CMakeFiles/opencv_perf_gpu.dir/perf/perf_video.cpp.o"

# External object files for target opencv_perf_gpu
opencv_perf_gpu_EXTERNAL_OBJECTS =

bin/opencv_perf_gpu: modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_filters.cpp.o
bin/opencv_perf_gpu: modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_main.cpp.o
bin/opencv_perf_gpu: modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_denoising.cpp.o
bin/opencv_perf_gpu: modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_core.cpp.o
bin/opencv_perf_gpu: modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_matop.cpp.o
bin/opencv_perf_gpu: modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_features2d.cpp.o
bin/opencv_perf_gpu: modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_calib3d.cpp.o
bin/opencv_perf_gpu: modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_imgproc.cpp.o
bin/opencv_perf_gpu: modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_objdetect.cpp.o
bin/opencv_perf_gpu: modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_labeling.cpp.o
bin/opencv_perf_gpu: modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_video.cpp.o
bin/opencv_perf_gpu: modules/gpu/CMakeFiles/opencv_perf_gpu.dir/build.make
bin/opencv_perf_gpu: lib/libopencv_core.so.2.4.11
bin/opencv_perf_gpu: lib/libopencv_flann.so.2.4.11
bin/opencv_perf_gpu: lib/libopencv_imgproc.so.2.4.11
bin/opencv_perf_gpu: lib/libopencv_highgui.so.2.4.11
bin/opencv_perf_gpu: lib/libopencv_features2d.so.2.4.11
bin/opencv_perf_gpu: lib/libopencv_calib3d.so.2.4.11
bin/opencv_perf_gpu: lib/libopencv_ml.so.2.4.11
bin/opencv_perf_gpu: lib/libopencv_video.so.2.4.11
bin/opencv_perf_gpu: lib/libopencv_legacy.so.2.4.11
bin/opencv_perf_gpu: lib/libopencv_objdetect.so.2.4.11
bin/opencv_perf_gpu: lib/libopencv_photo.so.2.4.11
bin/opencv_perf_gpu: lib/libopencv_gpu.so.2.4.11
bin/opencv_perf_gpu: lib/libopencv_ts.a
bin/opencv_perf_gpu: lib/libopencv_highgui.so.2.4.11
bin/opencv_perf_gpu: lib/libopencv_core.so.2.4.11
bin/opencv_perf_gpu: lib/libopencv_flann.so.2.4.11
bin/opencv_perf_gpu: lib/libopencv_imgproc.so.2.4.11
bin/opencv_perf_gpu: lib/libopencv_highgui.so.2.4.11
bin/opencv_perf_gpu: lib/libopencv_features2d.so.2.4.11
bin/opencv_perf_gpu: lib/libopencv_video.so.2.4.11
bin/opencv_perf_gpu: /usr/lib/x86_64-linux-gnu/libGLU.so
bin/opencv_perf_gpu: /usr/lib/x86_64-linux-gnu/libGL.so
bin/opencv_perf_gpu: /usr/lib/x86_64-linux-gnu/libSM.so
bin/opencv_perf_gpu: /usr/lib/x86_64-linux-gnu/libICE.so
bin/opencv_perf_gpu: /usr/lib/x86_64-linux-gnu/libX11.so
bin/opencv_perf_gpu: /usr/lib/x86_64-linux-gnu/libXext.so
bin/opencv_perf_gpu: lib/libopencv_legacy.so.2.4.11
bin/opencv_perf_gpu: lib/libopencv_calib3d.so.2.4.11
bin/opencv_perf_gpu: lib/libopencv_ml.so.2.4.11
bin/opencv_perf_gpu: lib/libopencv_objdetect.so.2.4.11
bin/opencv_perf_gpu: lib/libopencv_photo.so.2.4.11
bin/opencv_perf_gpu: lib/libopencv_features2d.so.2.4.11
bin/opencv_perf_gpu: lib/libopencv_flann.so.2.4.11
bin/opencv_perf_gpu: lib/libopencv_highgui.so.2.4.11
bin/opencv_perf_gpu: lib/libopencv_video.so.2.4.11
bin/opencv_perf_gpu: lib/libopencv_imgproc.so.2.4.11
bin/opencv_perf_gpu: lib/libopencv_core.so.2.4.11
bin/opencv_perf_gpu: modules/gpu/CMakeFiles/opencv_perf_gpu.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable ../../bin/opencv_perf_gpu"
	cd /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/gpu && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/opencv_perf_gpu.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
modules/gpu/CMakeFiles/opencv_perf_gpu.dir/build: bin/opencv_perf_gpu
.PHONY : modules/gpu/CMakeFiles/opencv_perf_gpu.dir/build

modules/gpu/CMakeFiles/opencv_perf_gpu.dir/requires: modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_filters.cpp.o.requires
modules/gpu/CMakeFiles/opencv_perf_gpu.dir/requires: modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_main.cpp.o.requires
modules/gpu/CMakeFiles/opencv_perf_gpu.dir/requires: modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_denoising.cpp.o.requires
modules/gpu/CMakeFiles/opencv_perf_gpu.dir/requires: modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_core.cpp.o.requires
modules/gpu/CMakeFiles/opencv_perf_gpu.dir/requires: modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_matop.cpp.o.requires
modules/gpu/CMakeFiles/opencv_perf_gpu.dir/requires: modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_features2d.cpp.o.requires
modules/gpu/CMakeFiles/opencv_perf_gpu.dir/requires: modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_calib3d.cpp.o.requires
modules/gpu/CMakeFiles/opencv_perf_gpu.dir/requires: modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_imgproc.cpp.o.requires
modules/gpu/CMakeFiles/opencv_perf_gpu.dir/requires: modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_objdetect.cpp.o.requires
modules/gpu/CMakeFiles/opencv_perf_gpu.dir/requires: modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_labeling.cpp.o.requires
modules/gpu/CMakeFiles/opencv_perf_gpu.dir/requires: modules/gpu/CMakeFiles/opencv_perf_gpu.dir/perf/perf_video.cpp.o.requires
.PHONY : modules/gpu/CMakeFiles/opencv_perf_gpu.dir/requires

modules/gpu/CMakeFiles/opencv_perf_gpu.dir/clean:
	cd /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/gpu && $(CMAKE_COMMAND) -P CMakeFiles/opencv_perf_gpu.dir/cmake_clean.cmake
.PHONY : modules/gpu/CMakeFiles/opencv_perf_gpu.dir/clean

modules/gpu/CMakeFiles/opencv_perf_gpu.dir/depend:
	cd /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11 /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/gpu /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11 /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/gpu /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/gpu/CMakeFiles/opencv_perf_gpu.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : modules/gpu/CMakeFiles/opencv_perf_gpu.dir/depend

