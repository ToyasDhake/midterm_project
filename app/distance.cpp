/**
* @file distance.cpp
* @author Toyas Dhake (Driver), Shivam Akhauri (Navigator)
* @date 11 October 2019
* @copyright 2019 Toyas Dhake, Shivam Akhauri
* @brief This is a class for depth perception module based on image from single 
* camera. 
*/

#include <dlib/opencv.h>
#include <dlib/image_processing/frontal_face_detector.h>
#include <dlib/image_processing/render_face_detections.h>
#include <dlib/image_processing.h>
#include <dlib/gui_widgets.h>
#include <dlib/image_io.h>
#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <distance.hpp>
#include <face.hpp>


/**
* @brief This is the function to calculate focal length of camera from a 
* refrence iamge.
* @return Focal length of camera
*/
double CalculateDistance::calculateFocalLength() {
    return 1;
}

/**
* @brief Constructor to set width of head and focal length.
* @params _width Width of head
* @params _focalLength Focal length of camera
*/
CalculateDistance::CalculateDistance() {
    focalLength = calculateFocalLength();
}

/**
* @brief This is the function which detects the distance from every human in 
* frame.
* @params image Image captured by camera
* @return Vector of <Face> which contain loaction and distance of faces.
*/
std::vector<Face> CalculateDistance::getDistance(cv::Mat image) {
    std::vector<Face> facesWithDistance;
    return facesWithDistance;
}

/**
* @brief This is the function which computes the distance from nearest human in 
* frame.
* @params width Width of face in pixels
* @params focalLength Focal length of camera
* @return Distance from human in consideration
*/
float CalculateDistance::calDist(float width, float focalLength) {
    return 1;
}

