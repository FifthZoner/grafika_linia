#include "arms.hpp"
#include <GL/freeglut.h>
#include <GL/gl.h>
#include <GL/glext.h>
#include <GL/glut.h>

void Arm::draw1() {
    glColor3d(0.3f, 0.3f, 0.7f);
    gluCylinder(gluNewQuadric(), 0.2f, 0.3f, 0.2f, 100, 1);
    glColor3d(0.6f, 0.6f, 0.6f);
    gluSphere(gluNewQuadric(), 0.2, 100, 100);
}

void Arm::draw2() {

}