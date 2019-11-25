//! "Copyright[2019] ShivamAkhauri, Toyas Dhake"
/**
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
#include "gmock/gmock.h"
#include "Gmock.h"
#include <chrono>
#include <opencv2/highgui/highgui.hpp>
#include <distance.hpp>
#include "face.h"

TEST(Gmock, cgetNearestFaceDistance) {

  std::unique_ptr<ParentMock> node(new ParentMock);
  std::unique_ptr<Gmock> m;
  // check for function call
  EXPECT_CALL(*node, getDistance()).Times(testing::AtLeast(1)).WillOnce(testing::Return(1));




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
