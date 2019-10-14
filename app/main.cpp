/**
* @file main.cpp
* @author Toyas Dhake (Driver), Shivam Akhauri (Navigator)
* @date 11 October 2019
* @copyright 2019 Toyas Dhake, Shivam Akhauri
* @brief Main file for implementation of the Depth Perception project.
*/

#include <dlib/opencv.h>
#include <opencv2/highgui/highgui.hpp>
#include <dlib/gui_widgets.h>
#include <distance.hpp>
#include <face.hpp>
#include <iostream>

int main() {
    CalculateDistance calculateDistance;
    // Initialize camera
    cv::VideoCapture cap(0);
    // Check camera is open
    if (!cap.isOpened())
    {
        std::cout << "Unable to connect to camera" << std::endl;
        return 1;
    }
    dlib::image_window win;
    // Until window is open
    while(!win.is_closed())
    {
        // Grab a frame
        cv::Mat temp;
        if (!cap.read(temp))
        {
            break;
        }
        // Create object of Acme robotics Depth Preception module
        CalculateDistance calculateDistance;
        /**
        * Loactions and distances of faces are stored in vector<Face> can be 
        * either use to compute something else or add overlay on gui window.
        */
        std::vector<Face> faces = calculateDistance.getDistance(temp);
        /**
        * There are 2 options for gui, opencv or dlib we are using dlib hence
        * cv::Mat needs to be converted to dlib::cv_image.
        */
        dlib::cv_image<dlib::bgr_pixel> cimg(temp);
        win.clear_overlay();
        win.set_image(cimg);
    }
    return 0;
}
