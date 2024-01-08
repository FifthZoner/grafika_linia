#ifndef GRAFIKA_LINIA_LINE_HPP
#define GRAFIKA_LINIA_LINE_HPP

#include "vector.hpp"

#define LINK_HEIGHT 0.1


struct Conveyor {
    // only one value should not be 0
    float size = 0.f;
    float speed = 0.f;
    float position = 0.f;

    Conveyor(float size, float speed);
    void draw();
    void drawLink();
};

inline Conveyor conveyor1(3, 0.005);
inline Conveyor conveyor2(4, 0.01);

#endif //GRAFIKA_LINIA_LINE_HPP
