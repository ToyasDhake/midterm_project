/**
* @file distance.hpp
* @author Toyas Dhake (Driver), Shivam Akhauri (Navigator)
* @date 11 October 2019
* @copyright 2019 Toyas Dhake, Shivam Akhauri
* @brief This is a class for depth perception module based on image from single 
* camera. 
*/

#ifndef INCLUDE_DISTANCE_HPP_
#define INCLUDE_DISTANCE_HPP_

#include <vector>
#include <opencv2/opencv.hpp>
#include <face.hpp>

class CalculateDistance {
 private:
    double knownWidth = 7.0;
    double knownDistance = 36.0;
    double focalLength = 1;
 public:
    double calculateFocalLength();
    CalculateDistance();
    std::vector<Face> getDistance(cv::Mat image);
    float calDist(float width, float focalLength);
};

#endif /* INCLUDE_DISTANCE_HPP_ */