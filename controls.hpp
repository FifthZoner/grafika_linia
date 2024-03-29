#ifndef GRAFIKA_LINIA_CONTROLS_HPP
#define GRAFIKA_LINIA_CONTROLS_HPP

inline float rotationX = 90;
inline float rotationY = 0;
inline float rotationZ = 0;
inline float positionX = -20;
inline float positionY = -50;
inline float positionZ = 5;

#define RES_X 2560
#define RES_Y 1400

void HandleKeyPress(unsigned char key, int x, int y);

void HandleMouseMove(int x, int y);

#endif //GRAFIKA_LINIA_CONTROLS_HPP
