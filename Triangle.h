
#ifndef COMPUTACAOGRAFICA_TRIANGLE_H
#define COMPUTACAOGRAFICA_TRIANGLE_H


#include <GL/glut.h>

class Triangle {
private:
    GLfloat fixedZ, x, y, z;
    GLfloat xMin, xMax, xSpeed, speed;
public:
    Triangle(GLfloat x, GLfloat y, GLfloat z);
    void draw();

    GLfloat getX() const;

    void setX(GLfloat x);

    GLfloat getY() const;

    void setY(GLfloat y);

    GLfloat getZ() const;

    void setZ(GLfloat z);

    GLfloat getXMin() const;

    void setXMin(GLfloat xMin);

    GLfloat getXMax() const;

    void setXMax(GLfloat xMax);

    GLfloat getSpeed() const;

    void setSpeed(GLfloat speed);

    GLfloat getXSpeed() const;

    void setXSpeed(GLfloat xSpeed);

    GLfloat getFixedZ() const;

    void setFixedZ(GLfloat fixedZ);
};


#endif
