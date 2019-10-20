/**
* @file distance.cpp
* @author Shivam Akhauri (Driver),Toyas Dhake (Navigator) 
* @date 19 October 2019
* @copyright 2019 Toyas Dhake, Shivam Akhauri
* @brief This is a class for depth perception module based on image from single 
* camera. 
*/

#include <dlib/opencv.h>
#include <opencv2/highgui/highgui.hpp>
#include <dlib/image_processing/frontal_face_detector.h>
#include <dlib/image_processing/render_face_detections.h>
#include <dlib/image_processing.h>
#include <dlib/gui_widgets.h>
#include <dlib/image_io.h>
#include <distance.hpp>
#include <face.hpp>
#include <iostream>


/**
* @brief This is the function to calculate focal length of camera from a 
* refrence iamge.
* @return Focal length of camera
*/
double CalculateDistance::calculateFocalLength() {
    dlib::frontal_face_detector detector = dlib::get_frontal_face_detector();
    dlib::matrix<dlib::bgr_pixel>  referenceImg;
    dlib::load_image(referenceImg, "../app/reference.jpg");
        // Detect faces 
    std::vector<dlib::rectangle> faces = detector(referenceImg);
    float refWidth;
    for (auto&& face : faces) {
        refWidth = face.r - face.l; 
    }
    float focalLength = ( refWidth * knownDistance) / knownWidth;
    return focalLength;
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
* @brief This is the function which computes the distance from nearest human in 
* frame.
* @params image Image captured by camera
* @return Distance from nearest human in frame
*/
std::vector<Face> CalculateDistance::getDistance(cv::Mat image, dlib::frontal_face_detector detector) {
    std::vector<Face> facesWithDistance;
    dlib::cv_image<dlib::bgr_pixel> cimg(image); 
    std::vector<dlib::rectangle> faces = detector(cimg);
    float width;
    for (auto&& face : faces) {
        width = face.r - face.l; 
        dist = calDist(width,focalLength);
        Face faceWithDistance(face.l, face.t, face.r, face.b, dist);
        facesWithDistance.emplace_back(faceWithDistance);
    }
    return facesWithDistance;
}


float CalculateDistance::calDist(float width,float focalLength)
{
    float distInches = (focalLength*knownWidth) / width;
    float distMetres = distInches * 0.0254;
    return distMetres;
}

