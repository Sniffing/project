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

# Utility rule file for pch_Generate_opencv_test_legacy.

# Include the progress variables for this target.
include modules/legacy/CMakeFiles/pch_Generate_opencv_test_legacy.dir/progress.make

modules/legacy/CMakeFiles/pch_Generate_opencv_test_legacy: modules/legacy/test_precomp.hpp.gch/opencv_test_legacy_RELEASE.gch

modules/legacy/test_precomp.hpp.gch/opencv_test_legacy_RELEASE.gch: modules/legacy/test/test_precomp.hpp
modules/legacy/test_precomp.hpp.gch/opencv_test_legacy_RELEASE.gch: modules/legacy/test_precomp.hpp
modules/legacy/test_precomp.hpp.gch/opencv_test_legacy_RELEASE.gch: lib/libopencv_test_legacy_pch_dephelp.a
	$(CMAKE_COMMAND) -E cmake_progress_report /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating test_precomp.hpp.gch/opencv_test_legacy_RELEASE.gch"
	cd /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/legacy && /usr/bin/cmake -E make_directory /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/legacy/test_precomp.hpp.gch
	cd /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/legacy && /usr/bin/c++ -O3 -DNDEBUG -DNDEBUG -I"/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/legacy/test" -I"/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/video/include" -I"/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/features2d/include" -I"/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/highgui/include" -I"/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/imgproc/include" -I"/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/flann/include" -I"/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/core/include" -I"/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/highgui/include" -I"/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/ts/include" -I"/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/legacy/include" -I"/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/video/include" -I"/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/ml/include" -I"/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/calib3d/include" -I"/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/features2d/include" -I"/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/highgui/include" -I"/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/imgproc/include" -I"/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/flann/include" -I"/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/core/include" -I"/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/legacy" -I"/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/legacy/src" -I"/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/legacy/include" -I"/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/video/include" -I"/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/ml/include" -I"/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/calib3d/include" -I"/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/features2d/include" -I"/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/highgui/include" -I"/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/imgproc/include" -I"/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/flann/include" -I"/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/core/include" -I"/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/legacy" -I"/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/legacy/src" -I"/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/legacy/include" -isystem"/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11" -fsigned-char -W -Wall -Werror=return-type -Werror=address -Werror=sequence-point -Wformat -Werror=format-security -Wmissing-declarations -Wundef -Winit-self -Wpointer-arith -Wshadow -Wsign-promo -Wno-narrowing -Wno-delete-non-virtual-dtor -fdiagnostics-show-option -Wno-long-long -pthread -fomit-frame-pointer -msse -msse2 -msse3 -ffunction-sections -x c++-header -o /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/legacy/test_precomp.hpp.gch/opencv_test_legacy_RELEASE.gch /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/legacy/test_precomp.hpp

modules/legacy/test_precomp.hpp: modules/legacy/test/test_precomp.hpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating test_precomp.hpp"
	cd /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/legacy && /usr/bin/cmake -E copy /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/legacy/test/test_precomp.hpp /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/legacy/test_precomp.hpp

pch_Generate_opencv_test_legacy: modules/legacy/CMakeFiles/pch_Generate_opencv_test_legacy
pch_Generate_opencv_test_legacy: modules/legacy/test_precomp.hpp.gch/opencv_test_legacy_RELEASE.gch
pch_Generate_opencv_test_legacy: modules/legacy/test_precomp.hpp
pch_Generate_opencv_test_legacy: modules/legacy/CMakeFiles/pch_Generate_opencv_test_legacy.dir/build.make
.PHONY : pch_Generate_opencv_test_legacy

# Rule to build all files generated by this target.
modules/legacy/CMakeFiles/pch_Generate_opencv_test_legacy.dir/build: pch_Generate_opencv_test_legacy
.PHONY : modules/legacy/CMakeFiles/pch_Generate_opencv_test_legacy.dir/build

modules/legacy/CMakeFiles/pch_Generate_opencv_test_legacy.dir/clean:
	cd /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/legacy && $(CMAKE_COMMAND) -P CMakeFiles/pch_Generate_opencv_test_legacy.dir/cmake_clean.cmake
.PHONY : modules/legacy/CMakeFiles/pch_Generate_opencv_test_legacy.dir/clean

modules/legacy/CMakeFiles/pch_Generate_opencv_test_legacy.dir/depend:
	cd /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11 /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/legacy /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11 /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/legacy /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/modules/legacy/CMakeFiles/pch_Generate_opencv_test_legacy.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : modules/legacy/CMakeFiles/pch_Generate_opencv_test_legacy.dir/depend

