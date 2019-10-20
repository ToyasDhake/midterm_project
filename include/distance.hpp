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

#include <dlib/image_processing/frontal_face_detector.h>
#include <vector>
#include <opencv2/opencv.hpp>
#include <face.hpp>

class CalculateDistance {
 private:
    double knownWidth = 7.0;
    double knownDistance = 36.0;
 public:
    double focalLength;
    double dist;
    double calculateFocalLength();
    CalculateDistance();
    std::vector<Face> getDistance(cv::Mat image,
                                        dlib::frontal_face_detector detector);
    float calDist(float width, float focalLength);
};

#endif /* INCLUDE_DISTANCE_HPP_ */
