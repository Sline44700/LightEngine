#ifndef STRUCTURES_H
#define STRUCTURES_H
//#include <cmath>

typedef struct {
  int x;
  int y;
} Point;

class Vector {
private:
  int x;
  int y;
public:
  Vector(int m_x, int m_y) { x = m_x; y = m_y; }
  int sqr() { return x*x + y*y; }
  float distance(Vector alt) { sqrt((float)(alt.x - x)*(alt.x - x) + (float)(alt.y - y)*(alt.y - y)); }
};

#endif // STRUCTURES_H
