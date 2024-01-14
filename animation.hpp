#ifndef GRAFIKA_LINIA_ANIMATION_HPP
#define GRAFIKA_LINIA_ANIMATION_HPP

#include <array>
#include <cstdint>

enum State {
    start, heated, brushed, cooled
};

struct Vector3f {
    float x, y, z;
    Vector3f();
    Vector3f(float x, float y, float z);
};


void Animate();

// the last one flies away
inline std::array <Vector3f, 17> positions {
    Vector3f(0.85, -0.4 + 0.3, 0.2),
    Vector3f(1.1, -0.4 + 0.3, 0.2),
    Vector3f(0.85, -0.65 + 0.3, 0.2),
    Vector3f(1.1, -0.65 + 0.3, 0.2),
    Vector3f(0.975, -0.525 + 0.3, 0),
    Vector3f(0.09, 0.75, -0.1),
    Vector3f(0.09, 1.5, -0.1),
    Vector3f(1.91, 2.3, -0.1),
    Vector3f(1.91, 3.6, -0.1),
    Vector3f(0.09, 5.9, -0.1),
    Vector3f(0.09, 5.9, -0.1),
    Vector3f(-0.86 - 0.125, 7.2 + 0.125, 0.2),
    Vector3f(-0.86 - 0.125, 7.2 - 0.125, 0.2),
    Vector3f(-0.86 + 0.125, 7.2 - 0.125, 0.2),
    Vector3f(-0.86 + 0.125, 7.2 + 0.125, 0.2),
    Vector3f(-0.86, 7.2, 0),
    Vector3f(-0.86, 7.2, 0)
};


inline std::array <uint8_t, 17> states {0, 0, 0, 0, 0, 0, 1, 1, 2, 2, 3, 3, 3, 3, 3, 3, 3};
inline std::array <bool, 17> display {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

#endif //GRAFIKA_LINIA_ANIMATION_HPP
