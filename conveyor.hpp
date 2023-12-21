#ifndef GRAFIKA_LINIA_LINE_HPP
#define GRAFIKA_LINIA_LINE_HPP

#include "vector.hpp"

struct Conveyor {
    // only one value should not be 0
    Vector2<float> speed = {0, 0};
    Vector2<float> conveyorSize = {0, 0};
    float height = 0;
    float position = 0;

    Conveyor(Vector2<float> speed, Vector2<float> conveyorSize, float height);
    void draw();
};

inline Conveyor conveyor1({10, 0}, {100, 50}, 10);

#endif //GRAFIKA_LINIA_LINE_HPP
