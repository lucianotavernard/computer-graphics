
#include "Point.h"

Point::Point(float x, float y, float z) : x(x), y(y), z(z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

float Point::getX() const {
    return x;
}

float Point::getY() const {
    return y;
}

float Point::getZ() const {
    return z;
}
