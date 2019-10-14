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
    double x, y, w, h;
    double distance;
 public:
    Face(double _x, double _y, double _w, double _h, double _distance);
    void setX(double _x);
    double getX();
    void setY(double _y);
    double getY();
    void setH(double _h);
    double getH();
    void setW(double _w);
    double getW();
    void setDistance(double _distance);
    double getDistance();
};

#endif /* INCLUDE_FACE_HPP_ */
