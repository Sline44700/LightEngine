#ifndef MAPOBJ_H
#define MAPOBJ_H
#include "structures.h"

class MapObj {
private:
  Point coords;
  string name;
  char symbol;
  int health = -1;
  int color = 1;

public:
  MapObj();
  Point getPos();
  void setPos(Point coords);
  void move(int side, int steps); // 0 - left, 1 - right, 2 - up, 3 - down
  int getHealth();
  void setHealth(int health);
  void damage(int health);
  char getSymbol();
  void setSymbol(char* symbol);
  int getColor();
  void setColor(int color);
};

#endif // MAPOBJ_H
