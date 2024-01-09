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
    static void drawLink();
    void drawHousing() const;
};

inline Conveyor conveyor1(3, 0.005);
inline Conveyor conveyor2(8, 0.01);
inline Conveyor conveyor3(5, 0.005);

#endif //GRAFIKA_LINIA_LINE_HPP
