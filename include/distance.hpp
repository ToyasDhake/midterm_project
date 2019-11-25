/**
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
    double getNearestDistance(cv::Mat image,
                                    dlib::frontal_face_detector detector);
    // function to calculate distance of the frame which contains formula
    double calDist(double width, double focalLength);
};


#endif  // INCLUDE_DISTANCE_HPP_
