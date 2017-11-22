
#include "Point.h"

Point::Point(GLfloat x, GLfloat y, GLfloat z) : x(x), y(y), z(z) {
    Point::x = x;
    Point::y = y;
    Point::z = z;
}

GLfloat Point::getX() const {
    return x;
}

void Point::setX(GLfloat x) {
    Point::x = x;
}

GLfloat Point::getY() const {
    return y;
}

void Point::setY(GLfloat y) {
    Point::y = y;
}

GLfloat Point::getZ() const {
    return z;
}

void Point::setZ(GLfloat z) {
    Point::z = z;
}

Point::~Point() {}