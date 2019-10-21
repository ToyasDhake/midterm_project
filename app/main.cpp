/**
* @file main.cpp
* @author Shivam Akhauri (Driver),Toyas Dhake (Navigator),
* @date 20 October 2019
* @copyright 2019 Toyas Dhake, Shivam Akhauri
* @brief Main file for implementation of the Depth Perception project.
*/

#include <dlib/opencv.h>
#include <dlib/gui_widgets.h>
#include <dlib/image_processing/frontal_face_detector.h>
#include <iostream>
#include <distance.hpp>
#include <face.hpp>
#include <opencv2/highgui/highgui.hpp>

int main() {
    // Constructor call for distance calculation
    CalculateDistance calculateDistance;
    // Initialise the video frame buffer of the camera
    cv::VideoCapture cap(0);
    // Check if the opencv was able to communicate with the camera
    if (!cap.isOpened()) {
        std::cout << "Unable to connect to camera" << std::endl;
        return 1;
    }
    dlib::frontal_face_detector detector = dlib::get_frontal_face_detector();
    // Assign a window named win to show the current frame
    dlib::image_window win;
    // Grab each frame and calculate distance till the window is closed
    while (!win.is_closed()) {
        // read each frame in the buffer one by one
        cv::Mat temp;
        // if not able to read a frame in the buffer, close the application
        if (!cap.read(temp)) {
            break;
        }
        std::vector<Face> faces = calculateDistance.getDistance(temp, detector);
        // This is vector of faces with their distance
        dlib::cv_image<dlib::bgr_pixel> cimg(temp);
        // Display the frame all on the screen
        win.clear_overlay();
        win.set_image(cimg);
        for (auto&& face : faces) {
            // draw a bounding box around the face
            dlib::rectangle rect(face.getX(), face.getY(), face.getW(),
                                    face.getH());
            // write the distance and the x,y coordinates
            // of the detected face below the bounding box
            win.add_overlay(dlib::image_window::overlay_rect(rect,
                                dlib::rgb_pixel(0, 255, 0),
                                std::to_string(face.getX()) + ", " +
                                std::to_string(face.getY()) + ", " +
                                std::to_string(face.getDistance())+" m"));
        }
    }
    return 0;
}
