#include <conio.h>
#include <string.h>
#include "defines.h"
#include "field.h"
#include "field.cpp"
#include "map.h"
#include "map.cpp"
#include "mapobj.cpp"
#include "wall.h"
#include "wall.cpp"
#include <iostream>

//using namespace std;
// TODO: 1) load/save
//       2) Controller
//       3) Config
//       4) Console
//       5) Camera?

int main(void) {
  Field* field = new Field(Vector(16, 16));
  Map* map = new Map(Vector(17, 17));

  for (auto x = 0; x <= 16; x++)
    for (auto y = 0; y <= 16; y++)
      if (x == 0 || y == 0 || x == 16 || y == 16)
        Wall wall(map, Vector(x, y));

  field->import(map->build(Vector(0, 0), Vector(16, 16)), Vector(16, 16));
  field->refresh();
  field->print('@', Vector(2, 3), HIGH_MAGENTA);
  field->printStr(strcpy(new char, "VIXODA HET"), Vector(4, 10), HIGH_RED);
  field->setCursorPos(Vector(0, 20));

  getch();
//  delete map;
//  delete field;
  system("cls");

  char name[32];
  Map* map2 = new Map(strcpy(name, "maps/easy.txt"));
  Vector size = map2->getSize();
  Field* field2 = new Field(size);
  field2->import(map2->build(Vector(0, 0), size), size);
  field2->refresh();
  field->print('@', Vector(2, 3), HIGH_MAGENTA);
  field->print('+', Vector(9, 10), HIGH_RED);
  getch();

  return 0;
}

