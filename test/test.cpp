/**
*
* Copyright 2019 Shivam Akhauri, Toyas Dhake
*
* Permission is hereby granted, free of charge, to any person obtaining a copy of 
* this software and associated documentation files (the "Software"), to deal in 
* the Software without restriction, including without limitation the rights to 
* use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
* the Software, and to permit persons to whom the Software is furnished to do so,
* subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in all 
* copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR 
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
* FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR 
*  COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER 
* IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN 
* CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*
* @file distanceTest.cpp
* @author ShivamAkhauri,ToyasDhake
* @date 20 Octoberr 2019
* @copyright 2019 Shivam, Toyas
* @brief Contains gtest style test cases including prodcuct accuracy and performance
*/

#include <gtest/gtest.h>
#include <dlib/opencv.h>
#include <dlib/image_processing/frontal_face_detector.h>
#include <dlib/image_processing/render_face_detections.h>
#include <dlib/image_processing.h>
#include <dlib/gui_widgets.h>
#include <dlib/image_io.h>
#include <chrono>
#include "test/face.h"
#include "gmock/gmock.h"
#include "Gmock.h"
#include <opencv2/highgui/highgui.hpp>
#include <distance.hpp>


TEST(Gmock, cgetNearestFaceDistance) {
  std::unique_ptr<ParentMock> node(new ParentMock);
  std::unique_ptr<Gmock> m;
  // check for function call
  EXPECT_CALL(*node, getDistance()).Times(testing::AtLeast(1))
                                                .WillOnce(testing::Return(1));




  // initialize a separate face detector for solitary testing
  dlib::frontal_face_detector test_face_detector =
  dlib::get_frontal_face_detector();
  // create a empty matrix for testImg
  dlib::matrix<dlib::bgr_pixel> testImg;
  // constructor
  CalculateDistance distance;
  // fix the focal length value as specified in the camera specification sheet
  distance.focalLength = 642.857;
  // load test images
  dlib::load_image(testImg, "../test/testCases/test_2.jpg");
  // typecast dlib matrix to opencv matrix
  cv::Mat testImg_ = dlib::toMat(testImg);
  // get distance for accuracy checking
  double dist = distance.getNearestDistance(testImg_, test_face_detector);
  EXPECT_EQ(dist, 0);
}
