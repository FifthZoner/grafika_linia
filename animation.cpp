#include "animation.hpp"
#include "arms.hpp"

Vector3f::Vector3f() {
    x = 0.f;
    y = 0.f;
    z = 0.f;
}

Vector3f::Vector3f(float x, float y, float z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

void ChangeFloat(float& num, float value) {
    num += value;
    while (num > 360.f) {
        num -= 360.f;
    }
    while (num < 0.f) {
        num += 360.f;
    }
}

unsigned int timer = 0;

// only moved things around, does not display anything
void Animate() {
    timer++;
    if (timer > 180) {
        timer = 0;
    }

    float time = float(timer);

    // grabbing the first cube and moving it to the belt
    if (timer <= 90) {
        display[5] = false;
        positions[4] = Vector3f(0.975, -0.525 + 0.3, 0 - ((120 - time) * 0.1));
        arm1.hasCube = true;
        arm1.rotationX2 = -30 - (20 * (time / 90));
        arm1.rotationX3 = 30 + (25 * (time / 90));
        arm1.rotationZ = 180.0 - time;
        if (timer <= 45) {
            // lifting up
            arm1.rotationX1 = 90 - time;
        }
        else {
            // moving down
            arm1.rotationX1 = time - (5 * ((time - 45) / 45));
        }
    }
    else {
        display[5] = true;
        positions[5] = Vector3f(0.09, 0.75 + ((time - 90) * 0.01), -0.1);
        if (timer <= 120) {
            positions[4] = Vector3f(0.975, -0.525 + 0.3, -((120 - time) / 180 * 20));
        }

        arm1.hasCube = false;
        arm1.rotationX2 = -30 - (20 * (1 - (time - 90) / 90));
        arm1.rotationX3 = 30 + (25 * (1 - (time - 90) / 90));
        arm1.rotationZ = 90 + (time - 90);
        if (timer <= 135) {
            // lifting up
            arm1.rotationX1 = 90 - (time - 90);
        }
        else {
            // moving down
            arm1.rotationX1 = (time - 90) - (5 * ((time - 135) / 45));
        }
    }

    // I will double it because it's easier that way
    // the heated to second conveyor transfer
    if (timer <= 90) {
        arm2.cubeState = 1;
        display[6] = true;
        positions[6] = Vector3f(0.09, 1.4 + ((time) * 0.01), -0.1);

    }
    else {
        display[6] = false;

    }

}