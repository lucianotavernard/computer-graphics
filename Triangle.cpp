
#include "Triangle.h"

Triangle::Triangle(GLfloat x, GLfloat y, GLfloat z) : x(x), y(y), z(z) {
    Triangle::x = x;
    Triangle::y = y;
    Triangle::z = z;
    Triangle::fixedZ = -3.5f;
    Triangle::xSpeed = 0.01f;
}

void Triangle::draw() {
    glPushMatrix();
        glTranslatef(Triangle::x, Triangle::y, Triangle::z);

        glBegin(GL_TRIANGLES);
            glColor3f(1.0f, 0.0f, 0.0f);
            glVertex3f(0.3f, -0.3f, Triangle::fixedZ + Triangle::z);
            glColor3f(0.0f, 1.0f, 0.0f);
            glVertex3f(-0.3f, -0.3f, Triangle::fixedZ + Triangle::z);
            glColor3f(0.0f, 0.0f, 1.0f);
            glVertex3f(-0.3f, 0.3f, Triangle::fixedZ + Triangle::z);
        glEnd();
    glPopMatrix();
}

GLfloat Triangle::getX() const {
    return x;
}

void Triangle::setX(GLfloat x) {
    Triangle::x = x;
}

GLfloat Triangle::getY() const {
    return y;
}

void Triangle::setY(GLfloat y) {
    Triangle::y = y;
}

GLfloat Triangle::getZ() const {
    return z;
}

void Triangle::setZ(GLfloat z) {
    Triangle::z = z;
}

GLfloat Triangle::getXMin() const {
    return xMin;
}

void Triangle::setXMin(GLfloat xMin) {
    Triangle::xMin = xMin;
}

GLfloat Triangle::getXMax() const {
    return xMax;
}

void Triangle::setXMax(GLfloat xMax) {
    Triangle::xMax = xMax;
}

GLfloat Triangle::getXSpeed() const {
    return xSpeed;
}

void Triangle::setXSpeed(GLfloat xSpeed) {
    Triangle::xSpeed = xSpeed;
}

GLfloat Triangle::getSpeed() const {
    return speed;
}

void Triangle::setSpeed(GLfloat speed) {
    Triangle::speed = speed;
}

GLfloat Triangle::getFixedZ() const {
    return fixedZ;
}

void Triangle::setFixedZ(GLfloat fixedZ) {
    Triangle::fixedZ = fixedZ;
}
