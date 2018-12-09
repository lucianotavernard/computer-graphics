#ifndef COMPUTACAOGRAFICA_POINT_H
#define COMPUTACAOGRAFICA_POINT_H


#include <GL/glut.h>

class Point {
private:
    GLfloat x, y, z;
public:
    Point(GLfloat x, GLfloat y, GLfloat z);

    GLfloat getX() const;

    void setX(GLfloat x);

    GLfloat getY() const;

    void setY(GLfloat y);

    GLfloat getZ() const;

    void setZ(GLfloat z);

    virtual ~Point();
};


#endif
