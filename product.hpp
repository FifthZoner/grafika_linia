#ifndef GRAFIKA_LINIA_PRODUCT_HPP
#define GRAFIKA_LINIA_PRODUCT_HPP

#include <GL/gl.h>

// the cube gets
// heated
// brushed like in brushed aluminum
// cooled
// thrown on a pile

inline GLuint textureCold = 0;
inline GLuint textureHot  = 0;
inline GLuint textureTile  = 0;

void drawFloor();

void drawDevice();

void drawCube();

void drawCubeHeated();

void drawCubeBrushed();

void drawCubeCooled();

void loadThings();

#endif //GRAFIKA_LINIA_PRODUCT_HPP
