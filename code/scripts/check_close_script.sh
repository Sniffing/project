#!/bin/bash
# My first script

cd ../

for i in `seq 1 10`;
do
    ./contourFinder testpics/height.jpg $i >> check_close_results.txt
    echo "\n" >> check_close_results.txt
done
