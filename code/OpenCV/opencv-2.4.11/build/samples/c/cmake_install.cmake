# Install script for directory: /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/c

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
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/OpenCV/samples/c" TYPE FILE PERMISSIONS OWNER_READ GROUP_READ WORLD_READ FILES
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/c/fback_c.c"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/c/morphology.c"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/c/contours.c"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/c/polar_transforms.c"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/c/delaunay.c"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/c/pyramid_segmentation.c"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/c/motempl.c"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/c/convert_cascade.c"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/c/mser_sample.cpp"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/c/tree_engine.cpp"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/c/bgfg_codebook.cpp"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/c/mushroom.cpp"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/c/blobtrack_sample.cpp"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/c/smiledetect.cpp"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/c/one_way_sample.cpp"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/c/facedetect.cpp"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/c/find_obj.cpp"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/c/latentsvmdetect.cpp"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/c/find_obj_ferns.cpp"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/c/adaptiveskindetector.cpp"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/c/find_obj_calonder.cpp"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/c/one_way_train_0000.jpg"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/c/baboon200.jpg"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/c/baboon.jpg"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/c/cat.jpg"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/c/fruits.jpg"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/c/baboon200_rotated.jpg"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/c/one_way_train_0001.jpg"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/c/lena.jpg"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/c/airplane.jpg"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/c/stuff.jpg"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/c/puzzle.png"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/c/box.png"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/c/JCB.png"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/c/box_in_scene.png"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/c/agaricus-lepiota.data"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/c/waveform.data"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/c/build_all.sh"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/c/cvsample.dsp"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/c/facedetect.cmd"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/c/one_way_train_images.txt"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/c/CMakeLists.txt"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "samples")

