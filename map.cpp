#include "map.h"
#include "mapobj.h"
#include "wall.h"
#include <fstream>
#include <iostream>

Map::Map(Vector m_size) {
  size = m_size;
  tab = new MapCell*[size.x];
  for (auto x = 0; x <= size.x; x++) {
    tab[x] = new MapCell[size.y];
    /*for (auto y = 0; y < size.y; y++)
      tab[x][y] = Floor();*/
  }
}

Map::Map(char* name) {
//  this->file = file;
  load(name);
}

Map::~Map() {
//  std::cout << "Map deconstructed" << std::endl;
/*  for (auto x = 0; x < size.x; x++)
    delete[] tab[x];
  delete[] tab;*/
}

char** Map::build(Vector start, Vector end) {
  Vector size(end.x - start.x, end.y - start.y);
  char** field = new char*[size.x];
  MapCell* cell;

  if (size.x > this->size.x || size.y > this->size.y) {
    std::cout << "POSHIV NAHUY" << std::endl; // replace this
    return field;
  }

  for (auto x = 0; x <= size.x; x++) {
    field[x] = new char[size.y];
    for (auto y = 0; y <= size.y; y++) {
      cell = &tab[x][y];
      if (cell != NULL && cell->obj != NULL)
        field[x][y] = cell->obj->getSymbol();
      else
        field[x][y] = '.';
    }
  }

  return field;
}

void Map::setSize(Vector size) {
  this->size = size;
}

void Map::load(char* name) {
  file.open(name, file.in);
  if (!file.is_open())
    return;

  size.x = -2;
  size.y = 0;
  char symbol;
  // finding out max of x coords
  while (!file.eof()) {
    file.get(symbol);
    if (symbol != ' ') size.x++;
    if (symbol == '\n') break;
  }
  file.seekg(0, file.beg);
  file.clear();
  // finding out max of x coords
  while (!file.eof()) {
    file.get(symbol);
    if (symbol == '\n') size.y++;
  }
  file.seekg(0, file.beg);
  file.clear();
  // creating table
  tab = new MapCell*[size.x];
  for (auto x = 0; x <= size.x; x++)
    tab[x] = new MapCell[size.y + 1];
  // loading objs
  file.seekg(0, file.beg);
  file.clear();
  for (auto x = 0; x <= size.x; x++)
    for (auto y = 0; y <= size.y; y++) {
      file.get(symbol);
      if (symbol == ' ' || symbol == '\n') file.get(symbol);
//      std::cout << std::endl << symbol << " " << x << " " << y;
      if (symbol == '|') { new Wall(this, Vector(y, x)); }
/*      switch(symbol) {
        case '|' : { new Wall(this, Vector(x, y)); };
        default : {};*/
      }
}

void Map::save(char* name) {
  file.open(name, file.out);
  if (!file.is_open())
    return;

  //
}

void Map::destroy() {
  //
}\

void Map::addObj(MapObj* obj, Vector coords) {
  MapCell* cell = &tab[coords.x][coords.y];

  if (cell->obj == NULL) {
    cell->obj = obj;
    // TODO: std -> Console
//  std::cout << "Object '" << obj->getSymbol() << "' added to coords " << coords.x << " " << coords.y << std::endl;
  }
}

MapObj* Map::findObj(Vector coords) {
  MapCell* cell = &tab[coords.x][coords.y];
  MapObj* obj = cell->obj;

  if (obj != NULL)
    return obj;
  else return NULL;
}
