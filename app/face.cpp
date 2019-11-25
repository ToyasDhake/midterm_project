/**
* @file face.cpp
* @author Shivam Akhauri (Navigator),Toyas Dhake (Navigator)
* @date 20 October 2019
* @copyright 2019 Toyas Dhake, Shivam Akhauri
* @brief This is a class to store properties of face.
*/

#include <face.hpp>

/**
* @brief Constructor to set x, y, width, height and distance of face.
* @params _x x coordinates of face
* @params _y y coordinates of face
* @params _w Width of face
* @params _h Height of face
* @params _distance Distance of face from camera
*/
Face::Face(double _x, double _y, double _w, double _h, double _distance) {
    x = _x;
    y = _y;
    w = _w;
    h = _h;
    distance = _distance;
}

/**
* @brief This is the function to set x coordinates of face.
* @params _x x coordinates of face
*/
void Face::setX(double _x) {
    x = _x;
}

/**
* @brief This is the function to get x coordinates of face.
* @return Current value of x
*/
double Face::getX() {
    return x;
}

/**
* @brief This is the function to set y coordinates of face.
* @params _y y coordinates of face
*/
void Face::setY(double _y) {
    y = _y;
}

/**
* @brief This is the function to get y coordinates of face.
* @return Current value of y
*/
double Face::getY() {
    return y;
}

/**
* @brief This is the function to set width of face.
* @params _w Width of face
*/
void Face::setW(double _w) {
    w = _w;
}

/**
* @brief This is the function to get width of face.
* @return Current value of width of face
*/
double Face::getW() {
    return w;
}

/**
* @brief This is the function to set height of face.
* @params _h Height of face
*/
void Face::setH(double _h) {
    h = _h;
}

/**
* @brief This is the function to get height of face.
* @return Current value of height of face
*/
double Face::getH() {
    return h;
}

/**
* @brief This is the function to set distance of face from camera.
* @params _distance Distance of face from camera
*/
void Face::setDistance(double _distance) {
    distance = _distance;
}

/**
* @brief This is the function to get distance of face from camera.
* @return Current distance of face from camera
*/
double Face::getDistance() {
    return distance;
}

Face::~Face() {
}
