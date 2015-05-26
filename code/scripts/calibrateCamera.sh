#!/bin/bash

cameraNumber=1
#these are num squares in direction-1
boardHeight=4
boardWidth=6
#in meters
squareSize=0.025

cd ~/finalyear/project/code/OpenCV/opencv-2.4.11/build/bin
./cpp-example-calibration $cameraNumber -w $boardWidth -h $boardHeight -s $squareSize -o ~/finalyear/project/code/cam_${cameraNumber}_params.yml -op -oe

