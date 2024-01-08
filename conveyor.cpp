#include <GL/glu.h>
#include <valarray>
#include "conveyor.hpp"
#include "normals.hpp"

Conveyor::Conveyor(float size, float speed) : speed(speed), size(size) {}

void Conveyor::draw() {

    // base
    glColor3d(0.6f, 0.6f, 0.6f);

    glBegin(GL_QUADS);
    glNormal3d(1, 0, 0);
    glVertex3d(-0.3f, -0.3f, LINK_HEIGHT);
    glVertex3d(0.3f, -0.3f, LINK_HEIGHT);
    glVertex3d(0.3f, size + 0.3f, LINK_HEIGHT);
    glVertex3d(-0.3f, size + 0.3f, LINK_HEIGHT);

    glNormal3d(-1, 0, 0);
    glVertex3d(-0.3f, size + 0.3f, LINK_HEIGHT * 3.f);
    glVertex3d(0.3f, size + 0.3f, LINK_HEIGHT * 3.f);
    glVertex3d(0.3f, -0.3f, LINK_HEIGHT * 3.f);
    glVertex3d(-0.3f, -0.3f, LINK_HEIGHT * 3.f);

    glNormal3d(0, -1, 0);
    glVertex3d(-0.3f, size + 0.3f, LINK_HEIGHT * 3.f);
    glVertex3d(0.3f, size + 0.3f, LINK_HEIGHT * 3.f);
    glVertex3d(0.3f, size + 0.3f, LINK_HEIGHT);
    glVertex3d(-0.3f, size + 0.3f, LINK_HEIGHT);

    glNormal3d(0, 1, 0);
    glVertex3d(-0.3f, -0.3f, LINK_HEIGHT * 3.f);
    glVertex3d(0.3f, -0.3f, LINK_HEIGHT * 3.f);
    glVertex3d(0.3f, -0.3f, LINK_HEIGHT);
    glVertex3d(-0.3f, -0.3f, LINK_HEIGHT);

    glNormal3d(0, 0, -1);
    glVertex3d(0.3f, size + 0.3f, LINK_HEIGHT * 3.f);
    glVertex3d(0.3f, size + 0.3f, LINK_HEIGHT);
    glVertex3d(0.3f, -0.3f, LINK_HEIGHT);
    glVertex3d(0.3f, -0.3f, LINK_HEIGHT * 3.f);

    glNormal3d(0, 0, 1);
    glVertex3d(-0.3f, size + 0.3f, LINK_HEIGHT * 3.f);
    glVertex3d(-0.3f, size + 0.3f, LINK_HEIGHT);
    glVertex3d(-0.3f, -0.3f, LINK_HEIGHT);
    glVertex3d(-0.3f, -0.3f, LINK_HEIGHT * 3.f);


    glEnd();

    // links
    for (int n = 0; n < size / 0.25f; n++) {
        glPushMatrix();
        glTranslated(0, float(n) * 0.25f + position, 0);
        drawLink();
        glPopMatrix();
    }
    position += speed;
    while (position > 0.25f) {
        position -= 0.25f;
    }

}