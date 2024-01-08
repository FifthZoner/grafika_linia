#include <GL/freeglut.h>
#include <GL/gl.h>
#include <valarray>
#include <iostream>
#include "conveyor.hpp"
#include "controls.hpp"

float g_lightPos[4] = { 4, 2, 3, 1 };

void drawTheLine() {

    glViewport(0, 0, RES_X, RES_Y);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(65.0, (float)1280 / 720, 1, 1000);
    glMatrixMode(GL_MODELVIEW);

    glClearColor(1.f, 1.f, 1.f, 1.f);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();
    gluLookAt(0, 0, -9, 0, 0, -1, 0, 1, 0);
    glLightfv(GL_LIGHT0, GL_POSITION, g_lightPos);

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();


    glRotatef(rotationX, 1, 0, 0);
    glRotatef(rotationY, 0, 0, 1);
    glTranslated(positionX, positionY, positionZ);

    glScaled(10, 10, 10);

    //glPushMatrix();
    conveyor1.draw();
    //glPopMatrix();
    glPushMatrix();
    glTranslated(0.8f, 0, 0);
    conveyor2.draw();
    glPopMatrix();

    glPopMatrix();
    glutSwapBuffers();
    //glFlush();
}

void frameTimer(int value) {
    drawTheLine();
    glutTimerFunc((unsigned int)(1000.f / 60.f), frameTimer, 0);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(RES_X, RES_Y);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Linia produkcyjna");

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    glShadeModel(GL_SMOOTH);
    //glEnable(GL_LIGHTING);
    //(GL_LIGHT0);
    //glEnable(GL_CULL_FACE);


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