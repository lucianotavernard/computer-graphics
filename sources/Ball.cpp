
#include "../headers/Ball.h"

Ball::Ball(GLdouble radius) : radius(radius) {
    Ball::radius = radius;
    Ball::slices = 100;
    Ball::stacks = 100;
    Ball::xSpeed = 0.02f;
    Ball::ySpeed = 0.007f;
    Ball::zSpeed = 0.01f;
    Ball::rSpeed = 45.0f;
}

void Ball::draw() {
    glPushMatrix();
        glTranslatef(Ball::x, Ball::y, Ball::z);
        glRotatef(Ball::angle, 0.0f, 1.0f, 0.0f);
        glColor3f(0.5f, 0.5f, 1.0f);
        glutSolidSphere(Ball::radius, Ball::slices, Ball::stacks);
    glPopMatrix();
}

GLint Ball::getSlices() const {
    return slices;
}

void Ball::setSlices(GLint slices) {
    Ball::slices = slices;
}

GLint Ball::getStacks() const {
    return stacks;
}

void Ball::setStacks(GLint stacks) {
    Ball::stacks = stacks;
}

GLdouble Ball::getRadius() const {
    return radius;
}

void Ball::setRadius(GLdouble radius) {
    Ball::radius = radius;
}

GLfloat Ball::getAngle() const {
    return angle;
}

void Ball::setAngle(GLfloat angle) {
    Ball::angle = angle;
}

GLfloat Ball::getX() const {
    return x;
}

void Ball::setX(GLfloat x) {
    Ball::x = x;
}

GLfloat Ball::getY() const {
    return y;
}

void Ball::setY(GLfloat y) {
    Ball::y = y;
}

GLfloat Ball::getZ() const {
    return z;
}

void Ball::setZ(GLfloat z) {
    Ball::z = z;
}

GLfloat Ball::getXSpeed() const {
    return xSpeed;
}

void Ball::setXSpeed(GLfloat xSpeed) {
    Ball::xSpeed = xSpeed;
}

GLfloat Ball::getYSpeed() const {
    return ySpeed;
}

void Ball::setYSpeed(GLfloat ySpeed) {
    Ball::ySpeed = ySpeed;
}

GLfloat Ball::getZSpeed() const {
    return zSpeed;
}

void Ball::setZSpeed(GLfloat zSpeed) {
    Ball::zSpeed = zSpeed;
}

GLfloat Ball::getRSpeed() const {
    return rSpeed;
}

void Ball::setRSpeed(GLfloat rSpeed) {
    Ball::rSpeed = rSpeed;
}


