#include <GL/freeglut.h>
#include <GL/gl.h>
#include <valarray>
#include <iostream>
#include "conveyor.hpp"
#include "controls.hpp"

void drawTriangle() {
    glClearColor(0.4, 0.4, 0.4, 0.4);
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 1.0, 1.0);
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);



    glBegin(GL_TRIANGLES);
    glVertex3f(-0.7, 0.7, 0);
    glVertex3f(0.7, 0.7, 0);
    glVertex3f(0, -1, 0);
    glEnd();

    glFlush();
}

void drawTheLine() {
    glClearColor(1.f, 1.f, 1.f, 1.f);
    glPolygonMode(GL_BACK,GL_LINE);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    glEnable(GL_CULL_FACE);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslated(0, 0, 0);
    glRotatef(rotationX, 1, 0, 0);
    glRotatef(rotationY, 0, 1, 0);
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

    glPushMatrix();

    conveyor1.draw();

    glPopMatrix();
    glutSwapBuffers();
    glFlush();
}

void frameTimer(int value) {
    drawTheLine();
    glutTimerFunc((unsigned int)(1000.f / 60.f), frameTimer, 0);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(1280, 720);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Linia produkcyjna");
    glutDisplayFunc(drawTheLine);
    //glutSpecialFunc(HandleKeyPress);
    glutKeyboardFunc(HandleKeyPress);
    glutMotionFunc(HandleMouseMove);
    glutPassiveMotionFunc(HandleMouseMove);
    glutTimerFunc((unsigned int)(1000.f / 60.f), frameTimer, 0);

    GLfloat  ambientLight[] = { 0.3f, 0.3f, 0.3f, 1.0f };
    GLfloat  diffuseLight[] = { 0.7f, 0.7f, 0.7f, 1.0f };
    GLfloat  specular[] = { 1.0f, 1.0f, 1.0f, 1.0f};
    GLfloat	 lightPos[] = { 0.0f, 150.0f, 150.0f, 1.0f };
    GLfloat  specref[] =  { 1.0f, 1.0f, 1.0f, 1.0f };


    glEnable(GL_LIGHTING);
    glLightfv(GL_LIGHT0,GL_AMBIENT,ambientLight);
    glLightfv(GL_LIGHT0,GL_DIFFUSE,diffuseLight);
    glLightfv(GL_LIGHT0,GL_SPECULAR,specular);
    glLightfv(GL_LIGHT0,GL_POSITION,lightPos);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
    glMaterialfv(GL_FRONT, GL_SPECULAR,specref);
    glMateriali(GL_FRONT,GL_SHININESS,128);

    glutMainLoop();
    return 0;
}