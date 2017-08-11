#include "map.h"
#include "mapobj.h"
#include <fstream>
#include <iostream>

Map::Map(Vector m_size) {
  size = m_size;
  tab = new MapCell*[size.x];
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
  std::cout << "Map deconstructed" << std::endl;
/*  for (auto x = 0; x < size.x; x++)
    delete[] tab[x];
  delete[] tab;*/
}

char** Map::build(Vector start, Vector end) {
  Vector size(end.x - start.x, end.y - start.y);
  char** field = new char*[size.x];
  MapCell* cell;

  if (size.x > this->size.x || size.y > this->size.y) {
    std::cout << "POSHIV NAHUY" << std::endl;
    return field;
  }

  for (auto x = 0; x <= size.x; x++) {
    field[x] = new char[size.y];
    for (auto y = 0; y <= size.y; y++) {
      cell = &tab[x][y];
      if (cell != NULL && cell->obj != NULL)
        //field[x][y] = cell->obj->getSymbol();
        field[x][y] = 'w';
      else
        field[x][y] = ' ';
    }
  }

  return field;
}

void Map::setSize(Vector size) {
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

void Map::addObj(MapObj* obj, Vector coords) {
  MapCell* cell = &tab[coords.x][coords.y];

  if (cell->obj == NULL) {
    cell->obj = obj;
    std::cout << "Object '" << obj->getSymbol() << "' added to coords " << coords.x << " " << coords.y << std::endl;
  }
}

MapObj* Map::findObj(Vector coords) {
  MapCell* cell = &tab[coords.x][coords.y];
  MapObj* obj = cell->obj;

  if (obj != NULL)
    return obj;
  else return NULL;
}
