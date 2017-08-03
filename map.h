#ifndef MAP_H
#define MAP_H
#include "structures.h"
#include "mapobj.h"
#include <fstream>

class Map {
private:
  MapObj** tab;
  Point size;
  void read(char** data);

public:
  Map();
  ~Map();
  char** build(Point start, Point end); // возвращает кусок карты для объекта класса Field
  void load(FILE data);
  void save(FILE data);
  void destroy(); // уничтожает все объекты на карте
  MapObj findObj(Point coords); // возвращает объект по координатам
  void addObj(MapObj obj);

};

#endif // MAP_H
