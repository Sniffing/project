# Install script for directory: /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/ocl

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
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/OpenCV/samples/ocl" TYPE FILE PERMISSIONS OWNER_READ GROUP_READ WORLD_READ FILES
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/ocl/stereo_match.cpp"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/ocl/squares.cpp"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/ocl/adaptive_bilateral_filter.cpp"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/ocl/hog.cpp"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/ocl/pyrlk_optical_flow.cpp"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/ocl/tvl1_optical_flow.cpp"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/ocl/facedetect.cpp"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/ocl/clahe.cpp"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/ocl/bgfg_segm.cpp"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/ocl/surf_matcher.cpp"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/ocl/CMakeLists.txt"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "samples")

