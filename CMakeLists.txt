cmake_minimum_required(VERSION 3.26)
project(grafika_linia)

set(CMAKE_CXX_STANDARD 23)

add_executable(grafika_linia main.cpp
        conveyor.hpp
        vector.hpp
        vector.tpp
        conveyor.cpp
        controls.hpp
        controls.cpp
        normals.cpp
        normals.hpp
        conveyorDrawing.cpp
        product.hpp
        product.cpp)
target_link_libraries(grafika_linia glut GL GLU)
