# Depth perception module for Acme Robotics

## Overview

The depth perception module aims to combine computer vision concepts with image processing
techniques to estimate the distance of the human from the camera. We use the
Histogram of Gradients (HOG) feature extractor as a human face feature detector and apply
pioneering image processing techniques based on pin hole camera concept to provide accurate
depth results.

We use the HOG (Histograms of Gradients) algorithm for human face detection. We use open source DLib for face detection. DLib inherently implements HOG with the best optimized hyperparameters for faster processing speeds on a CPU (benchmarks results show best - ‘processing speed’ vs accuracy ratio for dlib, even better than the SSD object detection by Google which is currently benchmarked as the best ‘processing speed’ detection algorithm and widely used). Dlib also have the best accuracy in terms of side view face detection. Dlib is Open Source (license) and widely used across industries.
We use OpenCV (v3.0) for supporting our computer vision and image processing tasks. OpenCV allows faster implementations and rapid prototyping and is open source (license).
We propose image processing techniques to estimate the distance of the human from the camera. We extrapolate the pin hole camera concept and apply it to real world scenarios. As explained in the diagram below, the distance of the human from the camera is a function of the camera focus and pixel width of the human face. The camera focus is calculated using a reference image with the human at a known depth from the camera.

![](Mathmodel.jpg)

### Main features of the product

- Distance perception for multiple humans concurrently from the Robots frame of reference
- Fast processing speed
- Cost effective solution - needs installation of only a camera in the Robot
- High accuracy
- Developed in C++(>11) with continuous integration 
- Developed by a team of two in an Agile iterative process 
- Standalone software product which includes all the dependencies (Note: This feature is still in development stage. We have added static libraries of Opencv and Dlib tp our repository. But still need to figure out a way to link these static libraries to our cmake. Hence, the current repo will expect opencv and dlib to be installed. Installation steps gievn below won't be needed in phase 2). 

### Results 
Accuracy: TBD
Processing speed: TBD

### Known Limitations and Assumptions for the product :
1. The depth estimation of the human from the robot’s frame of reference works within a range of 0.25 meters to 10 meters.
2. The depth estimation model expects satisfactory lighting conditions.
3. The depth estimation model expects the human face to be facing the robot camera and within its field of view. 
4. The depth estimation model presented here is tuned for Acme Robot camera specifications. Hyperparameters need to be re-calibrated before being deployed to another class of robots.
5. We assume that the average width of adult human face does not vary much. Calculation differences due to minor width differences (delta) are mitigated by P (pixel width values) which also increases proportionally with delta.


### System Overview
![](SystemOverview.png)


### Agile Development Process followed
![](Aip.png)

### AIP Details link
https://docs.google.com/spreadsheets/d/1t8c64cWS98ADABuzGFxU81cme3-aIhM_4wCTikXWeNU/edit?usp=sharing

### Meeting Notes (Minutes of Meetings)
https://docs.google.com/document/d/1sAKEHlb5n9JzfRYK6OL4Pm4foj7QHOMjy63lytvxo4Y/edit?usp=sharing

### Demo steps-Includes steps to run unit test cases for Stub (Note: Solitary test cases-TBD)
```
For OpenCV setup- (Won't be required in phase 2 as it will be run as static library)
sudo apt-get install libopenblas-dev liblapack-dev libx11-dev 
sudo apt-get install 
git clone https://github.com/opencv/opencv.git
cd opencv
mkdir build
cd build
cmake ..
make 
sudo make install

For Dlib setup- (Won't be required in phase 2 as it will be run as static library)
wget http://dlib.net/files/dlib-19.6.tar.bz2
tar xvf dlib-19.6.tar.bz2
cd dlib-19.6/
mkdir build
cd build
cmake ..
cmake --build . --config Release
sudo make install
sudo ldconfig

For runnig our solution:
git clone https://github.com/ToyasDhake/midterm_project.git
cd midterm_project
mkdir build
cd build
cmake .. 
make -j<number of cores>  (Example: make -j12)
Run tests: ./test/cpp-test
Run program: ./app/shell-app
```

### Known Issues and bugs
The open- source library used- Opencv and dlib have not been completely 
written in C++ 11 and greater. Hence cmake generates warnings.

### Code Coverage and Travis

The link to code coverage can be found here

Travis path :

[![Build Status](https://travis-ci.org/ToyasDhake/midterm_project.svg?branch=stub_function)](https://travis-ci.org/ToyasDhake/midterm_project)

Coveralls :

[![Coverage Status](https://coveralls.io/repos/github/ToyasDhake/midterm_project/badge.svg?branch=master)](https://coveralls.io/github/ToyasDhake/midterm_project?branch=master)

### Copyright

Copyright (C) 2001-2019 Shivam Akhauri, Toyas Dhake

For license information, see [LICENSE.txt](LICENSE.txt).


### Contributors

-Toyas Dhake (Driver)
-Computer engineer, from MIT College of Engineering, Pune.
-Skilled in embedded system with applications involving Arduino, Raspberry Pi and Jetson Boards.

-Shivam Akhauri (Navigator)
-Former Artificial Intelligence Engineer at Ether Labs
-Former Machine learning Engineer and Project Lead at Tata Elxsi
-Skilled in AI/ML with applications in Computer vision, NLP and Robotics.

