/**
* @file main.cpp
* @author Toyas Dhake (Driver), Shivam Akhauri (Navigator)
* @date 11 October 2019
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
    CalculateDistance calculateDistance;
    cv::VideoCapture cap(0);
    if (!cap.isOpened()) {
        std::cout << "Unable to connect to camera" << std::endl;
        return 1;
    }
    dlib::frontal_face_detector detector = dlib::get_frontal_face_detector();
    dlib::image_window win;
    while (!win.is_closed()) {
        // Grab a frame
        cv::Mat temp;
        if (!cap.read(temp)) {
            break;
        }
        std::vector<Face> faces = calculateDistance.getDistance(temp, detector);
        dlib::cv_image<dlib::bgr_pixel> cimg(temp);
        win.clear_overlay();
        win.set_image(cimg);
        for (auto&& face : faces) {
            dlib::rectangle rect(face.getX(), face.getY(), face.getW(),
                                    face.getH());
            win.add_overlay(dlib::image_window::overlay_rect(rect,
                                dlib::rgb_pixel(0, 255, 0),
                                std::to_string(face.getX()) + ", " +
                                std::to_string(face.getY()) + ", " +
                                std::to_string(face.getDistance())+" m"));
        }
    }
    return 0;
}
