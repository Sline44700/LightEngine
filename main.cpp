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
  Map* map = new Map(Vector(17, 17));
//  Wall wall(map, Vector(1, 1));

  for (auto x = 1; x <= 16; x++)
    for (auto y = 1; y <= 16; y++)
      if (x == 1 || y == 1 || x == 16 || y == 16)
        Wall wall(map, Vector(x, y));

  cout << "Light Engine v" << VERSION << endl;
  field->import(map->build(Vector(0, 0), Vector(16, 16)));
  field->refresh();

  return 0;
}

