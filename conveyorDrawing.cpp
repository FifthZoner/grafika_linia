#include <GL/glu.h>
#include <complex>
#include <iostream>
#include "conveyor.hpp"
#include "normals.hpp"

inline void drawInChute() {

    glBegin(GL_QUADS);

    glColor3d(0.6f, 0.6f, 0.6f);

    glNormal3d(1, 0, 0);
    glVertex3d(-0.3f, -0.15f, -LINK_HEIGHT * 1.5f);
    glVertex3d(0.3f, -0.15f, -LINK_HEIGHT * 1.5f);
    glVertex3d(0.3f, 0.3f, -LINK_HEIGHT * 1.5f);
    glVertex3d(-0.3f, 0.3f, -LINK_HEIGHT * 1.5f);

    glNormal3d(0, 0, -1);
    glVertex3d(0.3f, 0.3, -LINK_HEIGHT * 1.5f);
    glVertex3d(0.3f, 0.3, LINK_HEIGHT);
    glVertex3d(0.3f, -0.3f, LINK_HEIGHT);
    glVertex3d(0.3f, -0.15f, -LINK_HEIGHT * 1.5f);

    glNormal3d(0, 0, 1);
    glVertex3d(-0.3f, 0.3, -LINK_HEIGHT * 1.5f);
    glVertex3d(-0.3f, 0.3, LINK_HEIGHT);
    glVertex3d(-0.3f, -0.3f, LINK_HEIGHT);
    glVertex3d(-0.3f, -0.15f, -LINK_HEIGHT * 1.5f);

    //float out[3];
    //float coords[3][3] = {
    //        {0.3f, -0.3f, LINK_HEIGHT},
    //        {-0.3f, -0.3f, LINK_HEIGHT},
    //        {-0.3f, -0.15f, -LINK_HEIGHT * 1.5f}
    //};
    //Normal(coords, out);
    //std::cout << out[0] << " " << out[1] << " " << out[2] << "\n";

    glNormal3d(0, 0.8575f, -0.5145f);
    glVertex3d(-0.3f, -0.15f, -LINK_HEIGHT * 1.5f);
    glVertex3d(-0.3f, -0.3f, LINK_HEIGHT);
    glVertex3d(0.3f, -0.3f, LINK_HEIGHT);
    glVertex3d(0.3f, -0.15f, -LINK_HEIGHT * 1.5f);

    glNormal3d(-1, 0, 0);
    glVertex3d(0.25f, 0.3f, -LINK_HEIGHT * 1.5f);
    glVertex3d(0.25f, 0.3f, LINK_HEIGHT);
    glVertex3d(0.3f, 0.3f, LINK_HEIGHT);
    glVertex3d(0.3f, 0.3f, -LINK_HEIGHT * 1.5f);

    glVertex3d(-0.25f, 0.3f, -LINK_HEIGHT * 1.5f);
    glVertex3d(-0.25f, 0.3f, LINK_HEIGHT);
    glVertex3d(-0.3f, 0.3f, LINK_HEIGHT);
    glVertex3d(-0.3f, 0.3f, -LINK_HEIGHT * 1.5f);

    glVertex3d(-0.25f, 0.3f, -LINK_HEIGHT * 1.5f + 0.05f);
    glVertex3d(-0.25f, 0.3f, -LINK_HEIGHT * 1.5f);
    glVertex3d(0.25f, 0.3f, -LINK_HEIGHT * 1.5f);
    glVertex3d(0.25f, 0.3f, -LINK_HEIGHT * 1.5f + 0.05f);

    glNormal3d(1, 0, 0);
    glColor3d(0.f, 0.f, 0.f);
    glVertex3d(-0.25f, 0.3f, -LINK_HEIGHT * 1.5f + 0.05f);
    glVertex3d(-0.25f, 0.3f, LINK_HEIGHT);
    glVertex3d(0.25f, 0.3f, LINK_HEIGHT);
    glVertex3d(0.25f, 0.3f, -LINK_HEIGHT * 1.5f + 0.05f);

    glEnd();
}

void Conveyor::drawHousing() const {

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

    drawInChute();

    glPushMatrix();

    glRotated(180.f, 0, 0, 1);
    glTranslated(0, -size, 0);
    drawInChute();

    glPopMatrix();


}

void Conveyor::drawLink() {



    // near the arrow
    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_QUADS);
    glNormal3d(0.707107, 0.707107, 0);
    glVertex3d(-0.00, 0.20, 0.00);
    glVertex3d( 0.10, 0.10, 0.00);
    glVertex3d( 0.10, 0.10, LINK_HEIGHT);
    glVertex3d(-0.00, 0.20, LINK_HEIGHT);

    glNormal3d(-0.707107, 0.707107, 0);
    glVertex3d( 0.00, 0.20, LINK_HEIGHT);
    glVertex3d(-0.10, 0.10, LINK_HEIGHT);
    glVertex3d(-0.10, 0.10, 0.00);
    glVertex3d( 0.00, 0.20, 0.00);

    // top sides
    glNormal3d(-1, 0, 0);
    glVertex3d(-0.10, 0.00, 0.00);
    glVertex3d(-0.10, 0.10, 0.00);
    glVertex3d(-0.10, 0.10, LINK_HEIGHT);
    glVertex3d(-0.10, 0.00, LINK_HEIGHT);

    glNormal3d(1, 0, 0);
    glVertex3d( 0.10, 0.00, LINK_HEIGHT);
    glVertex3d( 0.10, 0.10, LINK_HEIGHT);
    glVertex3d( 0.10, 0.10, 0.00);
    glVertex3d( 0.10, 0.00, 0.00);

    glNormal3d(0, 1, 0);
    glVertex3d(-0.10, 0.00, LINK_HEIGHT);
    glVertex3d(-0.18, 0.00, LINK_HEIGHT);
    glVertex3d(-0.18, 0.00, 0.00);
    glVertex3d(-0.10, 0.00, 0.00);

    glVertex3d( 0.10, 0.00, 0.00);
    glVertex3d( 0.18, 0.00, 0.00);
    glVertex3d( 0.18, 0.00, LINK_HEIGHT);
    glVertex3d( 0.10, 0.00, LINK_HEIGHT);

    // small slopes
    glNormal3d(1.f / std::sqrt(2), 1.f / std::sqrt(2), 0);
    glVertex3d( 0.18, 0.00, 0.00);
    glVertex3d( 0.20,-0.02, 0.00);
    glVertex3d( 0.20,-0.02, LINK_HEIGHT);
    glVertex3d( 0.18, 0.00, LINK_HEIGHT);

    glNormal3d(-1.f / std::sqrt(2), 1.f / std::sqrt(2), 0);
    glVertex3d(-0.18, 0.00, LINK_HEIGHT);
    glVertex3d(-0.20,-0.02, LINK_HEIGHT);
    glVertex3d(-0.20,-0.02, 0.00);
    glVertex3d(-0.18, 0.00, 0.00);

    glNormal3d(-1, 0, 0);
    glVertex3d(-0.20,-0.02, LINK_HEIGHT);
    glVertex3d(-0.20,-0.20, LINK_HEIGHT);
    glVertex3d(-0.20,-0.20, 0.00);
    glVertex3d(-0.20,-0.02, 0.00);

    glNormal3d(1, 0, 0);
    glVertex3d( 0.20,-0.02, 0.00);
    glVertex3d( 0.20,-0.20, 0.00);
    glVertex3d( 0.20,-0.20, LINK_HEIGHT);
    glVertex3d( 0.20,-0.02, LINK_HEIGHT);

    glNormal3d(0, -1, 0);
    glVertex3d(-0.20,-0.20, LINK_HEIGHT);
    glVertex3d(-0.10,-0.20, LINK_HEIGHT);
    glVertex3d(-0.10,-0.20, 0.00);
    glVertex3d(-0.20,-0.20, 0.00);

    glVertex3d( 0.20,-0.20, 0.00);
    glVertex3d( 0.10,-0.20, 0.00);
    glVertex3d( 0.10,-0.20, LINK_HEIGHT);
    glVertex3d( 0.20,-0.20, LINK_HEIGHT);

    glNormal3d(1, 0, 0);
    glVertex3d(-0.10,-0.10, 0.00);
    glVertex3d(-0.10,-0.20, 0.00);
    glVertex3d(-0.10,-0.20, LINK_HEIGHT);
    glVertex3d(-0.10,-0.10, LINK_HEIGHT);

    glNormal3d(-1, 0, 0);
    glVertex3d( 0.10,-0.10, LINK_HEIGHT);
    glVertex3d( 0.10,-0.20, LINK_HEIGHT);
    glVertex3d( 0.10,-0.20, 0.00);
    glVertex3d( 0.10,-0.10, 0.00);

    // other belt hole slopes
    glNormal3d(0.707107, -0.707107, 0);
    glVertex3d(-0.00, 0.00, LINK_HEIGHT);
    glVertex3d( 0.10,-0.10, LINK_HEIGHT);
    glVertex3d( 0.10,-0.10, 0.00);
    glVertex3d(-0.00, 0.00, 0.00);

    glNormal3d(-0.707107, -0.707107, 0);
    glVertex3d( 0.00, 0.00, 0.00);
    glVertex3d(-0.10,-0.10, 0.00);
    glVertex3d(-0.10,-0.10, LINK_HEIGHT);
    glVertex3d( 0.00, 0.00, LINK_HEIGHT);

    glEnd();

    // link top
    glBegin(GL_TRIANGLES);
    glNormal3d(0, 0, -1);

    glVertex3d(-0.10, 0.10, 0.00);
    glVertex3d(-0.10,-0.10, 0.00);
    glVertex3d( 0.00, 0.00, 0.00);

    glVertex3d( 0.00, 0.12, 0.00);
    glVertex3d(-0.10, 0.10, 0.00);
    glVertex3d( 0.00, 0.00, 0.00);

    glVertex3d( 0.10, 0.10, 0.00);
    glVertex3d( 0.00, 0.12, 0.00);
    glVertex3d( 0.00, 0.00, 0.00);

    glVertex3d( 0.00, 0.00, 0.00);
    glVertex3d( 0.10,-0.10, 0.00);
    glVertex3d( 0.10, 0.10, 0.00);

    // left side
    glVertex3d(-0.10, 0.00, 0.00);
    glVertex3d(-0.18, 0.00, 0.00);
    glVertex3d(-0.10,-0.10, 0.00);

    glVertex3d(-0.18, 0.00, 0.00);
    glVertex3d(-0.20,-0.02, 0.00);
    glVertex3d(-0.10,-0.10, 0.00);

    glVertex3d(-0.20,-0.20, 0.00);
    glVertex3d(-0.10,-0.10, 0.00);
    glVertex3d(-0.20,-0.02, 0.00);

    glVertex3d(-0.20,-0.20, 0.00);
    glVertex3d(-0.10,-0.20, 0.00);
    glVertex3d(-0.10,-0.10, 0.00);

    // right side
    glVertex3d( 0.10,-0.10, 0.00);
    glVertex3d( 0.18, 0.00, 0.00);
    glVertex3d( 0.10, 0.00, 0.00);

    glVertex3d( 0.10,-0.10, 0.00);
    glVertex3d( 0.20,-0.02, 0.00);
    glVertex3d( 0.18, 0.00, 0.00);

    glVertex3d( 0.20,-0.02, 0.00);
    glVertex3d( 0.10,-0.10, 0.00);
    glVertex3d( 0.20,-0.20, 0.00);

    glVertex3d( 0.10,-0.10, 0.00);
    glVertex3d( 0.10,-0.20, 0.00);
    glVertex3d( 0.20,-0.20, 0.00);

    // lower surface
    glNormal3d(0, 0, 1);
    glVertex3d( 0.00, 0.00, LINK_HEIGHT);
    glVertex3d(-0.10,-0.10, LINK_HEIGHT);
    glVertex3d(-0.10, 0.10, LINK_HEIGHT);

    glVertex3d( 0.00, 0.00, LINK_HEIGHT);
    glVertex3d(-0.10, 0.10, LINK_HEIGHT);
    glVertex3d( 0.00, 0.12, LINK_HEIGHT);

    glVertex3d( 0.00, 0.00, LINK_HEIGHT);
    glVertex3d( 0.00, 0.12, LINK_HEIGHT);
    glVertex3d( 0.10, 0.10, LINK_HEIGHT);

    glVertex3d( 0.10, 0.10, LINK_HEIGHT);
    glVertex3d( 0.10,-0.10, LINK_HEIGHT);
    glVertex3d( 0.00, 0.00, LINK_HEIGHT);

    // left side
    glVertex3d(-0.10,-0.10, LINK_HEIGHT);
    glVertex3d(-0.18, 0.00, LINK_HEIGHT);
    glVertex3d(-0.10, 0.00, LINK_HEIGHT);

    glVertex3d(-0.10,-0.10, LINK_HEIGHT);
    glVertex3d(-0.20,-0.02, LINK_HEIGHT);
    glVertex3d(-0.18, 0.00, LINK_HEIGHT);

    glVertex3d(-0.20,-0.02, LINK_HEIGHT);
    glVertex3d(-0.10,-0.10, LINK_HEIGHT);
    glVertex3d(-0.20,-0.20, LINK_HEIGHT);

    glVertex3d(-0.10,-0.10, LINK_HEIGHT);
    glVertex3d(-0.10,-0.20, LINK_HEIGHT);
    glVertex3d(-0.20,-0.20, LINK_HEIGHT);

    // right side
    glVertex3d( 0.10, 0.00, LINK_HEIGHT);
    glVertex3d( 0.18, 0.00, LINK_HEIGHT);
    glVertex3d( 0.10,-0.10, LINK_HEIGHT);

    glVertex3d( 0.18, 0.00, LINK_HEIGHT);
    glVertex3d( 0.20,-0.02, LINK_HEIGHT);
    glVertex3d( 0.10,-0.10, LINK_HEIGHT);

    glVertex3d( 0.20,-0.20, LINK_HEIGHT);
    glVertex3d( 0.10,-0.10, LINK_HEIGHT);
    glVertex3d( 0.20,-0.02, LINK_HEIGHT);

    glVertex3d( 0.20,-0.20, LINK_HEIGHT);
    glVertex3d( 0.10,-0.20, LINK_HEIGHT);
    glVertex3d( 0.10,-0.10, LINK_HEIGHT);

    glVertex3d(-0.10, 0.10, LINK_HEIGHT);
    glVertex3d( 0.00, 0.20, LINK_HEIGHT);
    glVertex3d( 0.00, 0.12, LINK_HEIGHT);

    glVertex3d( 0.00, 0.12, LINK_HEIGHT);
    glVertex3d( 0.00, 0.20, LINK_HEIGHT);
    glVertex3d( 0.10, 0.10, LINK_HEIGHT);

    // arrow
    glColor3f(0.0, 0.0, 0.8);
    glNormal3d(0, 0, -1);
    glVertex3d( 0.00, 0.12, 0.00);
    glVertex3d( 0.00, 0.20, 0.00);
    glVertex3d(-0.10, 0.10, 0.00);

    glVertex3d( 0.10, 0.10, 0.00);
    glVertex3d( 0.00, 0.20, 0.00);
    glVertex3d( 0.00, 0.12, 0.00);
    glEnd();
}