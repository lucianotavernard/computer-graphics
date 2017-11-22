//
// Created by luciano on 21/11/17.
//

#ifndef COMPUTACAOGRAFICA_BALL_H
#define COMPUTACAOGRAFICA_BALL_H


#include <GL/glut.h>

class Ball {
private:
    GLint slices, stacks;
    GLdouble radius;
    GLfloat angle, x, y, z;
    GLfloat xSpeed, ySpeed, zSpeed, rSpeed;
public:
    Ball(GLdouble radius);
    void draw();

    GLint getSlices() const;

    void setSlices(GLint slices);

    GLint getStacks() const;

    void setStacks(GLint stacks);

    GLdouble getRadius() const;

    void setRadius(GLdouble radius);

    GLfloat getAngle() const;

    void setAngle(GLfloat angle);

    GLfloat getX() const;

    void setX(GLfloat x);

    GLfloat getY() const;

    void setY(GLfloat y);

    GLfloat getZ() const;

    void setZ(GLfloat z);

    GLfloat getXSpeed() const;

    void setXSpeed(GLfloat xSpeed);

    GLfloat getYSpeed() const;

    void setYSpeed(GLfloat ySpeed);

    GLfloat getZSpeed() const;

    void setZSpeed(GLfloat zSpeed);

    GLfloat getRSpeed() const;

    void setRSpeed(GLfloat rSpeed);
};


#endif //COMPUTACAOGRAFICA_BALL_H
