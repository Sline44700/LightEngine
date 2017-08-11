#ifndef MAP_H
#define MAP_H
#include "structures.h"
#include "mapobj.h"
#include <fstream>

class MapCell {
public:
  inline MapCell() {;}
  inline ~MapCell() {/*delete obj;*/}
  MapObj* obj = NULL;
  Point coords; // TODO: replace to Vector pos;
};

class Map {
private:
  MapCell** tab;
  Point size;
  FILE file;
  void read(char** data);
  void setSize(Point size);

public:
  Map(Point m_size);
  Map(FILE file);
  ~Map();
  char** build(Point start, Point end); // возвращает кусок карты для объекта класса Field
  void load();
  void save();
  void destroy(); // уничтожает все объекты на карте
  void addObj(MapObj* obj, Point coords);
  MapObj* findObj(Point coords); // возвращает объект по координатам

};

#endif // MAP_H
