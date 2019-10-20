 
//! "Copyright[2019] ShivamAkhauri, Toyas Dhake"
/**
* @file distanceTest.cpp
* @author ToyasDhake,ShivamAkhauri
* @date 13 Octoberr 2019
* @copyright 2019 Shivam, Toyas 
* @brief Contains gtest style test cases
*/
#include <chrono>
#include <gtest/gtest.h>
#include "../app/face.cpp"
#include "../app/distance.cpp"
#include <dlib/opencv.h>
#include <opencv2/highgui/highgui.hpp>
#include <dlib/image_processing/frontal_face_detector.h>
#include <dlib/image_processing/render_face_detections.h>
#include <dlib/image_processing.h>
#include <dlib/gui_widgets.h>
#include <dlib/image_io.h>

/**
* @brief Test for face left coordinates
*/
TEST(Face, setterTestForLeftCoordinates) {
  double temp = 100.0;
  // constructor
  Face face(0, 0, 0, 0, 0);
  // setter
  face.setX(temp);
  // getter
  double leftCoordinate = face.getX();
  EXPECT_EQ(100.0, leftCoordinate);
}

/**
* @brief Test for face right coordinates
*/
TEST(Face, setterTestForRightCoordinates) {
  double temp = 200.0;
  // constructor
  Face face(0, 0, 0, 0, 0);
  // setter
  face.setY(temp);
  // getter
  double rightCoordinate = face.getY();
  EXPECT_EQ(200.0, rightCoordinate);
}

/**
* @brief Test for face top coordinates
*/
TEST(Face, setterTestForTopCoordinates) {
  double temp = 500.0;
  // constructor
  Face face(0, 0, 0, 0, 0);
  face.setH(temp);
  // getter
  double topCoordinate = face.getH();
  EXPECT_EQ(500.0, topCoordinate);
}

/**
* @brief Test for face bottom coordinates
*/
TEST(Face, setterTestForBottomCoordinates) {
  double temp = 200.0;
  // constructor
  Face face(0, 0, 0, 0, 0);
  face.setW(temp);
  double bottomCoordinate = face.getW();
  EXPECT_EQ(900.0, bottomCoordinate);
}

/**
* @brief Test for face Distance
*/
TEST(Face, setterTestForFaceDistance) {
  double temp = 30.0;
  // constructor
  Face face(0, 0, 0, 0, 0);
  // setter
  face.setDistance(temp);
  // getter
  double faceDistance = face.getDistance();
  EXPECT_EQ(30.0, faceDistance);
}

/**
* @brief Test for calDist function
  The focal length is set as per camera specs
  if width and known width are passed as 1, the return should be 1
*/
TEST(calculateDistance, TestForCalDist) {
  // constructor
  CalculateDistance distance;
  // set focal length as per camera specifications
  distance.focalLength = 642.857;
  double temp = distance.calDist(1, 1);
  EXPECT_TRUE((0.17<= temp) && (0.18>=temp));
}

/**
* @brief Test for calculate focal length. 
focal length of the camera from camera specifications.
This should match with the return value from calculateFocalLength
*/
TEST(calculateDistance, TestForFocalLength) {
  // constructor
  CalculateDistance dist;
  double temp = dist.calculateFocalLength();
  EXPECT_TRUE((640<= temp) && (650>=temp));
}

/**
* @brief Test for ACCURACY with test image 1
  Took a test image with known distance of person from camera
  ran getDistance function (solitary testing)
*/
TEST(calculateDistance, productAccuracyTest_1) {
  // fix the focal length value as specified in the camera specification sheet
  // dlib::frontal_face_detector test_face_detector =
  // dlib::get_frontal_face_detector();
  // create a empty matrix for testImg
  dlib::matrix<dlib::bgr_pixel> testImg;
  // constructor
  CalculateDistance distance;
  // fix the focal length value as specified in the camera specification sheet
  distance.focalLength = 642.857;
  // load test images
  dlib::load_image(testImg, "../test/testCases/test_1.jpg");
  // typecast dlib matrix to opencv matrix
  cv::Mat testImg_ = dlib::toMat(testImg);
  // get distance for accuracy checking
  distance.getDistance(testImg_);
  EXPECT_TRUE((0.65<= distance.dist) && (0.85>=distance.dist));
}

/**
* @brief Test for ACCURACY with test image 2
  Took a test image with known distance of person from camera
  ran getDistance function (solitary testing)
*/
TEST(calculateDistance, productAccuracyTest_2) {
  // fix the focal length value as specified in the camera specification sheet
  double focalLength = 642.857;
  // initialize a separate face detector for solitary testing
  // dlib::frontal_face_detector test_face_detector =
  // dlib::get_frontal_face_detector();
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
  distance.getDistance(testImg_);
  EXPECT_TRUE((1.05<= distance.dist) && (1.15>=distance.dist));
}

/**
* @brief Test for ACCURACY with test image 3
  Took a test image with known distance of person from camera
  ran getDistance function (solitary testing)
*/
TEST(calculateDistance, productAccuracyTest_3) {
  // fix the focal length value as specified in the camera specification sheet
  double focalLength = 642.857;
  // initialize a separate face detector for solitary testing
  //dlib::frontal_face_detector test_face_detector =
  // dlib::get_frontal_face_detector();
  // create a empty matrix for testImg
  dlib::matrix<dlib::bgr_pixel> testImg;
  // constructor
  CalculateDistance distance;
  // fix the focal length value as specified in the camera specification sheet
  distance.focalLength = 642.857;
  // load test images
  dlib::load_image(testImg, "../test/testCases/test_3.jpg");
  // typecast dlib matrix to opencv matrix
  cv::Mat testImg_ = dlib::toMat(testImg);
  // get distance for accuracy checking
  distance.getDistance(testImg_);
  EXPECT_TRUE((1.25<= distance.dist) && (1.45>=distance.dist));
}

/**
* @brief Test for PERFORMANCE in terms of execution time for test image 1
*/
TEST(calculateDistance, productPerformanceTest_1) {
  // start the clock
  auto start = std::chrono::high_resolution_clock::now();
  // initialize a separate face detector for solitary testing
  // dlib::frontal_face_detector test_face_detector =
  // dlib::get_frontal_face_detector();
  // create a empty matrix for testImg
  dlib::matrix<dlib::bgr_pixel> testImg;
  // constructor
  CalculateDistance distance;
  // fix the focal length value as specified in the camera specification sheet
  distance.focalLength = 642.857;
  // load test images
  dlib::load_image(testImg, "../test/testCases/test_1.jpg");
  // convert dlib form matrix to opencv form matrix
  cv::Mat testImg_ = dlib::toMat(testImg);
  // calculate distance on the test image
  distance.getDistance(testImg_);
  // stop calculating the time at this point
  auto stop = std::chrono::high_resolution_clock::now();
  // calculate the executaion time for the code
  auto duration = std::chrono::duration_cast
  <std::chrono::microseconds>(stop-start);
  // the execution time should not lag 500 ms
  EXPECT_LT(500, duration.count());
}

/**
* @brief Test for PERFORMANCE in terms of execution time for test image 2
*/
TEST(calculateDistance, productPerformanceTest_2) {
  // start the clock
  auto start = std::chrono::high_resolution_clock::now();
  // initialize a separate face detector for solitary testing
  //dlib::frontal_face_detector test_face_detector =
  //dlib::get_frontal_face_detector();
  // create a empty matrix for testImg
  dlib::matrix<dlib::bgr_pixel> testImg;
  // constructor
  CalculateDistance distance;
  // fix the focal length value as specified in the camera specification sheet
  distance.focalLength = 642.857;
  // load test images
  dlib::load_image(testImg, "../test/testCases/test_2.jpg");
  // convert dlib form matrix to opencv form matrix
  cv::Mat testImg_ = dlib::toMat(testImg);
  // calculate distance on the test image
  distance.getDistance(testImg_);
  // stop calculating the time at this point
  auto stop = std::chrono::high_resolution_clock::now();
  // calculate the executaion time for the code
  auto duration = std::chrono::duration_cast
  <std::chrono::microseconds>(stop-start);
  // the execution time should not lag 500 ms
  EXPECT_LT(500, duration.count());
}

/**
* @brief Test for PERFORMANCE in terms of execution time for test image 3
*/
TEST(calculateDistance, productPerformanceTest_3) {
  // start the clock
  auto start = std::chrono::high_resolution_clock::now();
  // initialize a separate face detector for solitary testing
  //dlib::frontal_face_detector test_face_detector =
  //dlib::get_frontal_face_detector();
  // create a empty matrix for testImg
  dlib::matrix<dlib::bgr_pixel> testImg;
  // constructor
  CalculateDistance distance;
  // fix the focal length value as specified in the camera specification sheet
  distance.focalLength = 642.857;
  // load test images
  dlib::load_image(testImg, "../test/testCases/test_3.jpg");
  // convert dlib form matrix to opencv form matrix
  cv::Mat testImg_ = dlib::toMat(testImg);
  // calculate distance on the test image
  distance.getDistance(testImg_);
  // stop calculating the time at this point
  auto stop = std::chrono::high_resolution_clock::now();
  // calculate the executaion time for the code
  auto duration = std::chrono::duration_cast
  <std::chrono::microseconds>(stop-start);
  // the execution time should not lag 500 ms
  EXPECT_LT(500, duration.count());
}
