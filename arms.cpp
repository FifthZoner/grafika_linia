#include "arms.hpp"
#include "normals.hpp"
#include "product.hpp"
#include "animation.hpp"
#include <GL/freeglut.h>
#include <GL/gl.h>
#include <GL/glext.h>
#include <GL/glut.h>

#include <cmath>

void Ramie(float r1, float r2, float h, float d) {
    glBegin(GL_TRIANGLE_FAN);
    glNormal3d(0.0, 0.0, -1.0);
    glVertex3d(0.0f, 0.0f, 0.0f);
    for (double angle = 3.1415f; angle <= (2.f * 3.1415f); angle += (3.1415f / 32.0f))
    {
        double x = r1 * std::sin(angle);
        double y = r1 * std::cos(angle);
        glVertex3d(x, y, 0.0);
    }
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glNormal3d(0.0, 0.0, -1.0);
    glVertex3d(d, 0.0f, 0.0f);
    for (double angle = 0.f; angle <= (3.1415f); angle += (3.1415f / 32.0f))
    {
        double x = r2 * std::sin(angle) + d;
        double y = r2 * std::cos(angle);
        glVertex3d(x, y, 0.0);
    }
    glEnd();
    glBegin(GL_QUADS);
    glVertex3d(0.f, r1, 0.f);
    glVertex3d(d, r2, 0.f);
    glVertex3d(d, -r2, 0.f);
    glVertex3d(0.f, -r1, 0.f);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glNormal3d(0.0, 0.0, 1.0);
    glVertex3d(0.0f, 0.0f, h);
    for (double angle = 0.f; angle >= -(3.1415f); angle -= (3.1415f / 32.0f))
    {
        double x = r1 * std::sin(angle);
        double y = r1 * std::cos(angle);
        glVertex3d(x, y, h);
    }
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glNormal3d(0.0, 0.0, 1.0);
    glVertex3d(d, 0.0f, h);
    for (double angle = -3.1415f; angle >= -(2.f * 3.1415f); angle -= (3.1415f / 32.0f))
    {
        double x = r2 * std::sin(angle) + d;
        double y = r2 * std::cos(angle);
        glVertex3d(x, y, h);
    }
    glEnd();
    glBegin(GL_QUADS);
    glVertex3d(0.f, -r1, h);
    glVertex3d(d, -r2, h);
    glVertex3d(d, r2, h);
    glVertex3d(0.f, r1, h);
    glEnd();

    glBegin(GL_QUAD_STRIP);
    for (double angle = 3.1415f; angle <= (2.0f * 3.1415f); angle += (3.1415f / 32.0f))
    {
        double x = r1 * std::sin(angle);
        double y = r1 * std::cos(angle);
        glNormal3d(std::sin(angle), std::cos(angle), 0.0);
        glVertex3d(x, y, 0);
        glVertex3d(x, y, h);
    }
    glEnd();
    glBegin(GL_QUADS);
    float v[3][3] = { {0.0f, r1, h},
                      {d,r2,h},
                      {d,r2,0.f}
    };
    float norm[3];
    Normal(v, norm);
    glNormal3d(norm[0], norm[1], norm[2]);
    glVertex3d(0.f, r1, h);
    glVertex3d(d, r2, h);
    glVertex3d(d, r2, 0.f);
    glVertex3d(0.f, r1, 0.f);
    glEnd();
    glBegin(GL_QUAD_STRIP);
    for (double angle = 0.f; angle <= (3.1415f); angle += (3.1415f / 32.0f))
    {
        double x = r2 * std::sin(angle) + d;
        double y = r2 * std::cos(angle);
        glNormal3d(std::sin(angle), std::cos(angle), 0.0);
        glVertex3d(x, y, 0);
        glVertex3d(x, y, h);
    }
    glEnd();
    glBegin(GL_QUADS);
    float v2[3][3] = { {d, -r2, 0.f},
                       {d,-r2,h},
                       {0.f,-r1,h}
    };
    Normal(v2, norm);
    glNormal3d(norm[0], norm[1], norm[2]);
    glVertex3d(d, -r2, 0.f);
    glVertex3d(d, -r2, h);
    glVertex3d(0.f, -r1, h);
    glVertex3d(0.f, -r1, 0.f);
    glEnd();

}

void Arm::draw1() {
    glColor3d(0.3f, 0.3f, 0.7f);
    auto* quad = gluNewQuadric();
    gluCylinder(quad, 0.2f, 0.3f, 0.2f, 100, 1);

    glColor3d(0.6f, 0.6f, 0.6f);

    glPushMatrix();
    glRotated(rotationZ, 0, 0, 1);
    gluSphere(quad, 0.2, 100, 100);

    glRotated(rotationX1, 1, 0, 0);
    glTranslated(0.f, 0.f, -0.4f);
    gluCylinder(quad, 0.1f, 0.1f, 0.3f, 100, 1);

    glTranslated(-0.1f, 0.f, 0.f);
    glRotated(90, 0, 1, 0);
    gluCylinder(quad, 0.1f, 0.1f, 0.2f, 100, 1);
    glPushMatrix();

    glRotated(rotationX2, 0, 0, 1);
    glTranslated(0.f, 0.f, 0.2f);
    Ramie(0.1, 0.075, 0.05, 0.2);

    glTranslated(0.f, 0.f, -0.25f);
    Ramie(0.1, 0.075, 0.05, 0.2);

    glTranslated(0.2f, 0.f, 0.05f);
    glRotated(rotationX3, 0, 0, 1);
    gluCylinder(quad, 0.075f, 0.075f, 0.2f, 100, 1);
    glRotated(-90, 0, 1, 0);
    glTranslated(0.1f, 0.f, -0.2f);
    gluCylinder(quad, 0.075f, 0.075f, 0.2f, 100, 1);
    glTranslated(0.f, 0.f, -0.1f);
    gluCylinder(quad, 0.05f, 0.075f, 0.1f, 100, 1);
    gluDisk(quad, 0.f, 0.05f, 100, 1);

    if (hasCube) {
        glTranslated(0.f, 0.f, -0.1f);
        switch (cubeState) {
            case State::start:
                drawCube();
                break;
            case State::heated:
                drawCubeHeated();
                break;
            case State::brushed:
                drawCubeBrushed();
                break;
            case State::cooled:
                drawCubeCooled();
                break;
        }
    }

    glPopMatrix();
    glPopMatrix();

    gluDeleteQuadric(quad);
}

void Arm::draw2() {

}