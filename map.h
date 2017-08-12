#ifndef MAP_H
#define MAP_H
#include "structures.h"
#include "mapobj.h"
#include <fstream>

class MapCell {
public:
  inline MapCell() {}
  inline ~MapCell() {/*delete obj;*/}
  MapObj* obj = NULL;
  Vector coords;
};

class Map {
private:
  MapCell** tab;
  Vector size;
//  FILE file;
  void read(char** data);
  void setSize(Vector size);

public:
  Map(Vector m_size);
  Map(std::ifstream& file);
  ~Map();
  char** build(Vector start, Vector end); // возвращает кусок карты для объекта класса Field
  void load(std::ifstream& file);
  void save(std::ofstream& file);
  void destroy(); // уничтожает все объекты на карте
  void addObj(MapObj* obj, Vector coords);
  MapObj* findObj(Vector coords); // возвращает объект по координатам

};

#endif // MAP_H
