#ifndef GRAFIKA_LINIA_ARMS_HPP
#define GRAFIKA_LINIA_ARMS_HPP

#include <cstdint>

struct Arm {
    float rotationZ = 0.f;
    float rotationX1 = 0.f;
    float rotationX2 = 0.f;
    float rotationX3 = 0.f;
    bool hasCube = false;
    uint8_t cubeState = 0;

    void draw1();
    void draw2();
};

inline Arm arm1, arm2, arm3, arm4;

#endif //GRAFIKA_LINIA_ARMS_HPP
