#include "map.h"
#include "mapobj.h"
#include <fstream>

Map::Map(Point m_size) {
  size = m_size;
  for (auto x = 0; x < size.x; x++) {
    tab[x] = new MapCell[size.y];
    /*for (auto y = 0; y < size.y; y++)
      tab[x][y] = Floor();*/
  }
}

Map::Map(FILE file) {
  this->file = file;
  load();
}

Map::~Map() {
  for (auto x = 0; x < size.x; x++)
    delete[] tab[x];
  delete tab;
}

char** Map::build(Point start, Point end) {
  Point size = {
    end.x - start.x,
    end.y - start.y,
  };
  char** field = new char*[size.x];
  for (auto x = 0; x < size.x; x++) {
    field[x] = new char[size.y];
    for (auto y = 0; y < size.y; y++) {
      MapCell* cell = &tab[x][y];
      if (cell != NULL)
        field[x][y] = cell->obj->getSymbol();
      else
        field[x][y] = ' ';
    }
  }

  return field;
}

void Map::setSize(Point size) {
  this->size = size;
}

void Map::load() {
  //
}

void Map::save() {
  //
}

void Map::destroy() {
  //
}\

void Map::addObj(MapObj* obj, Point coords) {
  MapCell* cell = &tab[coords.x][coords.y];

  if (cell == NULL)
    cell->obj = obj;
}

MapObj* Map::findObj(Point coords) {
  MapCell* cell = &tab[coords.x][coords.y];
  MapObj* obj = cell->obj;

  if (obj != NULL)
    return obj;
}
