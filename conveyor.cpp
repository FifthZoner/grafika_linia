#include <GL/glu.h>
#include <valarray>
#include "conveyor.hpp"
#include "normals.hpp"

Conveyor::Conveyor(float size, float speed) : speed(speed), size(size) {}

void Conveyor::draw() {

    drawHousing();

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