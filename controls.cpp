#include <cmath>

#include "controls.hpp"

#include <iostream>

int currentX = 0;
int currentY = 0;
bool firstMove = true;
#define MOUSE_DEGREE_VALUE 2.f

void HandleKeyPress(unsigned char key, int x, int y) {
    //std::cout << key << " " << x << " " << y << "\n";
}

void HandleMouseMove(int x, int y) {
    if (firstMove) {
        firstMove = false;
        currentX = x;
        currentY = y;
        return;
    }
    //std::cout << x << " " << y << "\n";
    rotationX += float(y - currentY) / MOUSE_DEGREE_VALUE;
    rotationY += float(x - currentX) / MOUSE_DEGREE_VALUE;
    currentX = x;
    currentY = y;

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