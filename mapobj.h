#ifndef MAPOBJ_H
#define MAPOBJ_H
#include "structures.h"

class Map;

class MapObj {
private:
  Point coords;
//  string name;
  char symbol = '?';
  int health = -1;
  int color = 1;
  Map* map;
//  bool impenetrable = true;

public:
  MapObj(Map* m_map, Point m_coords);
  ~MapObj();
  Point getPos() { return coords; }
  inline void setPos(Point m_coords) { coords = m_coords; }
  void move(int side, int steps); // 0 - left, 1 - right, 2 - up, 3 - down
  inline int getHealth() { return health; }
  inline void setHealth(int m_health) { health = m_health; }
  inline void damage(int m_health) { health -= m_health; }
  inline char getSymbol() { return symbol; }
  inline void setSymbol(char m_symbol) { symbol = m_symbol; }
  inline int getColor() { return color; }
  inline void setColor(int m_color) { color = m_color; }
};

/*class Floor : public MapObj {
public:
  Floor();
  ~Floor();
}*/

#endif // MAPOBJ_H
