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
    if (timer > 60) {
        timer = 0;
    }

    float time = float(timer);

    // grabbing the first cube
    if (timer <= 60) {
        arm1.rotationZ = 180.0 - time * 1.5;
        if (timer <= 30) {
            // lifting up
            arm1.rotationX1 = 90 - time * 1.5;
        }
        else {
            // moving down
            arm1.rotationX1 = time * 1.5;
        }

    }


}