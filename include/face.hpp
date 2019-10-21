/**
* @file face.hpp
* @author Toyas Dhake (Driver), Shivam Akhauri (Navigator)
* @date 11 October 2019
* @copyright 2019 Toyas Dhake, Shivam Akhauri
* @brief This is a class to store properties of faces.
*/

#ifndef INCLUDE_FACE_HPP_
#define INCLUDE_FACE_HPP_

class Face {
 private:
    // face coordinates and width and height of the detected face
    double x, y, w, h;
    // face distance in the reference image
    double distance;
 public:
    // constructor
    Face(double _x, double _y, double _w, double _h, double _distance);
    // setter for x coordinates of the face
    void setX(double _x);
    double getX();
    // setter for y coordinates of the face
    void setY(double _y);
    double getY();
    // setter for the height of the face
    void setH(double _h);
    double getH();
    // setter for the width of the face
    void setW(double _w);
    double getW();
    // setter for the distance of the face in the referce frame
    void setDistance(double _distance);
    double getDistance();
};


#endif  // INCLUDE_FACE_HPP__
