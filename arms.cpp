#include "arms.hpp"
#include <GL/freeglut.h>
#include <GL/gl.h>
#include <GL/glext.h>
#include <GL/glut.h>

void Arm::draw1() {
    glColor3d(0.3f, 0.3f, 0.7f);
    gluCylinder(gluNewQuadric(), 0.2f, 0.3f, 0.2f, 100, 1);
    glColor3d(0.6f, 0.6f, 0.6f);

    glPushMatrix();
    glRotated(rotationZ, 0, 0, 1);
    gluSphere(gluNewQuadric(), 0.2, 100, 100);

    glRotated(rotationX1, 1, 0, 0);
    glTranslated(0.f, 0.f, -0.4f);
    gluCylinder(gluNewQuadric(), 0.1f, 0.1f, 0.3f, 100, 1);

    glTranslated(-0.1f, 0.f, 0.f);
    glRotated(90, 0, 1, 0);
    gluCylinder(gluNewQuadric(), 0.1f, 0.1f, 0.2f, 100, 1);
    glPushMatrix();

    gluDisk(gluNewQuadric(), 0.f, 0.1f, 100, 1);
    glTranslated(0.f, 0.f, 0.2f);
    gluDisk(gluNewQuadric(), 0.f, 0.1f, 100, 1);




    glPopMatrix();
    glPopMatrix();
}

void Arm::draw2() {

}