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
  std::fstream file;
  void read(char** data);
  void setSize(Vector size);

public:
  Map(Vector m_size);
  Map(char* name);
  ~Map();
  char** build(Vector start, Vector end); // возвращает кусок карты для объекта класса Field
  void load(char* name);
  void save(char* name);
  void destroy(); // уничтожает все объекты на карте
  void addObj(MapObj* obj, Vector coords);
  MapObj* findObj(Vector coords); // возвращает объект по координатам
  bool existObj(Vector coords); // проверяет, существует ли объект на данных коордах
  inline Vector getSize() {return size;}
};

#endif // MAP_H
