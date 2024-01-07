#include <cmath>

#include "controls.hpp"

#include <iostream>
#include <GL/freeglut.h>

int currentX = 0;
int currentY = 0;
bool firstMove = true;
#define MOUSE_DEGREE_VALUE 2.f

void HandleKeyPress(unsigned char key, int x, int y) {
    switch (key) {
        case 'a':

            break;
        case 'w':

            break;
        case 's':

            break;
        case 'd':

            break;
    }
}

void HandleMouseMove(int x, int y) {
    if (firstMove) {
        firstMove = false;

        currentX = x;
        currentY = y;
        return;
    }

    rotationX += float(y - RES_Y / 2) / MOUSE_DEGREE_VALUE;
    rotationY += float(x - RES_X / 2) / MOUSE_DEGREE_VALUE;
    glutWarpPointer(RES_X / 2, RES_Y / 2);

    while (rotationX > 360.f) {
        rotationX -= 360.f;
    }
    while (rotationX < 0.f) {
        rotationX += 360.f;
    }
    while (rotationY > 360.f) {
        rotationY -= 360.f;
    }
    while (rotationY < 0.f) {
        rotationY += 360.f;
    }

    //std::cout << rotationX << "\n";

}