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
