#ifndef GRAFIKA_LINIA_ARMS_HPP
#define GRAFIKA_LINIA_ARMS_HPP

struct Arm {
    float rotationZ = 0.f;
    float rotationX1 = 45.f;
    float rotationX2 = 0.f;
    float rotationX3 = 0.f;
    float rotationY = 0.f;

    void draw1();
    void draw2();
};

inline Arm arm1;

#endif //GRAFIKA_LINIA_ARMS_HPP
