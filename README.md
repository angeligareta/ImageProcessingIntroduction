<h1 align="center">Image Processing Overview</h1>
<h4 align="center">Image Processing projects developed for the Image Processing, Analysis And Classification course of the EIT Digital data science master at <a href="https://www.upm.es/">UPM</a></h4>

<p align="center">
  <img alt="UPM" src="https://img.shields.io/badge/EIT%20Digital-UPM-blue?style=flat-square">
  <img alt="License" src="https://img.shields.io/github/license/angeligareta/image-processing-overview?style=flat-square" />
</p>

## Introduction
The exercises developed in the area of image processing are the following:
- Image thresholding: thresholds an input image given a value. (Exercise  [2a](src/exercise_02a_thresh.cpp))
- Image comparision: compare two input PGM images and output '=' or '!='. (Exercise  [2b](src/exercise_02b_compare.cpp))
- Image supremum and infimum operation given two input PGM images. (Exercises [2d_inf](exercise_02d_inf.cpp) and [2d_sup](exercise_02d_sup.cpp))
- Morphological erosion and dilation given a size 'i' over the input image [assuming 8-connectivity]. (Exercises [3a](src/exercise_03a_erosion.cpp) and [3b](src/exercise_03b_dilation.cpp))
- Morphological opening and closing given a size 'i' over the input image [assuming 8-connectivity]. (Exercises [4a](src/exercise_04a_opening.cpp) and [4b](src/exercise_04b_closing.cpp))
- Closing-opening and Opening-closing alternaed filter given a size 'i' over the input image [assuming 8-connectivity]. (Exercises [6a](src/exercise_06a_closing_opening.cpp) and [6b](src/exercise_06b_opening_closing.cpp))

## Environment
This exercises have been developed in the following environment:
- Cmake version: 3.15
- C++ minimum required version: 14
- OpenCV version: 4.2.0
- OS: Ubuntu (Linux)

## Project structure
The project is structured as:
- data: Contains all the images that serve as input examples for the developed programs. 
- programs: Compiled version of src programs.
- src: Contains all the code with an utils folder and the main programs for the exercises.
- CMakeLists.txt: Used to compile with cmake.

## Author
- Angel Igareta [angel@igareta.com](mailto:angel@igareta.com) 
