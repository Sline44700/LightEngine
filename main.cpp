#include <iostream>
#include "defines.h"
#include "field.h"
#include "field.cpp"
#include "map.h"
#include "map.cpp"
#include "mapobj.cpp"
#include "wall.h"
#include "wall.cpp"

using namespace std;

int main(void) {
  Field* field = new Field();
  Point start = {0, 0};
  Point wall = {1, 1};
  Point end = {32, 32};
  Map* map = new Map(end);
  Wall* w = new Wall(map, wall);

  cout << "Light Engine v" << VERSION << endl;
  field->import(map->build(start, end));
  field->refresh();
//  map->build(start, end);

  return 0;
}

