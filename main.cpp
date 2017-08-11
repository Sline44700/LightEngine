#include <iostream>
#include <string.h>
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

  for (auto x = 0; x <= 16; x++)
    for (auto y = 0; y <= 16; y++)
      if (x == 0 || y == 0 || x == 16 || y == 16)
        Wall wall(map, Vector(x, y));

  char str[32];
  strcpy(str, "Light Engine v");
  field->printStr(strcat(str, VERSION), Vector(0, 0));
  field->import(map->build(Vector(0, 0), Vector(16, 16)));
  field->refresh();
  field->print('@', Vector(2, 3));
  field->printStr("VIXODA HET", Vector(4, 10));
  field->setCursorPos(Vector(0, 20));

  return 0;
}

