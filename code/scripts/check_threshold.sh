#!/bin/bash

cd ../

declare -rx stepsize=200
declare -rx Ulimit=3000
declare -rx kernelLim=9

lower=800
upper=1700
i=0
kernelsize=3
newLower=$lower

while [ $kernelsize -lt $kernelLim ]; do
  while [ $upper -lt $Ulimit ]; do
    while [ $newLower -lt $upper ]; do
	let newLower=$((lower+(i*stepsize)))
        ./contourFinder testpics/normal.jpg $newLower $upper $kernelsize
        let i+=1
    done
    let i=0
    let lower=800
    let newLower=800
    let upper+=500
  done
  let i=0
  let upper=1700
  let kernelsize+=2
done
