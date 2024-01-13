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

inline std::array <Vector3f, 10> positions {
    Vector3f(0.85, -0.4, 0.2),
    Vector3f(1.1, -0.4, 0.2),
    Vector3f(0.85, -0.65, 0.2),
    Vector3f(1.1, -0.65, 0.2),
    Vector3f(0.975, -0.525, 0)

};
inline std::array <Vector3f, 10> rotations;
inline std::array <uint8_t, 10> states {};

#endif //GRAFIKA_LINIA_ANIMATION_HPP
