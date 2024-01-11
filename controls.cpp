#include <cmath>

#include "controls.hpp"
#include <GL/freeglut.h>

int currentX = 0;
int currentY = 0;
bool firstMove = true;
#define MOUSE_DEGREE_VALUE 10.f

void HandleKeyPress(unsigned char key, int x, int y) {

    switch (key) {
        case 'a':
            positionX -= std::cos(rotationY * 0.017452778f) * 0.5f;
            positionY += std::sin(rotationY * 0.017452778f) * 0.5f;
            break;
        case 'w':
            positionX -= std::sin(rotationY * 0.017452778f) * 0.5f;
            positionY -= std::cos(rotationY * 0.017452778f) * 0.5f;
            break;
        case 's':
            positionX += std::sin(rotationY * 0.017452778f) * 0.5f;
            positionY += std::cos(rotationY * 0.017452778f) * 0.5f;
            break;
        case 'd':
            positionX += std::cos(rotationY * 0.017452778f) * 0.5f;
            positionY -= std::sin(rotationY * 0.017452778f) * 0.5f;
            break;
        case 'c':
            positionZ -= 0.1f;
            break;
        case 'f':
            positionZ += 0.1f;
            break;
    }
}

void HandleMouseMove(int x, int y) {

    if (x > (RES_X / 2) + 200 or x < (RES_X / 2) - 200 or y > (RES_Y / 2) + 200 or y < (RES_Y / 2) - 200) {
        glutWarpPointer(RES_X / 2, RES_Y / 2);
        currentX = RES_X / 2;
        currentY = RES_Y / 2;
        if (x > (RES_X / 2) + 200) {
            x -= 200;
        }
        else if (x < (RES_X / 2) - 200) {
            x += 200;
        }
        if (y > (RES_Y / 2) + 200) {
            y -= 200;
        }
        else if (y < (RES_Y / 2) - 200) {
            y += 200;
        }
    }

    if (firstMove) {
        firstMove = false;
        currentX = x;
        currentY = y;
        return;
    }

    rotationX -= float(y - currentY) / MOUSE_DEGREE_VALUE;
    rotationY -= float(x - currentX) / MOUSE_DEGREE_VALUE;

    currentX = x;
    currentY = y;

    while (rotationX > 135.f) {
        rotationX = 135.f;
    }
    while (rotationX < 45.f) {
        rotationX = 45.f;
    }
    while (rotationY > 360.f) {
        rotationY -= 360.f;
    }
    while (rotationY < 0.f) {
        rotationY += 360.f;
    }

    //std::cout << rotationX << "\n";

}