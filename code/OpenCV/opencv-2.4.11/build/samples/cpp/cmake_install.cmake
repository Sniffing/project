# Install script for directory: /home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp

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
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/OpenCV/samples/cpp" TYPE FILE PERMISSIONS OWNER_READ GROUP_READ WORLD_READ FILES
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/OpenEXRimages_HDR_Retina_toneMapping_video.cpp"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/descriptor_extractor_matcher.cpp"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/delaunay2.cpp"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/contours2.cpp"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/logpolar_bsm.cpp"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/stereo_match.cpp"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/detection_based_tracker_sample.cpp"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/latentsvm_multidetect.cpp"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/fitellipse.cpp"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/minarea.cpp"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/squares.cpp"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/points_classifier.cpp"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/cout_mat.cpp"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/facerec_demo.cpp"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/video_dmtx.cpp"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/peopledetect.cpp"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/kmeans.cpp"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/houghlines.cpp"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/freak_demo.cpp"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/opencv_version.cpp"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/houghcircles.cpp"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/intelperc_capture.cpp"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/facial_features.cpp"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/detector_descriptor_matcher_evaluation.cpp"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/fabmap_sample.cpp"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/matcher_simple.cpp"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/letter_recog.cpp"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/simpleflow_demo.cpp"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/distrans.cpp"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/matching_to_many_images.cpp"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/rgbdodometry.cpp"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/image_sequence.cpp"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/phase_corr.cpp"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/connected_components.cpp"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/starter_video.cpp"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/em.cpp"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/hybridtrackingsample.cpp"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/edge.cpp"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/bgfg_gmg.cpp"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/tvl1_optical_flow.cpp"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/openni_capture.cpp"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/build3dmodel.cpp"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/lkdemo.cpp"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/demhist.cpp"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/chamfer.cpp"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/meanshift_segmentation.cpp"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/morphology2.cpp"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/camshiftdemo.cpp"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/segment_objects.cpp"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/drawing.cpp"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/stitching_detailed.cpp"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/inpaint.cpp"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/fback.cpp"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/retinaDemo.cpp"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/watershed.cpp"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/select3dobj.cpp"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/bgfg_segm.cpp"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/grabcut.cpp"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/brief_match_test.cpp"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/bagofwords_classification.cpp"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/detector_descriptor_evaluation.cpp"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/3calibration.cpp"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/filestorage.cpp"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/stitching.cpp"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/ffilldemo.cpp"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/calibration.cpp"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/starter_imagelist.cpp"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/image.cpp"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/calibration_artificial.cpp"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/gencolors.cpp"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/linemod.cpp"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/video_homography.cpp"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/OpenEXRimages_HDR_Retina_toneMapping.cpp"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/convexhull.cpp"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/dft.cpp"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/videocapture_pvapi.cpp"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/stereo_calib.cpp"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/videostab.cpp"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/imagelist_creator.cpp"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/pca.cpp"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/kalman.cpp"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/laplace.cpp"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/generic_descriptor_match.cpp"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/right06.jpg"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/right04.jpg"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/left13.jpg"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/right13.jpg"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/baboon.jpg"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/right14.jpg"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/right12.jpg"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/left03.jpg"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/fruits.jpg"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/right11.jpg"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/building.jpg"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/left01.jpg"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/left08.jpg"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/right03.jpg"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/left06.jpg"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/right09.jpg"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/left09.jpg"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/left14.jpg"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/right01.jpg"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/left04.jpg"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/left11.jpg"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/right02.jpg"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/lena.jpg"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/right07.jpg"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/right08.jpg"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/left12.jpg"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/board.jpg"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/left07.jpg"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/right05.jpg"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/left02.jpg"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/left05.jpg"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/stuff.jpg"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/pic2.png"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/logo_in_clutter.png"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/logo.png"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/tsukuba_l.png"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/pic1.png"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/tsukuba_r.png"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/pic4.png"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/pic3.png"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/templ.png"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/pic6.png"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/pic5.png"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/letter-recognition.data"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/facerec_at_t.txt"
    "/home/terence/finalyear/IndividualProject/code/OpenCV/opencv-2.4.11/samples/cpp/CMakeLists.txt"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "samples")

