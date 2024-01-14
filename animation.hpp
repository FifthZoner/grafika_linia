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

inline std::array <Vector3f, 9> positions {
    Vector3f(0.85, -0.4 + 0.3, 0.2),
    Vector3f(1.1, -0.4 + 0.3, 0.2),
    Vector3f(0.85, -0.65 + 0.3, 0.2),
    Vector3f(1.1, -0.65 + 0.3, 0.2),
    Vector3f(0.975, -0.525 + 0.3, 0),
    Vector3f(0.09, 0.75, -0.1),
    Vector3f(0.09, 1.5, -0.1),
    Vector3f(1.91, 2.3, -0.1),
    Vector3f(1.91, 3.6, -0.1)

};
inline std::array <uint8_t, 9> states {0, 0, 0, 0, 0, 0, 1, 1, 2};
inline std::array <bool, 9> display {1, 1, 1, 1, 1, 1, 1, 1, 1};

#endif //GRAFIKA_LINIA_ANIMATION_HPP
