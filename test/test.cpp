 
//! "Copyright[2019] ToyasDhake, ShivamAkhauri"
/**
* @file distanceTest.cpp
* @author ToyasDhake,ShivamAkhauri
* @date 13 Octoberr 2019
* @copyright 2019 Shivam, Toyas 
* @brief Contains gtest style test cases
*/

#include <gtest/gtest.h>
#include "../app/face.cpp"



/**
* @brief Test for face left coordinates
*/
TEST(setterTestForLeftCoordinates, should_pass) {
  double temp = 100.0;
  Face face(0, 0, 0, 0, 0);
  face.setX(temp);
  double leftCoordinate = face.getX();
  EXPECT_EQ(100.0, leftCoordinate);
}

/**
* @brief Test for face right coordinates
*/
TEST(setterTestForRightCoordinates, should_pass) {
  double temp = 200.0;
  Face face(0, 0, 0, 0, 0);
  face.setY(temp);
  double rightCoordinate = face.getY();
  EXPECT_EQ(200.0, rightCoordinate);
}

/**
* @brief Test for face top coordinates
*/
TEST(setterTestForTopCoordinates, should_pass) {
  double temp = 500.0;
  Face face(0, 0, 0, 0, 0);
  face.setH(temp);
  double topCoordinate = face.getH();
  EXPECT_EQ(500.0, topCoordinate);
}

/**
* @brief Test for bottom coordinates
*/
TEST(setterTestForBottomCoordinates, should_pass) {
  double temp = 900.0;
  Face face(0, 0, 0, 0, 0);
  face.setW(temp);
  double bottomCoordinate = face.getH();
  EXPECT_EQ(900.0, bottomCoordinate);
}

    
