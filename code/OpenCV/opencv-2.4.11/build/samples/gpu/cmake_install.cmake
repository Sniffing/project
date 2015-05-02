# Install script for directory: /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/gpu

# Set the install prefix
IF(NOT DEFINED CMAKE_INSTALL_PREFIX)
  SET(CMAKE_INSTALL_PREFIX "/usr/local")
ENDIF(NOT DEFINED CMAKE_INSTALL_PREFIX)
STRING(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
IF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  IF(BUILD_TYPE)
    STRING(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  ELSE(BUILD_TYPE)
    SET(CMAKE_INSTALL_CONFIG_NAME "RELEASE")
  ENDIF(BUILD_TYPE)
  MESSAGE(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
ENDIF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)

# Set the component getting installed.
IF(NOT CMAKE_INSTALL_COMPONENT)
  IF(COMPONENT)
    MESSAGE(STATUS "Install component: \"${COMPONENT}\"")
    SET(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  ELSE(COMPONENT)
    SET(CMAKE_INSTALL_COMPONENT)
  ENDIF(COMPONENT)
ENDIF(NOT CMAKE_INSTALL_COMPONENT)

# Install shared libraries without execute permission?
IF(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  SET(CMAKE_INSTALL_SO_NO_EXE "1")
ENDIF(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "samples")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/OpenCV/samples/gpu/performance" TYPE FILE PERMISSIONS OWNER_READ GROUP_READ WORLD_READ FILES
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/gpu/performance/tests.cpp"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/gpu/performance/performance.cpp"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/gpu/performance/performance.h"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/gpu/performance/CMakeLists.txt"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "samples")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "samples")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/OpenCV/samples/gpu" TYPE FILE PERMISSIONS OWNER_READ GROUP_READ WORLD_READ FILES
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/gpu/alpha_comp.cpp"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/gpu/multi.cpp"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/gpu/morphology.cpp"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/gpu/stereo_match.cpp"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/gpu/cascadeclassifier.cpp"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/gpu/surf_keypoint_matcher.cpp"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/gpu/houghlines.cpp"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/gpu/hog.cpp"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/gpu/farneback_optical_flow.cpp"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/gpu/opengl.cpp"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/gpu/optical_flow.cpp"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/gpu/pyrlk_optical_flow.cpp"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/gpu/video_reader.cpp"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/gpu/generalized_hough.cpp"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/gpu/video_writer.cpp"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/gpu/super_resolution.cpp"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/gpu/bgfg_segm.cpp"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/gpu/stereo_multi.cpp"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/gpu/brox_optical_flow.cpp"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/gpu/aloeR.jpg"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/gpu/aloeL.jpg"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/gpu/basketball1.png"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/gpu/road.png"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/gpu/tsucuba_left.png"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/gpu/rubberwhale1.png"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/gpu/rubberwhale2.png"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/gpu/basketball2.png"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/gpu/tsucuba_right.png"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/gpu/CMakeLists.txt"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "samples")

