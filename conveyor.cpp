#include <GL/glu.h>
#include "conveyor.hpp"

Conveyor::Conveyor(Vector2<float> speed, Vector2<float> conveyorSize, float height)
: speed(speed), conveyorSize(conveyorSize), height(height){
    if (this->speed.x != 0 and this->speed.y != 0) {
        if (this->speed.x > this->speed.y){
            this->speed.y = 0;
        }
        else {
            this->speed.x = 0;
        }
    }
}

#define LINK_HEIGHT 0.2

inline void drawLink() {

    // link top
    glBegin(GL_TRIANGLES);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3d( 0.00, 0.00, LINK_HEIGHT);
    glVertex3d(-0.10,-0.10, LINK_HEIGHT);
    glVertex3d(-0.10, 0.10, LINK_HEIGHT);

    glVertex3d( 0.00, 0.00, LINK_HEIGHT);
    glVertex3d(-0.10, 0.10, LINK_HEIGHT);
    glVertex3d( 0.00, 0.12, LINK_HEIGHT);

    glVertex3d( 0.00, 0.00, LINK_HEIGHT);
    glVertex3d( 0.00, 0.12, LINK_HEIGHT);
    glVertex3d( 0.10, 0.10, LINK_HEIGHT);

    glVertex3d( 0.00, 0.00, LINK_HEIGHT);
    glVertex3d( 0.10,-0.10, LINK_HEIGHT);
    glVertex3d( 0.10, 0.10, LINK_HEIGHT);

    glVertex3d(-0.10, 0.20, LINK_HEIGHT);
    glVertex3d(-0.18, 0.00, LINK_HEIGHT);
    glVertex3d(-0.10, 0.00, LINK_HEIGHT);

    // arrow
    glColor3f(0.0, 0.0, 0.8);
    glVertex3d(-0.10, 0.10, LINK_HEIGHT);
    glVertex3d( 0.00, 0.20, LINK_HEIGHT);
    glVertex3d( 0.00, 0.12, LINK_HEIGHT);

    glVertex3d( 0.10, 0.10, LINK_HEIGHT);
    glVertex3d( 0.00, 0.20, LINK_HEIGHT);
    glVertex3d( 0.00, 0.12, LINK_HEIGHT);
    glEnd();
}

void Conveyor::draw() {
    drawLink();
}