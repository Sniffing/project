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

# Utility rule file for pch_Generate_opencv_test_features2d.

# Include the progress variables for this target.
include modules/features2d/CMakeFiles/pch_Generate_opencv_test_features2d.dir/progress.make

modules/features2d/CMakeFiles/pch_Generate_opencv_test_features2d: modules/features2d/test_precomp.hpp.gch/opencv_test_features2d_RELEASE.gch

modules/features2d/test_precomp.hpp.gch/opencv_test_features2d_RELEASE.gch: modules/features2d/test/test_precomp.hpp
modules/features2d/test_precomp.hpp.gch/opencv_test_features2d_RELEASE.gch: modules/features2d/test_precomp.hpp
modules/features2d/test_precomp.hpp.gch/opencv_test_features2d_RELEASE.gch: lib/libopencv_test_features2d_pch_dephelp.a
	$(CMAKE_COMMAND) -E cmake_progress_report /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating test_precomp.hpp.gch/opencv_test_features2d_RELEASE.gch"
	cd /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/features2d && /usr/bin/cmake -E make_directory /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/features2d/test_precomp.hpp.gch
	cd /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/features2d && /usr/bin/c++ -O3 -DNDEBUG -DNDEBUG -I"/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/features2d/test" -I"/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/video/include" -I"/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/features2d/include" -I"/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/highgui/include" -I"/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/imgproc/include" -I"/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/flann/include" -I"/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/core/include" -I"/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/highgui/include" -I"/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/ts/include" -I"/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/features2d/include" -I"/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/highgui/include" -I"/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/imgproc/include" -I"/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/flann/include" -I"/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/core/include" -I"/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/features2d" -I"/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/features2d/src" -I"/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/features2d/include" -I"/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/highgui/include" -I"/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/imgproc/include" -I"/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/flann/include" -I"/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/core/include" -I"/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/features2d" -I"/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/features2d/src" -I"/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/features2d/include" -isystem"/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11" -fsigned-char -W -Wall -Werror=return-type -Werror=address -Werror=sequence-point -Wformat -Werror=format-security -Wmissing-declarations -Wundef -Winit-self -Wpointer-arith -Wshadow -Wsign-promo -Wno-narrowing -Wno-delete-non-virtual-dtor -fdiagnostics-show-option -Wno-long-long -pthread -fomit-frame-pointer -msse -msse2 -msse3 -ffunction-sections -x c++-header -o /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/features2d/test_precomp.hpp.gch/opencv_test_features2d_RELEASE.gch /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/features2d/test_precomp.hpp

modules/features2d/test_precomp.hpp: modules/features2d/test/test_precomp.hpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating test_precomp.hpp"
	cd /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/features2d && /usr/bin/cmake -E copy /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/features2d/test/test_precomp.hpp /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/features2d/test_precomp.hpp

pch_Generate_opencv_test_features2d: modules/features2d/CMakeFiles/pch_Generate_opencv_test_features2d
pch_Generate_opencv_test_features2d: modules/features2d/test_precomp.hpp.gch/opencv_test_features2d_RELEASE.gch
pch_Generate_opencv_test_features2d: modules/features2d/test_precomp.hpp
pch_Generate_opencv_test_features2d: modules/features2d/CMakeFiles/pch_Generate_opencv_test_features2d.dir/build.make
.PHONY : pch_Generate_opencv_test_features2d

# Rule to build all files generated by this target.
modules/features2d/CMakeFiles/pch_Generate_opencv_test_features2d.dir/build: pch_Generate_opencv_test_features2d
.PHONY : modules/features2d/CMakeFiles/pch_Generate_opencv_test_features2d.dir/build

modules/features2d/CMakeFiles/pch_Generate_opencv_test_features2d.dir/clean:
	cd /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/features2d && $(CMAKE_COMMAND) -P CMakeFiles/pch_Generate_opencv_test_features2d.dir/cmake_clean.cmake
.PHONY : modules/features2d/CMakeFiles/pch_Generate_opencv_test_features2d.dir/clean

modules/features2d/CMakeFiles/pch_Generate_opencv_test_features2d.dir/depend:
	cd /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11 /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/features2d /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11 /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/features2d /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/features2d/CMakeFiles/pch_Generate_opencv_test_features2d.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : modules/features2d/CMakeFiles/pch_Generate_opencv_test_features2d.dir/depend

