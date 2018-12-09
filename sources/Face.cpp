
#include <GL/gl.h>
#include "../headers/Face.h"

void Face::draw(Point *point1, Point *point2, Point *point3, Point *point4) {
    glBegin(GL_QUADS);
        glVertex3f(point1->getX(),  point1->getY(), point1->getZ());
        glVertex3f(point2->getX(),  point2->getY(), point2->getZ());
        glVertex3f(point3->getX(),  point3->getY(), point3->getZ());
        glVertex3f(point4->getX(),  point4->getY(), point4->getZ());
    glEnd();
}