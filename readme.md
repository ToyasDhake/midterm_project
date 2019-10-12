# Depth perception using Mono camera

## Overview

The depth perception module aims to combine computer vision concepts with image processing
techniques to estimate the distance of the human from the camera. We aim to explore the
Histogram of Gradients (HOG) feature extractor as a human face feature detector and apply
pioneering image processing techniques based on pin hole camera concept to provide accurate
depth results.

## System Overview
![](SystemOverview.png)


## Standard install via command-line
```
git clone https://github.com/ToyasDhake/midterm_project.git
cd midterm_project
mkdir build
cd build
cmake .. 
make
Run tests: ./test/cpp-test
Run program: ./app/shell-app
```

### Code Coverage and Travis

The link to code coverage can be found here

Travis path :

[![Build Status](https://travis-ci.org/ToyasDhake/midterm_project.svg?branch=stub_function)](https://travis-ci.org/ToyasDhake/midterm_project)

Coveralls :

[![Coverage Status](https://coveralls.io/repos/github/ToyasDhake/midterm_project/badge.svg?branch=master)](https://coveralls.io/github/ToyasDhake/midterm_project?branch=master)

### Contributors

-Toyas Dhake (Driver)
-Shivam Akhauri (Navigator)
