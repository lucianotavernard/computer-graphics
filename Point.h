//
// Created by luciano on 17/11/17.
//

#ifndef COMPUTACAOGRAFICA_POINT_H
#define COMPUTACAOGRAFICA_POINT_H


class Point {
private:
    float x, y, z;
public:
    Point(float x, float y, float z);

    float getX() const;

    float getY() const;

    float getZ() const;
};


#endif //COMPUTACAOGRAFICA_POINT_H
