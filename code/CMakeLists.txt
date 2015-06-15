cmake_minimum_required(VERSION 2.8)
project(landscapeCreator)
SET(CMAKE_MODULE_PATH ${CMAKE_INSTALL_PREFIX}/lib/cmake/ )

add_executable(landscapeCreator landscapeCreator.cpp TreeNode.hpp contourFinder.hpp Tree.hpp drawOnContour.hpp)
add_executable(drawOnContour drawOnContour.cpp TreeNode.hpp contourFinder.hpp Tree.hpp drawOnContour.hpp)

find_package(aruco REQUIRED )
find_package(GLUT REQUIRED)
find_package(OpenGL REQUIRED)

add_definitions("-std=c++11 -ggdb -fopenmp")
include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} )
target_link_libraries(landscapeCreator  ${aruco_LIBS})
target_link_libraries(landscapeCreator ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES})
target_link_libraries(drawOnContour  ${aruco_LIBS})
target_link_libraries(drawOnContour ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES})
add_definitions(${OPENGL_DEFINITIONS})

#ADD_DEFINITIONS("-lglut -lGL -lGLU -lGLEW")

