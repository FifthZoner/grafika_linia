#ifndef GRAFIKA_LINIA_VECTOR_HPP
#define GRAFIKA_LINIA_VECTOR_HPP

#include <cstddef>
#include <concepts>

template <typename T>
concept Number = std::integral<T> or std::floating_point<T>;

template <Number T>
struct Vector2 {
    T x, y;
    Vector2(T x, T y) : x(x), y(y){}
    Vector2(){
        x = 0;
        y = 0;
    }
};

#endif //GRAFIKA_LINIA_VECTOR_HPP
