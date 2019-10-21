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
    // width of the face in the refernce image
    double knownWidth = 7.0;
    // distance of the face in the refernce image
    double knownDistance = 36.0;
 public:
    // focal length of the camera
    double focalLength;
    // the calculated distance of the detcetd face in the frame
    double realTimeDistance = 0;
    double calculateFocalLength();
    // constructor
    CalculateDistance();
    // function to pass each detected face in the
    // frame to calculateFocalLength function
    std::vector<Face> getDistance(cv::Mat image,
                                        dlib::frontal_face_detector detector);
    // function to calculate distance of the frame which contains formula
    double calDist(double width, double focalLength);
};


#endif  // INCLUDE_DISTANCE_HPP_
