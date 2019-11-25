/**
* @file distance.cpp
* @author Shivam Akhauri (Driver),Toyas Dhake (Navigator) 
* @date 19 October 2019
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
#include <distance.hpp>
#include <face.hpp>
#include <opencv2/highgui/highgui.hpp>

/**
* @brief Function to calculate focal length of camera from a 
* reference iamge.
* @return Focal length of camera calculated
*/
double CalculateDistance::calculateFocalLength() {
    // constructor call for the dlib face detector
    dlib::frontal_face_detector detector = dlib::get_frontal_face_detector();
    dlib::matrix<dlib::bgr_pixel>  referenceImg;
    // load the refernce image
    dlib::load_image(referenceImg, "../app/reference.jpg");
    // Detect faces
    std::vector<dlib::rectangle> faces = detector(referenceImg);
    // find the width of the detected face in pixels
    double refWidth = 0;
    for (auto&& face : faces) {
        refWidth = face.r - face.l;
    }
    // calculate the focal length from the refernce frame
    double focalLength = (refWidth * knownDistance) / knownWidth;
    return focalLength;
}

/**
* @brief Constructor to set the width of human face and find focal length from reference image.
* @params _width Width of head
* @params _focalLength Focal length of camera
*/
CalculateDistance::CalculateDistance() {
    focalLength = calculateFocalLength();
}

/**
* @brief This is the function which computes the distance of each human from the camera
* @params image Image captured by camera, dlib face detector object
* @return vector of Distances for each face in the frame
*/
std::vector<Face> CalculateDistance::getDistance(cv::Mat image,
                                    dlib::frontal_face_detector detector) {
    std::vector<Face> facesWithDistance;
    dlib::cv_image<dlib::bgr_pixel> cimg(image);
    std::vector<dlib::rectangle> faces = detector(cimg);
    // for each detected face calculate the distance
    for (auto&& face : faces) {
        // calculate width for each face
        double width = face.r - face.l;
        // calculate the distance for each face
        realTimeDistance = calDist(width, focalLength);
        Face faceWithDistance(face.l, face.t, face.r, face.b, realTimeDistance);
        // append the distance of each face in a vecor
        facesWithDistance.emplace_back(faceWithDistance);
    }
    return facesWithDistance;
}

double CalculateDistance::getNearestDistance(cv::Mat image,
                                    dlib::frontal_face_detector detector) {
    std::vector<Face> facesWithDistance;
    dlib::cv_image<dlib::bgr_pixel> cimg(image);
    std::vector<dlib::rectangle> faces = detector(cimg);
    // for each detected face calculate the distance
    for (auto&& face : faces) {
        // calculate width for each face
        double width = face.r - face.l;
        // calculate the distance for each face
        realTimeDistance = calDist(width, focalLength);
        Face faceWithDistance(face.l, face.t, face.r, face.b, realTimeDistance);
        // append the distance of each face in a vecor
        facesWithDistance.emplace_back(faceWithDistance);
    }
    std::vector<double> distances;
    for (auto&& face : facesWithDistance) {
        distances.emplace_back(face.getDistance());
    }
    std::sort(distances.begin(), distances.end());
    return distances.at(0);
}

/**
* @brief This function contains the formula for distance calculation
* @params width of the detected face, focalLength of the camera
* @return double value of the calculated distance
*/
double CalculateDistance::calDist(double width, double focalLength) {
    // formula for distance calculation
    double distInches = (focalLength*knownWidth) / width;
    // convert inches measurement to meters
    double distMetres = distInches * 0.0254;
    return distMetres;
}

